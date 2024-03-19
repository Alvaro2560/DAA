/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file brute-force-solver.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class BruteForce.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/brute-force-solver.h"

#include <climits>

/**
 * @brief Runs the brute force algorithm to solve the TSP.
 * 
 * @param graph Graph to solve.
 * @return Solution Solution to the TSP.
 */
Solution BruteForce::RunAlgorithm(Graph* graph) {
  std::vector<Node*> nodes;
  for (auto node : graph->getNodes()) {
    nodes.emplace_back(node);
  }
  Solution best_solution({}, INT_MAX);
  permute(nodes, 0, nodes.size() - 1, best_solution, graph);
  best_solution.first.emplace_back(best_solution.first.front());
  return best_solution;
}

/**
 * @brief Permutes the nodes to find the best solution.
 * 
 * @param nodes Nodes to permute.
 * @param left Left index of the permutation.
 * @param right Right index of the permutation.
 * @param best_solution Best solution found so far.
 * @param graph Graph to solve.
 */
void BruteForce::permute(std::vector<Node*>& nodes, size_t left, size_t right, Solution& best_solution, Graph* graph) {
  if (left == right) {
    int current_cost = calculate_cost(nodes, graph);
    if (current_cost < best_solution.second) {
      best_solution = Solution(nodes, current_cost);
    }
  } else {
    for (size_t i = left; i <= right; ++i) {
      std::swap(nodes[left], nodes[i]);
      permute(nodes, left + 1, right, best_solution, graph);
      std::swap(nodes[left], nodes[i]);
    }
  }
}

/**
 * @brief Calculates the cost of a path.
 * 
 * @param nodes Nodes of the path.
 * @param graph Graph to solve.
 * @return int Cost of the path.
 */
int BruteForce::calculate_cost(std::vector<Node*>& nodes, Graph* graph) {
  int cost = 0;
  for (size_t i = 0; i < nodes.size() - 1; ++i) {
    cost += graph->getWeight(nodes[i], nodes[i + 1]);
  }
  cost += graph->getWeight(nodes.back(), nodes.front());
  return cost;
}