/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief product.h
 *        This file contains the declaration of the Product class and its
 *       subclasses RowProduct and ColumnProduct.
 * 
 * @see https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design
 * @see https://refactoring.guru/design-patterns/strategy
 */

#pragma once

#include <iostream>
#include <vector>

class Product {
  public:
    virtual void MatrixProduct(
        const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) = 0;
};

class RowProduct : public Product {
  public:
    void MatrixProduct(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) override {
      resultado.resize(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
      for (size_t i = 0; i < matrix1.size(); i++) {
        for (size_t j = 0; j < matrix2[0].size(); j++) {
          for (size_t k = 0; k < matrix1[0].size(); k++) {
            resultado[i][j] += matrix1[i][k] * matrix2[k][j];
          }
        }
      }
    }
};

class ColumnProduct : public Product {
  public:
    void MatrixProduct(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) override {
      resultado.resize(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
      for (size_t j = 0; j < matrix2[0].size(); j++) {
        for (size_t i = 0; i < matrix1.size(); i++) {
          for (size_t k = 0; k < matrix1[0].size(); k++) {
            resultado[i][j] += matrix1[i][k] * matrix2[k][j];
          }
        }
      }
    }
};