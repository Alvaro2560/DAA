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
#include <fstream>

int main(int argc, char** argv) {
  try {
    std::ofstream quicksort_file, mergesort_file;
    if ((argc == 3 && std::string(argv[2]) != "-f") || 
        (argc == 2 && std::string(argv[1]) == "-h") || (argc > 3) || (argc < 2)) {
      Help();
      return 1;
    } else if (argc == 3 && std::string(argv[2]) == "-f") {
      quicksort_file.open("quicksort_times.csv");
      mergesort_file.open("mergesort_times.csv");
    }
    const size_t kInstances = (size_t)std::stoi(argv[1]);
    const size_t kPrintableIndex = kInstances / 10;
    size_t printable_element = kPrintableIndex;
    std::vector<std::pair<size_t, float>> quicksort_times, mergesort_times;
    std::vector<int> instance;
    float quicksort_time, mergesort_time;
    for (size_t i = 2; i < kInstances + 1; i++) {
      instance = GenerateRandom(i);
      DyV::Problem<std::vector<int>> problem(instance);
      quicksort_time = QuickSortTime(problem);
      mergesort_time = MergeSortTime(problem);
      if (i == printable_element) {
        quicksort_times.emplace_back(std::pair<size_t, float>(i, quicksort_time));
        mergesort_times.emplace_back(std::pair<size_t, float>(i, mergesort_time));
        printable_element += kPrintableIndex;
      }
      if (quicksort_file.is_open()) {
        quicksort_file << i << "," << quicksort_time << std::endl;
        mergesort_file << i << "," << mergesort_time << std::endl;
      }
    }
    if (quicksort_file.is_open()) {
      quicksort_file.close();
      mergesort_file.close();
    }
    PrintInfo(quicksort_times, mergesort_times);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}