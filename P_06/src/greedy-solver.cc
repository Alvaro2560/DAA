/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file greedy-solver.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Greedy.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/greedy-solver.h"

#include <iostream>

/**
 * @brief Runs the greedy algorithm to solve the graph.
 * 
 * @param graph Graph to solve.
 * @return Solution Solution to the graph.
 */
Solution Greedy::RunAlgorithm(Graph* graph) {
  Node* start_node = graph->getFirstNode();
  Node* current_node = graph->getFirstNode();
  current_node->setVisited();
  std::vector<Node*> solution;
  solution.emplace_back(current_node);
  int total_cost = 0;
  while (!graph->allNodesVisited()) {
    Node* next_node = graph->getLowestNeighbour(current_node);
    if (next_node == nullptr) {
      break;
    }
    total_cost += graph->getWeight(current_node, next_node);
    next_node->setVisited();
    solution.emplace_back(next_node);
    current_node = next_node;
  }
  solution.emplace_back(start_node);
  total_cost += graph->getWeight(current_node, start_node);
  return Solution(solution, total_cost);
}