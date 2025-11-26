#include "config_loader.hpp"
#include <iostream>
#include <string>

int main() {
    const std::string config_path = "config.json";

    std::cout << "Loading config: " << config_path << std::endl;
    Bootloader::load_config(config_path);

    return 0;
}
