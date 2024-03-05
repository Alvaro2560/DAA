/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the functions used on the program.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "../include/dyv.h"

#include <iostream>
#include <chrono>

void Help(void);
std::vector<int> GenerateRandom(const size_t& size);
void PrintInfo(const std::vector<std::pair<size_t, float>>& quicksort_times,
               const std::vector<std::pair<size_t, float>>& mergesort_times,
               const std::vector<std::pair<int, int>>& quicksort_recurrences,
               const std::vector<std::pair<int, int>>& mergesort_recurrences);

/**
 * @brief Calculates the time it took to solve the problem using Quick Sort.
 * 
 * @tparam T 
 * @param array Problem to solve.
 * @param solution Solution of the problem.
 * @param print Flag that indicates if the problem is printable.
 * @return float Time it took to solve the problem.
 */
template <typename T>
float QuickSortTime(const DyV::Problem<T>& array, std::vector<std::pair<int, int>>& quicksort_recurrences,
                    DyV::Solution<T> solution, bool print = false) {
  DyV::QuickSort<T> quicksort;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  solution = quicksort.Solve(array, array.size());
  end = std::chrono::system_clock::now();
  if (print) {
    quicksort_recurrences.emplace_back(std::pair<int, int>(quicksort.getMaxRecursionLevel(), quicksort.getTotalCalls()));
  }
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

/**
 * @brief Calculates the time it took to solve the problem using Merge Sort.
 * 
 * @tparam T 
 * @param array Problem to solve.
 * @param solution Solution of the problem.
 * @param print Flag that indicates if the problem is printable.
 * @return float Time it took to solve the problem.
 */
template <typename T>
float MergeSortTime(const DyV::Problem<T>& array, std::vector<std::pair<int, int>>& mergesort_recurrences,
                    DyV::Solution<T> solution, bool print = false) {
  DyV::MergeSort<T> mergesort;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  solution = mergesort.Solve(array, array.size());
  end = std::chrono::system_clock::now();
  if (print) {
    mergesort_recurrences.emplace_back(std::pair<int, int>(mergesort.getMaxRecursionLevel(), mergesort.getTotalCalls()));
  }
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}