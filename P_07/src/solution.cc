/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solution.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class Solution.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/solution.hh"

Solution::Solution(const int& machines) : tasks_(machines) { }

void Solution::addTask(const int& machine, const Task& task) {
  tasks_[machine].emplace_back(task);
}

std::vector<Task> Solution::getTasks(const int& machine) const {
  return tasks_[machine];
}