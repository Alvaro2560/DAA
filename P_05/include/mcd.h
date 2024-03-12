/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file binary-search.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class MCD.
 * @version 0.1
 * @since Mar 12 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.h"

namespace DyV {
  /**
   * @brief Class that executes the BinarySearch algorithm.
   * 
   */
  template <typename T, typename U, typename V>
  class MCD : public Algorithm<T, U, V> {
    public:
      MCD(void) {
        Algorithm<T, U, V>::a_ = "1";
        Algorithm<T, U, V>::b_ = "n - 1";
        Algorithm<T, U, V>::c_ = "O(1)";
      };
    private:
      /**
       * @brief Checks if the array is small enough to be solved.
       * 
       * @param array The array to check.
       * @return true If the array is small enough to be solved.
       * @return false If the array is not small enough to be solved.
       */
      bool Small(const DyV::Problem<T>& problem) {
        if (problem.getData().first == problem.getData().second) {
          return true;
        } else {
          return false;
        }
      }

      /**
       * @brief Solves the problem for small arrays.
       * 
       * @param array The array to solve.
       * @return std::vector<int> The solution to the problem.
       */
      DyV::Solution<V> SolveSmall(const DyV::Problem<T>& problem, const U& key) {
        return Solution<V>(problem.getData().first);
      }

      /**
       * @brief Divides the problem into subproblems.
       * 
       * @param array The array to divide.
       * @param key The key to divide the array.
       * @return std::vector<DyV::Problem<T>> The divided array.
       */
      std::vector<DyV::Problem<T>> Divide(const DyV::Problem<T>& problem, const U& key) {
        std::vector<DyV::Problem<T>> subproblem;
        if (problem.getData().first > problem.getData().second) {
          subproblem.emplace_back(std::make_pair(problem.getData().first - problem.getData().second, problem.getData().second));
        } else {
          subproblem.emplace_back(std::make_pair(problem.getData().first, problem.getData().second - problem.getData().first));
        }
        return subproblem;
      }

      /**
       * @brief Combines the solutions to the subproblems.
       * 
       * @param solution1 The solution to the first subproblem.
       * @param solution2 The solution to the second subproblem.
       * @return std::vector<int> The combined solution.
       */
      DyV::Solution<V> Combine(const DyV::Solution<V>& solution1, const DyV::Solution<V>& solution2) {
        return solution1;
      }
  };
}