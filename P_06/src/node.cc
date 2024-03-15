/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file node.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Node.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/node.h"

/**
 * @brief Returns the id of the node.
 * 
 * @return std::string ID of the node.
 */
std::string Node::getId(void) const {
  return id_;
}

/**
 * @brief Returns if the node has been visited.
 * 
 * @return true If the node has been visited.
 * @return false If the node has not been visited.
 */
bool Node::isVisited(void) const {
  return visited_;
}

/**
 * @brief Sets the visited status of the node.
 * 
 * @param visited New visited status of the node.
 */
void Node::setVisited(bool visited) {
  visited_ = visited;
}