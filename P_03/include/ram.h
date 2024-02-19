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
    RAM(const std::vector<std::string>& instructions, 
        const std::vector<std::string>& input_tape);
    void run(const int& debug_flag);
    OutputUnit* getOutputUnit(void) const;
    ~RAM(void);
  private:
    void FormatInstructions(const std::vector<std::string>& instructions);
    std::vector<int> FormatTape(const std::vector<std::string>& file_name);
    void CreateInstruction(const std::string& instruction, 
                           const AddressingMode& addressing_mode, 
                           const int& operand, 
                           const std::string& label, const int& line,
                           const std::string& line_operand,
                           const std::string& jump_label);
    void CheckAddressingMode(const std::string& word, 
                             AddressingMode& addressing_mode, 
                             int& operand, 
                             const int& i, 
                             const std::string& instruction);
    void CheckLabels(const std::unordered_map<std::string, std::pair<size_t, std::string>>& labels_cache);
  private:
    size_t program_counter_;
    std::vector<Instruction*> program_memory_;
    std::unordered_map<std::string, size_t> labels_;
    std::vector<std::vector<int>> data_memory_;
    InputUnit* input_unit_;
    OutputUnit* output_unit_;
};