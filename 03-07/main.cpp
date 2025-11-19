#include <iostream>
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

int main() {
    Vector vec;

    std::cout << "Initial capacity: " << vec.capacity() << std::endl;
    std::cout << "Initial size: " << vec.size() << std::endl;
    std::cout << "Is empty: " << vec.empty() << std::endl;

    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
        std::cout << "After push_back(" << i << "): size=" << vec.size() 
                  << ", capacity=" << vec.capacity() << std::endl;
    }

    vec.clear();
    std::cout << "After clear(): size=" << vec.size() 
              << ", capacity=" << vec.capacity() << std::endl;
    std::cout << "Is empty: " << vec.empty() << std::endl;

    return 0;
}

