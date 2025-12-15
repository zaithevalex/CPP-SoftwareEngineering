#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;
    int grade;

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << std::endl;
    }
};

class Builder {
private:
    Person person;

public:
    Builder() {
        person.name = "Unknown";
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
    auto person = builder.name("Ivan").age(25).grade(10).get();
    
    person.print();

    return 0;
}
