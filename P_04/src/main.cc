/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main file of the program.
 * @version 0.1
 * @since Feb 23 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/dyv.h"
#include "../include/functions.h"

#include <iostream>

int main(int argc, char** argv) {
  try {
    DyV::QuickSort quicksort;
    int* array = GenerateRandom(10);
    PrintArray(array, 10);
    int* solution = quicksort.Solve(array, 10);
    PrintArray(solution, 10);
    return 0;
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}