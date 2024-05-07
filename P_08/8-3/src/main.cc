/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main file of the project.
 * @version 0.1
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/greedy.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/local-search.hh"
#include "../include/grasp.hh"
#include "../include/tabu-search.hh"
#include "../include/branch-bound.hh"

#include <iostream>
#include <chrono>

/**
 * @brief Main function of the project.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int Exit code.
 */
int main(int argc, char** argv) {
  try {
    srand(time(nullptr));
    if (argc != 4) {
      throw std::invalid_argument("Usage: ./p08 <filename> <solution_dimension> <algorithm>");
    }
    Problem problem(argv[1], std::stoi(argv[2]));
    Algorithm* algorithm;
    if (std::string(argv[3]) == "--greedy") {
      algorithm = new Greedy();
    } else if (std::string(argv[3]) == "--local-search") {
      algorithm = new LocalSearch();
    } else if (std::string(argv[3]) == "--grasp") {
      algorithm = new GRASP();
    } else if (std::string(argv[3]) == "--tabu-search") {
      algorithm = new TabuSearch();
    } else if (std::string(argv[3]) == "--branch-bound") {
      algorithm = new BranchBound();
    } else {
      throw std::invalid_argument("Invalid algorithm.");
    }
    auto start = std::chrono::high_resolution_clock::now();
    Solution solution = algorithm->Run(problem);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << solution;
    std::cout << "Time: " << duration.count() << "ms" << std::endl;
    return 0;
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}