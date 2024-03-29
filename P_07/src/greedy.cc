/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file greedy.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class Greedy.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/greedy.hh"

Solution Greedy::Run(const Problem& problem) {
  Solution solution;
  std::vector<Task> tasks = problem.getTasks();
  std::sort(tasks.begin(), tasks.end(), [](const Task& task1, const Task& task2) {
    return task1.getProcessingTime() > task2.getProcessingTime();
  });
  for (Task& task : tasks) {
    solution.addTask(task);
  }
  return solution;
}