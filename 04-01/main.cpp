#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
T medianOfThree(std::vector<T>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    T a = arr[low];
    T b = arr[mid];
    T c = arr[high];
    
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    } else {
        return c;
    }
}

template<typename T>
int hoarePartition(std::vector<T>& arr, int low, int high) {
    T pivot = medianOfThree(arr, low, high);
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);
        
        do {
            --j;
        } while (arr[j] > pivot);
        
        if (i >= j) {
            return j;
        }
        
        std::swap(arr[i], arr[j]);
    }
}

template<typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = hoarePartition(arr, low, high);
        quicksort(arr, low, pivotIndex);
        quicksort(arr, pivotIndex + 1, high);
    }
}

template<typename T>
void quicksort(std::vector<T>& arr) {
    if (arr.size() > 1) {
        quicksort(arr, 0, arr.size() - 1);
    }
}

int main() {
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    
    std::cout << "Original int array: ";
    for (int val : arr1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    quicksort(arr1);
    
    std::cout << "Sorted int array: ";
    for (int val : arr1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::vector<double> arr2 = {3.14, 1.41, 2.71, 0.57, 1.73};
    
    std::cout << "\nOriginal double array: ";
    for (double val : arr2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    quicksort(arr2);
    
    std::cout << "Sorted double array: ";
    for (double val : arr2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::vector<std::string> arr3 = {"banana", "apple", "cherry", "date"};
    
    std::cout << "\nOriginal string array: ";
    for (const std::string& val : arr3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    quicksort(arr3);
    
    std::cout << "Sorted string array: ";
    for (const std::string& val : arr3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

