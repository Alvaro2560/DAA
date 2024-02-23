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

// TODO: Implement the QuickSort class
class QuickSort : public Algorithm {
  private:
    bool Small(int* array) override;
    int* SolveSmall(int* array) override;
    int** Divide(int* array, int size) override;
    int* Combine(int* solution1, int* solution2) override;
};