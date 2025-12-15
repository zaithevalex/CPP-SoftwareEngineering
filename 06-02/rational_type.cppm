export module math.rational:type;
import <numeric>;

export namespace math {
    class Rational {
    public:
        Rational(int num = 0, int den = 1);

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

