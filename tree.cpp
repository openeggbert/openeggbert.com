#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

namespace fs = std::filesystem;

std::map<std::string, std::vector<std::string>> path_map;

std::vector<std::string> parsePath(const std::string& input) {
    std::string trimmed = input;
    if (trimmed.rfind("./", 0) == 0)
        trimmed = trimmed.substr(2);

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

    return parts;
}

struct OEFile {
    std::string name;
    std::vector<std::string> path;

    OEFile(const fs::path& filePath) {
        auto parsed = parsePath(filePath.string());
        if (!parsed.empty()) {
            name = parsed.back();
            parsed.pop_back();
            path = parsed;
        } else {
            name = "";
            path = {};
        }
    }

    std::string get_path_as_string() const {
        std::string path_str;
        for (const auto& part : path) {
            path_str += part + "/";
        }
        return path_str;
    }

    std::string get_human_name() const {
        std::string hn = name;
        std::replace(hn.begin(), hn.end(), '_', ' ');
        return hn.empty() ? "Home" : hn;
    }

    std::string get_link() const {
        std::string path_str = get_path_as_string();
        return path_str + name + "/index.html";
    }
};

void build_tree(const std::string& parent_path, std::ostream& out) {
    if (path_map.find(parent_path) == path_map.end()) return;

    out << "<ul>\n";
    for (const auto& child : path_map[parent_path]) {
        std::string child_path = parent_path + child + "/";
        std::string display_name = child;
        std::replace(display_name.begin(), display_name.end(), '_', ' ');

        out << "<li><a href=\"" << child_path << "index.html\">" << display_name << "</a>\n";
        build_tree(child_path, out);
        out << "</li>\n";
    }
    out << "</ul>\n";
}

void generateTreeHtml() {
    std::ofstream out("tree.html");
    if (!out.is_open()) {
        std::cerr << "Error creating tree.html\n";
        return;
    }

    out << R"(<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Open Eggbert - Tree</title>
<style>
    :root {
        color-scheme: light dark;
        --bg: #f8f8f8;
        --fg: #111;
        --accent: #ff9900;
        --line: #ccc;
        --hover: #ffe9b3;
    }

    @media (prefers-color-scheme: dark) {
        :root {
            --bg: #181818;
            --fg: #eee;
            --accent: #ffaa33;
            --line: #444;
            --hover: #333;
        }
    }

    body {
        background: var(--bg);
        color: var(--fg);
        font-family: "Segoe UI", system-ui, sans-serif;
        margin: 2em auto;
        max-width: 800px;
        padding: 0 1em;
    }

    h1 {
        text-align: center;
        font-size: 2rem;
        color: var(--accent);
        margin-bottom: 2em;
    }

    ul.tree {
        padding-left: 1em;
        position: relative;
        margin: 0;
    }

    ul.tree ul {
        margin-left: 1.5em;
        padding-left: 1em;
        border-left: 2px solid var(--line);
        position: relative;
    }

    ul.tree li {
        list-style: none;
        margin: 0;
        padding: 0.3em 0 0.3em 0.8em;
        position: relative;
    }

    ul.tree li::before {
        content: "";
        position: absolute;
        top: 0;
        left: -0.9em;
        width: 1em;
        height: 100%;
        border-left: 2px solid var(--line);
    }

    ul.tree li:last-child::before {
        height: 0.7em;
    }

    ul.tree li::after {
        content: "";
        position: absolute;
        top: 0.9em;
        left: -0.9em;
        width: 0.9em;
        height: 0;
        border-top: 2px solid var(--line);
    }

    a {
        color: var(--fg);
        text-decoration: none;
        border-radius: 4px;
        padding: 0.2em 0.4em;
        display: inline-block;
        transition: background 0.2s;
    }

    a:hover {
        background: var(--hover);
    }
</style>
</head>
<body>
<h1>Open Eggbert – All articles</h1>
<ul class="tree">
)";

    build_tree("", out);

    out << R"(</ul>
</body>
</html>
)";
    std::cout << "Generated tree.html with visual tree structure\n";
}




int main() {
    const std::string searchDir = "./";

    for (const auto& entry : fs::recursive_directory_iterator(searchDir)) {
        if (entry.path().filename() == "index.html" &&
            entry.path() != "./Template/index.html") {

            OEFile file(entry.path());
            std::string key = file.get_path_as_string();
            path_map[key].push_back(file.name);
        }
    }

    generateTreeHtml();
    return 0;
}
