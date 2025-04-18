#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <vector>

namespace fs = std::filesystem;

// Structure to store tag associations
std::map<std::string, std::vector<std::pair<std::string, std::string>>> tagsMap;

// Function to process individual HTML files
void processHtmlFile(const fs::path& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return;
    }

    std::string line, title, url = filePath.string();
    std::smatch match;
    std::regex titleRegex(R"(<title>(.*?)</title>)");
    std::regex tagsRegex(R"(<ul id="tags">(.*?)</ul>)");
    std::regex tagRegex(R"(<li>(.*?)</li>)");

    // Modify file path display format
    if (url.starts_with("./")) {
        url = url.substr(2);  // Remove "./"
    }
    if (url.ends_with("/index.html")) {
        url = url.substr(0, url.length() - 11);  // Remove "/index.html"
    }
    std::string formattedPath;
    for (char c : url) {
        formattedPath += (c == '/') ? " > " : std::string(1, c);
    }

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, titleRegex)) {
            title = match[1]; // Extract page title
        }
        if (std::regex_search(line, match, tagsRegex)) {
            std::string tagsList = match[1];

            // Extract individual tags
            auto tagsBegin = std::sregex_iterator(tagsList.begin(), tagsList.end(), tagRegex);
            auto tagsEnd = std::sregex_iterator();

            for (std::sregex_iterator i = tagsBegin; i != tagsEnd; ++i) {
                std::string tag = (*i)[1];
                tagsMap[tag].push_back({formattedPath, "<a href=\"" + filePath.string() + "\" style=\"text-decoration: underline;\">" + title + "</a>"});
            }
        }
    }
}

// Function to generate summary HTML with tables
void generateSummaryHtml() {
    std::ofstream outputFile("tags_summary.html");
    if (!outputFile.is_open()) {
        std::cerr << "Error creating HTML file!" << std::endl;
        return;
    }

    // HTML Header
    outputFile << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n";
    outputFile << "<title>Tags Overview</title>\n";
    outputFile << "<style>\n";
    outputFile << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    outputFile << "h2 { color: #0066cc; }\n";
    outputFile << "table { width: 100%; border-collapse: collapse; margin-bottom: 20px; }\n";
    outputFile << "th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n";
    outputFile << "th { background-color: #f4f4f4; }\n";
    outputFile << "a { text-decoration: underline; color: #333; }\n";
    outputFile << "a:hover { color: #ff6600; }\n";
    outputFile << "</style>\n</head>\n<body>\n";
    outputFile << "<h1>Tags Overview</h1>\n";

    // Generate tables for each tag
    for (const auto& [tag, articles] : tagsMap) {
        outputFile << "<h2>" << tag << "</h2>\n";
        outputFile << "<table>\n<tr><th>Path</th><th>Name</th></tr>\n";
        for (const auto& [path, article] : articles) {
            outputFile << "<tr><td>" << path << "</td><td>" << article << "</td></tr>\n";
        }
        outputFile << "</table>\n";
    }

    // Closing HTML
    outputFile << "</body></html>\n";
    outputFile.close();
    std::cout << "File tags_summary.html has been created!\n";
}

int main() {
    std::string searchDir = "./";  // Root directory for searching

    for (const auto& entry : fs::recursive_directory_iterator(searchDir)) {
        if (entry.path().filename() == "index.html") {
            processHtmlFile(entry.path());
        }
    }

    generateSummaryHtml();
    return 0;
}
