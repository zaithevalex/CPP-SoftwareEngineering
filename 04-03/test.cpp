#include <cassert>
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

void testInsertInts() {
    std::vector<int> vec;
    insert(vec, 1, 2, 3, 4, 5);
    
    assert(vec.size() == 5);
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    assert(vec[3] == 4);
    assert(vec[4] == 5);
}

void testInsertMixedTypes() {
    std::vector<int> vec;
    insert(vec, 10, 3.14, 20, "hello", 30, 'a', 40);
    
    assert(vec.size() == 4);
    assert(vec[0] == 10);
    assert(vec[1] == 20);
    assert(vec[2] == 30);
    assert(vec[3] == 40);
}

void testInsertEmpty() {
    std::vector<int> vec;
    insert(vec);
    
    assert(vec.size() == 0);
}

void testInsertSingle() {
    std::vector<int> vec;
    insert(vec, 42);
    
    assert(vec.size() == 1);
    assert(vec[0] == 42);
}

int main() {
    testInsertInts();
    testInsertMixedTypes();
    testInsertEmpty();
    testInsertSingle();
    return 0;
}

