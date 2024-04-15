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
 * @brief Add a task to a machine in a specific position.
 * 
 * @param machine Machine's id.
 * @param task_id Task's id.
 * @param position Position to add the task.
 */
void Solution::addTask(const int& machine, Task* task, const int& position) {
  tasks_[machine].insert(tasks_[machine].begin() + position, task);
}

/**
 * @brief Set the tasks of a machine.
 * 
 * @param machine Machine's id.
 * @param tasks Tasks to set.
 */
void Solution::setTasks(const int& machine, std::vector<Task*> tasks) {
  tasks_[machine] = tasks;
}

/**
 * @brief Get the number of machines.
 * 
 * @return int Number of machines.
 */
int Solution::getMachines(void) const {
  return (int)tasks_.size();
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
 * @brief Calculate the total completion time.
 * 
 * @return int Total completion time.
 */
void Solution::calculateTCT(void) {
  for (size_t i = 0; i < tcts_.size(); i++) {
    tcts_[i] = 0;
  }
  for (size_t i = 0; i < tasks_.size(); i++) {
    int tct = 0;
    for (size_t tasks = 0; tasks < tasks_[i].size(); tasks++) {
      int tct_machine = 0;
      for (size_t j = 0; j <= tasks; j++) {
        if (j == 0) {
          tct_machine += tasks_[i][j]->getPreparationTime(0) + tasks_[i][j]->getProcessingTime();
        } else {
          tct_machine += tasks_[i][j]->getPreparationTime(tasks_[i][j - 1]->getId()) + tasks_[i][j]->getProcessingTime();
        }
      }
      tct += tct_machine;
    }
    tcts_[i] = tct;
  }
}

/**
 * @brief Check if a task belongs to a machine.
 * 
 * @param machine Machine's id.
 * @param task_id Task's id.
 * @return true If the task belongs to the machine.
 * @return false If the task does not belong to the machine.
 */
bool Solution::taskBelongsToMachine(const int& machine, const int& task_id) const {
  for (size_t i = 0; i < tasks_[machine].size(); i++) {
    if (tasks_[machine][i]->getId() == task_id) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Remove a task from a machine.
 * 
 * @param machine Machine's id.
 * @param task_index Task's index.
 */
void Solution::removeTask(const int& machine, const int& task_index) {
  tasks_[machine].erase(tasks_[machine].begin() + task_index);
  tcts_[machine] = 0;
  calculateTCT();
}

/**
 * @brief Swap two tasks of a machine.
 * 
 * @param machine Machine's id.
 * @param task_index1 Index of the first task.
 * @param task_index2 Index of the second task.
 */
void Solution::swapTasks(const int& machine, const int& task_index1, const int& task_index2) {
  Task* task1 = tasks_[machine][task_index1];
  Task* task2 = tasks_[machine][task_index2];
  tasks_[machine][task_index1] = task2;
  tasks_[machine][task_index2] = task1;
  tcts_[machine] = 0;
  calculateTCT();
}

/**
 * @brief Swap two tasks of different machines.
 * 
 * @param machine1 First machine's id.
 * @param task_index1 Index of the first task.
 * @param machine2 Second machine's id.
 * @param task_index2 Index of the second task.
 */
void Solution::swapTasks(const int& machine1, const int& task_index1, const int& machine2, const int& task_index2) {
  Task* task1 = tasks_[machine1][task_index1];
  Task* task2 = tasks_[machine2][task_index2];
  tasks_[machine1][task_index1] = task2;
  tasks_[machine2][task_index2] = task1;
  tcts_[machine1] = 0;
  tcts_[machine2] = 0;
  calculateTCT();
}

/**
 * @brief Overload of the operator =.
 * 
 * @param solution Solution to copy.
 * @return Solution& Copied solution.
 */
Solution& Solution::operator=(const Solution& solution) {
  tasks_ = solution.tasks_;
  tcts_ = solution.tcts_;
  return *this;
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