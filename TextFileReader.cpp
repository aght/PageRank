//
// Created by Andy Tang on 10/11/2018.
//

#include "TextFileReader.hpp"

// Reads a text file and returns a vector containing each word in the text file
std::vector<std::string> TextFileReader::read_file(const char *fileName) {
    std::vector<std::string> lines;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "File not found." << std::endl;
    }

    std::string word;
    while (file >> word) {
        lines.push_back(word);
        word.empty();
    }

    return lines;
}