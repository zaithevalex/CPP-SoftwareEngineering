export module rational;

import <numeric>;
import <stdexcept>;

export namespace Math {
    class Rational {
    public:
        Rational(int n = 0, int d = 1);

        int getNum() const { return num; }
        int getDen() const { return den; }

        Rational add(const Rational& other) const;
        Rational sub(const Rational& other) const;
        Rational mul(const Rational& other) const;
        Rational div(const Rational& other) const;

    private:
        int num;
        int den;

        void simplify();
    };
}

