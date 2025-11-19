#include <iostream>
#include <numeric>
#include <cassert>

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

int main() {
    int pairs[][2] = {
        {48, 18},
        {100, 25},
        {17, 13},
        {56, 42},
        {0, 5},
        {7, 0}
    };

    for (int i = 0; i < 6; ++i) {
        int a = pairs[i][0];
        int b = pairs[i][1];

        int gcdRec = gcdRecursive(a, b);
        int gcdIter = gcdIterative(a, b);
        int gcdStd = std::gcd(a, b);

        std::cout << "GCD(" << a << ", " << b << "):" << std::endl;
        std::cout << "  Recursive: " << gcdRec << std::endl;
        std::cout << "  Iterative: " << gcdIter << std::endl;
        std::cout << "  std::gcd:  " << gcdStd << std::endl;

        assert(gcdRec == gcdStd);
        assert(gcdIter == gcdStd);

        if (a != 0 && b != 0) {
            int lcmCustom = lcm(a, b);
            int lcmStd = std::lcm(a, b);

            std::cout << "LCM(" << a << ", " << b << "):" << std::endl;
            std::cout << "  Custom:   " << lcmCustom << std::endl;
            std::cout << "  std::lcm: " << lcmStd << std::endl;

            assert(lcmCustom == lcmStd);
        }

        std::cout << std::endl;
    }

    return 0;
}

