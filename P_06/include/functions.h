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
#include <future>

extern std::vector<std::future<void>> pending_futures;

std::vector<std::string> ReadFile(const std::string& file_name);
Graph* CreateGraph(const std::vector<std::string>& file_content);
std::vector<std::string> CalculateTimes(Graph* graph, const float& time_limit);
void PrintResult(const Solution& solution, const std::string& time);
void CreateInstances(const int& instances);
void GenerateRandomInstance(int numNodes, std::string file_name);
void write(int nodes, std::string time, int line);