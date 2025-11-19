#include <iostream>
#include <numbers>
#include <cmath>

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

int main() {
    Triangle t(3.0, 4.0, 5.0);
    Square s(5.0);
    Circle c(3.0);

    std::cout << "Triangle perimeter: " << t.perimeter() << std::endl;
    std::cout << "Triangle area: " << t.area() << std::endl;
    std::cout << "Square perimeter: " << s.perimeter() << std::endl;
    std::cout << "Square area: " << s.area() << std::endl;
    std::cout << "Circle perimeter: " << c.perimeter() << std::endl;
    std::cout << "Circle area: " << c.area() << std::endl;

    return 0;
}

