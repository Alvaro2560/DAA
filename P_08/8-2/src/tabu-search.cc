/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file tabu-search.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the Tabu Search algorithm.
 * @version 0.1
 * @since Apr 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/tabu-search.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/grasp.hh"
#include "../include/greedy.hh"

#include <algorithm>

/**
 * @brief Runs the Tabu Search algorithm.
 * 
 * @param problem Problem to solve.
 * @return Solution Best solution found.
 */
Solution TabuSearch::Run(const Problem& problem) {
  Solution best_solution = GRASP().Construct(problem);
  int solutions = 0;
  while (solutions < 100) {
    Solution current_solution = GRASP().Construct(problem);
    Problem copy_problem = problem;
    for (const Element& element : best_solution.getElements()) {
      copy_problem.removeElement(element);
    }
    const int kMaxIterations = 1000;
    int iterations = 0, not_improving = 0;
    while (iterations < kMaxIterations && not_improving < 50) {
      Solution new_solution = LocalSearch(copy_problem, current_solution);
      Move move = CheckMove(current_solution, new_solution);
      UpdateTabuList(move);
      if (new_solution.TotalDistance() > best_solution.TotalDistance()) {
        best_solution = new_solution;
      } else {
        not_improving++;
      }
      current_solution = new_solution;
      iterations++;
      ReduceIterations();
    }
    solutions++;
  }
  return best_solution;
}

/**
 * @brief Runs the local search algorithm.
 * 
 * @param problem Problem to solve.
 * @param solution Initial solution.
 * @return Solution Best solution found.
 */
Solution TabuSearch::LocalSearch(Problem& problem, const Solution& solution) {
  Solution best_solution = solution;
  double best_distance = solution.TotalDistance();
  Element problem_add;
  for (size_t i = 0; i < solution.size(); i++) {
    for (const Element& candidate : problem.getElements()) {
      Solution new_solution = solution;
      Move move = std::make_pair(solution.getElements()[i], candidate);
      Element problem_candidate = solution.getElements()[i];
      new_solution.removeElement(i);
      new_solution.addElement(candidate);
      if (new_solution.TotalDistance() > best_distance && !IsTabu(move)) {
        best_solution = new_solution;
        best_distance = new_solution.TotalDistance();
        problem_add = problem_candidate;
      }
    }
  }
  for (const Element& element : best_solution.getElements()) {
    problem.removeElement(element);
  }
  if (problem_add.size() > 0) problem.addElement(problem_add);
  return best_solution;
}

/**
 * @brief Checks if a move is tabu.
 * 
 * @param previous_solution Previous solution.
 * @param current_solution Current solution.
 * @return Move Move to perform.
 */
Move TabuSearch::CheckMove(const Solution& previous_solution, const Solution& current_solution) {
  for (size_t i = 0; i < previous_solution.size(); i++) {
    for (size_t j = 0; j < current_solution.size(); j++) {
      if (previous_solution.getElements()[i] != current_solution.getElements()[j] && 
          IsTabu(std::make_pair(previous_solution.getElements()[i], current_solution.getElements()[j])) == false) {
        return std::make_pair(previous_solution.getElements()[i], current_solution.getElements()[j]);
      }
    }
  }
  return std::make_pair(Element(), Element());
}

/**
 * @brief Updates the tabu list.
 * 
 * @param move Move to add to the tabu list.
 */
void TabuSearch::UpdateTabuList(const Move& move) {
  for (auto tabu_move : tabu_list_) {
    if (tabu_move.first == move) {
      return;
    }
  }
  tabu_list_.emplace_back(std::make_pair(move, 5));
}

/**
 * @brief Checks if a move is tabu.
 * 
 * @param move Move to check.
 * @return bool True if the move is tabu, false otherwise.
 */
bool TabuSearch::IsTabu(const Move& move) const {
  for (const std::pair<Move, int>& tabu_move : tabu_list_) {
    if (tabu_move.first == move) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Reduces the iterations of the tabu search.
 */
void TabuSearch::ReduceIterations(void) {
  for (std::pair<Move, int>& tabu_move : tabu_list_) {
    tabu_move.second--;
    if (tabu_move.second == 0) {
      tabu_list_.erase(std::remove(tabu_list_.begin(), tabu_list_.end(), tabu_move), tabu_list_.end());
    }
  }
}