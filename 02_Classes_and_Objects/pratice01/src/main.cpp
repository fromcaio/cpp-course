#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <filesystem>

#include <nlohmann/json.hpp>

#include "sensor.hpp"
#include "utils.hpp"

using json = nlohmann::json;

std::filesystem::path resolve_config_path() {
    // Prefer the project source directory if provided at compile time
#ifdef PROJECT_SOURCE_DIR
    const std::filesystem::path source_root(PROJECT_SOURCE_DIR);
    const auto candidate = source_root / "mission_config.json";
    if (std::filesystem::exists(candidate)) {
        return candidate;
    }
#endif
    return std::filesystem::path("mission_config.json");
}

int main() {
    // 1. RAII: Create the sensor. It manages its own lifetime.
    auto sensor = std::make_unique<Sensor>("Lidar-X1");

    // 2. Load Config
    const auto config_path = resolve_config_path();
    std::ifstream f(config_path);
    if (!f.is_open()) {
        std::cerr << "Failed to open config at: " << config_path << std::endl;
        return 1;
    }

    json config = json::parse(f, nullptr, /*allow_exceptions=*/true, /*ignore_comments=*/true);

    std::string mission = config.value("mission_id", "<unknown>");
    std::cout << "Mission: " << mission << " initialized." << std::endl;

    // 3. Load Data into Vector
    std::vector<double> telemetry = config.value("readings", std::vector<double>{});

    // 4. Pass by Reference
    analyze_telemetry(telemetry);

    return 0;
} // <--- 'sensor' is destroyed here automatically. No memory leak.
