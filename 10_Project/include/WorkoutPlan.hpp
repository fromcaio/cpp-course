#pragma once

#include <vector>

#include "Exercise.hpp"

class WorkoutPlan {
public:
    WorkoutPlan(std::vector<std::vector<Exercise>> plan = {});
    ~WorkoutPlan() = default;

    // Accessors
    const std::vector<std::vector<Exercise>>& plan() const;

    // Mutators
    void setPlan(const std::vector<std::vector<Exercise>>& plan);

private:
    // We need a vector of vectors to hold the days and exercises
    std::vector<std::vector<Exercise>> trainning_plan_;
};
