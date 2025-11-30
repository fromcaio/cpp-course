#include "Payment.hpp"

#include <stdexcept>
#include <utility>

Payment::Payment(double amount, std::string date, std::string duration) {
    if (amount < MIN_PAYMENT_VALUE) {
        throw std::invalid_argument("Amount cannot be negative");
    }
    if (date.empty()) {
        throw std::invalid_argument("Date cannot be empty");
    }
    amount_ = amount;
    date_ = std::move(date);
    if (!duration.empty()) {
        duration_ = std::move(duration);
    } else {
        duration_ = "Monthly";
    }
}

double Payment::amount() const { return amount_; }

const std::string& Payment::date() const { return date_; }

const std::string& Payment::duration() const { return duration_; }

void Payment::setAmount(double amount) {
    if (amount < MIN_PAYMENT_VALUE) {
        throw std::invalid_argument(
            "Amount payed must be at least " +
            std::to_string(MIN_PAYMENT_VALUE));
    }
    amount_ = amount;
}

void Payment::setDate(const std::string& date) {
    if (date.empty()) {
        throw std::invalid_argument("Date cannot be empty");
    }
    date_ = date;
}

void Payment::setDuration(const std::string& duration) {
    if (!duration.empty()) {
        duration_ = duration;
    } else {
        duration_ = "Monthly";
    }
}
