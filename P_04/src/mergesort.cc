/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file mergesort.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class MergeSort.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/mergesort.h"

/**
 * @brief Checks if the array is small enough to be solved.
 * 
 * @param array The array to check.
 * @return true If the array is small enough to be solved.
 * @return false If the array is not small enough to be solved.
 */
bool DyV::MergeSort::Small(const std::vector<int>& array) {
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
std::vector<int> DyV::MergeSort::SolveSmall(const std::vector<int>& array) {
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
std::pair<std::vector<int>, std::vector<int>> DyV::MergeSort::Divide(const std::vector<int>& array, const size_t& size) {
  std::vector<int> first_half;
  std::vector<int> second_half;
  size_t half = size / 2;
  if (size % 2 != 0) {
    half = size / 2 + 1;
  }
  for (size_t i = 0; i < half; i++) {
    first_half.emplace_back(array[i]);
  }
  for (size_t i = half; i < size; i++) {
    second_half.emplace_back(array[i]);
  }
  return std::make_pair(first_half, second_half);
}

/**
 * @brief Combines the solutions to the subproblems.
 * 
 * @param solution1 The solution to the first subproblem.
 * @param solution2 The solution to the second subproblem.
 * @return std::vector<int> The combined solution.
 */
std::vector<int> DyV::MergeSort::Combine(const std::vector<int>& solution1, const std::vector<int>& solution2) {
  std::vector<int> solution;
  size_t i = 0;
  size_t j = 0;
  while (i < solution1.size() && j < solution2.size()) {
    if (solution1[i] < solution2[j]) {
      solution.emplace_back(solution1[i]);
      i++;
    } else {
      solution.emplace_back(solution2[j]);
      j++;
    }
  }
  while (i < solution1.size()) {
    solution.emplace_back(solution1[i]);
    i++;
  }
  while (j < solution2.size()) {
    solution.emplace_back(solution2[j]);
    j++;
  }
  return solution;
}

/**
 * @brief Returns the recurrence of the algorithm.
 * 
 * @return std::string The recurrence of the algorithm.
 */
std::string DyV::MergeSort::getRecurrence(void) {
  return "T(n) = 2T(n/2) + O(n)";
}