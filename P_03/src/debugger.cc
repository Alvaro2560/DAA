/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file debugger.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the class Debugger.
 * @version 0.1
 * @since Feb 12 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/debugger.h"
#include "../include/ram.h"
#include "../include/input-unit.h"
#include "../include/output-unit.h"
#include "../include/instructions.h"

#include <typeinfo>

int Debugger::instruction_counter_ = 0;

/**
 * @brief Increment the instruction counter.
 */
void Debugger::increment(void) {
  instruction_counter_++;
}

/**
 * @brief Print the number of instructions executed.
 */
void Debugger::printInstructions(void) {
  std::cout << "\nInstructions executed: " << instruction_counter_ << std::endl;
}

/**
 * @brief Print the information of the RAM.
 * 
 * @param ram RAM to print the information of.
 */
void Debugger::printInfo(const RAM& ram) {
  std::cout << "Program counter: " << ram.program_memory_[ram.program_counter_]->toString() << std::endl;
  std::cout << "\nData memory: " << std::endl;
  for (size_t i = 0; i < ram.data_memory_.size(); i++) {
    std::cout << "R" << i << ": ";
    for (size_t j = 0; j < ram.data_memory_[i].size(); j++) {
      std::cout << ram.data_memory_[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "\nInput unit: ";
  int* tape = ram.input_unit_->getTape();
  size_t size = ram.input_unit_->getSize();
  for (size_t i = 0; i < size; i++) {
    std::cout << tape[i] << " ";
  }
  std::cout << std::endl;
  size_t head = ram.input_unit_->getHead();
  std::cout << "            ";
  for (size_t i = 0; i < head; i++) {
    std::cout << "  ";
  }
  std::cout << "^" << std::endl;
  std::cout << "\nOutput unit: ";
  tape = ram.output_unit_->getTape();
  size = ram.output_unit_->getSize();
  for (size_t i = 0; i < size - 1; i++) {
    std::cout << tape[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "           ";
  for (size_t i = 0; i < size; i++) {
    std::cout << "  ";
  }
  std::cout << "^" << std::endl;
  std::cout << std::endl;
}