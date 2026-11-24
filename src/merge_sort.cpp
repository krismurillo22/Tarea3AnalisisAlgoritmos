#include "sorting.h"

static void merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right){
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }   
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for (int x = left; x <= right; x++){
        arr[x] = temp[x];
    }
}

static void mergeSortRecursive(std::vector<int>& arr, std::vector<int>& temp, int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, temp, left, mid);
    mergeSortRecursive(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}

void mergeSort(std::vector<int>& arr){
    if (arr.size() < 2)
        return;

    std::vector<int> temp(arr.size());
    mergeSortRecursive(arr, temp, 0, static_cast<int>(arr.size()) - 1);
}