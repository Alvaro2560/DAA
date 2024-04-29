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
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/problem.hh"

#include <fstream>
#include <iostream>

/**
 * @brief Construct a new Problem:: Problem object
 * 
 * @param filename Name of the file that contains the problem.
 * @param dimension Dimension of the solution to create.
 */
Problem::Problem(const std::string& filename, const int& dimension) : dimension_(dimension) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error: file not found.");
  }
  int n, k;
  file >> n >> k;
  elements_.resize(n);
  for (int i = 0; i < n; i++) {
    elements_[i].resize(k);
    for (int j = 0; j < k; j++) {
      std::string number;
      file >> number;
      if (number.find(',') != std::string::npos) {
        number.replace(number.find(','), 1, ".");
      }
      elements_[i][j] = std::stod(number);
    }
  }
  file.close();
}

/**
 * @brief Get the dimension of the problem.
 * 
 * @return int Dimension of the problem.
 */
int Problem::getDimension(void) const {
  return dimension_;
}

/**
 * @brief Get the elements of the problem.
 * 
 * @return std::vector<Element> Elements of the problem.
 */
std::vector<Element> Problem::getElements(void) const {
  return elements_;
}

/**
 * @brief Remove an element from the problem.
 * 
 * @param element Element to remove.
 */
void Problem::removeElement(const Element& element) {
  for (size_t i = 0; i < elements_.size(); ++i) {
    if (elements_[i] == element) {
      elements_.erase(elements_.begin() + i);
      return;
    }
  }
}

/**
 * @brief Overload of the operator <<.
 * 
 * @param os Output stream.
 * @param problem Problem to print.
 * @return std::ostream& Output stream.
 */
std::ostream& operator<<(std::ostream& os, const Problem& problem) {
  os << "Elements: " << std::endl;
  for (size_t i = 0; i < problem.elements_.size(); ++i) {
    os << "Element " << i << ": ";
    for (size_t j = 0; j < problem.elements_[i].size(); ++j) {
      os << problem.elements_[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}