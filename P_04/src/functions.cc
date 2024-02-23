/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the functions used on the program.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>

// TODO: Create a namespace

/**
 * @brief Generates a random array of integers.
 * 
 * @param size The size of the array.
 * @return int* The generated array.
 */
int* GenerateRandom(int size) {
  srand(time(NULL));
  int* array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

/**
 * @brief Writes an array to a file.
 * 
 * @param array The array to write.
 * @param size The size of the array.
 * @param file_name The name of the file.
 */
void WriteArray(int* array, const int& size, const std::string& file_name) {
  std::ofstream file(file_name);
  for (int i = 0; i < size; i++) {
    file << array[i] << std::endl;
  }
  file.close();
}