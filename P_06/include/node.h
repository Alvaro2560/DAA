/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file node.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Node.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>

class Node {
  public:
    Node(std::string id) : id_(id), visited_(false) { };
    std::string get_id(void) const;
    bool is_visited(void) const;
    void set_visited(void);
    ~Node(void) = default;
  private:
    std::string id_;
    bool visited_;
};