/*
How to compile:
g++ -std=c++20 -o check check.cpp
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <vector>

namespace fs = std::filesystem;

std::map<std::string, std::vector<std::string>> path_map;

std::vector<std::string> parsePath(const std::string& input);

struct ParsedPage {
    std::string title;
    std::string base_href;
    std::vector<std::pair<std::string, std::string>> breadcrumb;
    std::vector<std::pair<std::string, std::string>> hierarchy_panel;
    std::string h1;

    friend std::ostream& operator<<(std::ostream& os, const ParsedPage& page) {
        os << "Title: " << page.title << "\n";
        os << "Base Href: " << page.base_href << "\n";

        os << "Breadcrumb:\n";
        for (const auto& [text, link] : page.breadcrumb) {
            os << "  - [" << text << "](" << link << ")\n";
        }

        os << "Hierarchy Panel:\n";
        for (const auto& [label, href] : page.hierarchy_panel) {
            os << "  - [" << label << "](" << href << ")\n";
        }
        os << "H1: " << page.h1 << "\n";

        return os;
    }
};

struct OEFile {
private:
    std::string name;
    std::vector<std::string> path;
    fs::path fspath;
    int depth;

public:
    OEFile(const fs::path& filePath) {
        this->fspath = filePath;
        path = parsePath(filePath.string());
        depth = path.empty() ? 0 : path.size();
        name = path.empty() ? "" : path.back();
        if (!path.empty()) {
            path.pop_back();
        }

    }
    std::string& get_name() {return name;}
    std::string get_human_name() const {
        auto human_name = name;
        std::replace(human_name.begin(), human_name.end(), '_', ' ');
        return human_name;
    }
    std::vector<std::string>& get_path() {return path;}
    [[nodiscard]] int get_depth() const {
        return depth;
    }
    ////
    std::string get_path_as_string() const {
        std::string path_str;
        for (const auto& part : path) {
            path_str+=part;
            path_str+="/";
        }
        return path_str;
    }
    fs::path get_fs_path() const {
        return this->fspath;
    }

    friend std::ostream& operator<<(std::ostream& os, const OEFile& file) {
        os << "Name: " << file.name << "\n";
        os << "Human Name: " << file.get_human_name() << "\n";
        os << "Path: ";
        os << file.get_path_as_string();
        // for (const auto& part : file.path) {
        //     os << part << "/";
        // }
        os << std::endl;
        os << "Depth: " << file.get_depth() << "\n";
        os << "Filesystem Path: " << file.fspath << "\n";
        os << "Children: " << std::endl;
        for (auto &child : file.get_children()) {
            os << child << "\n";
        }
        os << "Parsed page: " << file.create_parsed_page() << "\n";
        return os;
    }

    std::vector<std::string> get_children() const {
        for (const auto& [path_, vector] : path_map) {
            if (path_.find(get_path_as_string() + "/" + name + "/") == 0) {

                return vector;
            }
        }
        return std::vector<std::string>();
    }
    ParsedPage create_parsed_page() const {
        ParsedPage parsed_page;
        parsed_page.title = "Open Eggbert - " + get_human_name();
        if (depth == 0) {
            parsed_page.base_href=".";
        } else {
            for (int i = 1; i <= depth; i++) {
                parsed_page.base_href += "..";
                if (i < depth) {
                    parsed_page.base_href += "/";
                }
            }
        }
        if (depth > 0) {
            std::string path_fragment;
            for (auto &part : path) {
                path_fragment+=part+"/";
                auto hn = part;
                std::replace(hn.begin(), hn.end(), '_', ' ');
                parsed_page.breadcrumb.push_back({path_fragment + "index.html", hn});
            }

            ////
            parsed_page.hierarchy_panel.push_back({get_path_as_string() + "index.html", "Go Up"});
            for (auto &child : get_children()) {
                parsed_page.hierarchy_panel.push_back({get_path_as_string() + name + "/" + child + "/index.html", get_human_name()});
            }

        }
        parsed_page.h1 = get_human_name();
        if (depth == 0) {
            parsed_page.h1 = "Open Eggbert";
            parsed_page.title = "Open Eggbert - Revival of Speedy Blupi games";
        }
        // {
        //     std::string title;
        //     std::string base_href;
        //     std::vector<std::pair<std::string, std::string>> breadcrumb;
        //     std::vector<std::pair<std::string, std::string>> hierarchy_panel;
        //     std::string h1;
        // };
        return parsed_page;
    }

};

std::vector<std::string> splitLines(const std::string& input) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;
    while (std::getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Process a single HTML file: extract its <title> and all <li> items under <ul id="tags">
void processHtmlFile(const OEFile oeFile) {

    auto filePath = oeFile.get_fs_path();
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
    std::regex h1Regex(R"(<h1>(.*?)</h1>)", std::regex::icase);



    std::smatch match;
    std::string title;
    std::string h1;
    std::string baseHref;
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
    if (std::regex_search(content, match, h1Regex)) {
        h1 = match[1];
    }

    ParsedPage expected_parsed_page = oeFile.create_parsed_page();
    if (title != expected_parsed_page.title) {
        std::cerr << "KO : Title is wrong. Expected= \"" << expected_parsed_page.title << "\" Actual= \"" << title << "\" " <<
            oeFile.get_fs_path().c_str() << std::endl;
    }
    if (h1 != expected_parsed_page.h1) {
        std::cerr << "KO : h1 is wrong. Expected= \"" << expected_parsed_page.h1 << "\" Actual= \"" << h1 << "\" " <<
            oeFile.get_fs_path().c_str() << std::endl;
    }
    for (const auto& line : splitLines(content)) {
        std::size_t start = line.find("<base href=\"");
        if (start != std::string::npos) {
            start += std::strlen("<base href=\"");
            std::size_t end = line.find("\"", start);
            if (end != std::string::npos) {
                baseHref = line.substr(start, end - start);
            }
        }
    }

    if (baseHref != expected_parsed_page.base_href) {
        std::cerr << "KO : baseHref is wrong. Expected= " << expected_parsed_page.base_href << " actual= " << baseHref << " " <<
            oeFile.get_fs_path().c_str() << std::endl;
    }


}


/**
 * Parses a given file path into its constituent parts by splitting on the '/' delimiter.
 *
 * This function removes certain prefixes and suffixes from the input path string:
 * - Removes a leading "./" if present.
 * - Removes a trailing "/index.html" if present.
 *
 * After trimming these components, the function tokenizes the remaining path
 * using the '/' character as a delimiter and stores each part as an individual
 * string in a vector.
 *
 * @param input A string representing the file path to be parsed.
 * @return A vector of strings, where each string represents a part of the path.
 */
