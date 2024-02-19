/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the RAM class.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/ram.h"
#include "../include/input-unit.h"
#include "../include/output-unit.h"
#include "../include/instructions.h"
#include "../include/debugger.h"

#include <typeinfo>

const size_t HALT_FLAG = -1;

/**
 * @brief Construct a new RAM::RAM object
 * 
 * @param instructions Instructions of the program as a vector of instructions.
 * @param input_tape Input data as a vector of ints.
 * @param labels Labels of the program as an unordered map.
 */
RAM::RAM(const std::vector<Instruction*>& instructions, 
         const std::vector<int>& input_tape,
         const std::unordered_map<std::string, size_t>& labels) {
  program_memory_ = instructions;
  input_unit_ = new InputUnit(input_tape);
  output_unit_ = new OutputUnit();
  data_memory_.resize(32);
  for (size_t i = 0; i < 32; i++) {
    data_memory_[i] = std::vector<int>();
  }
  data_memory_[0].resize(1);
  data_memory_[0][0] = 0;
  program_counter_ = 0;
  labels_ = labels;
  for (size_t i = 0; i < program_memory_.size(); i++) {
    if (typeid(*program_memory_[i]) == typeid(READ)) {
      static_cast<READ*>(program_memory_[i])->setUnit(input_unit_);
    } else if (typeid(*program_memory_[i]) == typeid(WRITE)) {
      static_cast<WRITE*>(program_memory_[i])->setUnit(output_unit_);
    }
  }
}

/**
 * @brief Run the RAM.
 * 
 * @param debug_flag Flag to indicate if the program should be run in debug mode.
 */
void RAM::run(const int& debug_flag) {
  size_t next_instruction;
  while (program_counter_ != HALT_FLAG && program_counter_ < program_memory_.size()) {
    next_instruction = program_memory_[program_counter_]->execute(data_memory_);
    if (debug_flag != 0) {
      if (debug_flag == 2) {
        Debugger::printInfo(*this);
        std::cout << "\nPress enter to continue...";
        std::cin.get();
        std::cout << "--------------------------------------------\n";
      }
      Debugger::increment();
    }
    if (next_instruction == HALT_FLAG) {
      program_counter_ = HALT_FLAG;
    } else if (next_instruction == 1) {
      program_counter_++;
    } else {
      // If the instruction is a jump, the next instruction is the one returned by the execute method.
      program_counter_ = next_instruction;
    }
  }
}

/**
 * @brief Get the Output Unit.
 * 
 * @return OutputUnit* Pointer to the OutputUnit object.
 */
OutputUnit* RAM::getOutputUnit(void) const {
  return output_unit_;
}

/**
 * @brief Destroy the RAM::RAM object
 */
RAM::~RAM(void) {
  for (size_t i = 0; i < program_memory_.size(); i++) {
    delete program_memory_[i];
  }
  delete input_unit_;
  delete output_unit_;
}