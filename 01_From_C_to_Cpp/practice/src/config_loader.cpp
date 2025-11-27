// --- src/config_loader.cpp ---
#include "config_loader.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

// Alias for cleaner code
using json = nlohmann::json;

namespace Bootloader {
    void load_config(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open config file!" << std::endl;
            return;
        }

        // Parse JSON directly from file stream
        json data = json::parse(file);

        // Accessing data (Notice how it looks like Python dictionaries)
        std::string name = data["system_name"];
        int cpu = data["cpu_count"];

        std::cout << "Booting System: " << name << std::endl;
        std::cout << "CPUs Detected:  " << cpu << std::endl;
        std::cout << "Modules: " << std::endl;

        // Range-based for loop (Modern C++)
        for (const auto& mod : data["modules"]) {
            std::cout << "  [+] " << mod << std::endl;
        }
    }
}