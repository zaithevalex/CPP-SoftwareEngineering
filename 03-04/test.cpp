#include <cassert>
#include <sstream>
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

void testTesterV1() {
    Entity entity;
    Tester_v1 tester1;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    tester1.run_test(entity);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("test_v1") != std::string::npos);
}

void testTesterV2() {
    Entity entity;
    Tester_v2 tester2;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    tester2.run_test(entity);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("test_v2") != std::string::npos);
}

void testAttorneyPattern() {
    Entity entity;
    Tester_v1 tester1;
    Tester_v2 tester2;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    tester1.run_test(entity);
    tester2.run_test(entity);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("test_v1") != std::string::npos);
    assert(output.find("test_v2") != std::string::npos);
}

int main() {
    testTesterV1();
    testTesterV2();
    testAttorneyPattern();
    return 0;
}
