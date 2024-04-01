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
#include "../include/task.hh"

Solution::Solution(const int& machines) : tasks_(machines), tcts_(machines, 0) { }

void Solution::addTask(const int& machine, Task* task) {
  tasks_[machine].emplace_back(task);
}

std::vector<Task*> Solution::getTasks(const int& machine) const {
  return tasks_[machine];
}

Task* Solution::getLastTask(const int& machine) {
  return tasks_[machine].back();
}

int Solution::getTCT(void) const {
  int tct = 0;
  for (size_t i = 0; i < tcts_.size(); i++) {
    tct += tcts_[i];
  }
  return tct;
}

int Solution::getTCT(const int& machine) const {
  return tcts_[machine];
}

void Solution::sumTCT(const int& machine) {
  for (size_t i = 0; i < tasks_[machine].size(); i++) {
    if (i == 0) {
      tcts_[machine] += tasks_[machine][i]->getPreparationTime(0) + tasks_[machine][i]->getProcessingTime();
    } else {
      tcts_[machine] += tasks_[machine][i]->getPreparationTime(tasks_[machine][i - 1]->getId()) + tasks_[machine][i]->getProcessingTime();
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Solution& solution) {
  for (size_t i = 0; i < solution.tasks_.size(); ++i) {
    os << "Machine " << i + 1 << ": ";
    for (size_t j = 0; j < solution.tasks_[i].size(); ++j) {
      os << solution.tasks_[i][j]->getId() << " ";
    }
    os << "\nTCT: " << solution.tcts_[i] << std::endl;
  }
  os << "Total TCT: " << solution.getTCT() << std::endl;
  return os;
}