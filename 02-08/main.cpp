#include <algorithm>
#include <iostream>
#include <vector>

std::size_t len(unsigned long long int n, std::vector<std::size_t>& seq);
bool compareByValue(const std::pair<int, int>& a, const std::pair<int, int>& b);

int main() {
    const auto CACHE_SIZE = 10000;

    std::vector<std::size_t> cache(CACHE_SIZE, 0);
    std::vector<std::pair<int, unsigned long long int>> pairs;
    for (unsigned long long int i = 1; i <= 100; ++i) {
        std::size_t current_length = len(i, cache);
        pairs.push_back(std::make_pair(i, current_length));
    }

    std::sort(pairs.begin(), pairs.end(), compareByValue);
    for (const auto& p : pairs) {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    }
}

std::size_t len(unsigned long long int n, std::vector<std::size_t>& seq) {
    if (n < seq.size() && seq[n] != 0) {
        return seq[n];
    }
    if (n == 1) {
        return 1;
    }

    std::size_t length = 1 + len(n % 2 == 0 ? n / 2 : 3 * n + 1, seq);
    if (n < seq.size()) {
        seq[n] = length;
    }
    return length;
}

bool compareByValue(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}