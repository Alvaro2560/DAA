/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file task.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Task.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <map>

/**
 * @class Task
 * @brief Class that represents a task.
 */
class Task {
  public:
    Task(const int& id, const int& processing_time);
    ~Task(void);
    int getId(void) const;
    int getProcessingTime(void) const;
    int getPreparationTime(const int& id) const;
    bool isScheduled(void) const;
    void setScheduled(void);
    void addPreparationTime(const int& id, const int& time);
  private:
    int id_;
    int processing_time_;
    std::map<int, int> preparation_times_;
    bool scheduled_;
};