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

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>

/**
 * @brief Prints the help message.
 * 
 */
void Help(void) {
  std::cout << "Usage: ./dyv [arrays]" << std::endl;
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
 * @brief Calculates the time it takes to solve the problems.
 * 
 * @param array The array to solve.
 * @param quicksort The Quick Sort algorithm.
 * @param mergesort The Merge Sort algorithm.
 * @param quicksort_solutions The solutions to the Quick Sort problem.
 * @param mergesort_solutions The solutions to the Merge Sort problem.
 * @param quicksort_times The time it took to solve the Quick Sort problem.
 * @param mergesort_times The time it took to solve the Merge Sort problem.
 */
void CalculateTime(const std::vector<int>& array, DyV::QuickSort& quicksort,
                   DyV::MergeSort& mergesort, std::vector<std::vector<int>>& quicksort_solutions,
                   std::vector<std::vector<int>>& mergesort_solutions, std::vector<float>& quicksort_times,
                   std::vector<float>& mergesort_times) {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  quicksort_solutions.emplace_back(quicksort.Solve(array, array.size()));
  end = std::chrono::system_clock::now();
  quicksort_times.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
  start = std::chrono::system_clock::now();
  mergesort_solutions.emplace_back(mergesort.Solve(array, array.size()));
  end = std::chrono::system_clock::now();
  mergesort_times.emplace_back(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}

/**
 * @brief Prints the data to the console.
 * 
 * @param quicksort_solutions The solutions to the Quick Sort problem.
 * @param mergesort_solutions The solutions to the Merge Sort problem.
 * @param quicksort_times The time it took to solve the Quick Sort problem.
 * @param mergesort_times The time it took to solve the Merge Sort problem.
 */
void PrintData(std::vector<std::vector<int>>& quicksort_solutions,
               std::vector<std::vector<int>>& mergesort_solutions,
               std::vector<float>& quicksort_times,
               std::vector<float>& mergesort_times) {
  for (size_t i = 0; i < quicksort_solutions.size(); i++) {
    std::cout << "Quick Sort:\n";
    std::cout << "Size: " << quicksort_solutions[i].size() << ", ";
    std::cout << "Time: " << quicksort_times[i] << "ms" << std::endl;
  }
  for (size_t i = 0; i < mergesort_solutions.size(); i++) {
    std::cout << "Merge Sort:\n";
    std::cout << "Size: " << mergesort_solutions[i].size() << ", ";
    std::cout << "Time: " << mergesort_times[i] << "ms" << std::endl;
  }
}

/**
 * @brief Writes the data to a file.
 * 
 * @param quicksort_solutions The solutions to the Quick Sort algorithm.
 * @param mergesort_solutions The solutions to the Merge Sort algorithm.
 * @param quicksort_times The times it took to solve the problems using Quick Sort.
 * @param mergesort_times The times it took to solve the problems using Merge Sort.
 */
void WriteData(std::vector<std::vector<int>>& quicksort_solutions,
               std::vector<std::vector<int>>& mergesort_solutions,
               std::vector<float>& quicksort_times,
               std::vector<float>& mergesort_times) {
  std::ofstream file;
  file.open("quick_sort.txt");
  for (size_t i = 0; i < quicksort_solutions.size(); i++) {
    file << "Size: " << quicksort_solutions[i].size() << ", ";
    file << "Time: " << quicksort_times[i] << "ms" << std::endl;
  }
  file.close();
  file.open("merge_sort.txt");
  for (size_t i = 0; i < mergesort_solutions.size(); i++) {
    file << "Size: " << mergesort_solutions[i].size() << ", ";
    file << "Time: " << mergesort_times[i] << "ms" << std::endl;
  }
  file.close();
}