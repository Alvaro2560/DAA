/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file units.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the InputUnit class.
 * @version 1.0
 * @since Feb 18 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/input-unit.h"

/**
 * @brief Construct a new InputUnit::InputUnit object
 * 
 * @param tape The tape that the input unit will process.
 */
InputUnit::InputUnit(const std::vector<int>& tape) {
  tape_ = new int[tape.size()];
  for (size_t i = 0; i < tape.size(); i++) {
    tape_[i] = tape[i];
  }
  head_ = &tape_[0];
}

/**
 * @brief Process the input unit.
 * 
 * @return int The value of the tape at the current position.
 */
int InputUnit::process(void) {
  return *head_++;
}

/**
 * @brief Destroy the InputUnit::InputUnit object
 * 
 */
InputUnit::~InputUnit(void) {
  delete[] tape_;
}