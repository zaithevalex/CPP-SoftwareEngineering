#include <iostream>

class Entity {
private:
    void test_v1() {
        std::cout << "test_v1 executed" << std::endl;
    }

    void test_v2() {
        std::cout << "test_v2 executed" << std::endl;
    }

    friend class Attorney;
    friend class Tester_v1;
    friend class Tester_v2;

public:
    Entity() {}
};

class Attorney {
public:
    static void call_test_v1(Entity& e) {
        e.test_v1();
    }

    static void call_test_v2(Entity& e) {
        e.test_v2();
    }
};

class Tester_v1 {
public:
    void run_test(Entity& entity) {
        Attorney::call_test_v1(entity);
    }
};

class Tester_v2 {
public:
    void run_test(Entity& entity) {
        Attorney::call_test_v2(entity);
    }
};

int main() {
    Entity entity;
    
    Tester_v1 tester1;
    tester1.run_test(entity);
    
    Tester_v2 tester2;
    tester2.run_test(entity);
    
    return 0;
}
