#include <iostream>
#include <vector>

template<typename Container>
void handle(Container& container, int value) {
    container.push_back(value);
}

template<typename Container, typename T>
void handle(Container&, T) {
    // ignore non-int types
}

template<typename Container, typename... Args>
void insert(Container& container, Args... args) {
    (handle(container, args), ...);
}

int main() {
    std::vector<int> vec;
    
    insert(vec, 1, 2, 3, 4, 5);
    
    std::cout << "Vector after inserting ints: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> vec2;
    insert(vec2, 10, 3.14, 20, "hello", 30, 'a', 40);
    
    std::cout << "\nVector after inserting mixed types (only ints inserted): ";
    for (int val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> vec3;
    insert(vec3, 100, 200, 300);
    
    std::cout << "\nVector with three ints: ";
    for (int val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

