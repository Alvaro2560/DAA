/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file DyV::quicksort.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class DyV::QuickSort.
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
bool DyV::QuickSort::Small(int* array, int size) {
  if (size <= 1) {
    return true;
  }
  return false;
}

/**
 * @brief Solves the problem for small arrays.
 * 
 * @param array The array to solve.
 * @return int* The solution to the problem.
 */
int* DyV::QuickSort::SolveSmall(int* array, int size) {
  return array;
}

/**
 * @brief Divides the problem into subproblems.
 * 
 * @param array The array to divide.
 * @param size The size of the array.
 * @return int** The divided array.
 */
int** DyV::QuickSort::Divide(int* array, int size) {
  int pivot = array[size / 2];
  int i = 0;
  int j = size - 1;
  while (i <= j) {
    while (array[i] < pivot) i++;
    while (array[j] > pivot) j--;
    if (i <= j) {
      std::swap(array[i], array[j]);
      i++;
      j--;
    }
  }
  int** divided_array = new int*[2];
  divided_array[0] = array;
  divided_array[1] = array + i;
  return divided_array;
}
// TODO: Check why two numbers converts to 0
/**
 * @brief Combines the solutions to the subproblems.
 * 
 * @param solution1 The solution to the first subproblem.
 * @param solution2 The solution to the second subproblem.
 * @return int* The combined solution.
 */
int* DyV::QuickSort::Combine(int* solution1, int* solution2, int size) {
  size_t size1 = size, size2 = size;
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
std::string DyV::QuickSort::getRecurrence(void) {
  return "T(n) = 2T(n/2) + O(n)";
}