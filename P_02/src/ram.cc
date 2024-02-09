/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file ram.h
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the class RAM.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/ram.h"
#include "../include/alcu.h"
#include "../include/units.h"
#include "../include/instructions.h"

#include <sstream>
#include <bits/stdc++.h>

/**
 * @brief Construct a new RAM::RAM object
 * 
 * @param input_tape 
 */
RAM::RAM(const std::vector<std::string>& instructions, const std::vector<std::string>& input_tape) {
  input_unit_ = new InputUnit(FormatTape(input_tape));
  output_unit_ = new OutputUnit();
  data_memory_ = new int[16];
  for (size_t i = 0; i < 16; i++) {
    data_memory_[i] = 0;
  }
  FormatInstructions(instructions);
  alcu_ = new ALCU(program_memory_);
}

/**
 * @brief Run the RAM.
 */
void RAM::run(void) {
  alcu_->run(data_memory_);
}

/**
 * @brief Write the output tape to a file.
 * 
 * @param file_name Name of the file to write.
 */
void RAM::write(const std::string& file_name) {
  std::ofstream file(file_name);
  int* output_tape = output_unit_->getTape();
  size_t size = output_unit_->getSize();
  if (file.is_open()) {
    for (size_t i = 0; i < size; i++) {
      file << output_tape[i] << std::endl;
    }
  } else {
    throw std::runtime_error("Unable to open file.");
  }
  file.close();
}

/**
 * @brief Destroy the RAM::RAM object
 */
RAM::~RAM(void) {
  delete data_memory_;
  delete alcu_;
  delete input_unit_;
  delete output_unit_;
}

/**
 * @brief Formats the instructions and stores them in a vector of strings.
 * 
 * @param instructions Content of the file as a vector of strings.
 */
void RAM::FormatInstructions(const std::vector<std::string>& instructions) {
  for (size_t i = 0; i < instructions.size(); i++) {
    std::string line = instructions[i], word;
    if (line[0] == '#' || line.empty()) {
      continue;
    }
    int counter = 0, operand;
    AddressingMode addressing_mode;
    std::string instruction, label;
    std::stringstream ss(line);
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
        ++counter;
      } else if (counter == 1) {
        if (word.length() == 1) {
          addressing_mode = CONSTANT;
          operand = std::stoi(word);
        } else if (word[0] == '=') {
          addressing_mode = DIRECT;
          operand = std::stoi(word.substr(1));
        } else if (word[0] == '*') {
          addressing_mode = INDIRECT;
          operand = std::stoi(word.substr(1));
        } else {
          throw std::runtime_error("Invalid operand syntax.");
        }
      }
    }
    if (instruction == "LOAD") {
      program_memory_.emplace_back(new LOAD(operand));
    } else if (instruction == "STORE") {
      program_memory_.emplace_back(new STORE(operand));
    } else if (instruction == "ADD") {
      program_memory_.emplace_back(new ADD(addressing_mode, operand));
    } else if (instruction == "SUB") {
      program_memory_.emplace_back(new SUB(addressing_mode, operand));
    } else if (instruction == "MUL") {
      program_memory_.emplace_back(new MUL(addressing_mode, operand));
    } else if (instruction == "DIV") {
      program_memory_.emplace_back(new DIV(addressing_mode, operand));
    } else if (instruction == "READ") {
      program_memory_.emplace_back(new READ(addressing_mode, operand, input_unit_));
    } else if (instruction == "WRITE") {
      program_memory_.emplace_back(new WRITE(addressing_mode, operand, output_unit_));
    // TODO: Implement jump instructions.
    // } else if (instruction == "JUMP") {
    //   program_memory_.emplace_back(new JUMP(i));
    // } else if (instruction == "JZERO") {
    //   program_memory_.emplace_back(new JZERO(i));
    // } else if (instruction == "JGTZ") {
    //   program_memory_.emplace_back(new JGTZ(i));
    } else if (instruction == "HALT") {
      program_memory_.emplace_back(new HALT());
    } else {
      throw std::runtime_error("Invalid instruction.");
    }
    if (!label.empty()) {
      labels_[label] = program_memory_[program_memory_.size() - 1];
      label.clear();
    }
  }
}

/**
 * @brief Formats the tape and stores it in a vector of integers.
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