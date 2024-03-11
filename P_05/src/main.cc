/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file main.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Main file of the program.
 * @version 0.1
 * @since Feb 23 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

#include <iostream>
#include <fstream>

/**
 * @brief Main function of the program.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int 
 */
int main(int argc, char** argv) {
  try {
    srand(time(NULL));
    std::ofstream output_file;
    bool debug = false;
    if ((argc == 2 && std::string(argv[1]) == "-h") || (argc > 2)) {
      Help();
      return 1;
    }
    if (argc == 2 && std::string(argv[1]) == "-d") {
      debug = true;
    }
    std::cout << "Introduce the algorithm to use:\n\t1. Quick Sort\n\t2. Merge Sort\n"
              << "\t3. Binary Search\n\t4. Hanoi Towers\n";
    int option;
    std::cin >> option;
    std::cout << std::endl;
    switch (option) {
      case 1:
        if (!debug) {
          std::cout << "Size             Time (ms)" << std::endl;
          for (size_t i = 100; i <= 10000; i += 100) {
            std::vector<int> array = GenerateRandom(i);
            DyV::Problem<std::vector<int>> problem(array);
            DyV::Solution<std::vector<int>> solution;
            float time = QuickSortTime<std::vector<int>, int, std::vector<int>>(problem, solution);
            std::cout << i << "                 " << time << std::endl;
          }
        } else {
          std::cout << "\nIntroduce the array size: ";
          size_t size;
          std::cin >> size;
          std::vector<int> array = GenerateRandom(size);
          DyV::Problem<std::vector<int>> problem(array);
          DyV::Solution<std::vector<int>> solution;
          float time = QuickSortTime<std::vector<int>, int, std::vector<int>>(problem, solution);
          std::cout << "Problem: ";
          for (size_t i = 0; i < problem.size(); i++) {
            std::cout << problem[i] << " ";
          }
          std::cout << "\nSolution: ";
          std::cout << "Time: " << time << " ms" << std::endl;
          for (size_t i = 0; i < solution.size(); i++) {
            std::cout << solution[i] << " ";
          }
          std::cout << std::endl;
        }
        break;
      case 2:
        if (!debug) {
          std::cout << "Size             Time (ms)" << std::endl;
          for (size_t i = 100; i <= 10000; i += 100) {
            std::vector<int> array = GenerateRandom(i);
            DyV::Problem<std::vector<int>> problem(array);
            DyV::Solution<std::vector<int>> solution;
            float time = MergeSortTime<std::vector<int>, int, std::vector<int>>(problem, solution);
            std::cout << i << "                 " << time << std::endl;
          }
        } else {
          std::cout << "\nIntroduce the array size: ";
          size_t size;
          std::cin >> size;
          std::vector<int> array = GenerateRandom(size);
          DyV::Problem<std::vector<int>> problem(array);
          DyV::Solution<std::vector<int>> solution;
          float time = MergeSortTime<std::vector<int>, int, std::vector<int>>(problem, solution);
          std::cout << "Problem: ";
          for (size_t i = 0; i < problem.size(); i++) {
            std::cout << problem[i] << " ";
          }
          std::cout << "\nSolution: ";
          std::cout << "Time: " << time << " ms" << std::endl;
          for (size_t i = 0; i < solution.size(); i++) {
            std::cout << solution[i] << " ";
          }
          std::cout << std::endl;
        }
        break;
      case 3:
        if (!debug) {
          std::cout << "Size             Time (ms)" << std::endl;
          const int candidate = 50;
          for (size_t i = 100; i <= 10000; i += 100) {
            std::vector<int> array = GenerateRandom(i);
            DyV::MergeSort<std::vector<int>, int, std::vector<int>> mergesort;
            DyV::Problem<std::vector<int>> problem(mergesort.Solve(DyV::Problem<std::vector<int>>(array), array.size()).getData());
            DyV::Solution<int> solution;
            float time = BinarySearchTime<std::vector<int>, int, int>(problem, candidate, solution);
            std::cout << i << "                 " << time << std::endl;
          }
        } else {
          std::cout << "\nIntroduce the array size: ";
          size_t size;
          std::cin >> size;
          std::vector<int> array = GenerateRandom(size);
          DyV::MergeSort<std::vector<int>, int, std::vector<int>> mergesort;
          DyV::Problem<std::vector<int>> problem(mergesort.Solve(DyV::Problem<std::vector<int>>(array), array.size()).getData());
          DyV::Solution<int> solution;
          std::cout << "Problem: ";
          for (size_t i = 0; i < problem.size(); i++) {
            std::cout << problem[i] << " ";
          }
          std::cout << "\nIntroduce the number to search: ";
          int candidate;
          std::cin >> candidate;
          float time = BinarySearchTime<std::vector<int>, int, int>(problem, candidate, solution);
          std::cout << "\nSolution: " << solution.getData() << std::endl;
          std::cout << "Time: " << time << " ms" << std::endl;
        }
        break;
      case 4:
        if (!debug) {
          std::cout << "Size             Time (ms)" << std::endl;
          for (size_t i = 1; i <= 25; i++) {
            DyV::HanoiSolver<int, int, int> hanoi;
            DyV::Problem<int> problem(i);
            DyV::Solution<int> solution;
            float time = HanoiTime<int, int, int>(problem, solution);
            std::cout << i << "                 " << time << std::endl;
          }
        } else {
          std::cout << "\nIntroduce the number of disks: ";
          size_t disks;
          std::cin >> disks;
          DyV::HanoiSolver<int, int, int> hanoi;
          DyV::Problem<int> problem(disks);
          DyV::Solution<int> solution;
          float time = HanoiTime<int, int, int>(problem, solution);
          std::cout << "\nProblem: " << problem.getData() << std::endl;
          std::cout << "Solution: " << solution.getData() << " steps" << std::endl;
          std::cout << "Time: " << time << " ms" << std::endl;
        }
        break;
      default:
        throw std::invalid_argument("Opción no válida.");
        break;
    }
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}