/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file binary-search.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class BinarySearch.
 * @version 0.1
 * @since Mar 9 2024
 * 
 * @see https://stackoverflow.com/questions/9811235/best-way-to-split-a-vector-into-two-smaller-arrays
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
  class BinarySearch : public Algorithm<T, U, V> {
    public:
      BinarySearch(void) {
        Algorithm<T, U, V>::a_ = "2";
        Algorithm<T, U, V>::b_ = "n/2";
        Algorithm<T, U, V>::c_ = "O(n)";
        index_ = 0;
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
      DyV::Solution<V> SolveSmall(const DyV::Problem<T>& array, const U& key) {
        if (array[0] == key) {
          return Solution<V>(index_);
        } else {
          return Solution<V>(-1);
        }
      }

      /**
       * @brief Divides the problem into subproblems.
       * 
       * @param array The array to divide.
       * @param key The key to divide the array.
       * @return std::vector<DyV::Problem<T>> The divided array.
       */
      std::vector<DyV::Problem<T>> Divide(const DyV::Problem<T>& array, const U& key) {
        std::vector<DyV::Problem<T>> subproblem;
        std::vector<int> problem = array.getData();
        std::size_t const half_size = problem.size() / 2;
        std::vector<int> split_lo(problem.begin(), problem.begin() + half_size);
        std::vector<int> split_hi(problem.begin() + half_size, problem.end());
        if (split_lo[split_lo.size() - 1] > key) {
          subproblem.emplace_back(DyV::Problem<T>(split_lo));
          index_ += split_lo.size();
        } else {
          subproblem.emplace_back(DyV::Problem<T>(split_hi));
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
    private:
      int index_;
  };
}