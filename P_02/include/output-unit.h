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

#include <vector>
#include <string>

/**
 * @brief Class that represents the output unit.
 */
class OutputUnit {
  public:
    OutputUnit(const std::string& file_name);
    void process(const int& data);
    size_t getSize(void);
    void write(void);
    ~OutputUnit(void);
  private:
    int* tape_;
    size_t size_;
    std::string file_name_;
};