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
#include <random>

Solution GRASP::Run(const Problem& problem) {
  return Construct(problem);
}

Solution GRASP::Construct(const Problem& problem) {
  Solution solution(problem.getMachines());
  std::vector<Task*> tasks = problem.getTasks();
  std::vector<Task*> remaining_tasks = tasks;
  std::vector<int> machine_end_times(problem.getMachines(), 0);
  std::random_device rd;
  std::mt19937 random_engine(rd());
  while (!remaining_tasks.empty()) {
    std::vector<Task*> feasible_tasks;
    for (Task* task : remaining_tasks) {
      int task_start = task->getPreparationTime(0);
      int task_duration = task->getProcessingTime();
      for (int machine = 0; machine < problem.getMachines(); ++machine) {
        int machine_end_time = machine_end_times[machine];
        int task_end_time = machine_end_time + task_start + task_duration;
        if (machine_end_time <= task_start) {
          feasible_tasks.push_back(task);
          break;
        }
      }
    }
    if (feasible_tasks.empty()) break; // Si no hay tareas factibles, salir del bucle
    // Seleccionar una tarea aleatoria de entre las tareas factibles
    std::uniform_int_distribution<int> distribution(0, feasible_tasks.size() - 1);
    int random_index = distribution(random_engine);
    Task* selected_task = feasible_tasks[random_index];
    // Seleccionar la máquina con el TCT mínimo
    int min_tct_machine = std::distance(machine_end_times.begin(), std::min_element(machine_end_times.begin(), machine_end_times.end()));
    // Asignar la tarea seleccionada a la máquina con el TCT mínimo
    selected_task->setScheduled();
    solution.addTask(min_tct_machine, selected_task);
    solution.sumTCT(min_tct_machine);
    machine_end_times[min_tct_machine] += selected_task->getPreparationTime(0) + selected_task->getProcessingTime();
    // Eliminar la tarea seleccionada de las tareas restantes
    remaining_tasks.erase(std::remove(remaining_tasks.begin(), remaining_tasks.end(), selected_task), remaining_tasks.end());
  }

  return solution;
}