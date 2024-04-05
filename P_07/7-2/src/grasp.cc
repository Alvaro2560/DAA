/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file grasp.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class GRASP.
 * @version 0.1
 * @since Apr 01 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/grasp.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/task.hh"

#include <algorithm>
#include <climits>
#include <random>

/**
 * @brief Run the GRASP algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution to the problem.
 */
Solution GRASP::Run(const Problem& problem) {
  return Construct(problem);
}

/**
 * @brief Construct a solution using the GRASP algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution to the problem.
 */
Solution GRASP::Construct(const Problem& problem) {
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
      std::vector<Task*> candidates = problem.getLowerTCTTasks(solution.getLastTask(current_machine)->getId(), 3);
      Task* lower_tct_task = candidates[rand() % candidates.size()];
      if (lower_tct_task == nullptr) {
        break;
      }
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