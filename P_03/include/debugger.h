/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file debugger.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Debugger.
 * @version 0.1
 * @since Feb 12 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

class RAM;

/**
 * @brief Class that represents the debugger.
 */
class Debugger {
  public:
    Debugger(void) = default;
    static void increment(void);
    static void print_info(const RAM& ram);
    ~Debugger() = default;
  private:
    static int instruction_counter_;
};