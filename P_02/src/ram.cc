/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the class RAM.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/ram.h"
#include "../include/alcu.h"
#include "../include/units.h"
#include "../include/instructions.h"

/**
 * @brief Construct a new RAM::RAM object
 * 
 * @param input_tape 
 */
RAM::RAM(const std::vector<std::string>& instructions, 
         const std::vector<int>& input_tape) {
  input_unit_ = new InputUnit(input_tape);
  output_unit_ = new OutputUnit();
  data_memory_.emplace_back(0);
  alcu_ = new ALCU(program_memory_);
  for (const auto& instruction : instructions) {
    program_memory_.emplace_back(new Instruction(instruction));
  }
}

/**
 * @brief Run the RAM.
 */
void RAM::run(void) {
  alcu_->run(data_memory_);
}