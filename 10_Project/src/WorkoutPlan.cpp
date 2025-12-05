#include "WorkoutPlan.hpp"

#include <utility>

WorkoutPlan::WorkoutPlan(std::vector<std::vector<Exercise>> plan)
    : trainning_plan_(std::move(plan)) {}

const std::vector<std::vector<Exercise>>& WorkoutPlan::plan() const {
    return trainning_plan_;
}

void WorkoutPlan::setPlan(const std::vector<std::vector<Exercise>>& plan) {
    trainning_plan_ = plan;
}
