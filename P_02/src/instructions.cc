/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file instructions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definitions of instruction classes.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/instructions.h"
#include "../include/input-unit.h"
#include "../include/output-unit.h"

#include <iostream>

/**
 * @brief Construct a new LOAD::LOAD object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction.
 */
LOAD::LOAD(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t LOAD::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0] = operand_;
      break;
    case DIRECT:
      data_memory[0] = data_memory[operand_];
      break;
    case INDIRECT:
      data_memory[0] = data_memory[data_memory[operand_]];
      break;
  }
  return 1;
}

/**
 * @brief Construct a new STORE::STORE object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
STORE::STORE(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t STORE::execute(int* data_memory) {
  switch (addressing_mode_) {
    case DIRECT:
      data_memory[operand_] = data_memory[0];
      break;
    case INDIRECT:
      data_memory[data_memory[operand_]] = data_memory[0];
      break;
  }
  return 1;
}

/**
 * @brief Construct a new ADD::ADD object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
ADD::ADD(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t ADD::execute(int* data_memory) {
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
  }
  return 1;
}

/**
 * @brief Construct a new SUB::SUB object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
SUB::SUB(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t SUB::execute(int* data_memory) {
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
  }
  return 1;
}

/**
 * @brief Construct a new MUL::MUL object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
MUL::MUL(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t MUL::execute(int* data_memory) {
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
  }
  return 1;
}

/**
 * @brief Construct a new DIV::DIV object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
DIV::DIV(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t DIV::execute(int* data_memory) {
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
  }
  return 1;
}

/**
 * @brief Construct a new READ::READ object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
READ::READ(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t READ::execute(int* data_memory) {
  switch (addressing_mode_) {
    case DIRECT:
      data_memory[operand_] = input_unit_->process();
      break;
    case INDIRECT:
      data_memory[data_memory[operand_]] = input_unit_->process();
      break;
  }
  return 1;
}

/**
 * @brief Set the input unit.
 * 
 * @param input_unit The input unit.
 */
void READ::setUnit(InputUnit* input_unit) {
  input_unit_ = input_unit;
}

/**
 * @brief Construct a new WRITE::WRITE object
 * 
 * @param addressing_mode THe addressing mode of the instruction.
 * @param operand The operand of the instruction. 
 */
WRITE::WRITE(const AddressingMode& addressing_mode, const int& operand) {
  addressing_mode_ = addressing_mode;
  operand_ = operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t WRITE::execute(int* data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      output_unit_->process(operand_);
      break;
    case DIRECT:
      output_unit_->process(data_memory[operand_]);
      break;
    case INDIRECT:
      output_unit_->process(data_memory[data_memory[operand_]]);
      break;
  }
  return 1;
}

/**
 * @brief Set the output unit.
 * 
 * @param output_unit The output unit.
 */
void WRITE::setUnit(OutputUnit* output_unit) {
  output_unit_ = output_unit;
}

/**
 * @brief Construct a new JUMP::JUMP object
 * 
 * @param label The target label to jump.
 * @param labels The labels of the program.
 * @param program_memory The program memory.
 */
JUMP::JUMP(const std::string& label,
           std::unordered_map<std::string, size_t>* labels, 
           const std::vector<Instruction*>& program_memory) 
           : label_(label), labels_(labels), program_memory_(program_memory) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t JUMP::execute(int* data_memory) {
  return (*labels_)[label_];
}

/**
 * @brief Destroy the JUMP::JUMP object
 * 
 */
JUMP::~JUMP(void) { 
  labels_ = nullptr;
  delete labels_;
}

/**
 * @brief Construct a new JZERO::JZERO object
 * 
 * @param label The target label to jump.
 * @param labels The labels of the program.
 * @param program_memory The program memory.
 */
JZERO::JZERO(const std::string& label, 
             std::unordered_map<std::string, size_t>* labels, 
             const std::vector<Instruction*>& program_memory) 
             : JUMP(label, labels, program_memory) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t JZERO::execute(int* data_memory) {
  if (data_memory[0] == 0) {
    return (*labels_)[label_];
  } else {
    return 1;
  }
}

/**
 * @brief Destroy the JZERO::JZERO object
 * 
 */
JZERO::~JZERO(void) { 
  labels_ = nullptr;
  delete labels_;
}

/**
 * @brief Construct a new JGTZ::JGTZ object
 *  
 * @param label The target label to jump.
 * @param labels The labels of the program.
 * @param program_memory The program memory.
 */
JGTZ::JGTZ(const std::string& label, 
           std::unordered_map<std::string, size_t>* labels, 
           const std::vector<Instruction*>& program_memory) 
           : JUMP(label, labels, program_memory) { }

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t JGTZ::execute(int* data_memory) {
  if (data_memory[0] > 0) {
    return (*labels_)[label_];
  } else {
    return 1;
  }
}

/**
 * @brief Destroy the JGTZ::JGTZ object
 * 
 */
JGTZ::~JGTZ(void) { 
  labels_ = nullptr;
  delete labels_;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t HALT::execute(int* data_memory) {
  return -1;
}