/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file tabu-search.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the Tabu Search algorithm.
 * @version 0.1
 * @since Apr 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"

#include <vector>

typedef std::vector<double> Element;
typedef std::pair<Element, Element> Move;

/**
 * @class TabuSearch
 * @brief Class that represents a Tabu Search algorithm.
 */
class TabuSearch : public Algorithm {
  public:
    TabuSearch(void) = default;
    ~TabuSearch(void) = default;
    Solution Run(const Problem& problem) override;
  private:
    Solution LocalSearch(Problem& problem, const Solution& solution);
    Move CheckMove(const Solution& previous_solution, const Solution& current_solution);
    void UpdateTabuList(const Move& move);
    bool IsTabu(const Move& move) const;
    void ReduceIterations(void);
  private:
    std::vector<std::pair<Move, int>> tabu_list_;
};