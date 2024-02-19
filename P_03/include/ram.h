/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class RAM.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "../include/instructions.h"

#include <iostream>
#include <vector>
#include <unordered_map>

class InputUnit;
class OutputUnit;
class Instruction;

/**
 * @brief Class that represents the RAM.
 */
class RAM {
  friend class Debugger;
  public:
    RAM(const std::vector<Instruction*>& instructions, 
        const std::vector<int>& input_tape,
        const std::unordered_map<std::string, size_t>& labels);
    void run(const int& debug_flag);
    OutputUnit* getOutputUnit(void) const;
    ~RAM(void);
  private:
    size_t program_counter_;
    std::vector<Instruction*> program_memory_;
    std::unordered_map<std::string, size_t> labels_;
    std::vector<std::vector<int>> data_memory_;
    InputUnit* input_unit_;
    OutputUnit* output_unit_;
};