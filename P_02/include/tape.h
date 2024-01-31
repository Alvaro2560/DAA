/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file tape.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Tape.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>

/**
 * @brief Class that represents the tape.
 */
class Tape {
  public:
    Tape(void);
    ~Tape(void);
  private:
    std::vector<int> tape_;
    int* head_;
};

/**
 * @brief Class that represents the input tape.
 */
class InputTape : public Tape {
  public:
    InputTape(void);
    int ReadSlot(void);
    ~InputTape(void);
};

/**
 * @brief Class that represents the output tape.
 */
class OutputTape : public Tape {
  public:
    OutputTape(void);
    void WriteSlot(int value);
    ~OutputTape(void);
};