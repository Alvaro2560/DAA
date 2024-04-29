/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solution.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Solution.
 * @version 0.1
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <iostream>

typedef std::vector<double> Element;

/**
 * @class Solution
 * @brief Class that represents a solution.
 */
class Solution {
  public:
    Solution(void) = default;
    ~Solution(void) = default;
    std::vector<Element> getElements(void) const;
    void setElements(const std::vector<Element>& elements);
    void addElement(const Element& element);
    void removeElement(const size_t index);
    size_t size(void) const;
    void SwapElements(const size_t index1, const size_t index2);
    double TotalDistance(void) const;
    bool operator<(const Solution& solution) const;
    bool operator==(const Solution& solution) const;
    friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
  private:
    std::vector<Element> elements_;
};

std::ostream& operator<<(std::ostream& os, const Solution& solution);