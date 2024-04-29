/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file greedy.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Greedy.
 * @version 0.1
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

#include <vector>

typedef std::vector<double> Element;

/**
 * @class Greedy
 * @brief Class that represents a greedy algorithm.
 */
class Greedy : public Algorithm {
  public:
    Greedy(void) = default;
    ~Greedy(void) = default;
    Solution Run(const Problem& problem) override;
    double CalculateEuclideanDistance(const Element& element1, const Element& element2);
    Element CalculateCentroid(const std::vector<Element>& elements);
};