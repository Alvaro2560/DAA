/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief main.cc
 *       This file contains the declaration of the main function.
 */

#include <chrono>

#include "product.h"
#include "context.h"
#include "functions.h"

int main(int argc, char** argv) {
  int rows1, cols1, rows2, cols2, sel;
  if (argc == 5) {
    rows1 = std::atoi(argv[1]);
    cols1 = std::atoi(argv[2]);
    rows2 = cols1;
    cols2 = std::atoi(argv[3]);
    sel = std::atoi(argv[4]);
  } else {
    Help();
    return 1;
  }
  srand(time(nullptr));
  std::vector<std::vector<int>> matrix1(rows1);
  FillMatrix(matrix1, rows1, cols1);
  std::vector<std::vector<int>> matrix2(rows2);
  FillMatrix(matrix2, rows2, cols2);
  Product* product;
  int selection;
  switch (sel) {
    case 1:
      product = new RowProduct();
      selection = 1;
      break;
    case 2:
      product = new ColumnProduct();
      selection = 2;
      break;
  }
  Context context(product);
  std::vector<std::vector<int>> resultado;
  auto start_time = std::chrono::high_resolution_clock::now();
  context.RunProduct(matrix1, matrix2, resultado);
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
  WriteSpecs(rows1, cols1, rows2, cols2, duration.count(), selection);
  return 0;
}