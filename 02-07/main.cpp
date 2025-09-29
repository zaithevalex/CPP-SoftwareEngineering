#include <iostream>
#include <cmath>

double getMax(std::vector<double> arr);

double getMin(std::vector<double> arr);

double getAverage(std::vector<double> arr);

double getStandardDeviation(std::vector<double> arr);

int main() {
    std::vector<double> arr;
    std::string line;
    std::getline(std::cin, line);
    std::string current_number;
    for (char c : line) {
        if (std::isdigit(c) || (c == '-' && current_number.empty())) {
            current_number += c;
        } else if (!current_number.empty()) {
            arr.push_back(std::stoi(current_number));
            current_number.clear();
        }
    }

    if (!current_number.empty()) {
        arr.push_back(std::stoi(current_number));
    }

    std::cout << "Max: " << getMax(arr) << std::endl;
    std::cout << "Min: " << getMin(arr) << std::endl;
    std::cout << "Average: " << getAverage(arr) << std::endl;
    std::cout << "Standard Deviation: " << getStandardDeviation(arr) << std::endl;
}

double getAverage(const std::vector<double> arr) {
    if (arr.size() == 0) {
        return 0;
    }

    double average = 0;
    for (auto element : arr) {
        average += element;
    }
    return average / arr.size();
}



double getMax(const std::vector<double> arr) {
    double max = arr.size() > 0 ? arr.front() : 0;
    for (auto num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

double getMin(const std::vector<double> arr) {
    double min = arr.size() > 0 ? arr.front() : 0;
    for (auto num : arr) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

double getStandardDeviation(const std::vector<double> arr) {
    double stDev = 0, avg = getAverage(arr);
    for (auto num : arr) {
        double diff = (num - avg);
        stDev += diff * diff;
    }
    return std::sqrt(stDev / arr.size());
}