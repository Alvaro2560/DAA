/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file units.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the classes InputUnit and OutputUnit.
 * @version 0.1
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
    ~InputUnit(void);
  private:
    int* tape_;
    int* head_;
};

/**
 * @brief Class that represents the output unit.
 */
class OutputUnit {
  public:
    OutputUnit(void);
    void process(const int& data);
    int* getTape(void);
    size_t getSize(void);
    ~OutputUnit(void);
  private:
    int* tape_;
    int* head_;
    size_t size_;
};