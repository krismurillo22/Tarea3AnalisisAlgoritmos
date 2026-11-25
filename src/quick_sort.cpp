#include "sorting.h"
#include <utility>

static int partition(std::vector<int>& arr, int left, int right){
    int pivotIndex = left + (right - left) / 2;
    std::swap(arr[pivotIndex], arr[right]);

    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++){
        if (arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

static void quickSortRecursive(std::vector<int>& arr, int left, int right){
    while (left < right){
        int pivot = partition(arr, left, right);
        if (pivot - left < right - pivot){
            quickSortRecursive(arr, left, pivot - 1);
            left = pivot + 1;
        }else{
            quickSortRecursive(arr, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

void quickSort(std::vector<int>& arr){
    if (arr.size() < 2)
        return;
    quickSortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}