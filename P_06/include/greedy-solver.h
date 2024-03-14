/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file greedy-solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Greedy.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "solver.h"

class Greedy : public Solver {
  public:
    Greedy(void) = default;
    ~Greedy(void) = default;
  private:
    void RunAlgorithm(Graph* graph) override;
};