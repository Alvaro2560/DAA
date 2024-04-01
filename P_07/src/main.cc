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

#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/greedy.hh"

#include <iostream>

/**
 * @brief Main function of the program.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int Exit status.
 */
int main(int argc, char* argv[]) {
  try {
    Problem problem(argv[1]);
    Algorithm* greedy = new Greedy();
    Solution solution = greedy->Run(problem);
    std::cout << solution;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}