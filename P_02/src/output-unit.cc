/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file units.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of OutputUnit class.
 * @version 1.0
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/output-unit.h"

#include <fstream>

/**
 * @brief Construct a new OutputUnit::OutputUnit object
 * 
 */
OutputUnit::OutputUnit(const std::string& file_name) {
  tape_ = new int[1];
  size_ = 1;
  file_name_ = file_name;
}

/**
 * @brief Process the output unit.
 * 
 * @param data Data to be processed.
 */
void OutputUnit::process(const int& data) {
  if (size_ == 1) {
    tape_[0] = data;
  } else {
    int* new_tape = new int[size_];
    for (size_t i = 0; i < size_ - 1; i++) {
      new_tape[i] = tape_[i];
    }
    new_tape[size_ - 1] = data;
    delete[] tape_;
    tape_ = new_tape;
  }
  ++size_;
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
 * @brief Write the tape to a file.
 * 
 */
void OutputUnit::write(void) {
  std::ofstream file(file_name_);
  if (file.is_open()) {
    for (size_t i = 0; i < size_ - 1; i++) {
      file << tape_[i] << std::endl;
    }
  } else {
    throw std::runtime_error("Unable to open output file.");
  }
  file.close();
}

/**
 * @brief Destroy the OutputUnit::OutputUnit object
 * 
 */
OutputUnit::~OutputUnit(void) {
  delete[] tape_;
}