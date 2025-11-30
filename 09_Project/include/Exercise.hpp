#pragma once

#include <string>

class Exercise {
public:
    Exercise(std::string name, int sets = 0, int reps = 0, double weight = 0.0);
    ~Exercise() = default;

    // Accessors
    const std::string& name() const;
    int sets() const;
    int reps() const;
    double weight() const;

    // Mutators
    void setName(std::string name);
    void setSets(int sets);
    void setReps(int reps);
    void setWeight(double weight);

private:
    std::string name_;
    int sets_;
    int reps_;
    double weight_;
};
