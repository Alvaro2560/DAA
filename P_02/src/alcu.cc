/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file alcu.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the class ALCU.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/alcu.h"
#include "../include/instructions.h"
#include "../include/units.h"

#include <iostream>

/**
 * @brief Construct a new ALCU::ALCU object
 * 
 * @param program_memory
 */
ALCU::ALCU(Instruction** program_counter) : program_counter_(program_counter) { }

/**
 * @brief Run the ALCU.
 * 
 * @param data_memory 
 */
void ALCU::run(int* data_memory) {
  while ((*(program_counter_++))->execute(data_memory) != -1);
}