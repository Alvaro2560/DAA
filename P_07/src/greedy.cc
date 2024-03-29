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
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/task.hh"

#include <algorithm>

Solution Greedy::Run(const Problem& problem) {
  Solution solution(problem.getMachines());
  std::vector<Task> ordered_tasks = problem.getTasks();
  std::sort(ordered_tasks.begin(), ordered_tasks.end(), [](const Task& task1, const Task& task2) {
    return task1.getPreparationTime(0) > task2.getPreparationTime(0);
  });
  for (int i = 0; i < problem.getMachines(); ++i) {
    solution.addTask(i, ordered_tasks[i]);
  }
  
  return solution;
}