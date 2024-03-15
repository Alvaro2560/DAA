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

#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
  try {
    srand(time(NULL));
    int nodes = 0;
    int time_limit = 5;
    if (argc != 2 && argc != 3 && argc != 4) {
      std::cerr << "Usage: " << argv[0] << " <files_directory> <-t [time_limit]> <-g [files to generate]>" << std::endl;
      throw std::invalid_argument("Invalid number of arguments");
    } else if (argc == 4) {
      if (std::string(argv[2]) == "-t") {
        time_limit = std::stoi(argv[3]);
      } else if (std::string(argv[2]) == "-g") {
        nodes = std::stoi(argv[3]);
        for (int i = 0; i < 3; i++) {
          GenerateRandomInstance(nodes, "instance" + std::to_string(i + 1) + ".txt");
        }
      }
    } else if (argc == 6) {
      if (std::string(argv[2]) == "-t") {
        time_limit = std::stoi(argv[3]);
      } else if (std::string(argv[2]) == "-g") {
        nodes = std::stoi(argv[3]);
        for (int i = 0; i < 3; i++) {
          GenerateRandomInstance(nodes, "instance" + std::to_string(i + 1) + ".txt");
        }
      }
      if (std::string(argv[4]) == "-t") {
        time_limit = std::stoi(argv[5]);
      } else if (std::string(argv[4]) == "-g") {
        nodes = std::stoi(argv[5]);
        for (int i = 0; i < 3; i++) {
          GenerateRandomInstance(nodes, "instance" + std::to_string(i + 1) + ".txt");
        }
      }
    }
    std::string files_directory = argv[1];
    std::vector<std::string> file_names;
    for (const auto& entry : std::filesystem::directory_iterator(files_directory)) {
      file_names.emplace_back(entry.path());
    }
    std::cout << "Instancia\tValor F.B.\tTiempo F.B. (ms)\tValor P.D.\tTiempo P.D. (ms)\t"
                 "Valor Greedy\tTiempo Greedy (ms)" << std::endl;
    for (const auto& file_name : file_names) {
      std::vector<std::string> file_content = ReadFile(file_name);
      Graph* graph = CreateGraph(file_content);
      std::cout << file_name << "\t";
      // ! ?????
      std::cout << file_name.size() << "\t";
      CalculateTimes(graph, time_limit);
      std::cout << "\n";
    }
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}