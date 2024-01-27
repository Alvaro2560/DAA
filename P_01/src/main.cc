/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Álvaro Fontenla León
 * @since Jan 27 2024
 * @brief
 * @see
 */

#include <iostream>
#include <vector>

// Interfaz para la estrategia de producto de matrices
class EstrategiaProductoMatrices {
public:
    virtual void multiplicarMatrices(const std::vector<std::vector<int>>& matriz1,
                                      const std::vector<std::vector<int>>& matriz2,
                                      std::vector<std::vector<int>>& resultado) const = 0;

    virtual ~EstrategiaProductoMatrices() {}
};

// Estrategia concreta: producto por filas
class EstrategiaProductoFilas : public EstrategiaProductoMatrices {
public:
    void multiplicarMatrices(const std::vector<std::vector<int>>& matriz1,
                             const std::vector<std::vector<int>>& matriz2,
                             std::vector<std::vector<int>>& resultado) const override {
        // Verificar si las matrices son multiplicables
        if (matriz1[0].size() != matriz2.size()) {
            std::cerr << "No se pueden multiplicar las matrices. Dimensiones incorrectas." << std::endl;
            return;
        }

        // Inicializar la matriz de resultado
        resultado.resize(matriz1.size(), std::vector<int>(matriz2[0].size(), 0));

        // Realizar la multiplicación por filas
        for (size_t i = 0; i < matriz1.size(); ++i) {
            for (size_t j = 0; j < matriz2[0].size(); ++j) {
                for (size_t k = 0; k < matriz1[0].size(); ++k) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
    }
};

// Estrategia concreta: producto por columnas
class EstrategiaProductoColumnas : public EstrategiaProductoMatrices {
public:
    void multiplicarMatrices(const std::vector<std::vector<int>>& matriz1,
                             const std::vector<std::vector<int>>& matriz2,
                             std::vector<std::vector<int>>& resultado) const override {
        // Verificar si las matrices son multiplicables
        if (matriz1[0].size() != matriz2.size()) {
            std::cerr << "No se pueden multiplicar las matrices. Dimensiones incorrectas." << std::endl;
            return;
        }

        // Inicializar la matriz de resultado
        resultado.resize(matriz1.size(), std::vector<int>(matriz2[0].size(), 0));

        // Realizar la multiplicación por columnas
        for (size_t j = 0; j < matriz2[0].size(); ++j) {
            for (size_t i = 0; i < matriz1.size(); ++i) {
                for (size_t k = 0; k < matriz1[0].size(); ++k) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
    }
};

// Contexto que utiliza la estrategia de producto de matrices
class ContextoProductoMatrices {
private:
    EstrategiaProductoMatrices* estrategia;

public:
    ContextoProductoMatrices(EstrategiaProductoMatrices* estrategia) : estrategia(estrategia) {}

    void ejecutarProductoMatrices(const std::vector<std::vector<int>>& matriz1,
                                  const std::vector<std::vector<int>>& matriz2,
                                  std::vector<std::vector<int>>& resultado) const {
        estrategia->multiplicarMatrices(matriz1, matriz2, resultado);
    }
};

int main() {
    // Ejemplo de uso

    // Definir las matrices
    std::vector<std::vector<int>> matriz1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> matriz2 = {{7, 8}, {9, 10}, {11, 12}};

    // Uso de la estrategia de producto por filas
    EstrategiaProductoFilas estrategiaFilas;
    ContextoProductoMatrices contextoFilas(&estrategiaFilas);
    std::vector<std::vector<int>> resultadoFilas;
    contextoFilas.ejecutarProductoMatrices(matriz1, matriz2, resultadoFilas);

    // Uso de la estrategia de producto por columnas
    EstrategiaProductoColumnas estrategiaColumnas;
    ContextoProductoMatrices contextoColumnas(&estrategiaColumnas);
    std::vector<std::vector<int>> resultadoColumnas;
    contextoColumnas.ejecutarProductoMatrices(matriz1, matriz2, resultadoColumnas);

    // Mostrar los resultados
    std::cout << "Resultado del producto por filas:" << std::endl;
    for (const auto& row : resultadoFilas) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Resultado del producto por columnas:" << std::endl;
    for (const auto& row : resultadoColumnas) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

