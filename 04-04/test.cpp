#include <cassert>
#include <sstream>
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

void testConstructor() {
    Rational<long long> r1(1, 2);
    Rational<long long> r2(2, 4);
    assert(r1 == r2);
    
    Rational<long long> r3(0, 1);
    Rational<long long> r4(0);
    assert(r3 == r4);
}

void testNormalization() {
    Rational<long long> r1(2, 4);
    Rational<long long> r2(1, 2);
    assert(r1 == r2);
    
    Rational<long long> r3(-1, 2);
    Rational<long long> r4(1, -2);
    assert(r3 == r4);
    
    Rational<long long> r5(4, 2);
    Rational<long long> r6(2, 1);
    assert(r5 == r6);
}

void testEquality() {
    Rational<long long> r1(1, 2);
    Rational<long long> r2(2, 4);
    Rational<long long> r3(3, 4);
    
    assert(r1 == r2);
    assert(r1 != r3);
    assert(r2 != r3);
}

void testComparison() {
    Rational<long long> r1(1, 2);
    Rational<long long> r2(3, 4);
    Rational<long long> r3(1, 3);
    
    assert(r1 < r2);
    assert(r1 > r3);
    assert(r2 > r1);
    assert(r3 < r1);
    assert(r1 <= r2);
    assert(r1 >= r3);
    assert(r1 <= r1);
    assert(r1 >= r1);
}

void testIntType() {
    Rational<int> r1(3, 5);
    Rational<int> r2(6, 10);
    assert(r1 == r2);
    
    Rational<int> r3(1, 3);
    Rational<int> r4(2, 3);
    assert(r3 < r4);
}

void testOutput() {
    Rational<long long> r1(1, 2);
    Rational<long long> r2(5, 1);
    Rational<long long> r3(0, 1);
    
    std::stringstream ss1, ss2, ss3;
    ss1 << r1;
    ss2 << r2;
    ss3 << r3;
    
    assert(ss1.str().find("1") != std::string::npos);
    assert(ss2.str().find("5") != std::string::npos);
    assert(ss3.str().find("0") != std::string::npos);
}

int main() {
    testConstructor();
    testNormalization();
    testEquality();
    testComparison();
    testIntType();
    testOutput();
    return 0;
}

