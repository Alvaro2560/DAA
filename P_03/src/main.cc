/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main function of the program.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/ram.h"

#include <iostream>

/**
 * @brief Main function of the program.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int 0 if the program ends correctly, 1 otherwise.
 */
int main(int argc, char** argv) {
  try {
    if (argc != 5) {
      PrintHelp();
      return 1;
    }
    std::vector<std::string> instructions = ReadFile(argv[1]),
                             input_tape = ReadFile(argv[2]);
    RAM ram(instructions, input_tape);
    ram.run(std::stoi(argv[4]));
    WriteUnit(ram.getOutputUnit(), argv[3]);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}