/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the functions used in the program.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "instructions.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class Instruction;
class OutputUnit;

void PrintHelp(void);

std::vector<std::string> ReadFile(const std::string& file_name);

void WriteUnit(const OutputUnit* output_unit, const std::string& file_name);

std::vector<Instruction*> FormatInstructions(const std::vector<std::string>& instructions, 
                                             std::unordered_map<std::string, size_t>& labels);

void CreateInstruction(std::vector<Instruction*>& program_memory,
                       const std::string& instruction, 
                       const AddressingMode& addressing_mode, 
                       const int& operand, 
                       const int& position,
                       const std::string& label, const int& line,
                       const std::string& line_operand,
                       const std::string& jump_label,
                       std::unordered_map<std::string, size_t>& labels);
void CheckAddressingMode(const std::string& word, 
                          AddressingMode& addressing_mode, 
                          int& operand,
                          int& position, 
                          const int& i, 
                          const std::string& instruction);
void CheckLabels(const std::unordered_map<std::string, size_t>& labels, 
                 const std::unordered_map<std::string, std::pair<size_t, std::string>>& labels_cache);

std::vector<int> FormatTape(const std::vector<std::string>& file_name);