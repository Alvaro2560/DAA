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

/**
 * @brief Class that represents an instruction.
 */
class Instruction {
  public:
    Instruction(void);
    virtual int solve(void) = 0;
    ~Instruction(void);
  private:
    int opcode_;
    int operand_;
};

class LOAD : public Instruction {
  public:
    LOAD(void);
    int solve(void);
    ~LOAD(void);
};

class STORE : public Instruction {
  public:
    STORE(void);
    int solve(void);
    ~STORE(void);
};

class ADD : public Instruction {
  public:
    ADD(void);
    int solve(void);
    ~ADD(void);
};

class SUB : public Instruction {
  public:
    SUB(void);
    int solve(void);
    ~SUB(void);
};

class MUL : public Instruction {
  public:
    MUL(void);
    int solve(void);
    ~MUL(void);
};

class DIV : public Instruction {
  public:
    DIV(void);
    int solve(void);
    ~DIV(void);
};

class READ : public Instruction {
  public:
    READ(void);
    int solve(void);
    ~READ(void);
};

class WRITE : public Instruction {
  public:
    WRITE(void);
    int solve(void);
    ~WRITE(void);
};

class JUMP : public Instruction {
  public:
    JUMP(void);
    int solve(void);
    ~JUMP(void);
};

class JZERO : public Instruction {
  public:
    JZERO(void);
    int solve(void);
    ~JZERO(void);
};

class JGTZ : public Instruction {
  public:
    JGTZ(void);
    int solve(void);
    ~JGTZ(void);
};

class HALT : public Instruction {
  public:
    HALT(void);
    int solve(void);
    ~HALT(void);
};