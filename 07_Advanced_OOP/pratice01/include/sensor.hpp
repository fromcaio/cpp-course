#pragma once

#include <iostream>
#include <string>

class Sensor {
    std::string name;

public:
    explicit Sensor(std::string n);
    ~Sensor();

    std::string get_name() const;
};
