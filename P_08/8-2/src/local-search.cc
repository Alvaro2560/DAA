/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file local-search.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the local search algorithm.
 * @version 0.1
 * @since Apr 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/local-search.hh"
#include "../include/greedy.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"

#include <iostream>

/**
 * @brief Runs the local search algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution to the problem.
 */
Solution LocalSearch::Run(const Problem& problem) {
  Solution initial_solution = Greedy().Run(problem);
  Problem new_problem = problem;
  Solution best_solution = initial_solution;
  for (const Element& element : initial_solution.getElements()) {
    new_problem.removeElement(element);
  }
  bool improved = true;
  Element center = Greedy().CalculateCentroid(initial_solution.getElements());
  while (improved) {
    improved = false;
    for (size_t i = 0; i < initial_solution.size(); i++) {
      for (const Element& candidate : new_problem.getElements()) {
        Solution new_solution = initial_solution;
        new_solution.removeElement(i);
        new_solution.addElement(candidate);
        double new_distance = Greedy().TotalDistance(new_solution.getElements());
        double best_distance = Greedy().TotalDistance(best_solution.getElements());
        if (new_distance > best_distance) {
          best_solution = new_solution;
          improved = true;
        }
      }
    }
  }
  return best_solution;
}