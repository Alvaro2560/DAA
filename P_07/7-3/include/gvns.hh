/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file gvns.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class GVNS.
 * @version 0.1
 * @since Apr 12 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

/**
 * @class GVNS
 * @brief Class that represents the GVNS algorithm.
 */
class GVNS : public Algorithm {
  public:
    GVNS(void) = default;
    ~GVNS(void) = default;
    Solution Run(const Problem& problem) override;
};