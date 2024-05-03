/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file problem.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Problem.
 * @version 0.1
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <string>
#include <iostream>

typedef std::vector<double> Element;

/**
 * @class Problem
 * @brief Class that represents a problem.
 */
class Problem {
  public:
    Problem(const std::string& filename, const int& dimension);
    ~Problem(void) = default;
    int getDimension(void) const;
    std::vector<Element> getElements(void) const;
    void addElement(const Element& element);
    void removeElement(const Element& element);
    friend std::ostream& operator<<(std::ostream& os, const Problem& problem);
  private:
    int dimension_;
    std::vector<Element> elements_;
};

std::ostream& operator<<(std::ostream& os, const Problem& problem);