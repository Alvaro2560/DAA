/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file algorithm.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Algorithm.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <vector>

class Algorithm {
  public:
    std::vector<int> Solve(const std::vector<int>& array, const size_t& size);
    std::string Recurrence(void);
  protected:
    virtual bool Small(const std::vector<int>& array) = 0;
    virtual std::vector<int> SolveSmall(const std::vector<int>& array) = 0;
    virtual std::pair<std::vector<int>, std::vector<int>> Divide(const std::vector<int>& array, const size_t& size) = 0;
    virtual std::vector<int> Combine(const std::vector<int>& solution1, const std::vector<int>& solution2) = 0;
    virtual std::string getRecurrence(void) = 0;
};