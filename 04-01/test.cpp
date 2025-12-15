#include <cassert>
#include <vector>
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

void testIntSort() {
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    std::vector<int> expected1 = {5, 11, 12, 22, 25, 34, 50, 64, 77, 90};
    quicksort(arr1);
    assert(arr1 == expected1);
    
    std::vector<int> arr2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> expected2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quicksort(arr2);
    assert(arr2 == expected2);
}

void testDoubleSort() {
    std::vector<double> arr1 = {3.14, 1.41, 2.71, 0.57, 1.73};
    std::vector<double> expected1 = {0.57, 1.41, 1.73, 2.71, 3.14};
    quicksort(arr1);
    assert(arr1 == expected1);
    
    std::vector<double> arr2 = {5.5, 2.2, 8.8, 1.1, 9.9};
    std::vector<double> expected2 = {1.1, 2.2, 5.5, 8.8, 9.9};
    quicksort(arr2);
    assert(arr2 == expected2);
}

void testStringSort() {
    std::vector<std::string> arr1 = {"banana", "apple", "cherry", "date"};
    std::vector<std::string> expected1 = {"apple", "banana", "cherry", "date"};
    quicksort(arr1);
    assert(arr1 == expected1);
    
    std::vector<std::string> arr2 = {"zebra", "apple", "banana"};
    std::vector<std::string> expected2 = {"apple", "banana", "zebra"};
    quicksort(arr2);
    assert(arr2 == expected2);
}

int main() {
    testIntSort();
    testDoubleSort();
    testStringSort();
    return 0;
}

