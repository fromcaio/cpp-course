#include "Exercise.hpp"

#include <stdexcept>
#include <utility>

Exercise::Exercise(std::string name, int sets, int reps, double weight) {
    if (name.empty()) {
        throw std::invalid_argument("Exercise name cannot be empty");
    }
    if (sets < 0) {
        throw std::invalid_argument("Sets must be positive");
    }
    if (reps < 0) {
        throw std::invalid_argument("Reps must be positive");
    }
    if (weight < 0.0) {
        throw std::invalid_argument("Weight cannot be negative");
    }
    name_ = std::move(name);
    sets_ = sets;
    reps_ = reps;
    weight_ = weight;
}

const std::string& Exercise::name() const { return name_; }

int Exercise::sets() const { return sets_; }

int Exercise::reps() const { return reps_; }

double Exercise::weight() const { return weight_; }

void Exercise::setName(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument("Exercise name cannot be empty");
    }
    name_ = std::move(name);
}

void Exercise::setSets(int sets) {
    if (sets < 0) {
        throw std::invalid_argument("Sets must be positive");
    }
    sets_ = sets;
}

void Exercise::setReps(int reps) {
    if (reps < 0) {
        throw std::invalid_argument("Reps must be positive");
    }
    reps_ = reps;
}

void Exercise::setWeight(double weight) {
    if (weight < 0.0) {
        throw std::invalid_argument("Weight cannot be negative");
    }
    weight_ = weight;
}
