/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file dynamic-programming-solver.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Dynamic.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/dynamic-programming-solver.h"

/**
 * @brief Runs the dynamic programming algorithm to solve the TSP.
 * 
 * @param graph Graph to solve.
 * @return Solution Solution to the TSP.
 */
Solution DynamicProgramming::RunAlgorithm(Graph* graph) {
  std::vector<Node*> nodes = GetNodesVector(graph);
  int num_nodes = nodes.size();
  // Creamos una tabla para almacenar los subproblemas resueltos.
  std::vector<std::vector<int>> dp(1 << num_nodes, std::vector<int>(num_nodes, -1));
  // Llamamos a la función recursiva para calcular la distancia mínima.
  int min_distance = MinimumDistance(1, 0, num_nodes, nodes, dp, graph);
  // Reconstruir el camino mínimo.
  std::vector<Node*> path;
  path.emplace_back(nodes[0]);
  int bitmask = 1;
  int current_node = 0;
  for (int i = 0; i < num_nodes - 1; ++i) {
    int next_node = -1;
    for (int j = 0; j < num_nodes; ++j) {
      if (!(bitmask & (1 << j)) && (next_node == -1 || dp[bitmask][current_node] + // Verificar si el nodo j es candidato.
            graph->getWeight(nodes[current_node], nodes[j]) == dp[bitmask | (1 << j)][j])) { 
        next_node = j;
      }
    }
    path.emplace_back(nodes[next_node]);
    bitmask |= (1 << next_node);
    current_node = next_node;
  }
  path.emplace_back(nodes[0]); // Volvemos al nodo inicial para completar el ciclo.
  return std::make_pair(path, min_distance);
}

/**
 * @brief Calculates the minimum distance to visit all the nodes starting from the current node.
 * 
 * @param bitmask Bitmask to store the visited nodes.
 * @param current Current node.
 * @param num_nodes Number of nodes in the graph.
 * @param nodes Vector of nodes in the graph.
 * @param dp Table to store the subproblems solved.
 * @param graph Graph to solve.
 * @return int Minimum distance to visit all the nodes starting from the current node.
 */
int DynamicProgramming::MinimumDistance(int bitmask, int current, int num_nodes, 
                                        const std::vector<Node*>& nodes, std::vector<std::vector<int>>& dp, Graph* graph) {
  if (bitmask == (1 << num_nodes) - 1) { // Si ya hemos visitado todos los nodos.
    return graph->getWeight(nodes[current], nodes[0]); // Volvemos al nodo inicial.
  }
  if (dp[bitmask][current] != -1) { // Si ya hemos calculado esta subruta.
    return dp[bitmask][current];
  }
  int min_distance = INT_MAX;
  for (int next = 0; next < num_nodes; ++next) {
    if (!(bitmask & (1 << next))) { // Si el próximo nodo no ha sido visitado.
      int distance = graph->getWeight(nodes[current], nodes[next]) + 
                     MinimumDistance(bitmask | (1 << next), next, num_nodes, nodes, dp, graph);
      min_distance = std::min(min_distance, distance);
    }
  }
  return dp[bitmask][current] = min_distance;
}

/**
 * @brief Returns the nodes of the graph in a vector.
 * 
 * @param graph Graph to solve.
 * @return std::vector<Node*> Vector of nodes in the graph.
 */
std::vector<Node*> DynamicProgramming::GetNodesVector(Graph* graph) const {
  std::vector<Node*> nodes;
  for (Node* node : graph->getNodes()) {
    nodes.emplace_back(node);
  }
  return nodes;
}