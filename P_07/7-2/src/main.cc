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
#include "../include/grasp.hh"

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
    srand(time(nullptr));
    Problem problem(argv[1]);
    Algorithm* algorithm;
    if (std::string(argv[2]) == "--greedy") {
      algorithm = new Greedy;
      Solution solution = algorithm->Run(problem);
      std::cout << solution;
    } else if (std::string(argv[2]) == "--grasp") {
      algorithm = new GRASP;
      Solution solution = algorithm->Run(problem);
      std::cout << solution;
    } else {
      std::cerr << "Invalid algorithm." << std::endl;
    }
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}