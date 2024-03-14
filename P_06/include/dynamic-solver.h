/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file dynamic-solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Dynamic.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "solver.h"

class Dynamic : public Solver {
  public:
    Dynamic(void) = default;
    ~Dynamic(void) = default;
  private:
    void RunAlgorithm(Graph* graph) override;
};