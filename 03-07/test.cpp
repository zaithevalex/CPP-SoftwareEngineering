#include <cassert>
#include <cstddef>

class Vector {
private:
    std::size_t cap;
    std::size_t sz;
    int* data;

    void resize() {
        std::size_t newCap = (cap == 0) ? 1 : cap * 2;
        int* newData = new int[newCap];
        for (std::size_t i = 0; i < sz; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    Vector() : cap(0), sz(0), data(nullptr) {}

    ~Vector() {
        delete[] data;
    }

    std::size_t capacity() const {
        return cap;
    }

    std::size_t size() const {
        return sz;
    }

    void push_back(int value) {
        if (sz >= cap) {
            resize();
        }
        data[sz] = value;
        ++sz;
    }

    void clear() {
        sz = 0;
    }

    bool empty() const {
        return sz == 0;
    }
};

void testEmpty() {
    Vector vec;
    assert(vec.empty() == true);
    assert(vec.size() == 0);
    assert(vec.capacity() == 0);
}

void testPushBack() {
    Vector vec;
    vec.push_back(1);
    assert(vec.empty() == false);
    assert(vec.size() == 1);
    assert(vec.capacity() >= 1);
    
    vec.push_back(2);
    assert(vec.size() == 2);
    assert(vec.capacity() >= 2);
}

void testClear() {
    Vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    assert(vec.size() == 3);
    vec.clear();
    assert(vec.empty() == true);
    assert(vec.size() == 0);
    assert(vec.capacity() > 0);
}

void testCapacityGrowth() {
    Vector vec;
    std::size_t prevCap = 0;
    
    for (int i = 0; i < 20; ++i) {
        vec.push_back(i);
        if (vec.capacity() != prevCap) {
            prevCap = vec.capacity();
        }
        assert(vec.size() == i + 1);
        assert(vec.capacity() >= vec.size());
    }
}

void testMultipleOperations() {
    Vector vec;
    
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    
    assert(vec.size() == 10);
    assert(vec.empty() == false);
    
    vec.clear();
    assert(vec.size() == 0);
    assert(vec.empty() == true);
    
    vec.push_back(100);
    assert(vec.size() == 1);
    assert(vec.empty() == false);
}

int main() {
    testEmpty();
    testPushBack();
    testClear();
    testCapacityGrowth();
    testMultipleOperations();
    return 0;
}
