#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class GameObject {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void add(std::shared_ptr<GameObject> obj) {}
    virtual ~GameObject() = default;
};

class Unit : public GameObject {
protected:
    std::string name;
    int health;
    int damage;

    virtual void preUpdate() {}
    virtual void doUpdate() {
        std::cout << "Unit " << name << " updating logic." << std::endl;
    }
    virtual void postUpdate() {}

public:
    Unit(std::string n, int h, int d) : name(n), health(h), damage(d) {}

    void update() override {
        if (health <= 0) return;
        preUpdate();
        doUpdate();
        postUpdate();
    }

    void render() override {
        std::cout << "Unit: " << name << " [HP:" << health << "]" << std::endl;
    }
};

class Archer : public Unit {
public:
    Archer() : Unit("Archer", 50, 10) {}
    
protected:
    void doUpdate() override {
        std::cout << "Archer aiming..." << std::endl;
    }
};

class Warrior : public Unit {
public:
    Warrior() : Unit("Warrior", 100, 15) {}
    
protected:
    void doUpdate() override {
        std::cout << "Warrior charging..." << std::endl;
    }
};

class Squad : public GameObject {
private:
    std::vector<std::shared_ptr<GameObject>> members;

public:
    void add(std::shared_ptr<GameObject> obj) override {
        members.push_back(obj);
    }

    void update() override {
        std::cout << "Squad updating..." << std::endl;
        for (auto& member : members) {
            member->update();
        }
    }

    void render() override {
        std::cout << "Squad members:" << std::endl;
        for (auto& member : members) {
            member->render();
        }
    }
};

class UnitBuilder {
private:
    std::string name;
    int health;
    int damage;

public:
    UnitBuilder() : name("Soldier"), health(100), damage(10) {}

    UnitBuilder& setName(const std::string& n) {
        name = n;
        return *this;
    }

    UnitBuilder& setHealth(int h) {
        health = h;
        return *this;
    }

    UnitBuilder& setDamage(int d) {
        damage = d;
        return *this;
    }

    std::shared_ptr<Unit> build() {
        return std::make_shared<Unit>(name, health, damage);
    }
};

int main() {
    UnitBuilder builder;
    auto hero = builder.setName("Hero").setHealth(500).setDamage(50).build();

    auto army = std::make_shared<Squad>();
    auto squad1 = std::make_shared<Squad>();
    
    squad1->add(std::make_shared<Archer>());
    squad1->add(std::make_shared<Warrior>());
    
    army->add(squad1);
    army->add(hero);

    std::cout << "--- Game Loop Start ---" << std::endl;
    army->update();
    army->render();
    std::cout << "--- Game Loop End ---" << std::endl;

    return 0;
}
