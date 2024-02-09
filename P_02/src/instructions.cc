/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file instructions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the instructions classes.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/instructions.h"
#include "../include/units.h"

#include <iostream>

/**
 * @brief Construct a new LOAD::LOAD object
 * 
 * @param operand 
 */
LOAD::LOAD(const int& operand) {
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int LOAD::execute(int* data_memory) {
  data_memory[0] = data_memory[operand_];
  return 0;
}

/**
 * @brief Construct a new STORE::STORE object
 * 
 * @param operand 
 */
STORE::STORE(const int& operand) {
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int STORE::execute(int* data_memory) {
  data_memory[operand_] = data_memory[0];
  return 0;
}

/**
 * @brief Construct a new ADD::ADD object
 * 
 * @param addressing_mode 
 * @param operand 
 */
ADD::ADD(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int ADD::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0] += operand_;
      break;
    case DIRECT:
      data_memory[0] += data_memory[operand_];
      break;
    case INDIRECT:
      data_memory[0] += data_memory[data_memory[operand_]];
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new SUB::SUB object
 * 
 * @param addressing_mode 
 * @param operand 
 */
SUB::SUB(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int SUB::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0] -= operand_;
      break;
    case DIRECT:
      data_memory[0] -= data_memory[operand_];
      break;
    case INDIRECT:
      data_memory[0] -= data_memory[data_memory[operand_]];
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new MUL::MUL object
 * 
 * @param addressing_mode 
 * @param operand 
 */
MUL::MUL(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int MUL::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0] *= operand_;
      break;
    case DIRECT:
      data_memory[0] *= data_memory[operand_];
      break;
    case INDIRECT:
      data_memory[0] *= data_memory[data_memory[operand_]];
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new DIV::DIV object
 * 
 * @param addressing_mode 
 * @param operand 
 */
DIV::DIV(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int DIV::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0] /= operand_;
      break;
    case DIRECT:
      data_memory[0] /= data_memory[operand_];
      break;
    case INDIRECT:
      data_memory[0] /= data_memory[data_memory[operand_]];
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new READ::READ object
 * 
 * @param addressing_mode 
 * @param operand 
 */
READ::READ(const AddressingMode& addressing_mode, const int& operand, InputUnit* input_unit) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
  input_unit_ = input_unit;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 * @param input 
 */
int READ::execute(int* data_memory) {
  switch (addressing_mode_) {
    case DIRECT:
      data_memory[operand_] = input_unit_->process();
      break;
    case INDIRECT:
      data_memory[data_memory[operand_]] = input_unit_->process();
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode.");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new WRITE::WRITE object
 * 
 * @param addressing_mode 
 * @param operand 
 */
WRITE::WRITE(const AddressingMode& addressing_mode, const int& operand, OutputUnit* output_unit) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
  output_unit_ = output_unit;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int WRITE::execute(int* data_memory) {
  switch (addressing_mode_) {
    case DIRECT:
      output_unit_->process(data_memory[operand_]);
      break;
    case INDIRECT:
      output_unit_->process(data_memory[data_memory[operand_]]);
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode.");
      break;
  }
  return 0;
}

/**
 * @brief Construct a new JUMP::JUMP object
 * 
 * @param label 
 * @param program_counter 
 * @param labels 
 */
JUMP::JUMP(Instruction** program_counter, const std::string& label,
           std::unordered_map<std::string, Instruction*>& labels) 
           : program_counter_(program_counter), label_(label), labels_(labels) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int JUMP::execute(int* data_memory) {
  program_counter_ = &labels_[label_];
  return 0;
}

/**
 * @brief Construct a new JZERO::JZERO object
 * 
 * @param label 
 * @param program_counter 
 * @param labels 
 */
JZERO::JZERO(Instruction** program_counter, const std::string& label, 
             std::unordered_map<std::string, Instruction*>& labels) 
             : JUMP(program_counter, label, labels) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 * @return int 
 */
int JZERO::execute(int* data_memory) {
  if (data_memory[0] == 0) {
    program_counter_ = &labels_[label_];
  }
  return 0;
}

/**
 * @brief Construct a new JGTZ::JGTZ object
 * 
 * @param label 
 * @param program_counter 
 * @param labels 
 */
JGTZ::JGTZ(Instruction** program_counter, const std::string& label, 
           std::unordered_map<std::string, Instruction*>& labels) 
           : JUMP(program_counter, label, labels) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 * @return int 
 */
int JGTZ::execute(int* data_memory) {
  if (data_memory[0] > 0) {
    program_counter_ = &labels_[label_];
  }
  return 0;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int HALT::execute(int* data_memory) {
  return -1;
}