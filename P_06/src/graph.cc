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

/**
 * @brief Adds a node to the graph.
 * 
 * @param id ID of the node.
 */
void Graph::addNode(const std::string& id) {
  if (getNodeById(id) != nullptr) {
    return;
  }
  Node* node = new Node(id);
  nodes_.insert(node);
  edges_[node] = std::vector<std::pair<Node*, int>>();
}

/**
 * @brief Adds an edge to the graph.
 * 
 * @param node_id_1 ID of the first node.
 * @param node_id_2 ID of the second node.
 * @param weight Weight of the edge.
 */
void Graph::addEdge(const std::string& node_id_1, const std::string& node_id_2, int weight) {
  if (getNodeById(node_id_1) == nullptr) {
    addNode(node_id_1);
  }
  if (getNodeById(node_id_2) == nullptr) {
    addNode(node_id_2);
  }
  edges_[getNodeById(node_id_1)].emplace_back(std::make_pair(getNodeById(node_id_2), weight));
}

/**
 * @brief Returns the nodes of the graph.
 * 
 * @return std::unordered_set<Node*> Nodes of the graph.
 */
std::unordered_set<Node*> Graph::getNodes(void) const {
  return nodes_;
}

/**
 * @brief Returns the edges of a node.
 * 
 * @param node Node to get the edges from.
 * @return std::vector<std::pair<Node*, int>> Edges of the node.
 */
std::vector<std::pair<Node*, int>> Graph::getEdges(Node* node) const {
  return edges_.at(node);
}

/**
 * @brief Returns the first node of the graph.
 * 
 * @return Node* First node of the graph.
 */
Node* Graph::getFirstNode(void) {
  return *nodes_.begin();
}

/**
 * @brief Returns the lowest neighbour of a node.
 * 
 * @param node Node to get the lowest neighbour from.
 * @return Node* Lowest neighbour of the node.
 */
Node* Graph::getLowestNeighbour(Node* node) {
  std::vector<std::pair<Node*, int>> neighbours = edges_.at(node);
  Node* lowest_neighbour = nullptr;
  int lowest_weight = INT_MAX;
  for (auto neighbour : neighbours) {
    if (neighbour.second < lowest_weight && !neighbour.first->isVisited()) {
      lowest_neighbour = neighbour.first;
      lowest_weight = neighbour.second;
    }
  }
  return lowest_neighbour;
}

/**
 * @brief Returns a node by its ID.
 * 
 * @param id ID of the node.
 * @return Node* Node with the given ID.
 */
Node* Graph::getNodeById(const std::string& id) {
  for (auto node : nodes_) {
    if (node->getId() == id) {
      return node;
    }
  }
  return nullptr;
}

/**
 * @brief Returns the weight of an edge.
 * 
 * @param node_1 First node of the edge.
 * @param node_2 Second node of the edge.
 * @return int Weight of the edge.
 */
int Graph::getWeight(Node* node_1, Node* node_2) {
  for (auto edge : edges_[node_1]) {
    if (edge.first == node_2) {
      return edge.second;
    }
  }
  return INT_MAX;
}

/**
 * @brief Returns the visited nodes of the graph.
 * 
 * @return std::vector<Node*> Visited nodes of the graph.
 */
std::vector<Node*> Graph::getVisitedNodes(void) const {
  std::vector<Node*> visited_nodes;
  for (auto node : nodes_) {
    if (node->isVisited()) {
      visited_nodes.emplace_back(node);
    }
  }
  return visited_nodes;
}

/**
 * @brief Returns if all the nodes of the graph have been visited.
 * 
 * @return true If all the nodes have been visited.
 * @return false If not all the nodes have been visited.
 */
bool Graph::allNodesVisited(void) const {
  for (auto node : nodes_) {
    if (!node->isVisited()) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Destroy the Graph:: Graph object
 * 
 */
Graph::~Graph(void) {
  for (auto node : nodes_) {
    delete node;
  }
}