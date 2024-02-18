/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the RAM class.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/ram.h"
#include "../include/input-unit.h"
#include "../include/output-unit.h"
#include "../include/instructions.h"

#include <sstream>
#include <bits/stdc++.h>

const size_t HALT_FLAG = -1;

/**
 * @brief Construct a new RAM::RAM object
 * 
 * @param instructions Instructions of the program as a vector of strings.
 * @param input_tape Input data as a vector of strings.
 * @param output_tape Output data as a pointer to an OutputUnit object.
 */
RAM::RAM(const std::vector<std::string>& instructions, 
         const std::vector<std::string>& input_tape) {
  input_unit_ = new InputUnit(FormatTape(input_tape));
  output_unit_ = new OutputUnit();
  data_memory_ = new int[32];
  for (size_t i = 0; i < 32; i++) {
    data_memory_[i] = 0;
  }
  FormatInstructions(instructions);
  program_counter_ = 0;
}

/**
 * @brief Run the RAM.
 */
void RAM::run(void) {
  size_t next_instruction;
  while (program_counter_ != HALT_FLAG && program_counter_ < program_memory_.size()) {
    next_instruction = program_memory_[program_counter_]->execute(data_memory_);
    if (next_instruction == HALT_FLAG) {
      program_counter_ = HALT_FLAG;
    } else if (next_instruction == 1) {
      program_counter_++;
    } else {
      // If the instruction is a jump, the next instruction is the one returned by the execute method.
      program_counter_ = next_instruction;
    }
  }
}

/**
 * @brief Get the Output Unit.
 * 
 * @return OutputUnit* Pointer to the OutputUnit object.
 */
OutputUnit* RAM::getOutputUnit(void) const {
  return output_unit_;
}

/**
 * @brief Destroy the RAM::RAM object
 */
RAM::~RAM(void) {
  for (size_t i = 0; i < program_memory_.size(); i++) {
    delete program_memory_[i];
  }
  delete[] data_memory_;
  delete input_unit_;
  delete output_unit_;
}

/**
 * @brief Formats the instructions and stores them in a vector of strings.
 * 
 * @param instructions Content of the file as a vector of strings.
 */
