/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief context.h
 *       This file contains the declaration of the Context class.
 * 
 * @see https://refactoring.guru/design-patterns/strategy
 */

#pragma once

#include "product.h"

class Context {
  public:
    Context(Product* strategy) : strategy_(strategy) { }
    void RunProduct(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) const {
      strategy_->MatrixProduct(matrix1, matrix2, resultado);
    }
  private:
    Product* strategy_;
};