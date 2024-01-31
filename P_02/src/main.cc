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

#include <iostream>

int main(int argc, char** argv) {
  try {
    std::vector<std::string> lines = ReadFile(argv[1]);
    for (int i = 0; i < lines.size(); i++) {
      std::cout << lines[i] << std::endl;
    }
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}