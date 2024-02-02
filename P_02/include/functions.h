/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file functions.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the functions used in the program.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class Instruction;

void PrintHelp(void);

std::vector<std::string> ReadFile(const std::string& file_name);

void FormatInstructions(const std::vector<std::string>& file_content, 
                              std::vector<Instruction*>& instructions,
                              std::unordered_map<std::string, Instruction*>& labels);

std::vector<int> FormatTape(const std::string& file_name);