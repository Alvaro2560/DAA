/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solver.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Solver.
 * @version 0.1
 * @since Mar 14 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "graph.h"

#include <future>
#include <chrono>
#include <thread>
#include <iostream>

typedef std::pair<std::vector<Node*>, int> Solution;

/**
 * @brief Class that represents a solver for a graph.
 */
class Solver {
  public:
    Solver(void) = default;
    Solution Solve(Graph* graph, const int& time_limit, std::string& time) {
        auto start = std::chrono::steady_clock::now();

        // Iniciar la tarea asíncrona
        std::future<Solution> future = std::async(std::launch::async, [this, graph] {
            return this->RunAlgorithm(graph);
        });

        bool timeout = false;

        // Esperar hasta que la tarea se complete o el tiempo límite expire
        std::future_status status = future.wait_for(std::chrono::minutes(time_limit));
        
        if (status == std::future_status::timeout) {
            // Si la tarea excede el límite de tiempo, cancelarla
            future.get();
            timeout = true;
        }

        // Calcular el tiempo transcurrido
        auto end = std::chrono::steady_clock::now();
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        time = std::to_string(duration.count()); // Convertir a string para almacenar el tiempo

        // Manejar el caso de tiempo excedido
        if (timeout) {
            time = "EXCESIVO";
            return Solution();
        }

        // Obtener el resultado de la tarea
        return future.get();
    
    }
    ~Solver(void) = default;
  protected:
    virtual Solution RunAlgorithm(Graph* graph) = 0;
};