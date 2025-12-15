#include <cassert>
#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;
    int grade;
};

class Builder {
private:
    Person person;

public:
    Builder() {
        person.name = "";
        person.age = 0;
        person.grade = 0;
    }

    Builder& name(const std::string& n) {
        person.name = n;
        return *this;
    }

    Builder& age(int a) {
        person.age = a;
        return *this;
    }

    Builder& grade(int g) {
        person.grade = g;
        return *this;
    }

    Person get() {
        return person;
    }
};

int main() {
    Builder builder;
    auto person = builder.name("Test").age(20).grade(5).get();
    
    assert(person.name == "Test");
    assert(person.age == 20);
    assert(person.grade == 5);
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

