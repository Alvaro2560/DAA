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
#include "../include/units.h"

#include <typeinfo>

/**
 * @brief Construct a new ALCU::ALCU object
 * 
 * @param data_memory 
 */
ALCU::ALCU(std::vector<Instruction*>& program_memory, BaseUnit* input_unit, BaseUnit* output_unit) {
  program_counter_ = &program_memory[0];
  input_unit_ = &input_unit;
  output_unit_ = &output_unit;
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
  if (typeid(*(*program_counter_)) == typeid(ADD) || 
      typeid(*(*program_counter_)) == typeid(SUB) || 
      typeid(*(*program_counter_)) == typeid(MUL) || 
      typeid(*(*program_counter_)) == typeid(DIV)) {
    (*program_counter_)->execute(data_memory);
  } else if (typeid(*(*program_counter_)) == typeid(LOAD) || 
             typeid(*(*program_counter_)) == typeid(STORE)) {
    (*program_counter_)->execute(data_memory);
  // } else if (typeid(*(*program_counter_)) == typeid(JUMP) || 
  //            typeid(*(*program_counter_)) == typeid(JZERO) || 
  //            typeid(*(*program_counter_)) == typeid(JGTZ)) {
  //   (*program_counter_)->execute(data_memory, program_counter_);
  // }
  } else if (typeid(*(*program_counter_)) == typeid(READ)) {
    (*program_counter_)->execute(data_memory, (*input_unit_)->process());
  } else if (typeid(*(*program_counter_)) == typeid(WRITE)) {
    (*output_unit_)->process((*program_counter_)->execute(data_memory));
  }
  program_counter_++;
}

/**
 * @brief Destroy the ALCU::ALCU object
 * 
 */
ALCU::~ALCU(void) {
  delete input_unit_;
  delete output_unit_;
}