std::vector<std::string> parsePath(const std::string& input) {
    std::string trimmed = input;

    if (trimmed.rfind("./", 0) == 0) {
        trimmed = trimmed.substr(2);
    }

    const std::string suffix = "/index.html";
    if (trimmed.size() >= suffix.size() &&
        trimmed.compare(trimmed.size() - suffix.size(), suffix.size(), suffix) == 0) {
        trimmed = trimmed.substr(0, trimmed.size() - suffix.size());
        }

    std::vector<std::string> parts;
    std::stringstream ss(trimmed);
    std::string part;
    while (std::getline(ss, part, '/')) {
        parts.push_back(part);
    }

    if (parts.size() == 1 && parts[0] == "index.html") {
        parts.pop_back();
    }
    //for (auto it = parts.begin(); it != parts.end(); ++it) {std::cout << *it << std::endl;}
    return parts;
}
//
// // Generate a summary HTML file listing each tag and its associated pages
// void generateSummaryHtml() {
//     std::ofstream out("tags_summary.html");
//     if (!out.is_open()) {
//         std::cerr << "Error creating tags_summary.html" << std::endl;
//         return;
//     }
//
//     out << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n";
//     out << "<title>Tags Overview</title>\n";
//     out << "<style>\n"
//            "body { font-family: Arial, sans-serif; margin: 20px; }\n"
//            "h2 { color: #0066cc; }\n"
//            "table { width: 100%; border-collapse: collapse; margin-bottom: 20px; }\n"
//            "th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n"
//            "th { background-color: #f4f4f4; }\n"
//            "a { text-decoration: underline; color: #333; }\n"
//            "a:hover { color: #ff6600; }\n"
//         "</style>\n</head>\n<body>\n";
//     out << "<h1>Tags Overview</h1>\n";
//
//     // One table per tag
//     for (const auto& [tag, entries] : tagsMap) {
//         out << "<h2>" << tag << "</h2>\n";
//         out << "<table>\n<tr><th>Path</th><th>Page</th></tr>\n";
//         for (const auto& [path, linkHtml] : entries) {
//             out << "<tr><td>" << path << "</td><td>" << linkHtml << "</td></tr>\n";
//         }
//         out << "</table>\n";
//     }
//
//     out << "</body></html>\n";
//     std::cout << "Generated tags_summary.html\n";
// }

std::string vector_to_string(const std::vector<std::string>& v) {
    std::string s;
    for (const auto& item : v) {
        s += item + " ";
    }
    return s;
}
int main() {
    // Search recursively from current directory
    const std::string searchDir = "./";
    int i = 0;
    std::vector<OEFile> files;

    for (const auto& entry : fs::recursive_directory_iterator(searchDir)) {
        if (entry.path().filename() == "index.html") {
            if (entry.path() == "./Template/index.html") continue;
            auto oeFile = OEFile(entry.path());
            files.push_back(oeFile);
            if (path_map.find(oeFile.get_path_as_string()) == path_map.end()) {
            path_map.insert({oeFile.get_path_as_string(), std::vector<std::string>{oeFile.get_name()}});
            } else {
                path_map[oeFile.get_path_as_string()].push_back(oeFile.get_name());
            }
        }
    }


    for (const auto& oeFile : files) {//processHtmlFile(oeFile);
            i++;
            std::cout << "Found file #" << i << " " << std::endl << oeFile << std::endl;

    }
    std::cout << "Checking content of HTML files" << std::endl;
    for (const auto& oeFile : files) {//processHtmlFile(oeFile);
        processHtmlFile(oeFile);
    }
    // std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
    // for (auto const& item: path_map) {
    //     std::cout << item.first << " " << vector_to_string(item.second) << std::endl;
    // }

    //generateSummaryHtml();
    return 0;
}
