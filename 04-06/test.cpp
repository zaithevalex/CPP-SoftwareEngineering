#include <array>
#include <cmath>

consteval double calculate_pi() {
    double pi = 0.0;
    for (int i = 0; i < 10000; ++i) {
        pi += 4.0 / (2 * i + 1) * (i % 2 == 0 ? 1 : -1);
    }
    return pi;
}

consteval double calculate_e() {
    double e = 1.0;
    double factorial = 1.0;
    for (int i = 1; i < 15; ++i) {
        factorial *= i;
        e += 1.0 / factorial;
    }
    return e;
}

constexpr double pi = calculate_pi();
constexpr double e = calculate_e();

constexpr std::array<double, 5> epsilon_values = {
    0.1,
    0.01,
    0.001,
    0.0001,
    0.00001
};

static_assert(epsilon_values[0] == 0.1);
static_assert(epsilon_values[1] == 0.01);
static_assert(epsilon_values[2] == 0.001);
static_assert(epsilon_values[3] == 0.0001);
static_assert(epsilon_values[4] == 0.00001);

static_assert(epsilon_values.size() == 5);

constexpr double abs_diff_pi = (pi > 3.14159) ? (pi - 3.14159) : (3.14159 - pi);
constexpr double abs_diff_e = (e > 2.71828) ? (e - 2.71828) : (2.71828 - e);
static_assert(abs_diff_pi < 0.01);
static_assert(abs_diff_e < 0.01);

int main() {
    return 0;
}

