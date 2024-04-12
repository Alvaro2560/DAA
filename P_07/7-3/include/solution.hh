/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solution.hh
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of class Solution.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <iostream>

class Task;

/**
 * @class Solution
 * @brief Class that represents a solution.
 */
class Solution {
  public:
    Solution(const int& machines);
    ~Solution(void) = default;
    void addTask(const int& machine, Task* task);
    void addTask(const int& machine, Task* task, const int& position);
    void setTasks(const int& machine, std::vector<Task*> tasks);
    int getMachines(void) const;
    std::vector<Task*> getTasks(const int& machine) const;
    Task* getLastTask(const int& machine);
    int getTCT(void) const;
    int getTCT(const int& machine) const;
    void sumTCT(const int& machine);
    void calculateTCT(void);
    bool taskBelongsToMachine(const int& machine, const int& task_id) const;
    void removeTask(const int& machine, const int& task_index);
    void swapTasks(const int& machine, const int& task_index1, const int& task_index2);
    void swapTasks(const int& machine1, const int& task_index1, const int& machine2, const int& task_index2);
    Solution& operator=(const Solution& solution);
    friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
  private:
    std::vector<std::vector<Task*>> tasks_;
    std::vector<int> tcts_;
};

std::ostream& operator<<(std::ostream& os, const Solution& solution);