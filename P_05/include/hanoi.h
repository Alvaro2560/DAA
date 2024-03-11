/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file hanoi-solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class HanoiSolver.
 * @version 0.1
 * @since Mar 9 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.h"
#include "hanoi.h"

namespace DyV {
  /**
   * @brief Class that executes the HanoiSolver algorithm.
   * 
   */
  template <typename T, typename U, typename V>
  class HanoiSolver : public Algorithm<T, U, V> {
    public:
      HanoiSolver(void) {
        Algorithm<T, U, V>::a_ = "T(pn) + ";
        Algorithm<T, U, V>::b_ = "2T((1-p)n) + ";
        Algorithm<T, U, V>::c_ = "O(n)";
        steps_ = 0;
      };
    private:
      /**
       * @brief Checks if the problem is small enough to be solved.
       * 
       * @param problem The number of disks.
       * @return true If the problem is small enough to be solved.
       * @return false If the problem is not small enough to be solved.
       */
      bool Small(const DyV::Problem<T>& problem) {
        if (problem.getData() == 0) {
          return true;
        } else {
          return false;
        }
      }

      /**
       * @brief Solves the problem if it is small enough.
       * 
       * @param problem The problem to solve.
       * @param key Key to solve the problem.
       * @return DyV::Solution<V> The solution to the problem.
       */
      DyV::Solution<V> SolveSmall(const DyV::Problem<T>& problem, const U& key) {
        DyV::Solution<V> solution;
        solution.setData(steps_);
        return solution;
      }

      /**
       * @brief Divides the problem into subproblems.
       * 
       * @param problem The problem to divide.
       * @param key Key to divide the problem.
       * @return std::vector<DyV::Problem<T>> The subproblems.
       */
      std::vector<DyV::Problem<T>> Divide(const DyV::Problem<T>& problem, const U& key) {
        std::vector<DyV::Problem<T>> subproblems;
        subproblems.emplace_back(DyV::Problem<T>(problem.getData() - 1));
        subproblems.emplace_back(DyV::Problem<T>(problem.getData() - 1));
        ++steps_;
        return subproblems;
      }

      /**
       * @brief Combines the solutions of the subproblems.
       * 
       * @param solution1 The first solution.
       * @param solution2 The second solution.
       * @return DyV::Solution<V> The combined solution.
       */
      DyV::Solution<V> Combine(const DyV::Solution<V>& solution1, const DyV::Solution<V>& solution2) {
        DyV::Solution<V> solution;
        solution.setData(steps_);
        return solution;
      }
    private:
      int steps_;
  };
}