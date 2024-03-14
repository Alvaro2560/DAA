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
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/greedy-solver.h"

#include <iostream>

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
      throw std::invalid_argument("Invalid number of arguments");
    }
    std::string file_name = argv[1];
    std::vector<std::string> file_content = ReadFile(file_name);
    Graph* graph = CreateGraph(file_content);
    Greedy greedy;
    greedy.Solve(graph);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}