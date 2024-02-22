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
 * @return int* The solution to the problem.
 */
int* Algorithm::Solve(int* array, int size) {
  if (Small(array)) {
    return SolveSmall(array);
  } else {
    int** divided_array = Divide(array, size);
    int* solution1 = Solve(divided_array[0], size / 2);
    int* solution2 = Solve(divided_array[1] + size / 2, size / 2);
    int* solution = Combine(solution1, solution2);
    return solution;
  }
}