/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Solver.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "graph.h"

typedef std::pair<std::vector<Node*>, int> Solution;

/**
 * @brief Class that represents a solver for a graph.
 */
class Solver {
  public:
    Solver(void) = default;
    Solution Solve(Graph* graph) {
      return RunAlgorithm(graph);
    }
    ~Solver(void) = default;
  protected:
    virtual Solution RunAlgorithm(Graph* graph) = 0;
};