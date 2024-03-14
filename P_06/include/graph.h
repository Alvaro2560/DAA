/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file graph.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Graph.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "node.h"

#include <unordered_set>
#include <vector>
#include <unordered_map>

class Graph {
  public:
    Graph(void) = default;
    void AddNode(Node* node);
    void AddEdge(Node* node1, Node* node2, int weight);
    std::unordered_set<Node*> get_nodes(void) const;
    std::vector<std::pair<Node*, int>> get_edges(Node* node) const;
    Node* get_first_node(void);
    Node* get_lowest_neighbour(Node* node);
    bool all_nodes_visited(void) const;
    void Print(void);
    ~Graph(void);
  private:
    std::unordered_set<Node*> nodes_;
    std::unordered_map<Node*, std::vector<std::pair<Node*, int>>> edges_;
};