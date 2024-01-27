/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief
 * 
 * @see https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design
 * @see https://refactoring.guru/design-patterns/strategy
 */

class ProductoMatrices {
  public:
    virtual void multiplicarMatrices(
        const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) = 0;
};

class ProductoFilas : public ProductoMatrices {
public:
    void multiplicarMatrices(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) override {
      resultado.resize(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
      for (size_t i = 0; i < matrix1.size(); ++i) {
          for (size_t j = 0; j < matrix2[0].size(); ++j) {
              for (size_t k = 0; k < matrix1[0].size(); ++k) {
                  resultado[i][j] += matrix1[i][k] * matrix2[k][j];
              }
          }
      }
    }
};

class ProductoColumnas : public ProductoMatrices {
  public:
    void multiplicarMatrices(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) override {
      resultado.resize(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
      for (size_t j = 0; j < matrix2[0].size(); ++j) {
          for (size_t i = 0; i < matrix1.size(); ++i) {
              for (size_t k = 0; k < matrix1[0].size(); ++k) {
                  resultado[i][j] += matrix1[i][k] * matrix2[k][j];
              }
          }
      }
    }
};

class Contexto {
  public:
    Contexto(ProductoMatrices* estrategia) : estrategia_(estrategia) { }
    void ejecutarProductoMatrices(const std::vector<std::vector<int>>& matrix1,
        const std::vector<std::vector<int>>& matrix2,
        std::vector<std::vector<int>>& resultado) const {
        estrategia_->multiplicarMatrices(matrix1, matrix2, resultado);
    }
  private:
    ProductoMatrices* estrategia_;
};

#include <iostream>
#include <vector>
#include <random>

void FillMatrix(std::vector<std::vector<int>>& matrix, 
    const int& rows, const int& cols) {
  for (int i = 0; i < rows; i++) {
    matrix[i].resize(cols);
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = (rand() % 100) + 1;
    }
  }
}

int main(int argc, char** argv) {
  int rows1, cols1, rows2, cols2;
  if (argc != 4) {
    // Help();
    do {
      std::cout << "Introduce el número de filas de la primera matriz: ";
      std::cin >> rows1;
      std::cout << "Introduce el número de columnas de la primera matriz: ";
      std::cin >> cols1;
    } while (rows1 <= 0 || cols1 <= 0);
    rows2 = cols1;
    do {
      std::cout << "Introduce el número de columnas de la segunda matriz: ";
      std::cin >> cols2;
    } while (cols2 <= 0);
  } else {
    rows1 = std::atoi(argv[1]);
    cols1 = std::atoi(argv[2]);
    rows2 = cols1;
    cols2 = std::atoi(argv[3]);
  }
  srand(time(nullptr));
  std::vector<std::vector<int>> matrix1(rows1);
  FillMatrix(matrix1, rows1, cols1);
  std::vector<std::vector<int>> matrix2(rows2);
  FillMatrix(matrix2, rows2, cols2);
  return 0;
}