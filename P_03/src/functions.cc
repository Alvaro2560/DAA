/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Definition of the functions used in the program.
 * @version 1.0
 * @since Jan 31 2024
 * 
 * @see https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/instructions.h"
#include "../include/output-unit.h"

#include <sstream>
#include <bits/stdc++.h>

/**
 * @brief Prints the help menu.
 */
void PrintHelp(void) {
  std::cout << "Usage: ./P_03 <file_name.ram> <input_tape> <output_tape> <debug_mode>" << std::endl;
  std::cout << "  file_name.ram: File with the instructions of the RAM." << std::endl;
  std::cout << "  input_tape: File with the input tape." << std::endl;
  std::cout << "  output_tape: File where the output tape will be written." << std::endl;
  std::cout << "  debug_mode: 0 if the program should run in normal mode, 1 if it should print" 
               " the number of instructions executed, 2 if it should print the instruction executed," 
               " data memory, input tape, output tape and number of instructions executed, step by step." << std::endl;
}

/**
 * @brief Reads the content of a file and returns it as a vector of strings.
 * 
 * @param file_name Name of the file to read.
 * @return std::vector<std::string> Content of the file as a vector of strings.
 */
std::vector<std::string> ReadFile(const std::string& file_name) {
  std::ifstream file(file_name);
  std::vector<std::string> file_content;
  std::string line;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      file_content.emplace_back(line);
    }
    file.close();
  } else {
    throw std::runtime_error("Unable to open file.");
  }
  return file_content;
}

/**
 * @brief Writes the content of a vector of integers to a file.
 * 
 * @param output_tape Vector of integers to write to the file.
 * @param size Size of the vector.
 * @param file_name Name of the file to write.
 */
void WriteUnit(const OutputUnit* output_unit, const std::string& file_name) {
  std::ofstream file(file_name);
  if (file.is_open()) {
    int* output_tape = output_unit->getTape();
    size_t size = output_unit->getSize();
    for (size_t i = 0; i < size - 1; i++) {
      file << output_tape[i] << std::endl;
    }
    file.close();
  } else {
    throw std::runtime_error("Unable to open file.");
  }
}

/**
 * @brief Formats the instructions and stores them in a vector of strings.
 * 
 * @param instructions Content of the file as a vector of strings.
 * @return std::vector<Instruction*> Vector of instructions.
 */
std::vector<Instruction*> FormatInstructions(const std::vector<std::string>& instructions,
                                             std::unordered_map<std::string, size_t>& labels) {
  std::unordered_map<std::string, std::pair<size_t, std::string>> labels_cache;
  std::vector<Instruction*> program_memory;
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
        CheckAddressingMode(word, addressing_mode, operand, i, instruction);
      }
    }
    CreateInstruction(program_memory, instruction, addressing_mode, operand, label, i, word, jump_label, labels);
    if (!label.empty()) {
      labels[label] = program_memory.size() - 1;
      label.clear();
    }
  }
  CheckLabels(labels, labels_cache);
  return program_memory;
}

/**
 * @brief Creates an instruction and stores it in the program memory.
 * 
 * @param instruction Instruction to create.
 * @param addressing_mode Addressing mode of the instruction.
 * @param operand Operand of the instruction.
 * @param label Label of the instruction.
 * @param line Line of the instruction.
 * @param line_operand Operand of the instruction as a string.
 * @param jump_label Label of the instruction to jump to.
 */
void CreateInstruction(std::vector<Instruction*>& program_memory,
                       const std::string& instruction, 
                       const AddressingMode& addressing_mode, 
                       const int& operand, 
                       const std::string& label, const int& line,
                       const std::string& line_operand,
                       const std::string& jump_label,
                       std::unordered_map<std::string, size_t>& labels) {
  if (instruction == "LOAD") {
      program_memory.emplace_back(new LOAD(addressing_mode, operand));
  } else if (instruction == "STORE") {
    if (addressing_mode == CONSTANT) {
      std::string error = "Error at line " + std::to_string(line + 1) + ":\n\n";
      error += instruction + " " + line_operand + "\n";
      for (size_t i = 0; i < (instruction + line_operand).size() + 1; i++) {
        error += "^";
      }
      error += "\nInvalid operand for STORE instruction.";
      throw std::runtime_error(error);
    }
    program_memory.emplace_back(new STORE(addressing_mode, operand, 0));
  } else if (instruction == "ADD") {
    program_memory.emplace_back(new ADD(addressing_mode, operand, 0));
  } else if (instruction == "SUB") {
    program_memory.emplace_back(new SUB(addressing_mode, operand, 0));
  } else if (instruction == "MUL") {
    program_memory.emplace_back(new MUL(addressing_mode, operand, 0));
  } else if (instruction == "DIV") {
    program_memory.emplace_back(new DIV(addressing_mode, operand, 0));
  } else if (instruction == "READ") {
    if ((addressing_mode == DIRECT && operand == 0) || addressing_mode == CONSTANT) {
      std::string error = "Error at line " + std::to_string(line + 1) + ":\n\n";
      error += instruction + " " + line_operand + "\n";
      for (size_t i = 0; i < (instruction + line_operand).size() + 1; i++) {
        error += "^";
      }
      error += "\nInvalid operand for READ instruction.";
      throw std::runtime_error(error);
    }
    program_memory.emplace_back(new READ(addressing_mode, operand, 0));
  } else if (instruction == "WRITE") {
    if (addressing_mode == DIRECT && operand == 0) {
      std::string error = "Error at line " + std::to_string(line + 1) + ":\n\n";
      error += instruction + " " + line_operand + "\n";
      for (size_t i = 0; i < (instruction + line_operand).size() + 1; i++) {
        error += "^";
      }
      error += "\nInvalid operand for WRITE instruction.";
      throw std::runtime_error(error);
    }
    program_memory.emplace_back(new WRITE(addressing_mode, operand, 0));
  } else if (instruction == "JUMP") {
    program_memory.emplace_back(new JUMP(jump_label, &labels, program_memory));
  } else if (instruction == "JZERO") {
    program_memory.emplace_back(new JZERO(jump_label, &labels, program_memory));
  } else if (instruction == "JGTZ") {
    program_memory.emplace_back(new JGTZ(jump_label, &labels, program_memory));
  } else if (instruction == "HALT") {
    program_memory.emplace_back(new HALT());
  } else {
      std::string error = "Error at line " + std::to_string(line + 1) + ":\n\n";
      error += instruction + " " + line_operand + "\n";
      for (size_t i = 0; i < (instruction + line_operand).size() + 1; i++) {
        error += "^";
      }
      error += "\nInvalid instruction.";
      throw std::runtime_error(error);
  }
}

void CheckAddressingMode(const std::string& word, 
                         AddressingMode& addressing_mode, 
                         int& operand, 
                         const int& i, 
                         const std::string& instruction) {
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

/**
 * @brief Formats the input tape and stores it in a vector of integers.
 * 
 * @param file_name Name of the file to read.
 */
void CheckLabels(const std::unordered_map<std::string, size_t>& labels, 
                 const std::unordered_map<std::string, std::pair<size_t, std::string>>& labels_cache) {
  // Check if there are any undefined labels.
  for (auto it = labels_cache.begin(); it != labels_cache.end(); it++) {
    // If the label is not in the labels map, it is undefined.
    if (labels.find(it->first) == labels.end()) {
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
std::vector<int> FormatTape(const std::vector<std::string>& file_name) {
  std::vector<int> tape;
  for (size_t i = 0; i < file_name.size(); i++) {
    tape.emplace_back(std::stoi(file_name[i]));
  }
  return tape;
}