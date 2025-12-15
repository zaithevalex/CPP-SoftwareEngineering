#include <iostream>
#include <climits>

template<int N>
struct Fibonacci {
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
    
    static_assert(Fibonacci<N - 1>::value <= INT_MAX - Fibonacci<N - 2>::value, 
                  "Integer overflow detected in Fibonacci calculation");
};

template<>
struct Fibonacci<0> {
    static const int value = 0;
};

template<>
struct Fibonacci<1> {
    static const int value = 1;
};

template<int N>
constexpr int fibonacci_v = Fibonacci<N>::value;

int main() {
    std::cout << "Fibonacci(0) = " << fibonacci_v<0> << std::endl;
    std::cout << "Fibonacci(1) = " << fibonacci_v<1> << std::endl;
    std::cout << "Fibonacci(2) = " << fibonacci_v<2> << std::endl;
    std::cout << "Fibonacci(3) = " << fibonacci_v<3> << std::endl;
    std::cout << "Fibonacci(4) = " << fibonacci_v<4> << std::endl;
    std::cout << "Fibonacci(5) = " << fibonacci_v<5> << std::endl;
    std::cout << "Fibonacci(6) = " << fibonacci_v<6> << std::endl;
    std::cout << "Fibonacci(7) = " << fibonacci_v<7> << std::endl;
    std::cout << "Fibonacci(8) = " << fibonacci_v<8> << std::endl;
    std::cout << "Fibonacci(9) = " << fibonacci_v<9> << std::endl;
    std::cout << "Fibonacci(10) = " << fibonacci_v<10> << std::endl;
    
    std::cout << "\nUsing direct access:" << std::endl;
    std::cout << "Fibonacci<15>::value = " << Fibonacci<15>::value << std::endl;
    std::cout << "Fibonacci<20>::value = " << Fibonacci<20>::value << std::endl;
    
    return 0;
}

