/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file problem.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Problem.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <vector>

class Task;

/**
 * @class Problem
 * @brief Class that represents a problem instance.
 */
class Problem {
  public:
    Problem(const std::string& file_name);
    int getMachines(void) const;
    const std::vector<Task>& getTasks(void) const;
    const Task& getTask(int id) const;
    const std::vector<std::vector<int>>& getPreparationTimes(void) const;
    friend std::ostream& operator<<(std::ostream& os, const Problem& problem);
    ~Problem(void);
  private:
    void ReadFile(const std::string& file_name);
  private:
    int machines_;
    std::vector<Task> tasks_;
    std::vector<std::vector<int>> preparation_times_;
};

std::ostream& operator<<(std::ostream& os, const Problem& problem);