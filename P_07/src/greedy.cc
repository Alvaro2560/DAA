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
  std::vector<Task*> ordered_tasks = problem.getTasks();
  std::sort(ordered_tasks.begin(), ordered_tasks.end(), [](Task* task1, Task* task2) {
    return task1->getPreparationTime(0) + task1->getProcessingTime() < task2->getPreparationTime(0) + task2->getProcessingTime();
  });
  for (int i = 1; i <= problem.getMachines(); i++) {
    ordered_tasks[i]->setScheduled();
    solution.addTask(i - 1, ordered_tasks[i]);
    solution.sumTCT(i - 1);
  }
  const int kMachines = problem.getMachines();
  int current_machine = 0;
  while (!problem.allTasksScheduled()) {
    if (current_machine < kMachines) {
      Task* lower_tct_task = problem.getLowerTCTTask(solution.getLastTask(current_machine)->getId());
      lower_tct_task->setScheduled();
      solution.addTask(current_machine, lower_tct_task);
      solution.sumTCT(current_machine);
      ++current_machine;
    } else {
      current_machine = 0;
    }
  }
  return solution;
}