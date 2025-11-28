#include "utils.hpp"

#include <iostream>

void analyze_telemetry(const std::vector<double>& data) {
    std::cout << "--- Starting Analysis ---" << std::endl;
    std::cout << "Data Points: " << data.size() << std::endl;

    // Range-based for loop with const reference
    for (const auto& val : data) {
        if (val > 12.0) {
            std::cout << "[WARNING] High reading detected: " << val << std::endl;
        }
    }

    std::cout << "--- Analysis Complete ---" << std::endl;
}
