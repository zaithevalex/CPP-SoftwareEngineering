#include <iostream>
#include <numeric>

template <long long N, long long D>
struct Fraction {
    static_assert(D != 0, "Denominator cannot be zero");
    static constexpr long long Num = N;
    static constexpr long long Den = D;
};

template <long long N, long long D>
struct Simplify {
    static constexpr long long common = std::gcd(N, D);
    using type = Fraction<N / common, D / common>;
};

template <typename F1, typename F2>
struct Sum;

template <long long N1, long long D1, long long N2, long long D2>
struct Sum<Fraction<N1, D1>, Fraction<N2, D2>> {
    static constexpr long long num = N1 * D2 + N2 * D1;
    static constexpr long long den = D1 * D2;
    using type = typename Simplify<num, den>::type;
};

template <typename F1, typename F2>
struct Mul;

template <long long N1, long long D1, long long N2, long long D2>
struct Mul<Fraction<N1, D1>, Fraction<N2, D2>> {
    static constexpr long long num = N1 * N2;
    static constexpr long long den = D1 * D2;
    using type = typename Simplify<num, den>::type;
};

template <typename F1, typename F2>
struct Sub;

template <long long N1, long long D1, long long N2, long long D2>
struct Sub<Fraction<N1, D1>, Fraction<N2, D2>> {
    using type = typename Sum<Fraction<N1, D1>, Fraction<-N2, D2>>::type;
};

template <typename F1, typename F2>
struct Div;

template <long long N1, long long D1, long long N2, long long D2>
struct Div<Fraction<N1, D1>, Fraction<N2, D2>> {
    static_assert(N2 != 0, "Division by zero");
    using type = typename Mul<Fraction<N1, D1>, Fraction<D2, N2>>::type;
};

template <typename F1, typename F2>
using sum = typename Sum<F1, F2>::type;

template <typename F1, typename F2>
using sub = typename Sub<F1, F2>::type;

template <typename F1, typename F2>
using mul = typename Mul<F1, F2>::type;

template <typename F1, typename F2>
using div_op = typename Div<F1, F2>::type;

class Interval {
public:
    int min;
    int max;

    constexpr Interval(int min, int max) : min(min), max(max) {}

    constexpr Interval operator+(const Interval& other) const {
        return Interval(min + other.min, max + other.max);
    }
    
    constexpr Interval operator-() const {
        return Interval(-max, -min);
    }

    constexpr Interval operator-(const Interval& other) const {
        return *this + (-other);
    }
};

int main() {
    using F1 = Fraction<1, 2>;
    using F2 = Fraction<1, 3>;
    using F3 = Fraction<2, 4>;

    using F3_Simple = Simplify<2, 4>::type;
    static_assert(F3_Simple::Num == 1 && F3_Simple::Den == 2, "Simplification failed");

    using S = sum<F1, F2>;
    static_assert(S::Num == 5 && S::Den == 6, "Sum failed");

    using SubRes = sub<F1, F2>;
    static_assert(SubRes::Num == 1 && SubRes::Den == 6, "Sub failed");

    using M = mul<F1, F2>;
    static_assert(M::Num == 1 && M::Den == 6, "Mul failed");

    using D = div_op<F1, F2>;
    static_assert(D::Num == 3 && D::Den == 2, "Div failed");

    constexpr Interval i1(1, 5);
    constexpr Interval i2(2, 4);
    
    constexpr Interval sum_i = i1 + i2;
    static_assert(sum_i.min == 3 && sum_i.max == 9, "Interval sum failed");

    constexpr Interval sub_i = i1 - i2;
    static_assert(sub_i.min == -3 && sub_i.max == 3, "Interval sub failed");

    std::cout << "04.07: All static assertions passed successfully." << std::endl;

    return 0;
}
