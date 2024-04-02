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

Solution GRASP::Run(const Problem& problem) {
  return Construct(problem);
}

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
  std::vector<Solution*> candidates(5);
  for (int i = 0; i < 5; i++) {
    candidates[i] = new Solution(problem.getMachines());
  }
  for (size_t i = 0; i < 5; i++) {
    for (int j = 1; j <= problem.getMachines(); j++) {
      ordered_tasks[i]->setScheduled();
      candidates[i]->addTask(j - 1, ordered_tasks[j]);
      candidates[i]->sumTCT(j - 1);
    }
  }
  const int kMachines = problem.getMachines();
  int current_machine = 0;
  std::vector<Task*> scheduled_tasks;
  for (size_t i = 0; i < 5; i++) {
    for (int j = 0; j < kMachines; j++) {
      Task* lower_tct_task = problem.getLowerTCTTask(solution.getLastTask(current_machine)->getId());
      candidates[i]->addTask(current_machine, lower_tct_task);
      candidates[i]->sumTCT(current_machine);
      lower_tct_task->setScheduled();
      scheduled_tasks.emplace_back(lower_tct_task);
      ++current_machine;
      if (current_machine == kMachines) {
        current_machine = 0;
      }
    }
    for (size_t j = 0; j < scheduled_tasks.size(); j++) {
      scheduled_tasks[j]->setScheduled();
    }
    scheduled_tasks.clear();
  }
  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j < 5; j++) {
      if (current_machine < kMachines) {
        Task* rand_task;
        int index = rand() % ordered_tasks.size();
        while (ordered_tasks[index]->isScheduled()) {
          index = rand() % ordered_tasks.size();
        }
        rand_task = ordered_tasks[index];
        rand_task->setScheduled();
        scheduled_tasks.emplace_back(rand_task);
        candidates[i]->addTask(current_machine, rand_task);
        candidates[i]->sumTCT(current_machine);
        ++current_machine;
      } else {
        current_machine = 0;
      }
    }
    for (size_t j = 0; j < scheduled_tasks.size(); j++) {
      scheduled_tasks[j]->setScheduled();
    }
    scheduled_tasks.clear();
  }
  int best_solution, max_tct = INT_MAX;
  for (size_t i = 0; i < candidates.size(); i++) {
    if (candidates[i]->getTCT() < max_tct) {
      best_solution = i;
      max_tct = candidates[i]->getTCT();
    }
  }
  return *candidates[best_solution];
}