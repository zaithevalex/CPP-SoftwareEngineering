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

template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference<T&> {
    using type = T;
};

template <typename T>
struct remove_reference<T&&> {
    using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

template <typename T>
struct is_array : false_type {};

template <typename T>
struct is_array<T[]> : true_type {};

template <typename T, size_t N>
struct is_array<T[N]> : true_type {};

template <typename T>
struct remove_extent {
    using type = T;
};

template <typename T>
struct remove_extent<T[]> {
    using type = T;
};

template <typename T, size_t N>
struct remove_extent<T[N]> {
    using type = T;
};

template <typename T>
struct remove_volatile {
    using type = T;
};

template <typename T>
struct remove_volatile<volatile T> {
    using type = T;
};

template <typename T>
struct remove_cv {
    using type = typename remove_volatile<typename remove_const<T>::type>::type;
};

template <typename T>
struct decay {
private:
    using U = remove_reference_t<T>;
public:
    using type = typename conditional<
        is_array<U>::value,
        typename remove_extent<U>::type*,
        typename remove_cv<U>::type
    >::type;
};

template <typename T>
using decay_t = typename decay<T>::type;


struct MyClass {};
union MyUnion {};

int main() {
    static_assert(is_class_v<MyClass>, "MyClass should be a class");
    static_assert(is_class_v<MyUnion>, "MyUnion matches class check strategy"); 
    static_assert(!is_class_v<int>, "int is not a class");
    static_assert(!is_class_v<int*>, "pointer is not a class");

    static_assert(std::is_same<conditional_t<true, int, double>, int>::value, "conditional true failed");
    static_assert(std::is_same<conditional_t<false, int, double>, double>::value, "conditional false failed");

    static_assert(std::is_same<add_const_t<int>, const int>::value, "add_const failed");
    static_assert(std::is_same<remove_const_t<const int>, int>::value, "remove_const failed");
    static_assert(std::is_same<remove_const_t<int>, int>::value, "remove_const failed for non-const");

    static_assert(std::is_same<decay_t<const int&>, int>::value, "decay ref const failed");
    static_assert(std::is_same<decay_t<int[5]>, int*>::value, "decay array failed");
    
    std::cout << "04.09: All static assertions passed." << std::endl;
    return 0;
}
