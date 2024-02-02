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

/**
 * @brief Class that represents an instruction.
 */
class Instruction {
  public:
    Instruction(void);
    virtual int execute(std::vector<int>& data_memory) = 0;
    ~Instruction(void);
  protected:
    int opcode_;
    int operand_;
};

/**
 * @brief Class that represents the LOAD instruction.
 */
class LOAD : public Instruction {
  public:
    LOAD(void);
    int execute(std::vector<int>& data_memory);
    ~LOAD(void);
};

/**
 * @brief Class that represents the STORE instruction.
 */
class STORE : public Instruction {
  public:
    STORE(void);
    int execute(std::vector<int>& data_memory);
    ~STORE(void);
};

/**
 * @brief Class that represents the ADD instruction.
 */
class ADD : public Instruction {
  public:
    ADD(void);
    int execute(std::vector<int>& data_memory);
    ~ADD(void);
};

/**
 * @brief Class that represents the SUB instruction.
 */
class SUB : public Instruction {
  public:
    SUB(void);
    int execute(std::vector<int>& data_memory);
    ~SUB(void);
};

/**
 * @brief Class that represents the MUL instruction.
 */
class MUL : public Instruction {
  public:
    MUL(void);
    int execute(std::vector<int>& data_memory);
    ~MUL(void);
};

/**
 * @brief Class that represents the DIV instruction.
 */
class DIV : public Instruction {
  public:
    DIV(void);
    int execute(std::vector<int>& data_memory);
    ~DIV(void);
};

/**
 * @brief Class that represents the READ instruction.
 */
class READ : public Instruction {
  public:
    READ(void);
    int execute(std::vector<int>& data_memory);
    ~READ(void);
};

/**
 * @brief Class that represents the WRITE instruction.
 */
class WRITE : public Instruction {
  public:
    WRITE(void);
    int execute(std::vector<int>& data_memory);
    ~WRITE(void);
};

/**
 * @brief Class that represents the JUMP instruction.
 */
class JUMP : public Instruction {
  public:
    JUMP(void);
    int execute(std::vector<int>& data_memory);
    ~JUMP(void);
};

/**
 * @brief Class that represents the JGTZ instruction.
 */
class JZERO : public Instruction {
  public:
    JZERO(void);
    int execute(std::vector<int>& data_memory);
    ~JZERO(void);
};

/**
 * @brief Class that represents the JGTZ instruction.
 */
class JGTZ : public Instruction {
  public:
    JGTZ(void);
    int execute(std::vector<int>& data_memory);
    ~JGTZ(void);
};

/**
 * @brief Class that represents the HALT instruction.
 */
class HALT : public Instruction {
  public:
    HALT(void);
    int execute(std::vector<int>& data_memory);
    ~HALT(void);
};