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
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/solution.hh"

/**
 * @brief Returns the elements of the solution.
 * 
 * @return std::vector<Element> Elements of the solution.
 */
std::vector<Element> Solution::getElements(void) const {
  return elements_;
}

/**
 * @brief Sets the elements of the solution.
 * 
 * @param elements Elements to be set.
 */
void Solution::setElements(const std::vector<Element>& elements) {
  elements_ = elements;
}

/**
 * @brief Adds an element to the solution.
 * 
 * @param element Element to be added.
 */
void Solution::addElement(const Element& element) {
  elements_.emplace_back(element);
}

/**
 * @brief Returns the number of elements in the solution.
 * 
 * @return size_t Number of elements in the solution.
 */
size_t Solution::size(void) const {
  return elements_.size();
}

/**
 * @brief Overload of the operator << for the Solution class.
 * 
 * @param os Output stream.
 * @param solution Solution to be printed.
 * @return std::ostream& Output stream.
 */
std::ostream& operator<<(std::ostream& os, const Solution& solution) {
  for (const auto& element : solution.getElements()) {
    for (const auto& value : element) {
      os << value << " ";
    }
    os << std::endl;
  }
  return os;
}