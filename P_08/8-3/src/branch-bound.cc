/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file branch-bound.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class BranchBound.
 * @version 0.1
 * @since May 03 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/branch-bound.hh"
#include "../include/problem.hh"
#include "../include/solution.hh"
#include "../include/grasp.hh"
#include "../include/greedy.hh"

#include <algorithm>
#include <iostream>
#include <limits>

/**
 * @brief Runs the branch and bound algorithm.
 * 
 * @param problem Problem to be solved.
 * @return Solution Solution to the problem.
 */
Solution BranchBound::Run(const Problem& problem) {
  bound_ = Greedy().Run(problem).TotalDistance();
  lowerBound_ = 0;
  tree_ = new TreeNode();
  tree_->solution = Solution();
  tree_->children = std::vector<TreeNode*>();
  Branch(problem, tree_, 0);
  return best_solution_;
}

/**
 * @brief Branches the tree.
 * 
 * @param problem Problem to be solved.
 * @param node Node to be branched.
 * @param level Level of the node.
 */
void BranchBound::Branch(const Problem& problem, TreeNode* node, int level) {
  if (level == problem.getDimension()) {
    return;
  }
  for (Element element : problem.getElements()) {
    bool included = false;
    for (auto solution_element : node->solution.getElements()) {
      if (solution_element == element) {
        included = true;
        break;
      }
    }
    if (included) {
      continue;
    } else {
      Solution child_solution = node->solution;
      child_solution.addElement(element);
      TreeNode* child = new TreeNode();
      child->solution = child_solution;
      child->children = std::vector<TreeNode*>();
      node->children.emplace_back(child);
    }
  }
  CalculateLowerBound(node);
  Bound(tree_, 0, level + 1, problem);
  for (size_t i = 0; i < node->children.size(); i++) {
    if (node->children[i] == nullptr || node->children[i]->solution.size() > (size_t)problem.getDimension()) {
      node->children.erase(node->children.begin() + i);
      i--;
      continue;
    }
  }
  for (auto& child : node->children) {
    Branch(problem, child, level + 1);
  }
}

/**
 * @brief Bounds the tree.
 * 
 * @param node Node to be bounded.
 * @param level Level of the node.
 * @param top_level Top level of the tree.
 * @param problem Problem to be solved.
 */
void BranchBound::Bound(TreeNode* node, int level, int top_level, const Problem& problem) {
  if (node == nullptr) {
    return;
  }
  if (node->solution.size() > (size_t)problem.getDimension()) {
    node = nullptr;
    return;
  }
  if (node->solution.size() == (size_t)problem.getDimension()) {
    if (node->solution.TotalDistance() < bound_) {
      delete node;
      node = nullptr;
    } else {
      bound_ = node->solution.TotalDistance();
    }
  } else if (level == top_level) {
    if (node->solution.TotalDistance() < lowerBound_) {
      delete node;
      node = nullptr;
    }
  } else {
    for (auto& child : node->children) {
      Bound(child, level + 1, top_level, problem);
    }
  }
}

/**
 * @brief Calculates the lower bound of the tree.
 * 
 * @param node Node to be calculated.
 */
void BranchBound::CalculateLowerBound(TreeNode* node) {
  if (node == nullptr) {
    return;
  }
  for (auto& child : node->children) {
    CalculateLowerBound(child);
  }
  if (node->solution.TotalDistance() > lowerBound_) {
    lowerBound_ = node->solution.TotalDistance();
    best_solution_ = node->solution;
  }
}