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
    } else if (key == "Pi") {
      int processing_time;
      for (int i = 1; i <= tasks; i++) {
        if (!(iss >> processing_time)) {
          throw std::runtime_error("Error: Invalid format for processing times.");
        }
        tasks_.push_back(Task(i, processing_time));
      }
    } else if (key == "Sij") {
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
          tasks_[i].addPreparationTime(j, preparation_time);
        }
      }
    } else {
      throw std::runtime_error("Error: Unknown key '" + key + "'.");
    }
  }
  file.close();
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
  for (int i = 0; i < kTaskNum; ++i) {
    os << problem.tasks_[i].getProcessingTime() << " ";
  }
  os << std::endl;
  os << "Preparation times: " << std::endl;
  for (int i = 0; i < kTaskNum; ++i) {
    for (int j = 0; j < kTaskNum; ++j) {
      os << problem.tasks_[i].getPreparationTime(j) << " ";
    }
    os << std::endl;
  }
  return os;
}