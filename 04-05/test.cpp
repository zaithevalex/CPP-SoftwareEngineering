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

static_assert(fibonacci_v<0> == 0);
static_assert(fibonacci_v<1> == 1);
static_assert(fibonacci_v<2> == 1);
static_assert(fibonacci_v<3> == 2);
static_assert(fibonacci_v<4> == 3);
static_assert(fibonacci_v<5> == 5);
static_assert(fibonacci_v<6> == 8);
static_assert(fibonacci_v<7> == 13);
static_assert(fibonacci_v<8> == 21);
static_assert(fibonacci_v<9> == 34);
static_assert(fibonacci_v<10> == 55);

static_assert(Fibonacci<0>::value == 0);
static_assert(Fibonacci<1>::value == 1);
static_assert(Fibonacci<15>::value == 610);
static_assert(Fibonacci<20>::value == 6765);

int main() {
    return 0;
}

