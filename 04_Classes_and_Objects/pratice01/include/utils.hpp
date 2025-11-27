#pragma once

#include <vector>

// Passing by const reference to avoid deep copies
void analyze_telemetry(const std::vector<double>& data);
