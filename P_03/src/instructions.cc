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
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction.
 */
LOAD::LOAD(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t LOAD::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0][0] = register_;
      break;
    case DIRECT:
      if (direction_ < 0) {
        data_memory[0][0] = data_memory[register_][data_memory[-direction_][0]];
      } else {
        data_memory[0][0] = data_memory[register_][direction_];
      }
      break;
    case INDIRECT:
      data_memory[0][0] = data_memory[data_memory[register_][direction_]][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string LOAD::toString(void) const {
  std::string instruction = "LOAD ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new STORE::STORE object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
STORE::STORE(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t STORE::execute(std::vector<std::vector<int>>& data_memory) {
  if (direction_ == IND) {
    if (data_memory[register_].size() == 0) {
      data_memory[register_].resize(1);
    } else {
      data_memory[register_].resize(data_memory[register_].size() + 1);
    }
  } else if (data_memory[register_].size() <= direction_ && direction_ >= 0) {
    data_memory[register_].resize(-direction_ + 1);
  }
  switch (addressing_mode_) {
    case DIRECT:
      if (direction_ < 0) {
        data_memory[register_][data_memory[-direction_][0]] = data_memory[0][0];
      } else if (direction_ == IND) {
        data_memory[register_][data_memory[register_].size() - 1] = data_memory[0][0];
      } else {
        data_memory[register_][direction_] = data_memory[0][0];
      }
      break;
    case INDIRECT:
      data_memory[data_memory[register_][direction_]][0] = data_memory[0][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string STORE::toString(void) const {
  std::string instruction = "STORE ";
  switch (addressing_mode_) {
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new ADD::ADD object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
ADD::ADD(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t ADD::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0][0] += register_;
      break;
    case DIRECT:
      if (direction_ < 0) {
        data_memory[0][0] += data_memory[register_][data_memory[-direction_][0]];
      } else {
        data_memory[0][0] += data_memory[register_][direction_];
      }
      break;
    case INDIRECT:
      data_memory[0][0] += data_memory[data_memory[register_][direction_]][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string ADD::toString(void) const {
  std::string instruction = "ADD ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new SUB::SUB object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
SUB::SUB(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t SUB::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0][0] -= register_;
      break;
    case DIRECT:
      if (direction_ < 0) {
        data_memory[0][0] -= data_memory[register_][data_memory[-direction_][0]];
      } else {
        data_memory[0][0] -= data_memory[register_][direction_];
      }
      break;
    case INDIRECT:
      data_memory[0][0] -= data_memory[data_memory[register_][direction_]][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string SUB::toString(void) const {
  std::string instruction = "SUB ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new MUL::MUL object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
MUL::MUL(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}

/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t MUL::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0][0] *= register_;
      break;
    case DIRECT:
      if (direction_ < 0) {
        data_memory[0][0] *= data_memory[register_][data_memory[-direction_][0]];
      } else {
        data_memory[0][0] *= data_memory[register_][direction_];
      }
      break;
    case INDIRECT:
      data_memory[0][0] *= data_memory[data_memory[register_][direction_]][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string MUL::toString(void) const {
  std::string instruction = "MUL ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new DIV::DIV object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
DIV::DIV(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
}


/**
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t DIV::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      data_memory[0][0] /= register_;
      break;
    case DIRECT:
      if (direction_ < 0) {
        data_memory[0][0] /= data_memory[register_][data_memory[-direction_][0]];
      } else {
        data_memory[0][0] /= data_memory[register_][direction_];
      }
      break;
    case INDIRECT:
      data_memory[0][0] /= data_memory[data_memory[register_][direction_]][0];
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string DIV::toString(void) const {
  std::string instruction = "DIV ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new READ::READ object
 * 
 * @param addressing_mode The addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
READ::READ(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
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
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t READ::execute(std::vector<std::vector<int>>& data_memory) {
  if (direction_ == IND) {
    if (data_memory[register_].size() == 0) {
      data_memory[register_].resize(1);
    } else {
      data_memory[register_].resize(data_memory[register_].size() + 1);
    }
  } else if (data_memory[register_].size() <= direction_ && direction_ >= 0) {
    data_memory[register_].resize(-direction_ + 1);
  }
  switch (addressing_mode_) {
    case DIRECT:
      if (direction_ < 0) {
        data_memory[register_][data_memory[-direction_][0]] = input_unit_->process();
      } else if (direction_ == IND) {
        data_memory[register_][data_memory[register_].size() - 1] = input_unit_->process();
      } else {
        data_memory[register_][direction_] = input_unit_->process();
      }
      break;
    case INDIRECT:
      data_memory[data_memory[register_][direction_]][0] = input_unit_->process();
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string READ::toString(void) const {
  std::string instruction = "READ ";
  switch (addressing_mode_) {
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
}

/**
 * @brief Construct a new WRITE::WRITE object
 * 
 * @param addressing_mode THe addressing mode of the instruction.
 * @param register_operand The register accesed on the instruction.
 * @param direction_operand The direction operand of the instruction. 
 */
WRITE::WRITE(const AddressingMode& addressing_mode, const int& register_operand, const int& direction_operand) {
  addressing_mode_ = addressing_mode;
  register_ = register_operand;
  direction_ = direction_operand;
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
 * @brief Execute the instruction.
 * 
 * @param data_memory The data memory.
 * @return size_t
 */
size_t WRITE::execute(std::vector<std::vector<int>>& data_memory) {
  switch (addressing_mode_) {
    case CONSTANT:
      output_unit_->process(register_);
      break;
    case DIRECT:
      if (direction_ < 0) {
        output_unit_->process(data_memory[register_][data_memory[-direction_][0]]);
      } else {
        output_unit_->process(data_memory[register_][direction_]);
      }
      break;
    case INDIRECT:
      output_unit_->process(data_memory[data_memory[register_][direction_]][0]);
      break;
  }
  return 1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string WRITE::toString(void) const {
  std::string instruction = "WRITE ";
  switch (addressing_mode_) {
    case CONSTANT:
      instruction += "=" + std::to_string(register_);
      break;
    case DIRECT:
      if (direction_ == IND) {
        instruction += std::to_string(register_);
      } else if (direction_ >= 0) {
        instruction += std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      } else {
        instruction += std::to_string(register_) + "[*" + std::to_string(-direction_) + "]";
      }
      break;
    case INDIRECT:
      if (direction_ == 0) {
        instruction += "*" + std::to_string(register_);
      } else {
        instruction += "*" + std::to_string(register_) + "[" + std::to_string(direction_) + "]";
      }
      break;
  }
  return instruction;
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
size_t JUMP::execute(std::vector<std::vector<int>>& data_memory) {
  return (*labels_)[label_];
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string JUMP::toString(void) const {
  return "JUMP " + label_;
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
size_t JZERO::execute(std::vector<std::vector<int>>& data_memory) {
  if (data_memory[0][0] == 0) {
    return (*labels_)[label_];
  } else {
    return 1;
  }
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string JZERO::toString(void) const {
  return "JZERO " + label_;
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
size_t JGTZ::execute(std::vector<std::vector<int>>& data_memory) {
  if (data_memory[0][0] > 0) {
    return (*labels_)[label_];
  } else {
    return 1;
  }
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string JGTZ::toString(void) const {
  return "JGTZ " + label_;
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
size_t HALT::execute(std::vector<std::vector<int>>& data_memory) {
  return -1;
}

/**
 * @brief Convert the instruction to a string.
 * 
 * @return std::string
 */
std::string HALT::toString(void) const {
  return "HALT";
}