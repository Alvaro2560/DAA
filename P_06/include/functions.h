/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the functions used on the program.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "graph.h"
#include "solver.h"

#include <vector>
#include <unordered_map>

/**
 * @brief Struct that represents the final data of the solution.
 */
struct Data {
  std::vector<Solution> solutions;
  std::vector<std::string> times;
};

std::vector<std::string> ReadFile(const std::string& file_name);
Graph* CreateGraph(const std::vector<std::string>& file_content);
Data CalculateTimes(Graph* graph, const int& time_limit);
void PrintResults(const Data& data, const std::string& file_name);
void CreateInstances(const int& instances);
void GenerateRandomInstance(int numNodes, std::string file_name);