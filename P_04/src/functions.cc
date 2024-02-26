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

/**
 * @brief Prints the help message.
 * 
 */
void Help(void) {
  std::cout << "Usage: ./dyv <size> <[-m | --merge-sort] | [-q | --quick-sort]> [-f | --file] [filename]" << std::endl;
  std::cout << "Generates a random array of integers of the given size and sort it using the idicated algorithm." << std::endl;
}

/**
 * @brief Generates a random array of integers.
 * 
 * @param size The size of the array.
 * @return int* The generated array.
 */
std::vector<int> GenerateRandom(const size_t& size) {
  srand(time(NULL));
  std::vector<int> array(size);
  for (size_t i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}

/**
 * @brief Prints an array to the console.
 * 
 * @param array The array to print.
 * @param size The size of the array.
 */
void PrintArray(const std::vector<int>& array) {
  for (size_t i = 0; i < array.size(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Writes an array to a file.
 * 
 * @param array The array to write.
 * @param size The size of the array.
 * @param file_name The name of the file.
 */
void WriteArray(const std::vector<int>& array, const std::string& file_name) {
  std::ofstream file(file_name);
  for (size_t i = 0; i < array.size(); i++) {
    file << array[i] << std::endl;
  }
  file.close();
}