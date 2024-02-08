/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file instruction.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Instruction.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <string>

enum AddressingMode {
  CONSTANT,
  DIRECT,
  INDIRECT
};

/**
 * @brief Class that represents an instruction.
 */
class Instruction {
  public:
    Instruction(void) = default;
    virtual int execute(int* data_memory, const int& input = 0) = 0;
    virtual ~Instruction(void) = default;
  protected:
    AddressingMode addressing_mode_;
    int operand_;
};

/**
 * @brief Class that represents the LOAD instruction.
 */
class LOAD : public Instruction {
  public:
    LOAD(const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~LOAD(void) = default;
};

/**
 * @brief Class that represents the STORE instruction.
 */
class STORE : public Instruction {
  public:
    STORE(const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~STORE(void) = default;
};

/**
 * @brief Class that represents the ADD instruction.
 */
class ADD : public Instruction {
  public:
    ADD(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~ADD(void) = default;
};

/**
 * @brief Class that represents the SUB instruction.
 */
class SUB : public Instruction {
  public:
    SUB(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~SUB(void) = default;
};

/**
 * @brief Class that represents the MUL instruction.
 */
class MUL : public Instruction {
  public:
    MUL(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~MUL(void) = default;
};

/**
 * @brief Class that represents the DIV instruction.
 */
class DIV : public Instruction {
  public:
    DIV(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory, const int& input) override;
    ~DIV(void) = default;
};

class InputUnit;

/**
 * @brief Class that represents the READ instruction.
 */
class READ : public Instruction {
  public:
    READ(const AddressingMode& addressing_mode, const int& operand, InputUnit* input_unit);
    int execute(int* data_memory, const int& input) override;
    ~READ(void) = default;
  private:
    InputUnit* input_unit_;
};

class OutputUnit;

/**
 * @brief Class that represents the WRITE instruction.
 */
class WRITE : public Instruction {
  public:
    WRITE(const AddressingMode& addressing_mode, const int& operand, OutputUnit* output_unit);
    int execute(int* data_memory, const int& input) override;
    ~WRITE(void) = default;
  private:
    OutputUnit* output_unit_;
};

// TODO: Implement jump instructions.

// /**
//  * @brief Class that represents the JUMP instruction.
//  */
// class JUMP : public Instruction {
//   public:
//     JUMP(void) = default;
//     JUMP(const std::string& label);
//     int execute(int* data_memory);
//   protected:
//     std::string label_;
// };

// /**
//  * @brief Class that represents the JGTZ instruction.
//  */
// class JZERO : public Instruction, public JUMP {
//   public:
//     JZERO(const std::string& label);
//     int execute(int* data_memory);
// };

// /**
//  * @brief Class that represents the JGTZ instruction.
//  */
// class JGTZ : public Instruction, public JUMP {
//   public:
//     JGTZ(const std::string& label);
//     int execute(int* data_memory);
// };

/**
 * @brief Class that represents the HALT instruction.
 */
class HALT : public Instruction {
  public:
    HALT(void) = default;
    int execute(int* data_memory, const int& input) override;
    ~HALT(void) = default;
};