#include <iostream>
#include <vector>
#include <algorithm>
#include "sorting.h"

void printArray(const std::vector<int>& arr)
{
    for (int value : arr)
        std::cout << value << " ";

    std::cout << "\n";
}

void testAlgorithm(
    const char* name,
    void (*sortFunction)(std::vector<int>&),
    const std::vector<int>& original)
{
    std::vector<int> arr = original;

    sortFunction(arr);

    std::cout << name << ": ";

    printArray(arr);

    std::vector<int> expected = original;
    std::sort(expected.begin(), expected.end());

    if (arr == expected)
        std::cout << "Estado: OK\n";
    else
        std::cout << "Estado: ERROR\n";

    std::cout << "\n";
}

int main()
{
    std::vector<int> original = {
        64, 34, 25, 12, 22, 11, 90, 5, 18, 42
    };

    std::cout << "Arreglo original: ";
    printArray(original);

    std::cout << "\n";

    testAlgorithm("Merge Sort", mergeSort, original);
    testAlgorithm("Selection Sort", selectionSort, original);
    testAlgorithm("Bubble Sort", bubbleSort, original);
    testAlgorithm("Quick Sort", quickSort, original);
    testAlgorithm("Heap Sort", heapSort, original);
    
    return 0;
}