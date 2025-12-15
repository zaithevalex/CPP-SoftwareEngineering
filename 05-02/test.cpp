#include <iostream>
#include <cassert>
#include <sstream>

class Entity {
public:
    virtual void operation() = 0;
    virtual ~Entity() = default;
};

std::stringstream log_ss;

class ConcreteEntity : public virtual Entity {
public:
    void operation() override {
        log_ss << "Base";
    }
};

template <typename T>
class Decorator : public virtual Entity, public T {
public:
    void operation() override {
        log_ss << "(";
        T::operation();
        log_ss << ")";
    }
};

int main() {
    Decorator<ConcreteEntity> d;
    log_ss.str("");
    d.operation();
    assert(log_ss.str() == "(Base)");
    
    Decorator<Decorator<ConcreteEntity>> d2;
    log_ss.str("");
    d2.operation();
    assert(log_ss.str() == "((Base))");
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

