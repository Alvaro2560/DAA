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
#include <unordered_map>

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
    virtual int execute(int* data_memory = 0) = 0;
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
    int execute(int* data_memory) override;
    ~LOAD(void) = default;
};

/**
 * @brief Class that represents the STORE instruction.
 */
class STORE : public Instruction {
  public:
    STORE(const int& operand);
    int execute(int* data_memory) override;
    ~STORE(void) = default;
};

/**
 * @brief Class that represents the ADD instruction.
 */
class ADD : public Instruction {
  public:
    ADD(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory) override;
    ~ADD(void) = default;
};

/**
 * @brief Class that represents the SUB instruction.
 */
class SUB : public Instruction {
  public:
    SUB(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory) override;
    ~SUB(void) = default;
};

/**
 * @brief Class that represents the MUL instruction.
 */
class MUL : public Instruction {
  public:
    MUL(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory) override;
    ~MUL(void) = default;
};

/**
 * @brief Class that represents the DIV instruction.
 */
class DIV : public Instruction {
  public:
    DIV(const AddressingMode& addressing_mode, const int& operand);
    int execute(int* data_memory) override;
    ~DIV(void) = default;
};

class InputUnit;

/**
 * @brief Class that represents the READ instruction.
 */
class READ : public Instruction {
  public:
    READ(const AddressingMode& addressing_mode, const int& operand, InputUnit* input_unit);
    int execute(int* data_memory) override;
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
    int execute(int* data_memory) override;
    ~WRITE(void) = default;
  private:
    OutputUnit* output_unit_;
};

/**
 * @brief Class that represents the JUMP instruction.
 */
class JUMP : public Instruction {
  public:
    JUMP(Instruction** program_counter, const std::string& label,
         std::unordered_map<std::string, Instruction*>& labels);
    int execute(int* data_memory) override;
  protected:
    Instruction** program_counter_;
    std::string label_;
    std::unordered_map<std::string, Instruction*> labels_;
};

/**
 * @brief Class that represents the JZERO instruction.
 */
class JZERO : public JUMP {
  public:
    JZERO(Instruction** program_counter, const std::string& label, 
          std::unordered_map<std::string, Instruction*>& labels);
    int execute(int* data_memory) override;
};

/**
 * @brief Class that represents the JGTZ instruction.
 */
class JGTZ : public JUMP {
  public:
    JGTZ(Instruction** program_counter, const std::string& label, 
         std::unordered_map<std::string, Instruction*>& labels);
    int execute(int* data_memory) override;
};

/**
 * @brief Class that represents the HALT instruction.
 */
class HALT : public Instruction {
  public:
    HALT(void) = default;
    int execute(int* data_memory) override;
    ~HALT(void) = default;
};