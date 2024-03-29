/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solution.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Solution.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>

class Task;

class Solution {
  public:
    Solution(const int& machines);
    ~Solution(void) = default;
    void addTask(const int& machine, const Task& task);
    std::vector<Task> getTasks(const int& machine) const;
  private:
    std::vector<std::vector<Task>> tasks_;
};