/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file output-unit.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of OutputUnit class.
 * @version 1.0
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>

/**
 * @brief Class that represents the output unit.
 */
class OutputUnit {
  public:
    OutputUnit(void);
    void process(const int& data);
    int* getTape(void) const;
    size_t getSize(void) const;
    ~OutputUnit(void);
  private:
    int* tape_;
    size_t size_;
};