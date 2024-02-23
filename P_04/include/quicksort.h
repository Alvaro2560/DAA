/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file quicksort.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class QuickSort.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.h"
#include "dyv.h"

namespace DyV {
  class QuickSort : public Algorithm {
    private:
      bool Small(int* array, int size) override;
      int* SolveSmall(int* array, int size) override;
      int** Divide(int* array, int size) override;
      int* Combine(int* solution1, int* solution2, int size) override;
      std::string getRecurrence(void) override;
  };
}