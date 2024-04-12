/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file grasp.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class GRASP.
 * @version 0.1
 * @since Apr 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

/**
 * @class GRASP
 * @brief Class that represents the GRASP algorithm.
 */
class GRASP : public Algorithm {
  public:
    GRASP(void) = default;
    ~GRASP(void) = default;
    Solution Run(const Problem& problem) override;
    Solution Construct(const Problem& problem);
  private:
    Solution ReinsertIntra(const Problem& problem, Solution& solution);
    Solution ReinsertInter(const Problem& problem, Solution& solution);
    Solution SwapIntra(const Problem& problem, Solution& solution);
    Solution SwapInter(const Problem& problem, Solution& solution);
};