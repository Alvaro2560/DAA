/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file instruction.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Instruction and its subclasses.
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
    virtual size_t execute(int* data_memory = 0) = 0;
    virtual std::string getInstruction(void) = 0;
    // virtual ~Instruction(void) = default;
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
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "LOAD"; };
    // ~LOAD(void) = default;
};

/**
 * @brief Class that represents the STORE instruction.
 */
class STORE : public Instruction {
  public:
    STORE(const int& operand);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "STORE"; };
    // ~STORE(void) = default;
};

/**
 * @brief Class that represents the ADD instruction.
 */
class ADD : public Instruction {
  public:
    ADD(const AddressingMode& addressing_mode, const int& operand);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "ADD"; };
    // ~ADD(void) = default;
};

/**
 * @brief Class that represents the SUB instruction.
 */
class SUB : public Instruction {
  public:
    SUB(const AddressingMode& addressing_mode, const int& operand);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "SUB"; };
    // ~SUB(void) = default;
};

/**
 * @brief Class that represents the MUL instruction.
 */
class MUL : public Instruction {
  public:
    MUL(const AddressingMode& addressing_mode, const int& operand);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "MUL"; };
    // ~MUL(void) = default;
};

/**
 * @brief Class that represents the DIV instruction.
 */
class DIV : public Instruction {
  public:
    DIV(const AddressingMode& addressing_mode, const int& operand);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "DIV"; };
    // ~DIV(void) = default;
};

class InputUnit;

/**
 * @brief Class that represents the READ instruction.
 */
class READ : public Instruction {
  public:
    READ(const AddressingMode& addressing_mode, const int& operand, InputUnit* input_unit);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "READ"; };
    // ~READ(void) = default;
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
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "WRITE"; };
    // ~WRITE(void) = default;
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
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "JUMP"; };
    // ~JUMP(void);
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
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "JZERO"; };
    // ~JZERO(void);
};

/**
 * @brief Class that represents the JGTZ instruction.
 */
class JGTZ : public JUMP {
  public:
    JGTZ(const std::string& label, std::unordered_map<std::string, size_t>* labels, 
         const std::vector<Instruction*>& program_memory);
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "JGTZ"; };
    // ~JGTZ(void);
};

/**
 * @brief Class that represents the HALT instruction.
 */
class HALT : public Instruction {
  public:
    HALT(void) = default;
    size_t execute(int* data_memory) override;
    std::string getInstruction(void) override { return "HALT"; };
    // ~HALT(void) = default;
};