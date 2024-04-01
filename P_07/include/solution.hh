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
#include <iostream>

class Task;

class Solution {
  public:
    Solution(const int& machines);
    ~Solution(void) = default;
    void addTask(const int& machine, Task* task);
    std::vector<Task*> getTasks(const int& machine) const;
    Task* getLastTask(const int& machine);
    int getTCT(void) const;
    int getTCT(const int& machine) const;
    void sumTCT(const int& machine);
    friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
  private:
    std::vector<std::vector<Task*>> tasks_;
    std::vector<int> tcts_;
};

std::ostream& operator<<(std::ostream& os, const Solution& solution);