/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file units.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the classes BaseUnit, InputUnit and OutputUnit.
 * @version 0.1
 * @since Feb 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>

class Tape;

/**
 * @brief Basic class that represents a unit.
 */
class BaseUnit {
  public:
    BaseUnit(void) = default;
    virtual int process(void);
    virtual void process(const int& data);
  protected:
    std::vector<int> tape_;
    unsigned short int head_;
};

/**
 * @brief Class that represents the input unit.
 */
class InputUnit : public BaseUnit {
  public:
    InputUnit(const std::vector<int>& tape);
    int process(void) override;
};

/**
 * @brief Class that represents the output unit.
 */
class OutputUnit : public BaseUnit {
  public:
    OutputUnit(void);
    void process(const int& data) override;
};