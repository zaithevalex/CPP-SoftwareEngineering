#include <cassert>

double max(double first) {
    return first;
}

template<typename... Args>
double max(double first, double second, Args... rest) {
    double max_rest = max(second, rest...);
    return first > max_rest ? first : max_rest;
}

double min(double first) {
    return first;
}

template<typename... Args>
double min(double first, double second, Args... rest) {
    double min_rest = min(second, rest...);
    return first < min_rest ? first : min_rest;
}

template<typename... Args>
double sum(Args... args) {
    return (args + ...);
}

template<typename... Args>
double mean(Args... args) {
    return sum(args...) / sizeof...(args);
}

void testMax() {
    assert(max(3.5) == 3.5);
    assert(max(3.5, 1.2) == 3.5);
    assert(max(3.5, 1.2, 4.7) == 4.7);
    assert(max(3.5, 1.2, 4.7, 2.1) == 4.7);
    assert(max(10.5, 5.3, 8.9) == 10.5);
}

void testMin() {
    assert(min(3.5) == 3.5);
    assert(min(3.5, 1.2) == 1.2);
    assert(min(3.5, 1.2, 4.7) == 1.2);
    assert(min(3.5, 1.2, 4.7, 2.1) == 1.2);
    assert(min(10.5, 5.3, 8.9) == 5.3);
}

void testSum() {
    assert(sum(3.5) == 3.5);
    assert(sum(3.5, 1.2) == 4.7);
    assert(sum(1.0, 2.0, 3.0) == 6.0);
    assert(sum(1.0, 2.0, 3.0, 4.0, 5.0) == 15.0);
}

void testMean() {
    assert(mean(3.5) == 3.5);
    assert(mean(3.5, 1.2) == 2.35);
    assert(mean(1.0, 2.0, 3.0) == 2.0);
    assert(mean(1.0, 2.0, 3.0, 4.0, 5.0) == 3.0);
}

int main() {
    testMax();
    testMin();
    testSum();
    testMean();
    return 0;
}
