#include <cassert>
#include <sstream>
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

void testConstructor() {
    Rational r1(1, 2);
    Rational r2(2, 4);
    assert(r1 == r2);
    
    Rational r3(0, 1);
    Rational r4(0);
    assert(r3 == r4);
}

void testNormalization() {
    Rational r1(2, 4);
    Rational r2(1, 2);
    assert(r1 == r2);
    
    Rational r3(-1, 2);
    Rational r4(1, -2);
    assert(r3 == r4);
    
    Rational r5(4, 2);
    Rational r6(2, 1);
    assert(r5 == r6);
}

void testEquality() {
    Rational r1(1, 2);
    Rational r2(2, 4);
    Rational r3(3, 4);
    
    assert(r1 == r2);
    assert(r1 != r3);
    assert(r2 != r3);
}

void testComparison() {
    Rational r1(1, 2);
    Rational r2(3, 4);
    Rational r3(1, 3);
    
    assert(r1 < r2);
    assert(r1 > r3);
    assert(r2 > r1);
    assert(r3 < r1);
    assert(r1 <= r2);
    assert(r1 >= r3);
    assert(r1 <= r1);
    assert(r1 >= r1);
}

void testNegative() {
    Rational r1(-1, 2);
    Rational r2(1, -2);
    Rational r3(1, 2);
    
    assert(r1 == r2);
    assert(r1 < r3);
    assert(r3 > r1);
}

void testOutput() {
    Rational r1(1, 2);
    Rational r2(5, 1);
    Rational r3(0, 1);
    
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
    testNegative();
    testOutput();
    return 0;
}
