#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class GameObject {
public:
    virtual void update() = 0;
    virtual ~GameObject() = default;
};

class Unit : public GameObject {
public:
    int updateCount = 0;
    void update() override {
        updateCount++;
    }
};

class Squad : public GameObject {
    std::vector<std::shared_ptr<GameObject>> members;
public:
    void add(std::shared_ptr<GameObject> obj) {
        members.push_back(obj);
    }
    void update() override {
        for(auto& m : members) m->update();
    }
};

class UnitBuilder {
    int val = 0;
public:
    UnitBuilder& setVal(int v) { val = v; return *this; }
    std::shared_ptr<Unit> build() { return std::make_shared<Unit>(); }
};

int main() {
    auto s = std::make_shared<Squad>();
    auto u1 = std::make_shared<Unit>();
    auto u2 = std::make_shared<Unit>();
    
    s->add(u1);
    s->add(u2);
    
    s->update();
    
    assert(u1->updateCount == 1);
    assert(u2->updateCount == 1);
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

