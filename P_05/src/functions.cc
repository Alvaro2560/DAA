/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the functions used on the program.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

#include <time.h>

/**
 * @brief Prints the help message.
 * 
 */
void Help(void) {
  std::cout << "Usage: ./dyv [arrays] [-f]" << std::endl;
  std::cout << "Generates a random set of arrays and sorts them using Quick Sort and Merge Sort." << std::endl;
}

/**
 * @brief Generates a random array of integers.
 * 
 * @param size The size of the array.
 * @return int* The generated array.
 */
std::vector<int> GenerateRandom(const size_t& size) {
  srand(time(NULL));
  std::vector<int> array(size);
  for (size_t i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

/**
 * @brief Prints the information of the times it took to solve the problems.
 * 
 * @param quicksort_times Times it took to solve the problems using Quick Sort.
 * @param mergesort_times Times it took to solve the problems using Merge Sort.
 */
void PrintInfo(const std::vector<std::pair<size_t, float>>& quicksort_times,
               const std::vector<std::pair<size_t, float>>& mergesort_times,
               const std::vector<std::pair<int, int>>& quicksort_recurrences,
               const std::vector<std::pair<int, int>>& mergesort_recurrences) {
  std::cout << "QuickSort times:" << std::endl << std::endl;
  std::cout << "Size             Time (ms)              Max. Rec. Level          Calls" << std::endl;
  std::cout << "--------------------------------------------------------------------------" << std::endl;
  for (size_t i = 0; i < quicksort_times.size(); i++) {
    std::cout << quicksort_times[i].first << "                 " << quicksort_times[i].second;
    std::cout << "                         " << quicksort_recurrences[i].first;
    std::cout << "                   " << quicksort_recurrences[i].second << std::endl;
  }
  std::cout << std::endl;
  std::cout << "MergeSort times:" << std::endl << std::endl;
  std::cout << "Size             Time (ms)              Max. Rec. Level          Calls" << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  for (size_t i = 0; i < mergesort_times.size(); i++) {
    std::cout << mergesort_times[i].first << "                 " << mergesort_times[i].second;
    std::cout << "                         " << mergesort_recurrences[i].first;
    std::cout << "                   " << mergesort_recurrences[i].second << std::endl;
  }
} 