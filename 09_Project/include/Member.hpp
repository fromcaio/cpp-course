#pragma once

#include <string>
#include <vector>

#include "CheckIn.hpp"
#include "Payment.hpp"
#include "WorkoutPlan.hpp"

class Member {
public:
    Member(std::string name,
           std::string cpf = {},
           std::string phone = {},
           std::string pix = {},
           std::vector<Payment> payments = {},
           std::vector<CheckIn> checkins = {},
           WorkoutPlan workout_plan = {});

    // Accessors
    const std::string& name() const;
    const std::string& cpf() const;
    const std::string& phone() const;
    const std::string& pix() const;
    const std::vector<Payment>& payments() const;
    const std::vector<CheckIn>& checkins() const;
    const WorkoutPlan& workoutPlan() const;

    // Mutators
    void setName(std::string name);
    void setPhone(std::string phone);
    void setPix(std::string pix);
    void setCpf(std::string cpf);

private:
    std::string name_;
    std::string cpf_;
    std::string phone_;
    std::string pix_;
    std::vector<Payment> payments_;
    std::vector<CheckIn> checkins_;
    WorkoutPlan workout_plan_;
};
