#include "benchmark.h"
#include "sorting.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <stdexcept>

// Estructura para almacenar los algoritmos
struct Algorithm{
    std::string name;
    void (*sortFunction)(std::vector<int>&);
};

// Generar arreglo de numeros aleatorios
static std::vector<int> generateArray(int n, unsigned int seed){
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(-1000000000, 1000000000);
    std::vector<int> arr(n);

    for (int& value : arr){
        value = distribution(generator);
    }

    return arr;
}

void runBenchmark(const std::vector<int>& sizes, int repetitions){
    const std::vector<Algorithm> algorithms = {
        {"Merge Sort", mergeSort},
        {"Selection Sort", selectionSort},
        {"Bubble Sort", bubbleSort},
        {"Quick Sort", quickSort},
        {"Heap Sort", heapSort},
        {"Insertion Sort", insertionSort}
    };

    std::filesystem::create_directories("results");
    std::ofstream csv("results/resultados.csv");

    if (!csv.is_open()){
        throw std::runtime_error("No se pudo crear el archivo CSV");
    }

    csv << "Algoritmo,N,Repeticion,Tiempo_ms,Estado\n";
    csv << std::fixed << std::setprecision(6);
    int totalTests = sizes.size() * algorithms.size() * repetitions;
    int currentTest = 0;

    for (int n : sizes)
    {
        std::cout << "\n============================\n";
        std::cout << "N = " << n << "\n";
        std::cout << "============================\n";
        for (int r = 1; r <= repetitions; r++){
            // Semilla para reproducir los datos
            unsigned int seed = 2026u + n + r;
            std::vector<int> original = generateArray(n, seed);
            std::vector<int> expected = original;
            std::sort(expected.begin(), expected.end());

            // Ejecutar cada algoritmo
            for (const Algorithm& algorithm : algorithms){
                currentTest++;
                std::vector<int> arr = original;
                std::cout << "[" << currentTest << "/" << totalTests << "] " << algorithm.name
                    << " | N=" << n << " | Prueba=" << r << " ... " << std::flush;

                // Iniciar cronometro
                auto start = std::chrono::steady_clock::now();
                // Ejecutar algoritmo
                algorithm.sortFunction(arr);
                // Detener cronometro
                auto end = std::chrono::steady_clock::now();
                // Calcular tiempo en milisegundos
                double timeMs = std::chrono::duration<double, std::milli>(end - start).count();

                // Verificar resultado
                bool sorted = (arr == expected);
                std::string status = sorted ? "OK" : "ERROR";
                std::cout << std::fixed << std::setprecision(6) << timeMs << " ms" << " [" << status << "]\n";

                // Guardar resultado individual
                csv << algorithm.name << "," << n << "," << r << "," << timeMs << "," << status << "\n";
                csv.flush();
            }
        }
    }

    csv.close();

    std::cout << "\n============================\n";
    std::cout << "BENCHMARK FINALIZADO\n";
    std::cout << "============================\n";
    std::cout << "Pruebas realizadas: " << currentTest << "\n";
    std::cout << "Archivo generado: " << "results/resultados.csv\n";
}