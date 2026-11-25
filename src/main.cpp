#include <iostream>
#include <vector>
#include <exception>
#include "benchmark.h"

int main()
{
    std::cout << " SORTING ALGORITHMS BENCHMARK\n";
    const std::vector<int> sizes = {100, 1000, 10000};
    const int repetitions = 5;

    try{
        runBenchmark(sizes, repetitions);
    }catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}