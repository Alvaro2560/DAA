/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file quicksort.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class QuickSort.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/quicksort.h"

/**
 * @brief Checks if the array is small enough to be solved.
 * 
 * @param array The array to check.
 * @return true If the array is small enough to be solved.
 * @return false If the array is not small enough to be solved.
 */
bool DyV::QuickSort::Small(const std::vector<int>& array) {
  if (array.size() <= 2) {
    return true;
  }
  return false;
}

/**
 * @brief Solves the problem for small arrays.
 * 
 * @param array The array to solve.
 * @return std::vector<int> The solution to the problem.
 */
std::vector<int> DyV::QuickSort::SolveSmall(const std::vector<int>& array) {
  if (array.size() == 1) {
    return array;
  }
  std::vector<int> solution = array;
  if (solution[0] > solution[1]) {
    int temp = solution[0];
    solution[0] = solution[1];
    solution[1] = temp;
  }
  return solution;
}

/**
 * @brief Divides the problem into subproblems.
 * 
 * @param array The array to divide.
 * @param size The size of the array.
 * @return std::pair<std::vector<int>, std::vector<int>> The divided array.
 */
std::pair<std::vector<int>, std::vector<int>> DyV::QuickSort::Divide(const std::vector<int>& array, const size_t& size) {
  int pivot = array[0];
  std::vector<int> divided_array1, divided_array2;
  for (size_t i = 1; i < size; i++) {
    if (array[i] < pivot) {
      divided_array1.emplace_back(array[i]);
    } else {
      divided_array2.emplace_back(array[i]);
    }
  }
  if (divided_array2.size() == 0){
    divided_array2.emplace_back(pivot);
  } else {
    divided_array1.emplace_back(pivot);
  }
  return std::make_pair(divided_array1, divided_array2);
}

/**
 * @brief Combines the solutions to the subproblems.
 * 
 * @param solution1 The solution to the first subproblem.
 * @param solution2 The solution to the second subproblem.
 * @return std::vector<int> The combined solution.
 */
std::vector<int> DyV::QuickSort::Combine(const std::vector<int>& solution1, const std::vector<int>& solution2) {
  std::vector<int> combined_solution = solution1;
  for (size_t i = 0; i < solution2.size(); i++) {
    combined_solution.emplace_back(solution2[i]);
  }
  return combined_solution;
}

/**
 * @brief Returns the recurrence of the algorithm.
 * 
 * @return std::string The recurrence of the algorithm.
 */
std::string DyV::QuickSort::getRecurrence(void) {
  return "T(n) = 2T(n/2) + O(n)";
}