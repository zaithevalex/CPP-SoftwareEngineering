#include <iostream>
#include <type_traits>

template <typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

namespace detail {
    template <typename T>
    true_type test_is_class(int T::*);
    
    template <typename T>
    false_type test_is_class(...);
}

template <typename T>
struct is_class : decltype(detail::test_is_class<T>(nullptr)) {};

template <typename T>
constexpr bool is_class_v = is_class<T>::value;

template <bool B, typename T, typename F>
struct conditional {
    using type = T;
};

template <typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

template <bool B, typename T, typename F>
using conditional_t = typename conditional<B, T, F>::type;

template <typename T>
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<const T> {
    using type = T;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type;

template <typename T>
struct add_const {
    using type = const T;
};

template <typename T>
using add_const_t = typename add_const<T>::type;

struct MyClass {};

int main() {
    static_assert(is_class_v<MyClass>);
    static_assert(!is_class_v<int>);
    
    static_assert(std::is_same<remove_const_t<const int>, int>::value);
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