void RAM::FormatInstructions(const std::vector<std::string>& instructions) {
  std::unordered_map<std::string, std::pair<size_t, std::string>> labels_cache;
  for (size_t i = 0; i < instructions.size(); i++) {
    std::string line = instructions[i], word;
    // If the line is a comment or it is empty, skip it.
    if (line[0] == '#' || line.size() < 4) {
      continue;
    }
    int counter = 0, operand;
    AddressingMode addressing_mode;
    std::string instruction, label, jump_label;
    std::stringstream ss(line);
    // Separate the line into words.
    while (ss >> word) {
      // If the word ends with a colon, it is a label.
      if (word.substr(word.size() - 1) == ":") {
        label = word.substr(0, word.size() - 1);
        // The next word is the instruction.
        ss >> instruction;
        std::transform(instruction.begin(), instruction.end(), instruction.begin(), ::toupper);
        ++counter;
      } else if (counter == 0) {
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
        instruction = word;
        // If the instruction is a jump, the next word is the label.
        if (instruction[0] == 'J') {
          ss >> word;
          jump_label = word;
          // If the label is not in the cache, add it.
          labels_cache[jump_label] = std::make_pair(i + 1, instruction + " " + word);
          ++counter;
        }
        ++counter;
      } else if (counter == 1) {
        // Check what type of addressing mode the operand has.
        if (word.length() == 1) {
          addressing_mode = DIRECT;
          operand = std::stoi(word);
        } else if (word[0] == '=') {
          addressing_mode = CONSTANT;
          operand = std::stoi(word.substr(1));
        } else if (word[0] == '*') {
          addressing_mode = INDIRECT;
          operand = std::stoi(word.substr(1));
        } else {
          std::string error = "Error at line " + std::to_string(i + 1) + ":\n\n";
          error += instruction + " " + word + "\n";
          for (size_t i = 0; i < (instruction + word).size() + 1; i++) {
            error += "^";
          }
          error += "\nInvalid addressing mode.";
          throw std::runtime_error(error);
        }
      }
    }
    if (instruction == "LOAD") {
      program_memory_.emplace_back(new LOAD(addressing_mode, operand));
    } else if (instruction == "STORE") {
      if (addressing_mode == CONSTANT) {
        std::string error = "Error at line " + std::to_string(i + 1) + ":\n\n";
        error += instruction + " " + word + "\n";
        for (size_t i = 0; i < (instruction + word).size() + 1; i++) {
          error += "^";
        }
        error += "\nInvalid operand for STORE instruction.";
        throw std::runtime_error(error);
      }
      program_memory_.emplace_back(new STORE(addressing_mode, operand));
    } else if (instruction == "ADD") {
      program_memory_.emplace_back(new ADD(addressing_mode, operand));
    } else if (instruction == "SUB") {
      program_memory_.emplace_back(new SUB(addressing_mode, operand));
    } else if (instruction == "MUL") {
      program_memory_.emplace_back(new MUL(addressing_mode, operand));
    } else if (instruction == "DIV") {
      program_memory_.emplace_back(new DIV(addressing_mode, operand));
    } else if (instruction == "READ") {
      if ((addressing_mode == DIRECT && operand == 0) || addressing_mode == CONSTANT) {
        std::string error = "Error at line " + std::to_string(i + 1) + ":\n\n";
        error += instruction + " " + word + "\n";
        for (size_t i = 0; i < (instruction + word).size() + 1; i++) {
          error += "^";
        }
        error += "\nInvalid operand for READ instruction.";
        throw std::runtime_error(error);
      }
      program_memory_.emplace_back(new READ(addressing_mode, operand, input_unit_));
    } else if (instruction == "WRITE") {
      if (addressing_mode == DIRECT && operand == 0) {
        std::string error = "Error at line " + std::to_string(i + 1) + ":\n\n";
        error += instruction + " " + word + "\n";
        for (size_t i = 0; i < (instruction + word).size() + 1; i++) {
          error += "^";
        }
        error += "\nInvalid operand for WRITE instruction.";
        throw std::runtime_error(error);
      }
      program_memory_.emplace_back(new WRITE(addressing_mode, operand, output_unit_));
    } else if (instruction == "JUMP") {
      program_memory_.emplace_back(new JUMP(jump_label, &labels_, program_memory_));
    } else if (instruction == "JZERO") {
      program_memory_.emplace_back(new JZERO(jump_label, &labels_, program_memory_));
    } else if (instruction == "JGTZ") {
      program_memory_.emplace_back(new JGTZ(jump_label, &labels_, program_memory_));
    } else if (instruction == "HALT") {
      program_memory_.emplace_back(new HALT());
    } else {
        std::string error = "Error at line " + std::to_string(i + 1) + ":\n\n";
        error += instruction + " " + word + "\n";
        for (size_t i = 0; i < (instruction + word).size() + 1; i++) {
          error += "^";
        }
        error += "\nInvalid instruction.";
        throw std::runtime_error(error);
    }
    if (!label.empty()) {
      labels_[label] = program_memory_.size() - 1;
      label.clear();
    }
  }
  // Check if there are any undefined labels.
  for (auto it = labels_cache.begin(); it != labels_cache.end(); it++) {
    // If the label is not in the labels map, it is undefined.
    if (labels_.find(it->first) == labels_.end()) {
      std::string error = "Error at line " + std::to_string(it->second.first) + ":\n\n";
      error += it->second.second + "\n";
      for (size_t i = 0; i < it->second.second.size(); i++) {
        error += "^";
      }
      error += "\nUndefined label.";
      throw std::runtime_error(error);
    }
  }
}

/**
 * @brief Formats the input tape and stores it in a vector of integers.
 * 
 * @param file_name Name of the file to read.
 */
std::vector<int> RAM::FormatTape(const std::vector<std::string>& file_name) {
  std::vector<int> tape;
  for (size_t i = 0; i < file_name.size(); i++) {
    tape.emplace_back(std::stoi(file_name[i]));
  }
  return tape;
}