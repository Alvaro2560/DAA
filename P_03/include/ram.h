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
    RAM(const std::vector<std::string>& instructions, 
        const std::vector<std::string>& input_tape, 
        OutputUnit* output_unit);
    void run(const int& debug_flag);
    ~RAM(void);
  private:
    void FormatInstructions(const std::vector<std::string>& instructions);
    std::vector<int> FormatTape(const std::vector<std::string>& file_name);
  private:
    size_t program_counter_;
    std::vector<Instruction*> program_memory_;
    std::unordered_map<std::string, size_t> labels_;
    std::vector<std::vector<int>> data_memory_;
    InputUnit* input_unit_;
    OutputUnit* output_unit_;
};