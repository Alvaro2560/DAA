/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file algorithm.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Algorithm.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

class Problem;
class Solution;

/**
 * @class Algorithm
 * @brief Base class that represents an algorithm.
 */
class Algorithm {
  public:
    Algorithm(void) = default;
    ~Algorithm(void) = default;
    virtual Solution Run(const Problem& problem) = 0;
    float getTime(void) const { return time_; }
  protected:
    float time_;
};