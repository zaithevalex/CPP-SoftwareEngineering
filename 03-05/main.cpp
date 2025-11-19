#include <iostream>

class Entity_v1 {
public:
    virtual void test() {
        std::cout << "Entity_v1::test" << std::endl;
    }

    virtual ~Entity_v1() = default;
};

class Entity_v2 {
public:
    virtual void test() {
        std::cout << "Entity_v2::test" << std::endl;
    }

    virtual ~Entity_v2() = default;
};

class Adapter_v1 : public Entity_v1 {
public:
    virtual void test_v1() {
        test();
    }

    virtual ~Adapter_v1() = default;
};

class Adapter_v2 : public Entity_v2 {
public:
    virtual void test_v2() {
        test();
    }

    virtual ~Adapter_v2() = default;
};

class Client : public Adapter_v1, public Adapter_v2 {
public:
    void test_v1() override {
        std::cout << "Client::test_v1 override" << std::endl;
    }

    void test_v2() override {
        std::cout << "Client::test_v2 override" << std::endl;
    }
};

int main() {
    Client client;

    client.test_v1();
    client.test_v2();

    return 0;
}

