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
int LOAD::execute(std::vector<int>& data_memory, const int& input = 0) {
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
int STORE::execute(std::vector<int>& data_memory, const int& input = 0) {
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
int ADD::execute(std::vector<int>& data_memory, const int& input = 0) {
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
int SUB::execute(std::vector<int>& data_memory, const int& input = 0) {
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
int MUL::execute(std::vector<int>& data_memory, const int& input = 0) {
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
int DIV::execute(std::vector<int>& data_memory, const int& input = 0) {
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
READ::READ(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 * @param input 
 */
int READ::execute(std::vector<int>& data_memory, const int& input = 0) {
  switch (addressing_mode_) {
    case DIRECT:
      data_memory[operand_] = input;
      break;
    case INDIRECT:
      data_memory[data_memory[operand_]] = input;
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
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
WRITE::WRITE(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int WRITE::execute(std::vector<int>& data_memory, const int& input = 0) {
  switch (addressing_mode_) {
    case DIRECT:
      return data_memory[operand_];
      break;
    case INDIRECT:
      return data_memory[data_memory[operand_]];
      break;
    default:
      throw std::invalid_argument("Invalid addressing mode");
      break;
  }
  return 0;
}

// JUMP::JUMP(const std::string& label) {
//   label_ = label;
// }

// int JUMP::execute(std::vector<int>& data_memory) {
//   return operand_;
// }

// JZERO::JZERO(const std::string& label) {
//   label_ = label;
// }

// int JZERO::execute(std::vector<int>& data_memory) {
//   if (data_memory[0] == 0) {
//     return label_;
//   }
//   return 1;
// }

// JGTZ::JGTZ(const int& operand) {
//   operand_ = operand;
// }

// int JGTZ::execute(std::vector<int>& data_memory) {
//   if (data_memory[0] > 0) {
//     return operand_;
//   }
//   return 1;
// }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory 
 */
int HALT::execute(std::vector<int>& data_memory, const int& input = 0) {
  return -1;
}