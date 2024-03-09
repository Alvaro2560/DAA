/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file mergesort.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class MergeSort.
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
   * @brief Class that executes the MergeSort algorithm.
   * 
   */
  template <typename T, typename U, typename V>
  class MergeSort : public Algorithm<T, U, V> {
    public:
      MergeSort(void) {
        Algorithm<T, U, V>::a_ = "2";
        Algorithm<T, U, V>::b_ = "n/2";
        Algorithm<T, U, V>::c_ = "O(n)";
      };
    private:
      /**
       * @brief Checks if the array is small enough to be solved.
       * 
       * @param array The array to check.
       * @return true If the array is small enough to be solved.
       * @return false If the array is not small enough to be solved.
       */
      bool Small(const DyV::Problem<T>& array) {
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
      DyV::Solution<V> SolveSmall(const DyV::Problem<T>& array, const U& key) {
        if (array.size() == 1) {
          return Solution<V>(array.getData());
        }
        Solution<V> solution(array.getData());
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
       * @param key The key to divide the array.
       * @return std::vector<DyV::Problem<T>> The divided array.
       */
      std::vector<DyV::Problem<T>> Divide(const DyV::Problem<T>& array, const U& key) {
        Problem<T> first_half;
        Problem<T> second_half;
        size_t half = array.size() / 2;
        if (array.size() % 2 != 0) {
          half = array.size() / 2 + 1;
        }
        for (size_t i = 0; i < half; i++) {
          first_half.emplace_back(array[i]);
        }
        for (size_t i = half; i < array.size(); i++) {
          second_half.emplace_back(array[i]);
        }
        std::vector<Problem<T>> divided_arrays;
        divided_arrays.emplace_back(first_half);
        divided_arrays.emplace_back(second_half);
        return divided_arrays;
      }

      /**
       * @brief Combines the solutions to the subproblems.
       * 
       * @param solution1 The solution to the first subproblem.
       * @param solution2 The solution to the second subproblem.
       * @return std::vector<int> The combined solution.
       */
      DyV::Solution<V> Combine(const DyV::Solution<V>& solution1, const DyV::Solution<V>& solution2) {
        Solution<V> solution;
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
  };
}