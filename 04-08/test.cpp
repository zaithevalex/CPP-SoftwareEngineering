#include <cassert>
#include <iostream>

template <typename... Args>
struct Tuple;

template <>
struct Tuple<> {
    constexpr Tuple() {}
    static constexpr size_t size() { return 0; }
};

template <typename Head, typename... Tail>
struct Tuple<Head, Tail...> {
    Head head;
    Tuple<Tail...> tail;

    constexpr Tuple(Head h, Tail... t) : head(h), tail(t...) {}

    static constexpr size_t size() {
        return 1 + sizeof...(Tail);
    }

    template <size_t I>
    constexpr auto get() const {
        if constexpr (I == 0) {
            return head;
        } else {
            return tail.template get<I - 1>();
        }
    }
};

template <typename... Args>
Tuple(Args...) -> Tuple<Args...>;

int main() {
    constexpr Tuple<int, double, char> t(42, 3.14, 'a');
    
    static_assert(t.size() == 3, "Size check failed");
    assert(t.size() == 3);
    
    static_assert(t.get<0>() == 42, "Get<0> failed");
    assert(t.get<0>() == 42);
    
    assert(t.get<1>() == 3.14);
    assert(t.get<2>() == 'a');
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

