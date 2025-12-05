#pragma once

#include <string>

class Payment {
public:
    Payment(double amount, std::string date, std::string duration = "Monthly");
    ~Payment() = default;

    // Accessors
    double amount() const;
    const std::string& date() const;
    const std::string& duration() const;

    // Mutators
    void setAmount(double amount);
    void setDate(const std::string& date);
    void setDuration(const std::string& duration);

    static constexpr double MIN_PAYMENT_VALUE = 0.0;

private:
    double amount_;
    std::string date_;     // in format YYYY-MM-DD
    std::string duration_; // e.g., "Monthly", "Yearly"
};
