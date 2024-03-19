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
#include <thread>

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

std::vector<std::future<void>> pending_futures;

/**
 * @brief Calculates the time of the execution of the algorithms.
 * 
 * @param graph Graph to solve.
 * @param time_limit Time limit for the execution of the algorithms.
 */
std::vector<std::string> CalculateTimes(Graph* graph, const float& time_limit) {
  std::vector<std::string> times;
  BruteForce brute_force;
  DynamicProgramming dynamic;
  Greedy greedy;
  Solution solution;
  std::string time;
  auto end = std::chrono::high_resolution_clock::now();
  auto start = std::chrono::high_resolution_clock::now();
  auto future_brute = std::async(std::launch::async, [&] {
    solution = brute_force.Solve(graph);
  });
  auto status = future_brute.wait_for(std::chrono::milliseconds(0));
  do {
    status = future_brute.wait_for(std::chrono::milliseconds(0));
  } while (status != std::future_status::ready && 
          (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start).count() < time_limit));
  if (status == std::future_status::ready) {
    future_brute.get();
    end = std::chrono::high_resolution_clock::now();
    time = std::to_string(std::chrono::duration<float, std::milli>(end - start).count());
  } else {
    time = "EXCESIVO";
    solution.second = -1;
  }
  // PrintResult(solution, time);
  times.emplace_back(time);
  write(graph->getNodes().size(), time, 1);
  start = std::chrono::high_resolution_clock::now();
  auto future_dp = std::async(std::launch::async, [&] {
    solution = dynamic.Solve(graph);
  });
  do {
    status = future_dp.wait_for(std::chrono::milliseconds(0));
  } while (status != std::future_status::ready && 
          (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start).count() < time_limit));
  if (status == std::future_status::ready) {
    future_dp.get();
    end = std::chrono::high_resolution_clock::now();
    time = std::to_string(std::chrono::duration<float, std::milli>(end - start).count());
  } else {
    time = "EXCESIVO";
    solution.second = -1;
  }
  // PrintResult(solution, time);
  times.emplace_back(time);
  write(graph->getNodes().size(), time, 2);
  start = std::chrono::high_resolution_clock::now();
  auto future_greedy = std::async(std::launch::async, [&] {
    solution = greedy.Solve(graph);
  });
  do {
    status = future_greedy.wait_for(std::chrono::milliseconds(0));
  } while (status != std::future_status::ready &&
          (std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start).count() < time_limit));
  if (status == std::future_status::ready) {
    future_greedy.get();
    end = std::chrono::high_resolution_clock::now();
    time = std::to_string(std::chrono::duration<float, std::milli>(end - start).count());
  } else {
    time = "EXCESIVO";
    solution.second = -1;
  }
  // PrintResult(solution, time);
  times.emplace_back(time);
  write(graph->getNodes().size(), time, 3);
  pending_futures.emplace_back(std::move(future_brute));
  pending_futures.emplace_back(std::move(future_dp));
  pending_futures.emplace_back(std::move(future_greedy));
  return times;
}

/**
 * @brief Prints the result of the execution.
 * 
 * @param solution Solution of the algorithm.
 * @param time Time of the execution of the algorithm.
 */
void PrintResult(const Solution& solution, const std::string& time) {
  std::cout << solution.second << "              " << time << "               ";
}

void write(int nodes, std::string time, int line) {
  std::ofstream file("results.csv", std::ios::app);
  if (line == 0) {
    file << "Nodes,Time Brute Force,Time Dynamic Programming,Time Greedy" << std::endl;
  } else if (line == 1) {
    file << nodes << "," << time << ",";
  } else if  (line == 2) {
    file << time << ",";
  } else {
    file << time << std::endl;
  }
  file.close(); 
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