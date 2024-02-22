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

class Algorithm {
  public:
    int* Solve(int* array, int size);
  protected:
    virtual bool Small(int* array) = 0;
    virtual int* SolveSmall(int* array) = 0;
    virtual int** Divide(int* array, int size) = 0;
    virtual int* Combine(int* solution1, int* solution2) = 0;
};