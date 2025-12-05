#include "CheckIn.hpp"

#include <stdexcept>
#include <utility>

CheckIn::CheckIn(std::string date, std::string time) {
    if (date.empty()) {
        throw std::invalid_argument("Date cannot be empty");
    }
    date_ = std::move(date);
    time_ = std::move(time);
}

const std::string& CheckIn::date() const { return date_; }

const std::string& CheckIn::time() const { return time_; }

void CheckIn::setDate(const std::string& date) {
    if (date.empty()) {
        throw std::invalid_argument("Date cannot be empty");
    }
    date_ = date;
}

void CheckIn::setTime(const std::string& time) { time_ = time; }
