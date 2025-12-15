#include <iostream>
#include <cassert>
#include <sstream>

std::stringstream ss;

struct StratA {
    void execute() const { ss << "A"; }
};

struct StratB {
    void execute() const { ss << "B"; }
};

template <typename Strategy>
class Entity : public Strategy {
public:
    void act() {
        this->execute();
    }
};

int main() {
    Entity<StratA> e1;
    ss.str("");
    e1.act();
    assert(ss.str() == "A");

    Entity<StratB> e2;
    ss.str("");
    e2.act();
    assert(ss.str() == "B");

    std::cout << "Test passed!" << std::endl;
    return 0;
}

