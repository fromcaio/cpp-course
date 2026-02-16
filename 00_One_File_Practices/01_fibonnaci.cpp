#include <iostream>

int fibonacci(int n) {
    if (n == 0) 
        return 0;
    else if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n -2);
}

int main() {
    int n;
    std::cout << "Enter the Fibonacci index: ";
    std::cin >> n;

    int result = fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}