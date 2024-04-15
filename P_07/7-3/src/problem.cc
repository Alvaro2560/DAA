/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file problem.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class Problem.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/problem.hh"
#include "../include/task.hh"

#include <fstream>
#include <sstream>
#include <iostream>
#include <climits>
#include <algorithm>

/**
 * @brief Construct a new Problem:: Problem object.
 * 
 * @param file_name File name of the problem instance.
 */
Problem::Problem(const std::string& file_name) {
  ReadFile(file_name);
}

/**
 * @brief Destroy the Problem:: Problem object.
 */
Problem::~Problem(void) { }

/**
 * @brief Read the problem instance from a file.
 * 
 * @param file_name File name of the problem instance.
 */
void Problem::ReadFile(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Error: file not found.");
  }
  std::string line;
  int tasks = 0;
  while (std::getline(file, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);
    std::string key;
    if (!(iss >> key)) {
      throw std::runtime_error("Error: Invalid format.");
    }
    if (key == "n:") {
      if (!(iss >> tasks)) {
        throw std::runtime_error("Error: Invalid format for tasks.");
      }
    } else if (key == "m:") {
      if (!(iss >> machines_)) {
        throw std::runtime_error("Error: Invalid format for machines.");
      }
    } else if (key[2] == ':' || key[2] == '[') {
      int processing_time;
      tasks_.emplace_back(new Task(0, 0));
      tasks_[0]->setScheduled();
      for (int i = 1; i <= tasks; i++) {
        if (!(iss >> processing_time)) {
          throw std::runtime_error("Error: Invalid format for processing times.");
        }
        tasks_.emplace_back(new Task(i, processing_time));
      }
    } else if (key[3] == ':') {
      for (int i = 0; i < tasks + 1; i++) {
        if (!std::getline(file, line)) {
          throw std::runtime_error("Error: Unexpected end of file while reading preparation times.");
        }
        std::istringstream iss_sij(line);
        for (int j = 0; j < tasks + 1; j++) {
          int preparation_time;
          if (!(iss_sij >> preparation_time)) {
            throw std::runtime_error("Error: Invalid format for preparation times.");
          }
          tasks_[j]->addPreparationTime(i, preparation_time);
        }
      }
    } else {
      throw std::runtime_error("Error: Unknown key '" + key + "'.");
    }
  }
  file.close();
}

/**
 * @brief Get the number of machines.
 * 
 * @return int Number of machines.
 */
int Problem::getMachines(void) const {
  return machines_;
}

/**
 * @brief Get the tasks.
 * 
 * @return const std::vector<Task*>& Tasks.
 */
const std::vector<Task*>& Problem::getTasks(void) const {
  return tasks_;
}

/**
 * @brief Get a task by its id.
 * 
 * @param id Task id.
 * @return const Task* Task.
 */
const Task* Problem::getTask(const int& id) const {
  return tasks_[id];
}

/**
 * @brief Check if all tasks are scheduled.
 * 
 * @return true If all tasks are scheduled.
 * @return false If not all tasks are scheduled.
 */
bool Problem::allTasksScheduled(void) const {
  for (const Task* task : tasks_) {
    if (!task->isScheduled()) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Get the task with the lower total completion time.
 * 
 * @param prev_task Id of the previous task.
 * @return Task* Task with the lower total completion time.
 */
Task* Problem::getLowerTCTTask(const int& prev_task) const {
  std::vector<Task*> candidates;
  for (Task* task : tasks_) {
    if (!task->isScheduled()) {
      candidates.emplace_back(task);
    }
  }
  std::sort(candidates.begin(), candidates.end(), [prev_task](Task* task1, Task* task2) {
    return task1->getPreparationTime(prev_task) + task1->getProcessingTime() < task2->getPreparationTime(prev_task) + task2->getProcessingTime();
  });
  return candidates[0];
}

/**
 * @brief Get the tasks with the lower total completion time.
 * 
 * @param prev_task Id of the previous task.
 * @param tasks Number of tasks to get.
 * @return std::vector<Task*> Tasks with the lower total completion time.
 */
std::vector<Task*> Problem::getLowerTCTTasks(const int& prev_task, const int& tasks) const {
  std::vector<Task*> candidates;
  for (Task* task : tasks_) {
    if (!task->isScheduled()) {
      candidates.emplace_back(task);
    }
  }
  std::sort(candidates.begin(), candidates.end(), [prev_task](Task* task1, Task* task2) {
    return task1->getPreparationTime(prev_task) + task1->getProcessingTime() < task2->getPreparationTime(prev_task) + task2->getProcessingTime();
  });
  if (tasks > (int)candidates.size()) {
    return candidates;
  }
  return std::vector<Task*>(candidates.begin(), candidates.begin() + tasks);
}

/**
 * @brief Reset the problem instance.
 */
void Problem::reset(void) const {
  for (size_t i = 1 ; i < tasks_.size(); i++) {
    tasks_[i]->setScheduled();
  }
}

/**
 * @brief Overload of the operator << for the Problem class.
 * 
 * @param os Output stream.
 * @param problem Problem instance.
 * @return std::ostream& Output stream.
 */
std::ostream& operator<<(std::ostream& os, const Problem& problem) {
  const size_t kTaskNum = problem.tasks_.size();
  os << "Tasks: " << kTaskNum << std::endl;
  os << "Machines: " << problem.machines_ << std::endl;
  os << "Processing times: ";
  for (size_t i = 0; i < kTaskNum; ++i) {
    os << problem.tasks_[i]->getProcessingTime() << " ";
  }
  os << std::endl;
  os << "Preparation times: " << std::endl;
  for (size_t i = 0; i < kTaskNum; ++i) {
    for (size_t j = 0; j < kTaskNum; ++j) {
      os << problem.tasks_[i]->getPreparationTime(j) << " ";
    }
    os << std::endl;
  }
  return os;
}