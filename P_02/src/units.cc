/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file units.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definitions of the InputUnit and OutputUnit classes.
 * @version 0.1
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/units.h"

#include <vector>
#include <iostream>
#include <limits>

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

/**
 * @brief Construct a new OutputUnit::OutputUnit object
 * 
 */
OutputUnit::OutputUnit(void) {
  tape_ = new int[1];
  size_ = 1;
}

/**
 * @brief Process the output unit.
 * 
 * @param data Data to be processed.
 */
void OutputUnit::process(const int& data) {
  size_++;
  int* new_tape = new int[size_];
  for (size_t i = 0; i < size_ - 1; i++) {
    new_tape[i] = tape_[i];
  }
  tape_ = new int[size_];
  for (size_t i = 0; i < size_; i++) {
    tape_[i] = new_tape[i];
  }
  delete[] new_tape;
  tape_[size_ - 1] = data;
}

/**
 * @brief Get the tape.
 * 
 * @return int* The tape.
 */
int* OutputUnit::getTape(void) {
  return tape_;
}

/**
 * @brief Get the size of the tape.
 * 
 * @return size_t The size of the tape.
 */
size_t OutputUnit::getSize(void) {
  return size_;
}

/**
 * @brief Print the tape.
 * 
 */
void OutputUnit::print(void) {
  for (size_t i = 0; i < size_; i++) {
    std::cout << tape_[i] << std::endl;
  }
}

/**
 * @brief Destroy the OutputUnit::OutputUnit object
 * 
 */
OutputUnit::~OutputUnit(void) {
  delete[] tape_;
}