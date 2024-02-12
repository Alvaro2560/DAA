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
#include "../include/units.h"

#include <iostream>

/**
 * @brief Main function of the program.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int 0 if the program ends correctly, 1 otherwise.
 */
int main(int argc, char** argv) {
  OutputUnit* output_unit = new OutputUnit(argv[3]);
  try {
    if (argc != 5) {
      PrintHelp();
      return 1;
    }
    std::vector<std::string> instructions = ReadFile(argv[1]),
                             input_tape = ReadFile(argv[2]);
    RAM ram(instructions, input_tape, output_unit);
    ram.run();
    output_unit->write();
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    output_unit->write();
    return 1;
  }
}