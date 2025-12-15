#include <iostream>
#include <type_traits>

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
    using MyQueue = Queue<int, double, char, float>;
    using EmptyQueue = Queue<>;
    using IntQueue = Queue<int, int, int>;

    static_assert(Has_v<int, MyQueue>, "Queue should contain int");
    static_assert(Has_v<double, MyQueue>, "Queue should contain double");
    static_assert(Has_v<char, MyQueue>, "Queue should contain char");
    static_assert(!Has_v<long, MyQueue>, "Queue should not contain long");
    
    static_assert(!Has_v<int, EmptyQueue>, "Empty queue should not contain anything");
    
    static_assert(Has_v<int, IntQueue>, "IntQueue should contain int");
    static_assert(!Has_v<double, IntQueue>, "IntQueue should not contain double");

    std::cout << "04.10: All static assertions passed." << std::endl;
    
    std::cout << "Has<int, MyQueue>: " << std::boolalpha << Has_v<int, MyQueue> << std::endl;
    std::cout << "Has<long, MyQueue>: " << Has_v<long, MyQueue> << std::endl;

    return 0;
}
