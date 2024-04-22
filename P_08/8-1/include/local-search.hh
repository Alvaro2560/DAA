/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file local-search.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the local search algorithm.
 * @version 0.1
 * @since Apr 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

/**
 * @class LocalSearch
 * @brief Class that represents a local search algorithm.
 */
class LocalSearch : public Algorithm {
  public:
    LocalSearch(void) = default;
    ~LocalSearch(void) = default;
    Solution Run(const Problem& problem) override;
};