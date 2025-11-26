#include <iostream>      // Standard C++ IO
#include "simple_math.hpp" // Our custom header

int main() {
    int x = 10;
    int y = 5;

    // Using the function from our namespace
    // In C, this might have been MathUtils_add(x, y)
    int result = MathUtils::add(x, y);

    // std::cout is "Conceptually" writing to stdout
    // std::endl flushes the buffer and adds a newline
    std::cout << "Calculating: " << x << " + " << y << " = " << result << std::endl;

    return 0;
}