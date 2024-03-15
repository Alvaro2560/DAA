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

/**
 * @brief Class that represents a graph.
 */
class Graph {
  public:
    Graph(void) = default;
    void addNode(const std::string& id);
    void addEdge(const std::string& node_id_1, const std::string& node_id_2, int weight);
    std::unordered_set<Node*> getNodes(void) const;
    std::vector<std::pair<Node*, int>> getEdges(Node* node) const;
    Node* getFirstNode(void);
    Node* getLowestNeighbour(Node* node);
    Node* getNodeById(const std::string& id);
    int getWeight(Node* node_1, Node* node_2);
    std::vector<Node*> getVisitedNodes(void) const;
    bool allNodesVisited(void) const;
    ~Graph(void);
  private:
    std::unordered_set<Node*> nodes_;
    std::unordered_map<Node*, std::vector<std::pair<Node*, int>>> edges_;
};