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

/**
 * @brief Solves the problem.
 * 
 * @param array The array to solve.
 * @param size The size of the array.
 * @return std::vector<int> The solution to the problem.
 */
std::vector<int> Algorithm::Solve(const std::vector<int>& array, const size_t& size) {
  if (Small(array)) {
    return SolveSmall(array);
  } else {
    std::pair<std::vector<int>, std::vector<int>> divided_array = Divide(array, size);
    std::vector<int> solution1 = Solve(divided_array.first, divided_array.first.size());
    std::vector<int> solution2 = Solve(divided_array.second, divided_array.second.size());
    std::vector<int> solution = Combine(solution1, solution2);
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