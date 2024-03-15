/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file brute-force-solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class BruteForce.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "solver.h"

/**
 * @brief Class that represents a solver for a graph using the brute force algorithm.
 */
class BruteForce : public Solver {
  public:
    BruteForce(void) = default;
    ~BruteForce(void) = default;
  private:
    Solution RunAlgorithm(Graph* graph) override;
    void permute(std::vector<Node*>& nodes, size_t left, size_t right, Solution& best_solution, Graph* graph);
    int calculate_cost(std::vector<Node*>& nodes, Graph* graph);
};