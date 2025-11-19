#include <iostream>
#include <vector>
#include <numbers>
#include <cmath>
#include <memory>

class Shape {
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double perimeter() const override final {
        return a + b + c;
    }

    double area() const override final {
        double p = perimeter() / 2.0;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Square final : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double perimeter() const override {
        return 4.0 * side;
    }

    double area() const override {
        return side * side;
    }
};

class Circle final : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {
        return 2.0 * std::numbers::pi * radius;
    }

    double area() const override {
        return std::numbers::pi * radius * radius;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Triangle(3.0, 4.0, 5.0));
    shapes.push_back(new Square(5.0));
    shapes.push_back(new Circle(3.0));

    for (Shape* shape : shapes) {
        std::cout << "Perimeter: " << shape->perimeter() << ", Area: " << shape->area() << std::endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}

