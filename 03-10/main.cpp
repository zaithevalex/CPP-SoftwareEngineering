#include <iostream>
#include <numeric>
#include <compare>

class Rational {
private:
    long long numerator;
    long long denominator;

    void normalize() {
        if (denominator == 0) {
            return;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        long long gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Rational(long long num = 0, long long den = 1) 
        : numerator(num), denominator(den) {
        normalize();
    }

    friend std::strong_ordering operator<=>(const Rational& lhs, const Rational& rhs);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
};

std::strong_ordering operator<=>(const Rational& lhs, const Rational& rhs) {
    long long left = lhs.numerator * rhs.denominator;
    long long right = rhs.numerator * lhs.denominator;
    return left <=> right;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator;
    if (r.denominator != 1) {
        os << "/" << r.denominator;
    }
    return os;
}

int main() {
    Rational r1(1, 2);
    Rational r2(2, 4);
    Rational r3(3, 4);
    Rational r4(1, 3);

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

    Rational r5(-1, 2);
    Rational r6(1, -2);
    std::cout << "r5 = " << r5 << std::endl;
    std::cout << "r6 = " << r6 << std::endl;
    std::cout << "r5 == r6: " << (r5 == r6) << std::endl;

    return 0;
}

