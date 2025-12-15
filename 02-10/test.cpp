#include <cassert>
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

void testQuicksort() {
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    std::vector<int> expected1 = {5, 11, 12, 22, 25, 34, 50, 64, 77, 90};
    quicksort(arr1);
    assert(arr1 == expected1);
    
    std::vector<int> arr2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> expected2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quicksort(arr2);
    assert(arr2 == expected2);
    
    std::vector<int> arr3 = {1};
    std::vector<int> expected3 = {1};
    quicksort(arr3);
    assert(arr3 == expected3);
    
    std::vector<int> arr4 = {};
    std::vector<int> expected4 = {};
    quicksort(arr4);
    assert(arr4 == expected4);
    
    std::vector<int> arr5 = {5, 5, 5, 5, 5};
    std::vector<int> expected5 = {5, 5, 5, 5, 5};
    quicksort(arr5);
    assert(arr5 == expected5);
    
    std::vector<int> arr6 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> expected6 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quicksort(arr6);
    assert(arr6 == expected6);
}

void testMedianOfThree() {
    std::vector<int> arr1 = {3, 1, 2};
    int med1 = medianOfThree(arr1, 0, 2);
    assert(med1 == 2);
    
    std::vector<int> arr2 = {1, 2, 3};
    int med2 = medianOfThree(arr2, 0, 2);
    assert(med2 == 2);
    
    std::vector<int> arr3 = {5, 3, 4};
    int med3 = medianOfThree(arr3, 0, 2);
    assert(med3 == 4);
}

int main() {
   printf("testQuicksort\n");
    testQuicksort();
    testMedianOfThree();
    return 0;
}
