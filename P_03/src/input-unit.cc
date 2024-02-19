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
  head_ = 0;
  size_ = tape.size();
}

/**
 * @brief Process the input unit.
 * 
 * @return int The value of the tape at the current position.
 */
int InputUnit::process(void) {
  return tape_[head_++];
}

/**
 * @brief Get the tape of the input unit.
 * 
 * @return int* The tape of the input unit.
 */
int* InputUnit::getTape(void) {
  return tape_;
}

/**
 * @brief Get the head of the input unit.
 * 
 * @return size_t The head of the input unit.
 */
size_t InputUnit::getHead(void) {
  return head_;
}

/**
 * @brief Get the size of the tape.
 * 
 * @return size_t The size of the tape.
 */
size_t InputUnit::getSize(void) {
  return size_;
}

/**
 * @brief Destroy the InputUnit::InputUnit object
 * 
 */
InputUnit::~InputUnit(void) {
  delete[] tape_;
}