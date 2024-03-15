/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file dynamic-porgramming-solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Dynamic.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "solver.h"

#include <map>
#include <vector>
#include <algorithm>
#include <climits>

/**
 * @brief Class that represents a dynamic programming solver for a graph.
 */
class DynamicProgramming : public Solver {
  public:
    DynamicProgramming(void) = default;
    ~DynamicProgramming(void) = default;
  private:
    Solution RunAlgorithm(Graph* graph) override;
    int MinimumDistance(int bitmask, int current, int num_nodes, const std::vector<Node*>& nodes, 
                        std::vector<std::vector<int>>& dp, Graph* graph);
    std::vector<Node*> GetNodesVector(Graph* graph) const;
};