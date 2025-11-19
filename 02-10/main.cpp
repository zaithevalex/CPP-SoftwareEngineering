#include <iostream>
#include <vector>
#include <algorithm>

int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];
    
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    } else {
        return c;
    }
}

int hoarePartition(std::vector<int>& arr, int low, int high) {
    int pivot = medianOfThree(arr, low, high);
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

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = hoarePartition(arr, low, high);
        quicksort(arr, low, pivotIndex);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void quicksort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        quicksort(arr, 0, arr.size() - 1);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    
    std::cout << "Original array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    quicksort(arr);
    
    std::cout << "Sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> arr2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::cout << "\nOriginal array: ";
    for (int val : arr2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    quicksort(arr2);
    
    std::cout << "Sorted array: ";
    for (int val : arr2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

