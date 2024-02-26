/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main file of the program.
 * @version 0.1
 * @since Feb 23 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

#include <iostream>

int main(int argc, char** argv) {
  try {
    if (argc != 2) {
      Help();
      return 1;
    }
    std::vector<std::vector<int>> instances(std::stoi(argv[1]));
    for (size_t i = 0, j = 2; i < instances.size(); i++, j++) {
      instances[i] = GenerateRandom(j);
    }
    DyV::QuickSort quicksort;
    DyV::MergeSort mergesort;
    std::vector<std::vector<int>> quicksort_solutions, mergesort_solutions;
    std::vector<float> quicksort_times, mergesort_times;
    for (size_t i = 0; i < instances.size(); i++) {
      CalculateTime(instances[i], quicksort, mergesort, quicksort_solutions, mergesort_solutions, quicksort_times, mergesort_times);
    }
    PrintData(quicksort_solutions, mergesort_solutions, quicksort_times, mergesort_times);
    WriteData(quicksort_solutions, mergesort_solutions, quicksort_times, mergesort_times);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}