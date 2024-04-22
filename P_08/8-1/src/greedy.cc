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
 * @since Apr 21 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/greedy.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"

#include <cmath>

/**
 * @brief Runs the greedy algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Solution of the problem.
 */
Solution Greedy::Run(const Problem& problem) {
  Solution solution;
  std::vector<Element> elements = problem.getElements();
  Element center = CalculateCentroid(problem.getElements());
  while ((int)solution.size() < problem.getDimension()) {
    double maxDistance = -1.0;
    int maxIndex = -1;
    for (size_t i = 0; i < elements.size(); i++) {
      double distance = CalculateEuclideanDistance(elements[i], center);
      if (distance > maxDistance) {
        maxDistance = distance;
        maxIndex = i;
      }
    }
    solution.addElement(elements[maxIndex]);
    elements.erase(elements.begin() + maxIndex);
    center = CalculateCentroid(solution.getElements());
  }
  return solution;
}

/**
 * @brief Calculates the Euclidean distance between two elements.
 * 
 * @param element1 First element.
 * @param element2 Second element.
 * @return double Euclidean distance between the elements.
 */
double Greedy::CalculateEuclideanDistance(const Element& element1, const Element& element2) {
  double distance = 0.0;
  for (size_t i = 0; i < element1.size(); ++i) {
    distance += std::pow(element1[i] - element2[i], 2);
  }
  return std::sqrt(distance);
}

/**
 * @brief Calculates the centroid of a set of elements.
 * 
 * @param elements Elements to calculate the centroid.
 * @return Element Centroid of the elements.
 */
Element Greedy::CalculateCentroid(const std::vector<Element>& elements) {
  Element centroid(elements[0].size(), 0.0);
  for (const Element& element : elements) {
    for (size_t i = 0; i < element.size(); ++i) {
      centroid[i] += element[i];
    }
  }
  for (size_t i = 0; i < centroid.size(); ++i) {
    centroid[i] /= elements.size();
  }
  return centroid;
}