/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file units.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the classes InputUnit and OutputUnit.
 * @version 1.0
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <iostream>

/**
 * @brief Class that represents the input unit.
 */
class InputUnit {
  public:
    InputUnit(const std::vector<int>& tape);
    int process(void);
    int* getTape(void);
    int* getHead(void);
    size_t getSize(void);
    ~InputUnit(void);
  private:
    int* tape_;
    int* head_;
    size_t size_;
};

/**
 * @brief Class that represents the output unit.
 */
class OutputUnit {
  public:
    OutputUnit(const std::string& file_name);
    void process(const int& data);
    int* getTape(void);
    size_t getSize(void);
    void write(void);
    ~OutputUnit(void);
  private:
    int* tape_;
    size_t size_;
    std::string file_name_;
};