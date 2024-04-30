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
#include "../include/greedy.hh"

#include <algorithm>

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
 * @brief Removes an element from the solution.
 * 
 * @param index Index of the element to be removed.
 */
void Solution::removeElement(const size_t index) {
  elements_.erase(elements_.begin() + index);
}

/**
 * @brief Removes an element from the solution.
 * 
 * @param element Element to be removed.
 */
void Solution::removeElement(const Element& element) {
  elements_.erase(std::remove(elements_.begin(), elements_.end(), element), elements_.end());
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
 * @brief Swaps two elements of the solution.
 * 
 * @param index1 Index of the first element.
 * @param index2 Index of the second element.
 */
void Solution::SwapElements(const size_t index1, const size_t index2) {
  std::swap(elements_[index1], elements_[index2]);
}

/**
 * @brief Returns the total distance of the solution.
 * 
 * @return double Total distance of the solution.
 */
double Solution::TotalDistance(void) const {
  return Greedy().TotalDistance(elements_);
}

/**
 * @brief Overload of the operator < for the Solution class.
 * 
 * @param solution Solution to compare.
 * @return true If the current solution is less than the other.
 * @return false If the current solution is not less than the other.
 */
bool Solution::operator<(const Solution& solution) const {
  return Greedy().TotalDistance(elements_) < Greedy().TotalDistance(solution.getElements());
}

/**
 * @brief Overload of the operator == for the Solution class.
 * 
 * @param solution Solution to compare.
 * @return true If the current solution is equal to the other.
 * @return false If the current solution is not equal to the other.
 */
bool Solution::operator==(const Solution& solution) const {
  return Greedy().TotalDistance(elements_) == Greedy().TotalDistance(solution.getElements());
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
  os << "Distance: ";
  os << Greedy().TotalDistance(solution.getElements()) << std::endl;
  return os;
}