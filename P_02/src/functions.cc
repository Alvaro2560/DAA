/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the functions used in the program.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @see https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/instructions.h"

/**
 * @brief Prints the help menu.
 */
void PrintHelp(void) {
  std::cout << "Usage: ./P_02 <file_name.ram> <input_tape> <output_tape>" << std::endl;
}

/**
 * @brief Reads the content of a file and returns it as a vector of strings.
 * 
 * @param file_name Name of the file to read.
 * @return std::vector<std::string> Content of the file as a vector of strings.
 */
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