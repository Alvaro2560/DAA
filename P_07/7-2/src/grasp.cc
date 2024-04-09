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
  Solution constructed_solution = Construct(problem);
  Solution best_solution = constructed_solution;
  int best_tct = constructed_solution.getTCT();
  int current_tct = best_tct;
  bool improved = true;
  while (improved) {
    improved = false;
    Solution reinsert_solution = ReinsertIntra(problem, constructed_solution);
    current_tct = reinsert_solution.getTCT();
    if (current_tct < best_tct) {
      best_solution = reinsert_solution;
      best_tct = current_tct;
      improved = true;
    }
    Solution reinsert_within_machine_solution = ReinsertInter(problem, constructed_solution);
    current_tct = reinsert_within_machine_solution.getTCT();
    if (current_tct < best_tct) {
      best_solution = reinsert_within_machine_solution;
      best_tct = current_tct;
      improved = true;
    }
    Solution swap_within_machine_solution = SwapIntra(problem, constructed_solution);
    current_tct = swap_within_machine_solution.getTCT();
    if (current_tct < best_tct) {
      best_solution = swap_within_machine_solution;
      best_tct = current_tct;
      improved = true;
    }
    Solution swap_between_machines_solution = SwapInter(problem, constructed_solution);
    current_tct = swap_between_machines_solution.getTCT();
    if (current_tct < best_tct) {
      best_solution = swap_between_machines_solution;
      best_tct = current_tct;
      improved = true;
    }
    constructed_solution = best_solution;
  }
  return best_solution;
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

/**
 * @brief Perform a local search using the reinsert method.
 * 
 * @param problem Problem to solve.
 * @param initial_solution Initial solution.
 * @return Solution Solution to the problem.
 */
Solution GRASP::ReinsertIntra(const Problem& problem, Solution& initial_solution) {
  Solution best_solution = initial_solution;
  int best_tct = best_solution.getTCT();
  bool improved = true;
  while (improved) {
    improved = false;
    for (int machine = 0; machine < problem.getMachines(); machine++) {
      std::vector<Task*> tasks = best_solution.getTasks(machine);
      for (size_t task_index = 0; task_index < tasks.size(); task_index++) {
        Task* task_to_reinsert = tasks[task_index];
        best_solution.removeTask(machine, task_index);
        for (size_t position = 0; position < tasks.size(); position++) {
          Solution new_solution = best_solution;
          new_solution.addTask(machine, task_to_reinsert, position);
          new_solution.calculateTCT();
          if (new_solution.getTCT() < best_tct) {
            best_solution = new_solution;
            best_tct = new_solution.getTCT();
            improved = true;
            break;
          }
        }
        if (improved) break;
        else { 
          best_solution.addTask(machine, task_to_reinsert, task_index);
          best_solution.calculateTCT();
        }
      }
      if (improved) break;
    }
  }
  return best_solution;
}

/**
 * @brief Perform a local search using the reinsert within machine method.
 * 
 * @param problem Problem to solve.
 * @param initial_solution Initial solution.
 * @return Solution Solution to the problem.
 */
Solution GRASP::ReinsertInter(const Problem& problem, Solution& initial_solution) {
    Solution best_solution = initial_solution;
    int best_tct = best_solution.getTCT();
    bool improved = true;
    while (improved) {
      improved = false;
      for (int machine_from = 0; machine_from < problem.getMachines(); machine_from++) {
        for (int machine_to = 0; machine_to < problem.getMachines(); machine_to++) {
          if (machine_from == machine_to) continue;
          std::vector<Task*> tasks_from = best_solution.getTasks(machine_from);
          std::vector<Task*> tasks_to = best_solution.getTasks(machine_to);
          for (size_t i = 0; i < tasks_from.size(); i++) {
            for (size_t j = 0; j <= tasks_to.size(); j++) {
              Task* task_to_reinsert = tasks_from[i];
              Solution new_solution = best_solution;
              new_solution.removeTask(machine_from, i);
              new_solution.addTask(machine_to, task_to_reinsert, j);
              new_solution.calculateTCT();
              if (new_solution.getTCT() < best_tct) {
                best_solution = new_solution;
                best_tct = new_solution.getTCT();
                improved = true;
                break;
              }
            }
            if (improved) break;
          }
          if (improved) break;
        }
        if (improved) break;
      }
    }
  return best_solution;
}

/**
 * @brief Perform a local search using the swap within machine method.
 * 
 * @param problem Problem to solve.
 * @param initial_solution Initial solution.
 * @return Solution Solution to the problem.
 */
Solution GRASP::SwapIntra(const Problem& problem, Solution& initial_solution) {
  Solution best_solution = initial_solution;
  int best_tct = best_solution.getTCT();
  bool improved = true;
  while (improved) {
    improved = false;
    for (int machine = 0; machine < problem.getMachines(); machine++) {
      std::vector<Task*> tasks = best_solution.getTasks(machine);
      for (size_t i = 0; i < tasks.size(); i++) {
        for (size_t j = i + 1; j < tasks.size(); j++) {
          Solution new_solution = best_solution;
          new_solution.swapTasks(machine, i, j);
          new_solution.calculateTCT();
          if (new_solution.getTCT() < best_tct) {
            best_solution = new_solution;
            best_tct = new_solution.getTCT();
            improved = true;
            break;
          }
        }
        if (improved) break;
      }
      if (improved) break;
    }
  }
  return best_solution;
}

/**
 * @brief Perform a local search using the swap between machines method.
 * 
 * @param problem Problem to solve.
 * @param initial_solution Initial solution.
 * @return Solution Solution to the problem.
 */
Solution GRASP::SwapInter(const Problem& problem, Solution& initial_solution) {
  Solution best_solution = initial_solution;
  int best_tct = best_solution.getTCT();
  bool improved = true;
  while (improved) {
    improved = false;
    for (int machine_a = 0; machine_a < problem.getMachines(); machine_a++) {
      for (int machine_b = machine_a + 1; machine_b < problem.getMachines(); machine_b++) {
        std::vector<Task*> tasks_a = best_solution.getTasks(machine_a);
        std::vector<Task*> tasks_b = best_solution.getTasks(machine_b);
        for (size_t i = 0; i < tasks_a.size(); i++) {
          for (size_t j = 0; j < tasks_b.size(); j++) {
            Solution new_solution = best_solution;
            new_solution.swapTasks(machine_a, i, machine_b, j);
            new_solution.calculateTCT();
            if (new_solution.getTCT() < best_tct) {
              best_solution = new_solution;
              best_tct = new_solution.getTCT();
              improved = true;
              break;
            }
          }
          if (improved) break;
        }
        if (improved) break;
      }
      if (improved) break;
    }
  }
  return best_solution;
}