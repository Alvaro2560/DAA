/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file algorithm.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Algorithm.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/algorithm.h"

#include <iostream>

/**
 * @brief Solves the problem.
 * 
 * @param array The array to solve.
 * @param size The size of the array.
 * @return int* The solution to the problem.
 */
std::vector<int> Algorithm::Solve(const std::vector<int>& array, const size_t& size) {
  std::cout << "Array: ";
  for (size_t i = 0; i < array.size(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl << std::endl;
  if (Small(array)) {
    return SolveSmall(array);
  } else {
    std::pair<std::vector<int>, std::vector<int>> divided_array = Divide(array, size);
    std::cout << "Divided array 1: ";
    for (size_t i = 0; i < divided_array.first.size(); i++) {
      std::cout << divided_array.first[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Divided array 2: ";
    for (size_t i = 0; i < divided_array.second.size(); i++) {
      std::cout << divided_array.second[i] << " ";
    }
    std::cout << std::endl << std::endl;
    std::vector<int> solution1 = Solve(divided_array.first, size / 2);
    std::cout << "Solution 1: ";
    for (size_t i = 0; i < solution1.size(); i++) {
      std::cout << solution1[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> solution2 = Solve(divided_array.second, size / 2);
    std::cout << "Solution 2: ";
    for (size_t i = 0; i < solution2.size(); i++) {
      std::cout << solution2[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> solution = Combine(solution1, solution2);
    std::cout << "Combined solution: ";
    for (size_t i = 0; i < solution.size(); i++) {
      std::cout << solution[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return solution;
  }
}

/**
 * @brief Returns the recurrence of the algorithm.
 * 
 * @return std::string The recurrence of the algorithm.
 */
std::string Algorithm::Recurrence(void) {
  return getRecurrence();
}