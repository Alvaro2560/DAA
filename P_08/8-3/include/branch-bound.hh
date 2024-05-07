/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file branch-bound.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class BranchBound.
 * @version 0.1
 * @since May 03 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "algorithm.hh"
#include "solution.hh"
#include "problem.hh"

#include <vector>

typedef std::vector<double> Element;

struct TreeNode {
  Solution solution;
  std::vector<TreeNode*> children;
};

class BranchBound : public Algorithm {
  public:
    BranchBound(void) = default;
    ~BranchBound(void) = default;
    Solution Run(const Problem& problem) override;
  private:
    void Branch(const Problem& problem, TreeNode* node, int level);
    void Bound(TreeNode* node, int level, int top_level, const Problem& problem);
    void CalculateLowerBound(TreeNode* node);
  private:
    double lowerBound_;
    double bound_;
    TreeNode* tree_;
    Solution best_solution_;
};