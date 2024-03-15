/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definitions of the functions used on the program.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/greedy-solver.h"
#include "../include/brute-force-solver.h"
#include "../include/dynamic-programming-solver.h"

#include <fstream>
#include <chrono>
#include <iostream>
#include <set>

/**
 * @brief Reads the content of a file and returns it as a vector of strings.
 * 
 * @param file_name Name of the file to read.
 * @return std::vector<std::string> Content of the file.
 */
std::vector<std::string> ReadFile(const std::string& file_name) {
  std::vector<std::string> file_content;
  std::ifstream file(file_name);
  std::string word;
  while (file >> word) {
    file_content.emplace_back(word);
  }
  return file_content;
}

/**
 * @brief Creates a graph from the content of a file.
 * 
 * @param file_content Content of the file.
 * @return Graph* Graph created from the content of the file.
 */
Graph* CreateGraph(const std::vector<std::string>& file_content) {
  Graph* graph = new Graph();
  for (size_t i = 1; i < file_content.size(); i += 3) {
    std::string node1ID = file_content[i];
    std::string node2ID = file_content[i + 1];
    int weight = std::stoi(file_content[i + 2]);
    graph->addNode(node1ID);
    graph->addNode(node2ID);
    graph->addEdge(node1ID, node2ID, weight);
    graph->addEdge(node2ID, node1ID, weight);
  }
  return graph;
}

/**
 * @brief Calculates the time of the execution of the algorithms.
 * 
 * @param graph Graph to solve.
 * @param time_limit Time limit for the execution of the algorithms.
 * @return Data Data of the execution of the algorithms.
 */
Data CalculateTimes(Graph* graph, const int& time_limit) {
  std::vector<std::string> times;
  Greedy greedy;
  BruteForce brute_force;
  DynamicProgramming dynamic;
  Solution brute_solution, dynamic_solution, greedy_solution;
  bool solved = false;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  while (std::chrono::duration<double>(end - start).count() < time_limit && !solved) {
    brute_solution = brute_force.Solve(graph);
    end = std::chrono::system_clock::now();
    solved = true;
  }
  solved = false;
  if (std::chrono::duration<double>(end - start).count() > time_limit) {
    times.emplace_back("EXCESIVO");
  } else {
    times.emplace_back(std::to_string(std::chrono::duration<double>(end - start).count()));
  }
  start = std::chrono::system_clock::now();
  while (std::chrono::duration<double>(end - start).count() < time_limit && !solved) {
    dynamic_solution = dynamic.Solve(graph);
    end = std::chrono::system_clock::now();
    solved = true;
  }
  solved = false;
  if (std::chrono::duration<double>(end - start).count() > time_limit) {
    times.emplace_back("EXCESIVO");
  } else {
    times.emplace_back(std::to_string(std::chrono::duration<double>(end - start).count()));
  }
  start = std::chrono::system_clock::now();
  while (std::chrono::duration<double>(end - start).count() < time_limit && !solved) {
    greedy_solution = greedy.Solve(graph);
    end = std::chrono::system_clock::now();
    solved = true;
  }
  solved = false;
  if (std::chrono::duration<double>(end - start).count() > time_limit) {
    times.emplace_back("EXCESIVO");
  } else {
    times.emplace_back(std::to_string(std::chrono::duration<double>(end - start).count()));
  }
  Data data;
  data.times = times;
  data.solutions = {brute_solution, dynamic_solution, greedy_solution};
  return data;
}

/**
 * @brief Prints the results of the execution of the algorithms.
 * 
 * @param data Data of the execution of the algorithms.
 * @param file_name Name of the file.
 */
void PrintResults(const Data& data, const std::string& file_name) {
  std::cout << file_name;
  std::cout << "\t    " << data.solutions[0].second << "\t\t       " << data.times[0];
  std::cout << "\t\t    " << data.solutions[1].second << "\t\t        " << data.times[1];
  std::cout << "\t\t     " << data.solutions[2].second << "\t\t\t" << data.times[2] << std::endl;
}

/**
 * @brief Generates random instances of the TSP.
 * 
 * @param num_nodes Number of nodes of the instance.
 * @param file_name Name of the file to save the instance.
 */
void GenerateRandomInstance(int num_nodes, std::string file_name) {
  std::ofstream file(file_name);
  file << num_nodes << std::endl;
  std::set<std::pair<char, char>> used_edges;
  for (char i = 'A'; i < 'A' + num_nodes; ++i) {
    for (char j = i + 1; j < 'A' + num_nodes; ++j) {
      int weight = rand() % 50 + 1;
      file << i << " " << j << " " << weight << std::endl;
      used_edges.insert({i, j});
    }
  }
  for (char i = 'A'; i < 'A' + num_nodes - 1; ++i) {
    char j = i + 1;
    if (used_edges.find({i, j}) == used_edges.end()) {
      int weight = rand() % 50 + 1;
      file << i << " " << j << " " << weight << std::endl;
    }
  }
}