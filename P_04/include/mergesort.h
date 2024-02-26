/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file mergesort.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class MergeSort.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.h"

namespace DyV {
  class MergeSort : public Algorithm {
    private:
      bool Small(const std::vector<int>& array) override;
      std::vector<int> SolveSmall(const std::vector<int>& array) override;
      std::pair<std::vector<int>, std::vector<int>> Divide(const std::vector<int>& array, const size_t& size) override;
      std::vector<int> Combine(const std::vector<int>& solution1, const std::vector<int>& solution2) override;
      std::string getRecurrence(void) override;
  };
}