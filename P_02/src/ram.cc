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
RAM::RAM(const std::vector<int>& input_tape,
         const std::vector<Instruction*>& instructions,
         const std::unordered_map<std::string, Instruction*>& labels) {
  input_unit_ = new InputUnit(input_tape);
  output_unit_ = new OutputUnit();
  data_memory_.emplace_back(0);
  program_memory_ = instructions;
  alcu_ = new ALCU(program_memory_, input_unit_, output_unit_);
}

/**
 * @brief Run the RAM.
 */
void RAM::run(void) {
  alcu_->run(data_memory_);
}

/**
 * @brief Destroy the RAM::RAM object
 */
RAM::~RAM(void) {
  delete alcu_;
  delete input_unit_;
  delete output_unit_;
}