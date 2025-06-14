/*
How to compile:
g++ -std=c++20 -o tags tags.cpp
*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <vector>

namespace fs = std::filesystem;

// Map each tag string to a list of (formatted-path, link-HTML) pairs
std::map<std::string, std::vector<std::pair<std::string, std::string>>> tagsMap;

// Process a single HTML file: extract its <title> and all <li> items under <ul id="tags">
void processHtmlFile(const fs::path& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return;
    }

    // Read entire file into a single string
    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    // Regex to grab <title>...</title>, case-insensitive
    std::regex titleRegex(R"(<title>(.*?)</title>)", std::regex::icase);
    // Regex to match a <ul id="tags"> block, including across newlines:
    // [\s\S] means "any whitespace or non-whitespace" = any char
    std::regex tagsRegex(R"(<ul id="tags">([\s\S]*?)</ul>)", std::regex::icase);
    // Regex to grab each <li>…</li> inside that block, case-insensitive
    std::regex tagRegex(R"(<li>(.*?)</li>)", std::regex::icase);

    std::smatch match;
    std::string title;
    std::string url = filePath.string();

    // Normalize URL display: remove leading "./" and trailing "/index.html"
    if (url.rfind("./", 0) == 0) {
        url.erase(0, 2);
    }
    if (url.size() >= 11 && url.compare(url.size() - 11, 11, "/index.html") == 0) {
        url.erase(url.size() - 11);
    }

    // Build a user-friendly path display, replacing '/' with ' > '
    std::string formattedPath;
    for (char c : url) {
        formattedPath += (c == '/') ? " > " : std::string(1, c);
    }

    // Extract page title
    if (std::regex_search(content, match, titleRegex)) {
        title = match[1];
    }

    // Extract the tags block (supports multiple lines)
    if (std::regex_search(content, match, tagsRegex)) {
        std::string tagsBlock = match[1];

        // Iterate all <li> inside the tags block
        auto it = std::sregex_iterator(tagsBlock.begin(), tagsBlock.end(), tagRegex);
        auto end = std::sregex_iterator();
        for (; it != end; ++it) {
            std::string tag = (*it)[1];
            // Store the formatted path and an HTML link with the page title
            tagsMap[tag].push_back({
                formattedPath,
                "<a href=\"" + filePath.string() +
                "\" style=\"text-decoration: underline;\">" + title + "</a>"
            });
        }
    }
}

// Generate a summary HTML file listing each tag and its associated pages
void generateSummaryHtml() {
    std::ofstream out("tags_summary.html");
    if (!out.is_open()) {
        std::cerr << "Error creating tags_summary.html" << std::endl;
        return;
    }

    out << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n";
    out << "<title>Tags Overview</title>\n";
    out << "<style>\n"
           "body { font-family: Arial, sans-serif; margin: 20px; }\n"
           "h2 { color: #0066cc; }\n"
           "table { width: 100%; border-collapse: collapse; margin-bottom: 20px; }\n"
           "th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n"
           "th { background-color: #f4f4f4; }\n"
           "a { text-decoration: underline; color: #333; }\n"
           "a:hover { color: #ff6600; }\n"
        "</style>\n</head>\n<body>\n";
    out << "<h1>Tags Overview</h1>\n";

    // One table per tag
    for (const auto& [tag, entries] : tagsMap) {
        out << "<h2>" << tag << "</h2>\n";
        out << "<table>\n<tr><th>Path</th><th>Page</th></tr>\n";
        for (const auto& [path, linkHtml] : entries) {
            out << "<tr><td>" << path << "</td><td>" << linkHtml << "</td></tr>\n";
        }
        out << "</table>\n";
    }

    out << "</body></html>\n";
    std::cout << "Generated tags_summary.html\n";
}

int main() {
    // Search recursively from current directory
    const std::string searchDir = "./";
    for (const auto& entry : fs::recursive_directory_iterator(searchDir)) {
        if (entry.path().filename() == "index.html") {
            processHtmlFile(entry.path());
        }
    }

    generateSummaryHtml();
    return 0;
}
