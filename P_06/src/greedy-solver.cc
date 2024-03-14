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

void Greedy::RunAlgorithm(Graph* graph) {
  Node* current_node = graph->get_first_node();
  current_node->set_visited();
  std::vector<Node*> solution;
  solution.emplace_back(current_node);
  std::cout << current_node->get_id() << "\n";
  while (!graph->all_nodes_visited()) {
    Node* next_node = graph->get_lowest_neighbour(current_node);
    next_node->set_visited();
    solution.emplace_back(next_node);
    current_node = next_node;
  }
  for (auto node : solution) {
    std::cout << node->get_id() << " ";
  }
  std::cout << std::endl;
}