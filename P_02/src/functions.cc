/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the functions used in the program.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

void PrintHelp(void) {
  std::cout << "Usage: ./P_02 <file_name.ram> <input_tape> <output_tape>" << std::endl;
}

std::vector<std::string> ReadFile(const std::string& file_name) {
  std::ifstream file(file_name);
  std::vector<std::string> file_content;
  std::string line;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      file_content.emplace_back(line);
    }
    file.close();
  } else {
    throw std::runtime_error("Unable to open file.");
  }
  return file_content;
}