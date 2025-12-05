#include "Member.hpp"

#include <stdexcept>
#include <utility>

Member::Member(std::string name,
               std::string cpf,
               std::string phone,
               std::string pix,
               std::vector<Payment> payments,
               std::vector<CheckIn> checkins,
               WorkoutPlan workout_plan) {
    name_ = std::move(name);
    cpf_ = std::move(cpf);
    phone_ = std::move(phone);
    pix_ = std::move(pix);
    payments_ = std::move(payments);
    checkins_ = std::move(checkins);
    workout_plan_ = std::move(workout_plan);
}

const std::string& Member::name() const { return name_; }

const std::string& Member::cpf() const { return cpf_; }

const std::string& Member::phone() const { return phone_; }

const std::string& Member::pix() const { return pix_; }

const std::vector<Payment>& Member::payments() const { return payments_; }

const std::vector<CheckIn>& Member::checkins() const { return checkins_; }

const WorkoutPlan& Member::workoutPlan() const { return workout_plan_; }

void Member::setName(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }
    name_ = std::move(name);
}

void Member::setPhone(std::string phone) { phone_ = std::move(phone); }

void Member::setPix(std::string pix) { pix_ = std::move(pix); }

void Member::setCpf(std::string cpf) { cpf_ = std::move(cpf); }
