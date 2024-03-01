/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file quicksort.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class QuickSort.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.h"

namespace DyV {
  /**
   * @brief Class that executes the QuickSort algorithm.
   * 
   */
  template <typename T>
  class QuickSort : public Algorithm<T> {
    public:
      QuickSort(void) = default;
    private:
      /**
       * @brief Checks if the array is small enough to be solved.
       * 
       * @param array The array to check.
       * @return true If the array is small enough to be solved.
       * @return false If the array is not small enough to be solved.
       */
      bool Small(const DyV::Problem<T>& array) {
        if (array.size() == 1) {
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
      DyV::Solution<T> SolveSmall(const DyV::Problem<T>& array) {
        return Solution<T>(array.getData());
      }

      /**
       * @brief Divides the problem into subproblems.
       * 
       * @param array The array to divide.
       * @param size The size of the array.
       * @return std::pair<std::vector<int>, std::vector<int>> The divided array.
       */
      std::vector<Problem<T>> Divide(const DyV::Problem<T>& array, const size_t& size) {
        typename T::value_type pivot = array[0];
        Problem<T> divided_array1, divided_array2;
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
        std::vector<Problem<T>> divided_arrays;
        divided_arrays.emplace_back(divided_array1);
        divided_arrays.emplace_back(divided_array2);
        return divided_arrays;
      }

      /**
       * @brief Combines the solutions to the subproblems.
       * 
       * @param solution1 The solution to the first subproblem.
       * @param solution2 The solution to the second subproblem.
       * @return std::vector<int> The combined solution.
       */
      DyV::Solution<T> Combine(const DyV::Solution<T>& solution1, const DyV::Solution<T>& solution2) {
        size_t i = 0, j = 0;
        Solution<T> combined_solution;
        while (i < solution1.size() && j < solution2.size()) {
          if (solution1[i] < solution2[j]) {
            combined_solution.emplace_back(solution1[i]);
            i++;
          } else {
            combined_solution.emplace_back(solution2[j]);
            j++;
          }
        }
        while (i < solution1.size()) {
          combined_solution.emplace_back(solution1[i]);
          i++;
        }
        while (j < solution2.size()) {
          combined_solution.emplace_back(solution2[j]);
          j++;
        }
        return combined_solution;
      }

      /**
       * @brief Returns the recurrence of the algorithm.
       * 
       * @return std::string The recurrence of the algorithm.
       */
      std::string getRecurrence(void) {
        return "T(n) <= T(pn) + T((1-p)n) + O(n)";
      }
  };
}