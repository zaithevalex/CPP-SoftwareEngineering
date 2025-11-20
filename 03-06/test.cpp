#include <cassert>
#include <cmath>
#include <vector>
#include <numbers>
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

void testTriangle() {
    Triangle* t = new Triangle(3.0, 4.0, 5.0);
    assert(std::abs(t->perimeter() - 12.0) < 1e-9);
    assert(std::abs(t->area() - 6.0) < 1e-9);
    delete t;
}

void testSquare() {
    Square* s = new Square(5.0);
    assert(std::abs(s->perimeter() - 20.0) < 1e-9);
    assert(std::abs(s->area() - 25.0) < 1e-9);
    delete s;
}

void testCircle() {
    Circle* c = new Circle(3.0);
    assert(std::abs(c->perimeter() - 2.0 * std::numbers::pi * 3.0) < 1e-9);
    assert(std::abs(c->area() - std::numbers::pi * 9.0) < 1e-9);
    delete c;
}

void testPolymorphism() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));
    shapes.push_back(new Square(5.0));
    shapes.push_back(new Circle(3.0));
    
    assert(shapes.size() == 3);
    assert(std::abs(shapes[0]->perimeter() - 12.0) < 1e-9);
    assert(std::abs(shapes[1]->perimeter() - 20.0) < 1e-9);
    assert(std::abs(shapes[2]->perimeter() - 2.0 * std::numbers::pi * 3.0) < 1e-9);
    
    for (Shape* shape : shapes) {
        delete shape;
    }
}

int main() {
    testTriangle();
    testSquare();
    testCircle();
    testPolymorphism();
    return 0;
}
