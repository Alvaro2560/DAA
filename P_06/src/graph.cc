/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file graph.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Graph.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/graph.h"

#include <iostream>
#include <climits>

void Graph::AddNode(Node* node) {
  nodes_.insert(node);
}

void Graph::AddEdge(Node* node1, Node* node2, int weight) {
  edges_[node1].emplace_back(std::make_pair(node2, weight));
}

std::unordered_set<Node*> Graph::get_nodes(void) const {
  return nodes_;
}

std::vector<std::pair<Node*, int>> Graph::get_edges(Node* node) const {
  return edges_.at(node);
}

Node* Graph::get_first_node(void) {
  return *nodes_.begin();
}

Node* Graph::get_lowest_neighbour(Node* node) {
  std::vector<std::pair<Node*, int>> neighbours = edges_.at(node);
  Node* lowest_neighbour = nullptr;
  int lowest_weight = INT_MAX;
  for (auto neighbour : neighbours) {
    if (neighbour.second < lowest_weight && !neighbour.first->is_visited()) {
      lowest_neighbour = neighbour.first;
      lowest_weight = neighbour.second;
    }
  }
  std::cout << lowest_neighbour->get_id() << " (" << lowest_weight << ")" << std::endl;
  return lowest_neighbour;
}

bool Graph::all_nodes_visited(void) const {
  for (auto node : nodes_) {
    if (!node->is_visited()) {
      return false;
    }
  }
  return true;
}

void Graph::Print(void) {
  for (auto node : nodes_) {
    std::cout << "Node: " << node->get_id() << std::endl;
    for (auto edge : edges_[node]) {
      std::cout << "  -> " << edge.first->get_id() << " (" << edge.second << ")" << std::endl;
    }
  }
}

Graph::~Graph(void) {
  for (auto node : nodes_) {
    delete node;
  }
}