/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file instruction.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Instruction and its subclasses.
 * @version 1.0
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
    virtual size_t execute(std::vector<std::vector<int>>& data_memory) = 0;
    virtual ~Instruction(void) = default;
  protected:
    AddressingMode addressing_mode_;
    int register_;
    int direction_;
};

/**
 * @brief Class that represents the LOAD instruction.
 */
class LOAD : public Instruction {
  public:
    LOAD(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~LOAD(void) = default;
};

/**
 * @brief Class that represents the STORE instruction.
 */
class STORE : public Instruction {
  public:
    STORE(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~STORE(void) = default;
};

/**
 * @brief Class that represents the ADD instruction.
 */
class ADD : public Instruction {
  public:
    ADD(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~ADD(void) = default;
};

/**
 * @brief Class that represents the SUB instruction.
 */
class SUB : public Instruction {
  public:
    SUB(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~SUB(void) = default;
};

/**
 * @brief Class that represents the MUL instruction.
 */
class MUL : public Instruction {
  public:
    MUL(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~MUL(void) = default;
};

/**
 * @brief Class that represents the DIV instruction.
 */
class DIV : public Instruction {
  public:
    DIV(const AddressingMode& addresing_mode, const int& register_operand, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~DIV(void) = default;
};

class InputUnit;

/**
 * @brief Class that represents the READ instruction.
 */
class READ : public Instruction {
  public:
    READ(const AddressingMode& addresing_mode, const int& register_operand, 
         InputUnit* input_unit, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
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
    WRITE(const AddressingMode& addresing_mode, const int& register_operand, 
          OutputUnit* output_unit, const int& direction_operand = 0);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~WRITE(void) = default;
  private:
    OutputUnit* output_unit_;
};

/**
 * @brief Class that represents the JUMP instruction.
 */
class JUMP : public Instruction {
  public:
    JUMP(const std::string& label, std::unordered_map<std::string, size_t>* labels, 
         const std::vector<Instruction*>& program_memory);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~JUMP(void);
  protected:
    std::string label_;
    std::unordered_map<std::string, size_t>* labels_;
    std::vector<Instruction*> program_memory_;
};

/**
 * @brief Class that represents the JZERO instruction.
 */
class JZERO : public JUMP {
  public:
    JZERO(const std::string& label, std::unordered_map<std::string, size_t>* labels, 
          const std::vector<Instruction*>& program_memory);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~JZERO(void);
};

/**
 * @brief Class that represents the JGTZ instruction.
 */
class JGTZ : public JUMP {
  public:
    JGTZ(const std::string& label, std::unordered_map<std::string, size_t>* labels, 
         const std::vector<Instruction*>& program_memory);
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~JGTZ(void);
};

/**
 * @brief Class that represents the HALT instruction.
 */
class HALT : public Instruction {
  public:
    HALT(void) = default;
    size_t execute(std::vector<std::vector<int>>& data_memory) override;
    ~HALT(void) = default;
};