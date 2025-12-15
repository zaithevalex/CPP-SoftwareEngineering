module rational;

import <numeric>;

namespace Math {
    void Rational::simplify() {
        if (den == 0) throw "Denominator cannot be zero";
        int common = std::gcd(num, den);
        num /= common;
        den /= common;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    Rational::Rational(int n, int d) : num(n), den(d) {
        simplify();
    }

    Rational Rational::add(const Rational& other) const {
        return Rational(num * other.den + other.num * den, den * other.den);
    }

    Rational Rational::sub(const Rational& other) const {
        return Rational(num * other.den - other.num * den, den * other.den);
    }

    Rational Rational::mul(const Rational& other) const {
        return Rational(num * other.num, den * other.den);
    }

    Rational Rational::div(const Rational& other) const {
        return Rational(num * other.den, den * other.num);
    }
}
