#include <cassert>
#include <cmath>
#include <numbers>

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double p = perimeter() / 2.0;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Square {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double perimeter() const {
        return 4.0 * side;
    }

    double area() const {
        return side * side;
    }
};

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const {
        return 2.0 * std::numbers::pi * radius;
    }

    double area() const {
        return std::numbers::pi * radius * radius;
    }
};

void testTriangle() {
    Triangle t(3.0, 4.0, 5.0);
    assert(std::abs(t.perimeter() - 12.0) < 1e-9);
    assert(std::abs(t.area() - 6.0) < 1e-9);
    
    Triangle t2(5.0, 5.0, 5.0);
    assert(std::abs(t2.perimeter() - 15.0) < 1e-9);
    double expectedArea = (5.0 * 5.0 * std::sqrt(3.0)) / 4.0;
    assert(std::abs(t2.area() - expectedArea) < 1e-6);
}

void testSquare() {
    Square s(5.0);
    assert(std::abs(s.perimeter() - 20.0) < 1e-9);
    assert(std::abs(s.area() - 25.0) < 1e-9);
    
    Square s2(10.0);
    assert(std::abs(s2.perimeter() - 40.0) < 1e-9);
    assert(std::abs(s2.area() - 100.0) < 1e-9);
}

void testCircle() {
    Circle c(3.0);
    assert(std::abs(c.perimeter() - 2.0 * std::numbers::pi * 3.0) < 1e-9);
    assert(std::abs(c.area() - std::numbers::pi * 9.0) < 1e-9);
    
    Circle c2(5.0);
    assert(std::abs(c2.perimeter() - 2.0 * std::numbers::pi * 5.0) < 1e-9);
    assert(std::abs(c2.area() - std::numbers::pi * 25.0) < 1e-9);
}

int main() {
    testTriangle();
    testSquare();
    testCircle();
    return 0;
}
