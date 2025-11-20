#include <cassert>
#include <sstream>
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

void testClientTestV1() {
    Client client;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    client.test_v1();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("Client::test_v1") != std::string::npos);
}

void testClientTestV2() {
    Client client;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    client.test_v2();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("Client::test_v2") != std::string::npos);
}

void testAdapterV1() {
    Adapter_v1 adapter;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    adapter.test_v1();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("Entity_v1::test") != std::string::npos);
}

void testAdapterV2() {
    Adapter_v2 adapter;
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    adapter.test_v2();
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    assert(output.find("Entity_v2::test") != std::string::npos);
}

int main() {
    testClientTestV1();
    testClientTestV2();
    testAdapterV1();
    testAdapterV2();
    return 0;
}
