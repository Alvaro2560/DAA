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

Solution GRASP::Run(const Problem& problem) {
  Solution best_solution(problem.getMachines());

  // Parámetros GRASP (ajusta según sea necesario)
  const int max_iterations = 1000;

  for (int iter = 0; iter < max_iterations; ++iter) {
    Solution current_solution = Construct(problem);

    // Evaluar la solución actual (puedes usar la función de costo o algún otro criterio)
    int current_cost = current_solution.getTCT();
    int best_cost = best_solution.getTCT();

    // Actualizar la mejor solución si la solución actual es mejor
    if (current_cost < best_cost) {
      best_solution = current_solution;
    }
  }

  return best_solution;
}

Solution GRASP::Construct(const Problem& problem) {
  Solution solution(problem.getMachines());
  std::vector<Task*> ordered_tasks = problem.getTasks();
  
  // Ordena las tareas en base a algún criterio GRASP (aquí se usa un criterio greedy)
  std::sort(ordered_tasks.begin(), ordered_tasks.end(), [](Task* task1, Task* task2) {
    return task1->getPreparationTime(0) + task1->getProcessingTime() < task2->getPreparationTime(0) + task2->getProcessingTime();
  });

  // Construye la solución agregando tareas a las máquinas
  for (int i = 1; i <= problem.getMachines(); ++i) {
    ordered_tasks[i]->setScheduled();
    solution.addTask(i - 1, ordered_tasks[i]);
    solution.sumTCT(i - 1);
  }

  // Completa la asignación de tareas a las máquinas
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
