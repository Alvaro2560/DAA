/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file grasp.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the GRASP algorithm.
 * @version 0.1
 * @since Apr 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/grasp.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/local-search.hh"
#include "../include/greedy.hh"

#include <algorithm>
#include <random>

/**
 * @brief Runs the GRASP algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution to the problem.
 */
Solution GRASP::Run(const Problem& problem) {
  Solution constructed_solution = Construct(problem);
  return LocalSearch(problem, constructed_solution);
}

/**
 * @brief Constructs a solution using the GRASP algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution to the problem.
 */
Solution GRASP::Construct(const Problem& problem) {
  Solution solution;
  std::vector<Element> problem_elements = problem.getElements();
  std::vector<std::pair<Element, double>> element_distances;
  Element center = Greedy().CalculateCentroid(problem.getElements());
  while ((int)solution.size() < problem.getDimension() / 2) {
    double maxDistance = -1.0;
    int maxIndex = -1;
    for (size_t i = 0; i < problem_elements.size(); i++) {
      double distance = Greedy().CalculateEuclideanDistance(problem_elements[i], center);
      if (distance > maxDistance) {
        maxDistance = distance;
        maxIndex = i;
      }
    }
    solution.addElement(problem_elements[maxIndex]);
    problem_elements.erase(problem_elements.begin() + maxIndex);
    center = Greedy().CalculateCentroid(solution.getElements());
  }
  while ((int)solution.size() < problem.getDimension()) {
    center = Greedy().CalculateCentroid(solution.getElements());
    for (size_t i = 0; i < problem_elements.size(); i++) {
      element_distances.emplace_back(std::make_pair(problem_elements[i], Greedy().CalculateEuclideanDistance(problem_elements[i], center)));
    }
    std::sort(element_distances.begin(), element_distances.end(), [](const std::pair<Element, double>& element1, const std::pair<Element, double>& element2) {
      return element1.second > element2.second;
    });
    int index;
    if (element_distances.size() > 3) {
      index = rand() % 3;
    } else {
      index = rand() % element_distances.size();
    }
    solution.addElement(element_distances[index].first);
    problem_elements.erase(problem_elements.begin() + index);
    element_distances.clear();
  }
  return solution;
}

/**
 * @brief Runs the local search algorithm.
 * 
 * @param problem Problem to solve.
 * @param initial_solution Initial solution to start the search.
 * @return Solution Solution to the problem.
 */
Solution GRASP::LocalSearch(const Problem& problem, const Solution& initial_solution) {
  Solution best_solution = initial_solution;
  Problem new_problem = problem;
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