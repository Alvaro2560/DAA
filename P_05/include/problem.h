/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file problem.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Declaration of the class Problem.
 * @version 0.1
 * @since Feb 28 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <stdlib.h>
#include <type_traits>

namespace DyV {
  /**
   * @brief Class that represents a Problem.
   * 
   * @tparam T Type of the data that the problem contains.
   */
  template <typename T>
  class Problem {
    public:
      Problem(void) = default;
      
      /**
       * @brief Constructor of the class Solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param data Data that the solution contains.
       */
      Problem(const T& data) : data_(data) { }
      
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
       * @brief Operator to access the data of the problem.
       * 
       * @tparam Container 
       * @param index Index of the data to access.
       * @return std::enable_if<std::is_class<Container>::value, typename Container::value_type&>::type 
       */
      template<typename Container = T>
      typename std::enable_if<std::is_class<Container>::value, typename Container::value_type&>::type
      operator[](size_t index) {
        return data_[index];
      }
      
      /**
       * @brief Operator to access the data of the problem.
       * 
       * @tparam Container 
       * @param index Index of the data to access.
       * @return std::enable_if<std::is_class<Container>::value, typename Container::value_type&>::type 
       */
      template<typename Container = T>
      typename std::enable_if<std::is_class<Container>::value, const typename Container::value_type&>::type
      operator[](size_t index) const {
        return data_[index];
      }

      /**
       * @brief Getter for the size of the data of the solution.
       * 
       * @tparam T Type of the data that the solution contains.
       * @return size_t Size of the data that the solution contains.
       */
      template<typename Container = T>
      typename std::enable_if<std::is_class<Container>::value, size_t>::type
      size(void) const {
        return data_.size();
      }

      /**
       * @brief Adds an element to the end of the data.
       * 
       * @tparam T Type of the data that the solution contains.
       * @param data Data to add to the end of the data.
       */
      template<typename Container = T>
      typename std::enable_if<std::is_class<Container>::value>::type
      emplace_back(const typename Container::value_type& data) {
        data_.emplace_back(data);
      }
    private:
      T data_;
  };
}