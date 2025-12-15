#include <iostream>
#include <string>

class Entity {
public:
    virtual void operation() = 0;
    virtual ~Entity() = default;
};

class ConcreteEntity : public virtual Entity {
public:
    void operation() override {
        std::cout << "ConcreteEntity operation" << std::endl;
    }
};

template <typename T>
class Decorator : public virtual Entity, public T {
public:
    void operation() override {
        std::cout << "Decorator before" << std::endl;
        T::operation();
        std::cout << "Decorator after" << std::endl;
    }
};

template <typename T>
class AnotherDecorator : public virtual Entity, public T {
public:
    void operation() override {
        std::cout << "AnotherDecorator start" << std::endl;
        T::operation();
        std::cout << "AnotherDecorator end" << std::endl;
    }
};

int main() {
    std::cout << "--- Base ---" << std::endl;
    ConcreteEntity base;
    base.operation();
    
    std::cout << "\n--- Decorated ---" << std::endl;
    Decorator<ConcreteEntity> decorated;
    decorated.operation();
    
    std::cout << "\n--- Double Decorated ---" << std::endl;
    AnotherDecorator<Decorator<ConcreteEntity>> doubleDecorated;
    doubleDecorated.operation();

    return 0;
}
