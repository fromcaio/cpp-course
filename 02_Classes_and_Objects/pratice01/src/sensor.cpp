#include "sensor.hpp"

Sensor::Sensor(std::string n) : name(std::move(n)) {
    std::cout << "[System] Sensor " << name << " online." << std::endl;
}

Sensor::~Sensor() {
    std::cout << "[System] Sensor " << name << " offline." << std::endl;
}

std::string Sensor::get_name() const {
    return name;
}
