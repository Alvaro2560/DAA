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
  bool read_processing_times = false;
  bool read_preparation_times = false;
  while (std::getline(file, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);
    std::string key;
    if (!(iss >> key)) {
      throw std::runtime_error("Error: Invalid format.");
    }
    if (key == "n:") {
      if (!(iss >> tasks_)) {
        throw std::runtime_error("Error: Invalid format for tasks.");
      }
    } else if (key == "m:") {
      if (!(iss >> machines_)) {
        throw std::runtime_error("Error: Invalid format for machines.");
      }
    } else if (key == "Pi") {
      read_processing_times = true;
      processing_times_.resize(tasks_);
      for (int i = 0; i < tasks_; ++i) {
        if (!(iss >> processing_times_[i])) {
          throw std::runtime_error("Error: Invalid format for processing times.");
        }
      }
    } else if (key == "Sij") {
      read_preparation_times = true;
      // Leer los tiempos de preparación
      preparation_times_.resize(tasks_ + 1, std::vector<int>(tasks_ + 1));
      for (int i = 0; i < tasks_ + 1; i++) {
        if (!std::getline(file, line)) {
          throw std::runtime_error("Error: Unexpected end of file while reading preparation times.");
        }
        std::istringstream iss_sij(line);
        for (int j = 0; j < tasks_ + 1; j++) {
          if (!(iss_sij >> preparation_times_[i][j])) {
            throw std::runtime_error("Error: Invalid format for preparation times.");
          }
        }
      }
    } else {
      throw std::runtime_error("Error: Unknown key '" + key + "'.");
    }
  }
  if (!read_processing_times || !read_preparation_times) {
    throw std::runtime_error("Error: Incomplete data in file.");
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
  os << "Tasks: " << problem.tasks_ << std::endl;
  os << "Machines: " << problem.machines_ << std::endl;
  os << "Processing times: ";
  for (int i = 0; i < problem.tasks_; ++i) {
    os << problem.processing_times_[i] << " ";
  }
  os << std::endl;
  os << "Preparation times: " << std::endl;
  for (int i = 0; i < problem.tasks_ + 1; i++) {
    for (int j = 0; j < problem.tasks_ + 1; j++) {
      os << problem.preparation_times_[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}