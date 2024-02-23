/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file DyV::mergesort.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class DyV::MergeSort.
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
bool DyV::MergeSort::Small(int* array, int size) {
  return false;
}

/**
 * @brief Solves the problem for small arrays.
 * 
 * @param array The array to solve.
 * @return int* The solution to the problem.
 */
int* DyV::MergeSort::SolveSmall(int* array, int size) {
  return array;
}

/**
 * @brief Divides the problem into subproblems.
 * 
 * @param array The array to divide.
 * @param size The size of the array.
 * @return int** The divided array.
 */
int** DyV::MergeSort::Divide(int* array, int size) {
  int mid = size / 2;
  int** divided_array = new int*[2];
  divided_array[0] = new int[mid];
  divided_array[1] = new int[size - mid];
  for (int i = 0; i < mid; ++i) {
    divided_array[0][i] = array[i];
  }
  for (int i = mid; i < size; ++i) {
    divided_array[1][i - mid] = array[i];
  }
  return divided_array;
}

/**
 * @brief Combines the solutions to the subproblems.
 * 
 * @param solution1 The solution to the first subproblem.
 * @param solution2 The solution to the second subproblem.
 * @return int* The combined solution.
 */
int* DyV::MergeSort::Combine(int* solution1, int* solution2, int size) {
  int size1 = sizeof(solution1), size2 = sizeof(solution2);
  int* combined = new int[size1 + size2];
  int i = 0, j = 0, k = 0;
  while (i < size1 && j < size2) {
    if (solution1[i] <= solution2[j]) {
        combined[k++] = solution1[i++];
    } else {
        combined[k++] = solution2[j++];
    }
  }
  while (i < size1) {
    combined[k++] = solution1[i++];
  }
  while (j < size2) {
    combined[k++] = solution2[j++];
  }
  return combined;
}

/**
 * @brief Returns the recurrence of the algorithm.
 * 
 * @return std::string The recurrence of the algorithm.
 */
std::string DyV::MergeSort::getRecurrence(void) {
  return "T(n) = 2T(n/2) + O(n)";
}