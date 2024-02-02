/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file alcu.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the class ALCU.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/alcu.h"
#include "../include/instructions.h"

#include <typeinfo>

/**
 * @brief Construct a new ALCU::ALCU object
 * 
 * @param data_memory 
 */
ALCU::ALCU(std::vector<Instruction*>& program_memory) {
  program_counter_ = &program_memory[0];
}

/**
 * @brief Run the ALCU.
 * 
 * @return true 
 * @return false 
 */
void ALCU::run(std::vector<int>& data_memory) {
  while (typeid(*(*program_counter_)) != typeid(HALT)) {
    processInstruction(data_memory);
  }
}

/**
 * @brief Process the instruction.
 * 
 * @param program_memory 
 * @param data_memory 
 */
void ALCU::processInstruction(std::vector<int>& data_memory) {
  (*program_counter_)->execute(data_memory);
  program_counter_++;
}