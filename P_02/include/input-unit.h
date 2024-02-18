/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file input-unit.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the classes InputUnit and OutputUnit.
 * @version 1.0
 * @since Feb 18 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>

/**
 * @brief Class that represents the input unit.
 */
class InputUnit {
  public:
    InputUnit(const std::vector<int>& tape);
    int process(void);
    ~InputUnit(void);
  private:
    int* tape_;
    int* head_;
};