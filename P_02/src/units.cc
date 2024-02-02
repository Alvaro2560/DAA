/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file tape.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the classes InputUnit and OutputUnit.
 * @version 0.1
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/units.h"

/**
 * @brief Construct a new InputUnit::InputUnit object
 * 
 * @param tape 
 */
InputUnit::InputUnit(const std::vector<int>& tape) {
  tape_ = tape;
  head_ = 0;
}

/**
 * @brief Process the input unit.
 * 
 * @return int 
 */
int InputUnit::process(void) {
  return tape_[head_++];
}

/**
 * @brief Construct a new OutputUnit::OutputUnit object
 * 
 */
OutputUnit::OutputUnit(void) {
  head_ = 0;
}

/**
 * @brief Process the output unit.
 * 
 * @return int 
 */
void OutputUnit::process(const int& data) {
  tape_.emplace_back(data);
}