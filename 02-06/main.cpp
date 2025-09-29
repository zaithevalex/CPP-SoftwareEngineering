#include <iostream>
#include <span>
#include <cmath>

const size_t MAX_SIZE = 100;

double getMax(std::span<double> arr);

double getMin(std::span<double> arr);

double getAverage(std::span<double> arr);

double getStandardDeviation(std::span<double> arr);

int main() {
    std::array<double, MAX_SIZE> arr{};
    std::string line;
    std::getline(std::cin, line);
    std::string current_number;
    size_t count = 0;
    for (char c : line) {
        if (std::isdigit(c) || (c == '-' && current_number.empty())) {
            current_number += c;
        } else if (!current_number.empty()) {
            try {
                if (count < MAX_SIZE) {
                    arr[count++] = std::stoi(current_number);
                } else {
                    break;
                }
            } catch (const std::exception& e) {}
            current_number.clear();
        }
    }

    if (!current_number.empty() && count < MAX_SIZE) {
        try {
            arr[count++] = std::stoi(current_number);
        } catch (const std::exception& e) {}
    }

    std::span<double> sp{arr.begin(), count};

    std::cout << "Max: " << getMax(sp) << std::endl;
    std::cout << "Min: " << getMin(sp) << std::endl;
    std::cout << "Average: " << getAverage(sp) << std::endl;
    std::cout << "Standard Deviation: " << getStandardDeviation(sp) << std::endl;
}

double getAverage(const std::span<double> arr) {
    if (arr.size() == 0) {
        return 0;
    }

    double average = 0;
    for (auto element : arr) {
        average += element;
    }
    return average / arr.size();
}



double getMax(const std::span<double> arr) {
    double max = arr.size() > 0 ? arr.front() : 0;
    for (auto num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

double getMin(const std::span<double> arr) {
    double min = arr.size() > 0 ? arr.front() : 0;
    for (auto num : arr) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

double getStandardDeviation(const std::span<double> arr) {
    double stDev = 0, avg = getAverage(arr);
    for (auto num : arr) {
        double diff = (num - avg);
        stDev += diff * diff;
    }
    return std::sqrt(stDev / arr.size());
}