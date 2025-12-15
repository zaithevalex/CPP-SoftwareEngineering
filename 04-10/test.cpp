#include <iostream>
#include <type_traits>
#include <cassert>

template <typename... Args>
struct Queue {};

template <typename T, typename Q>
struct Has;

template <typename T>
struct Has<T, Queue<>> : std::false_type {};

template <typename T, typename Head, typename... Tail>
struct Has<T, Queue<Head, Tail...>> {
    static constexpr bool value = std::is_same<T, Head>::value || Has<T, Queue<Tail...>>::value;
};

template <typename T, typename Q>
constexpr bool Has_v = Has<T, Q>::value;

int main() {
    using Q = Queue<int, double>;
    
    static_assert(Has_v<int, Q>);
    static_assert(Has_v<double, Q>);
    static_assert(!Has_v<char, Q>);
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

