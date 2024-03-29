/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file task.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of class Task.
 * @version 0.1
 * @since Mar 29 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/task.hh"

/**
 * @brief Construct a new Task::Task object
 * 
 * @param id Task's id.
 * @param processing_time Task's processing time.
 */
Task::Task(int id, int processing_time) : id_(id), processing_time_(processing_time), scheduled_(false) { }

/**
 * @brief Destroy the Task::Task object
 */
Task::~Task(void) { }

/**
 * @brief Get the Task's id.
 * 
 * @return int Task's id.
 */
int Task::getId(void) const {
  return id_;
}

/**
 * @brief Get the Task's processing time.
 * 
 * @return int Task's processing time.
 */
int Task::getProcessingTime(void) const {
  return processing_time_;
}

/**
 * @brief Check if the task is scheduled.
 * 
 * @return true If the task is scheduled.
 * @return false If the task is not scheduled.
 */
bool Task::isScheduled(void) const {
  return scheduled_;
}

/**
 * @brief Set the task as scheduled.
 */
void Task::setScheduled(void) {
  scheduled_ = true;
}