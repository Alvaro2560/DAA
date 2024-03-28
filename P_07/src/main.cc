/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main function of the program.
 * @version 0.1
 * @since Mar 28 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <exception>

/**
 * @brief Main function of the program.
 * 
 * @param argc Number of arguments. 
 * @param argv Array of arguments.
 * @return int Exit status of the program.
 */
int main(int argc, char** argv) {
  try {
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}
