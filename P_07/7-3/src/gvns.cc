/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file gvns.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class GVNS.
 * @version 0.1
 * @since Apr 12 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/gvns.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/grasp.hh"
#include "../include/task.hh"

#include <algorithm>
#include <chrono>

/**
 * @brief Runs the GVNS algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Best solution found.
 */
Solution GVNS::Run(const Problem& problem) {
  auto start = std::chrono::high_resolution_clock::now();
  const int kMaxIterations = 10, kMaxK = 7;
  int iterations = 0;
  std::vector<Solution> solutions;
  // MODIFICACIÓN
  Solution solution = GRASP().Construct(problem);
  solution = GRASP().ReinsertIntra(problem, solution);
  do {
    int k = 1;
    do {
      Solution shaked_solution = Shake(solution, k);
      Solution vnd_solution = VND(problem, shaked_solution);
      if (vnd_solution.getTCT() < solution.getTCT()) {
        solution = vnd_solution;
        k = 1;
      } else {
        k++;
      }
    } while (k < kMaxK);
    solutions.emplace_back(solution);
    iterations++;
    problem.reset();
  } while (iterations < kMaxIterations);
  std::sort(solutions.begin(), solutions.end(), [](const Solution& a, const Solution& b) {
    return a.getTCT() < b.getTCT();
  });
  auto end = std::chrono::high_resolution_clock::now();
  time_ = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  return solutions[0];
}

/**
 * @brief Shakes a solution.
 * 
 * @param solution Solution to shake.
 * @param k Number of tasks to move.
 * @return Solution Shaked solution.
 */
Solution GVNS::Shake(const Solution& solution, const int& k) {
  Solution shaked_solution = solution;
  for (int i = 0; i < k; i++) {
    int machine1 = rand() % solution.getMachines();
    int machine2 = rand() % solution.getMachines();
    if (shaked_solution.getTasks(machine1).size() == 0 || shaked_solution.getTasks(machine2).size() == 0) {
      continue;
    }
    int task_index1 = rand() % shaked_solution.getTasks(machine1).size();
    int task_index2 = rand() % shaked_solution.getTasks(machine2).size();
    shaked_solution = this->ReinsertInter(shaked_solution, machine1, task_index1, machine2, task_index2, shaked_solution.getTasks(machine1)[task_index1]);
  }
  return shaked_solution;
}

/**
 * @brief Reinserts a task from a machine to another.
 * 
 * @param solution Solution to modify.
 * @param machine1 Machine to remove the task.
 * @param task_index1 Task's index to remove.
 * @param machine2 Machine to add the task.
 * @param task_index2 Task's index to add.
 * @param task Task to reinsert.
 * @return Solution Modified solution.
 */
Solution GVNS::ReinsertInter(const Solution& solution, const int& machine1, const int& task_index1, const int& machine2, const int& task_index2, Task* task) {
  Solution new_solution = solution;
  new_solution.removeTask(machine1, task_index1);
  new_solution.addTask(machine2, task, task_index2);
  return new_solution;
}

/**
 * @brief Executes the VND algorithm.
 * 
 * @param problem The problem to solve.
 * @param solution The solution to improve.
 * @return Solution The improved solution.
 */
Solution GVNS::VND(const Problem& problem, const Solution& solution) {
  Solution new_solution = solution, old_solution = solution;
  int k = 0;
  do {
    switch (k) {
      // MODIFICACIÓN
      case 0:
        new_solution = GRASP().ReinsertInter(problem, new_solution);
        break;
      case 1:
        new_solution = GRASP().SwapInter(problem, new_solution);
        break;
    }
    if (new_solution.getTCT() < old_solution.getTCT()) {
      old_solution = new_solution;
      k = 0;
    } else {
      k++;
    }
  } while (k < 2);
  return old_solution;
}