/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the functions used in the program.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @see https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/instructions.h"
#include "../include/output-unit.h"

/**
 * @brief Prints the help menu.
 */
void PrintHelp(void) {
  std::cout << "Usage: ./P_02 <file_name.ram> <input_tape> <output_tape>" << std::endl;
  std::cout << "  file_name.ram: File with the instructions of the RAM." << std::endl;
  std::cout << "  input_tape: File with the input tape." << std::endl;
  std::cout << "  output_tape: File where the output tape will be written." << std::endl;
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

/**
 * @brief Writes the content of a vector of integers to a file.
 * 
 * @param output_tape Vector of integers to write to the file.
 * @param size Size of the vector.
 * @param file_name Name of the file to write.
 */
void WriteUnit(const OutputUnit* output_unit, const std::string& file_name) {
  std::ofstream file(file_name);
  if (file.is_open()) {
    int* output_tape = output_unit->getTape();
    size_t size = output_unit->getSize();
    for (size_t i = 0; i < size - 1; i++) {
      file << output_tape[i] << std::endl;
    }
    file.close();
  } else {
    throw std::runtime_error("Unable to open file.");
  }
}