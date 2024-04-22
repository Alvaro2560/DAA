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

Solution LocalSearch::Run(const Problem& problem) {
  Solution initial_solution = Greedy().Run(problem);
  Solution best_solution = initial_solution;
  bool improved = true;
  while (improved) {
    improved = false;
    for (size_t i = 0; i < best_solution.size(); i++) {
      for (const Element& candidate : problem.getElements()) {
        Solution new_solution = best_solution;
        new_solution.removeElement(i);
        new_solution.addElement(candidate);
        Element center = Greedy().CalculateCentroid(new_solution.getElements());
        double new_distance = Greedy().CalculateEuclideanDistance(candidate, center);
        if (new_distance > Greedy().CalculateEuclideanDistance(best_solution.getElements()[i], center)) {
          best_solution = new_solution;
          improved = true;
        }
      }
    }
  }
  return best_solution;
}