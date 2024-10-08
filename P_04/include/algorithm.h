/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file algorithm.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Algorithm.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "problem.h"
#include "solution.h"

#include <string>
#include <vector>

/**
 * @brief Class that acts as a base for the Divide and Conquer algorithms.
 * 
 */
template <typename T>
class Algorithm {
  public:
    /**
     * @brief Solves the problem using the Divide and Conquer paradigm.
     * 
     * @param array The problem to solve.
     * @param size The size of the problem.
     * @param recursion_level Level of the recursion tree.
     * @return DyV::Solution<T> The solution to the problem.
     */
    DyV::Solution<T> Solve(const DyV::Problem<T>& array, const size_t& size, int recursion_level = 0) {
      total_calls_++;
      if (recursion_level > max_depth_) {
        max_depth_ = recursion_level;
      }
      if (Small(array)) {
        return SolveSmall(array);
      } else {
        std::vector<DyV::Problem<T>> subproblems = Divide(array, size);
        std::vector<DyV::Solution<T>> solutions;
        // Solve the subproblems.
        for (size_t i = 0; i < subproblems.size(); i++) {
          solutions.emplace_back(DyV::Solution<T>(Solve(subproblems[i], subproblems[i].size(), recursion_level + 1)));
        }
        DyV::Solution<T> solution = solutions[0];
        // Combine the solutions.
        for (size_t i = 1; i < solutions.size(); i++) {
          solution = Combine(solution, solutions[i]);
        }
        return solution;
      }
    }

    /**
     * @brief Returns the recurrence of the algorithm.
     * 
     * @return std::string The recurrence of the algorithm.
     */
    std::string getRecurrence(void) {
      std::string recurrence = "T(n) <= ";
      recurrence += a_;
      recurrence += "T(";
      recurrence += b_;
      recurrence += ") + ";
      recurrence += c_;
      return recurrence;
    }

    /**
     * @brief Returns the maximum recursion level of the algorithm.
     * 
     * @return int The maximum recursion level of the algorithm.
     */
    int getMaxRecursionLevel(void) {
      return max_depth_;
    }

    /**
     * @brief Returns the total calls of the algorithm.
     * 
     * @return int The total calls of the algorithm.
     */
    int getTotalCalls(void) {
      return total_calls_;
    }
  protected:
    virtual bool Small(const DyV::Problem<T>& array) = 0;
    virtual DyV::Solution<T> SolveSmall(const DyV::Problem<T>& array) = 0;
    virtual std::vector<DyV::Problem<T>> Divide(const DyV::Problem<T>& array, const size_t& size) = 0;
    virtual DyV::Solution<T> Combine(const DyV::Solution<T>& solution1, const DyV::Solution<T>& solution2) = 0;
  protected:
    std::string a_;
    std::string b_;
    std::string c_;
    int max_depth_;
    int total_calls_;
};