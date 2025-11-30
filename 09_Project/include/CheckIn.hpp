#pragma once

#include <string>

class CheckIn {
public:
    CheckIn(std::string date, std::string time = {});
    ~CheckIn() = default;

    // Accessors
    const std::string& date() const;
    const std::string& time() const;

    // Mutators
    void setDate(const std::string& date);
    void setTime(const std::string& time);

private:
    std::string date_; // in format YYYY-MM-DD
    std::string time_; // in format HH:MM:SS
};
