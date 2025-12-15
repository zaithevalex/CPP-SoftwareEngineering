#include <iostream>

double max(double first) {
    return first;
}

template<typename... Args>
double max(double first, double second, Args... rest) {
    double max_rest = max(second, rest...);
    return first > max_rest ? first : max_rest;
}

double min(double first) {
    return first;
}

template<typename... Args>
double min(double first, double second, Args... rest) {
    double min_rest = min(second, rest...);
    return first < min_rest ? first : min_rest;
}

template<typename... Args>
double sum(Args... args) {
    return (args + ...);
}

template<typename... Args>
double mean(Args... args) {
    return sum(args...) / sizeof...(args);
}

int main() {
    std::cout << "max(3.5, 1.2, 4.7, 2.1) = " << max(3.5, 1.2, 4.7, 2.1) << std::endl;
    std::cout << "min(3.5, 1.2, 4.7, 2.1) = " << min(3.5, 1.2, 4.7, 2.1) << std::endl;
    std::cout << "sum(3.5, 1.2, 4.7, 2.1) = " << sum(3.5, 1.2, 4.7, 2.1) << std::endl;
    std::cout << "mean(3.5, 1.2, 4.7, 2.1) = " << mean(3.5, 1.2, 4.7, 2.1) << std::endl;
    
    std::cout << "\nMore examples:" << std::endl;
    std::cout << "max(10.5, 5.3, 8.9) = " << max(10.5, 5.3, 8.9) << std::endl;
    std::cout << "min(10.5, 5.3, 8.9) = " << min(10.5, 5.3, 8.9) << std::endl;
    std::cout << "sum(1.0, 2.0, 3.0, 4.0, 5.0) = " << sum(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
    std::cout << "mean(1.0, 2.0, 3.0, 4.0, 5.0) = " << mean(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
    
    return 0;
}
