/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file solution.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Solution.
 * @version 0.1
 * @since Feb 28 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <stdlib.h>

namespace DyV {
  /**
   * @brief Class that represents a Solution.
   * 
   * @tparam T Type of the data that the solution contains.
   */
  template <typename T>
  class Solution {
    public:
      Solution(void) = default;
      
      /**
       * @brief Constructor of the class Solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param data Data that the solution contains.
       */
      Solution(const T& data) : data_(data) { }

      /**
       * @brief Getter for the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @return T Data that the solution contains.
       */
      T getData(void) const {
        return data_;
      }

      /**
       * @brief Setter for the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param data Data to set to the solution.
       */
      void setData(const T& data) {
        data_ = data;
      }

      /**
       * @brief Operator to access the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param index Index of the data to access.
       * @return T& Reference to the data at the given index.
       */
      typename T::value_type& operator[](const size_t& index) {
        return data_[index];
      }

      /**
       * @brief Operator to access the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param index Index of the data to access.
       * @return T& Reference to the data at the given index.
       */
      const typename T::value_type& operator[](const size_t& index) const {
        return data_[index];
      }

      /**
       * @brief Getter for the size of the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @return size_t Size of the data that the solution contains.
       */
      size_t size(void) const {
        return data_.size();
      }

      /**
       * @brief Adds an element to the end of the data.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param data Data to add to the end of the data.
       */
      void emplace_back(const typename T::value_type& data) {
        data_.emplace_back(data);
      }
    private:
      T data_;
  };
}