/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the functions used on the program.
 * @version 0.1
 * @since Feb 22 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "../include/dyv.h"

#include <string>
#include <vector>

void Help(void);
std::vector<int> GenerateRandom(const size_t& size);
void CalculateTime(const std::vector<int>& array, DyV::QuickSort& quicksort,
                   DyV::MergeSort& mergesort, std::vector<std::vector<int>>& quicksort_solutions,
                   std::vector<std::vector<int>>& mergesort_solutions, std::vector<float>& quicksort_times,
                   std::vector<float>& mergesort_times);
void PrintData(std::vector<std::vector<int>>& quicksort_solutions,
               std::vector<std::vector<int>>& mergesort_solutions,
               std::vector<float>& quicksort_times,
               std::vector<float>& mergesort_times);
void WriteData(std::vector<std::vector<int>>& quicksort_solutions,
               std::vector<std::vector<int>>& mergesort_solutions,
               std::vector<float>& quicksort_times,
               std::vector<float>& mergesort_times);