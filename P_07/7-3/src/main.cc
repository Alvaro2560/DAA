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
#include "../include/gvns.hh"

#include <iostream>
#include <filesystem>

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
    if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " <input_directory> <algorithm>" << std::endl;
      return 1;
    } if (std::string(argv[2]) == "--greedy") {
      algorithm = new Greedy;
    } else if (std::string(argv[2]) == "--grasp") {
      algorithm = new GRASP;
    } else if (std::string(argv[2]) == "--gvns") {
      algorithm = new GVNS;
    } else {
      std::cerr << "Invalid algorithm." << std::endl;
    }
    std::string input_directory = argv[1];
    std::vector<std::string> files;
    for (const auto& entry : std::filesystem::directory_iterator(input_directory)) {
      files.emplace_back(entry.path().string());
    }
    std::cout << "Problema\t\t\tm    Ejecución\tTCT\tCPU" << std::endl;
    int execution = 0;
    for (const auto& file : files) {
      execution++;
      problem = Problem(file);
      Solution solution = algorithm->Run(problem);
      std::cout << file << "\t" << problem.getMachines() << "\t" << execution << "\t" << solution.getTCT() << "\t" << algorithm->getTime() << std::endl;
    }
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}