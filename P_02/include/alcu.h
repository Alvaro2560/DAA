/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file alcu.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class ALCU.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>

class Instruction;
class InputUnit;
class OutputUnit;

/**
 * @brief Class that represents the ALCU.
 */
class ALCU {
  public:
    ALCU(std::vector<Instruction*>& program_memory);
    void run(int* data_memory);
    ~ALCU(void) = default;
  private:
    Instruction** program_counter_;
    InputUnit* input_unit_;
    OutputUnit* output_unit_;
};