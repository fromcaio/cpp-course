// In C, you use #ifndef MACROS. 
// In Modern C++, #pragma once is widely supported and cleaner.
#pragma once

// Namespaces:
// C has a flat global namespace. C++ allows us to group logic.
// This prevents collision if two libraries both have an "add" function.
namespace MathUtils {

    // Function Declaration
    // Note: No "class" here yet, just standard functions.
    int add(int a, int b);
    
    int subtract(int a, int b);

}