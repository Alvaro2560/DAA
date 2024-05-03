/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file grasp.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the GRASP algorithm.
 * @version 0.1
 * @since Apr 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

#include <vector>

typedef std::vector<double> Element;

/**
 * @class Grasp
 * @brief Class that represents a GRASP algorithm.
 */
class GRASP : public Algorithm {
  public:
    GRASP(void) = default;
    ~GRASP(void) = default;
    Solution Run(const Problem& problem) override;
    Solution Construct(const Problem& problem);
    Solution LocalSearch(const Problem& problem, const Solution& solution);
};