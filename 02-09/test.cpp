#include <cassert>
#include <numeric>

int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / gcdIterative(a, b)) * b;
}

void testGcdRecursive() {
    assert(gcdRecursive(48, 18) == 6);
    assert(gcdRecursive(100, 25) == 25);
    assert(gcdRecursive(17, 13) == 1);
    assert(gcdRecursive(56, 42) == 14);
    assert(gcdRecursive(0, 5) == 5);
    assert(gcdRecursive(7, 0) == 7);
    assert(gcdRecursive(1, 1) == 1);
    assert(gcdRecursive(100, 100) == 100);
}

void testGcdIterative() {
    assert(gcdIterative(48, 18) == 6);
    assert(gcdIterative(100, 25) == 25);
    assert(gcdIterative(17, 13) == 1);
    assert(gcdIterative(56, 42) == 14);
    assert(gcdIterative(0, 5) == 5);
    assert(gcdIterative(7, 0) == 7);
    assert(gcdIterative(1, 1) == 1);
    assert(gcdIterative(100, 100) == 100);
}

void testLcm() {
    assert(lcm(48, 18) == 144);
    assert(lcm(100, 25) == 100);
    assert(lcm(17, 13) == 221);
    assert(lcm(56, 42) == 168);
    assert(lcm(1, 1) == 1);
    assert(lcm(5, 7) == 35);
    assert(lcm(0, 5) == 0);
    assert(lcm(7, 0) == 0);
}

void testAgainstStd() {
    assert(gcdRecursive(48, 18) == std::gcd(48, 18));
    assert(gcdIterative(48, 18) == std::gcd(48, 18));
    assert(lcm(48, 18) == std::lcm(48, 18));
    
    assert(gcdRecursive(100, 25) == std::gcd(100, 25));
    assert(gcdIterative(100, 25) == std::gcd(100, 25));
    assert(lcm(100, 25) == std::lcm(100, 25));
}

int main() {
    testGcdRecursive();
    testGcdIterative();
    testLcm();
    testAgainstStd();
    return 0;
}
