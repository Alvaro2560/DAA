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

/**
 * @brief Construct a new Solution::Solution object
 * 
 * @param machines Number of machines.
 */
Solution::Solution(const int& machines) : tasks_(machines), tcts_(machines, 0) { }

/**
 * @brief Add a task to a machine.
 * 
 * @param machine Machine's id.
 * @param task Task to add.
 */
void Solution::addTask(const int& machine, Task* task) {
  tasks_[machine].emplace_back(task);
}

/**
 * @brief Get the tasks of a machine.
 * 
 * @param machine Machine's id.
 * @return std::vector<Task*> Tasks of the machine.
 */
std::vector<Task*> Solution::getTasks(const int& machine) const {
  return tasks_[machine];
}

/**
 * @brief Get the last task of a machine.
 * 
 * @param machine Machine's id.
 * @return Task* Last task of the machine.
 */
Task* Solution::getLastTask(const int& machine) {
  return tasks_[machine].back();
}

/**
 * @brief Get the total completion time.
 * 
 * @return int Total completion time.
 */
int Solution::getTCT(void) const {
  int tct = 0;
  for (size_t i = 0; i < tcts_.size(); i++) {
    tct += tcts_[i];
  }
  return tct;
}

/**
 * @brief Get the total completion time of a machine.
 * 
 * @param machine Machine's id.
 * @return int Total completion time of the machine.
 */
int Solution::getTCT(const int& machine) const {
  return tcts_[machine];
}

/**
 * @brief Sum the total completion time of a machine.
 * 
 * @param machine Machine's id.
 */
void Solution::sumTCT(const int& machine) {
  for (size_t i = 0; i < tasks_[machine].size(); i++) {
    if (i == 0) {
      tcts_[machine] += tasks_[machine][i]->getPreparationTime(0) + tasks_[machine][i]->getProcessingTime();
    } else {
      tcts_[machine] += tasks_[machine][i]->getPreparationTime(tasks_[machine][i - 1]->getId()) + tasks_[machine][i]->getProcessingTime();
    }
  }
}

/**
 * @brief Overload of the operator <<.
 * 
 * @param os Output stream.
 * @param solution Solution to print.
 * @return std::ostream& Output stream.
 */
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