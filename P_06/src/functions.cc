/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definitions of the functions used on the program.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

#include <fstream>

std::vector<std::string> ReadFile(const std::string& file_name) {
  std::vector<std::string> file_content;
  std::ifstream file(file_name);
  std::string word;
  while (file >> word) {
    file_content.emplace_back(word);
  }
  return file_content;
}

Graph* CreateGraph(const std::vector<std::string>& file_content) {
  // int nodes = std::stoi(file_content[0]);
  Graph* graph = new Graph();
  for (size_t i = 1; i < file_content.size(); i += 3) {
    std::string node1ID = file_content[i];
    std::string node2ID = file_content[i + 1];
    int weight = std::stoi(file_content[i + 2]);
    Node* node1 = new Node(node1ID);
    Node* node2 = new Node(node2ID);
    graph->AddNode(node1);
    graph->AddNode(node2);
    graph->AddEdge(node1, node2, weight);
    graph->AddEdge(node2, node1, weight);
  }
  // TODO: Check if all nodes are conected with each other
  return graph;
}