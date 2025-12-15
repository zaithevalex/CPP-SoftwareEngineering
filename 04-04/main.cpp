#include <iostream>
#include <numeric>
#include <compare>

template<typename T>
class Rational {
private:
    T numerator;
    T denominator;

    void normalize() {
        if (denominator == 0) {
            return;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        T gcd_val = std::gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

public:
    Rational(T num = 0, T den = 1) 
        : numerator(num), denominator(den) {
        normalize();
    }

    friend std::strong_ordering operator<=>(const Rational<T>& lhs, const Rational<T>& rhs) {
        T left = lhs.numerator * rhs.denominator;
        T right = rhs.numerator * lhs.denominator;
        return left <=> right;
    }
    
    friend bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
        return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Rational<T>& r) {
        os << r.numerator;
        if (r.denominator != 1) {
            os << "/" << r.denominator;
        }
        return os;
    }
};

int main() {
    Rational<long long> r1(1, 2);
    Rational<long long> r2(2, 4);
    Rational<long long> r3(3, 4);
    Rational<long long> r4(1, 3);

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    std::cout << "r4 = " << r4 << std::endl;

    std::cout << "r1 == r2: " << (r1 == r2) << std::endl;
    std::cout << "r1 != r2: " << (r1 != r2) << std::endl;
    std::cout << "r1 < r3: " << (r1 < r3) << std::endl;
    std::cout << "r1 > r4: " << (r1 > r4) << std::endl;
    std::cout << "r3 <= r3: " << (r3 <= r3) << std::endl;
    std::cout << "r4 >= r1: " << (r4 >= r1) << std::endl;

    Rational<long long> r5(-1, 2);
    Rational<long long> r6(1, -2);
    std::cout << "\nr5 = " << r5 << std::endl;
    std::cout << "r6 = " << r6 << std::endl;
    std::cout << "r5 == r6: " << (r5 == r6) << std::endl;
    
    Rational<int> r7(3, 5);
    Rational<int> r8(6, 10);
    std::cout << "\nr7 (int) = " << r7 << std::endl;
    std::cout << "r8 (int) = " << r8 << std::endl;
    std::cout << "r7 == r8: " << (r7 == r8) << std::endl;

    return 0;
}

