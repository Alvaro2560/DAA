/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Programación de Aplicaciones Interactivas 2023-2024
 * 
 * @file functions.cc
 * @author Álvaro Fontenla León (alu0101437989@ull.edu.es)
 * @brief Implementation of the functions used in the program.
 * @version 0.1
 * @since Jan 31 2024
 * 
 * @see https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"
#include "../include/instructions.h"

#include <sstream>
#include <bits/stdc++.h>

/**
 * @brief Prints the help menu.
 */
void PrintHelp(void) {
  std::cout << "Usage: ./P_02 <file_name.ram> <input_tape> <output_tape>" << std::endl;
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
 * @brief Formats the instructions and stores them in a vector of strings.
 * 
 * @param file_content Content of the file as a vector of strings.
 * @param instructions Vector of strings where the formatted instructions will be stored.
 * @param labels Map where the labels will be stored.
 */
void FormatInstructions(const std::vector<std::string>& file_content, 
                              std::vector<Instruction*>& instructions,
                              std::unordered_map<std::string, Instruction*>& labels) {
  for (size_t i = 0; i < file_content.size(); i++) {
    std::string line = file_content[i], word;
    if (line[0] == '#' || line.empty()) {
      continue;
    }
    int counter = 0, operand;
    AddressingMode addressing_mode;
    std::string instruction;
    std::stringstream ss(line); 
    while (ss >> word) {
      if (counter == 0) {
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
        instruction = word;
        ++counter;
      } else {
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
      instructions.emplace_back(new LOAD(operand));
    } else if (instruction == "STORE") {
      instructions.emplace_back(new STORE(operand));
    } else if (instruction == "ADD") {
      instructions.emplace_back(new ADD(addressing_mode, operand));
    } else if (instruction == "SUB") {
      instructions.emplace_back(new SUB(addressing_mode, operand));
    } else if (instruction == "MUL") {
      instructions.emplace_back(new MUL(addressing_mode, operand));
    } else if (instruction == "DIV") {
      instructions.emplace_back(new DIV(addressing_mode, operand));
    } else if (instruction == "READ") {
      instructions.emplace_back(new READ(addressing_mode, operand));
    } else if (instruction == "WRITE") {
      instructions.emplace_back(new WRITE(addressing_mode, operand));
    // } else if (instruction == "JUMP") {
    //   instructions.emplace_back(new JUMP(i));
    // } else if (instruction == "JZERO") {
    //   instructions.emplace_back(new JZERO(i));
    // } else if (instruction == "JGTZ") {
    //   instructions.emplace_back(new JGTZ(i));
    } else if (instruction == "HALT") {
      instructions.emplace_back(new HALT());
    } else {
      throw std::runtime_error("Invalid instruction.");
    }
    // if (line.find(':') != std::string::npos) {
    //   std::string label = line.substr(0, line.find(':'));
    //   // labels[label] = new Instruction(i);
    //   line = line.substr(line.find(':') + 1);
  }
}

/**
 * @brief Formats the tape and stores it in a vector of integers.
 * 
 * @param file_name Name of the file to read.
 * @return std::vector<int> Content of the file as a vector of integers.
 */
std::vector<int> FormatTape(const std::string& file_name) {
  std::ifstream file(file_name);
  std::vector<int> tape;
  int number;
  if (file.is_open()) {
    while (file >> number) {
      tape.emplace_back(number);
    }
  } else {
    throw std::runtime_error("Unable to open file.");
  }
  file.close();
  return tape;
}