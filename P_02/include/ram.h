/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class RAM.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>
#include <vector>

class Instruction;
class Tape;
class ALCU;

/**
 * @brief Class that represents the RAM.
 */
class RAM {
  public:
    RAM(void);
    ~RAM(void);
  private:
    std::vector<Instruction*> program_memory_;
    std::vector<int> data_memory_;
    ALCU* alcu_;
    Tape* input_tape_;
    Tape* output_tape_;
};