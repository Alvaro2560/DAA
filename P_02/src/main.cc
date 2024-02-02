/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main function of the program.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/ram.h"

#include <iostream>

int main(int argc, char** argv) {
  try {
    if (argc != 4) {
      PrintHelp();
      return 1;
    }
    std::vector<std::string> file_content = ReadFile(argv[1]);
    std::vector<Instruction*> instructions;
    std::unordered_map<std::string, Instruction*> labels;
    FormatInstructions(file_content, instructions, labels);
    std::vector<int> input_tape = FormatTape(argv[2]);
    RAM ram(input_tape, instructions, labels);
    ram.run();
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}