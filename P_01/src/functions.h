/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief functions.h
 *       This file contains the declaration of the functions used in the program.
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

void Help(void) {
  std::cout << "Usage: ./pr_01 <rows1> <cols1> <cols2> <selection>\n";
  std::cout << "selection: 1 recorrer por filas, 2 recorrer por columnas.\n";
}

void FillMatrix(std::vector<std::vector<int>>& matrix, 
    const int& rows, const int& cols) {
  for (int i = 0; i < rows; i++) {
    matrix[i].resize(cols);
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = (rand() % 9) + 1;
    }
  }
}

void WriteSpecs(const int& rows1, const int& cols1, const int& rows2, 
    const int& cols2, const int& miliseconds, const int& selection) {
  std::ofstream file;
  file.open("specs.csv", std::ios::app);
  file << rows1 << "," << cols1 << "," << rows2 << "," << cols2 << ","; 
  file << miliseconds << "," << selection << "\n";
  file.close();
}