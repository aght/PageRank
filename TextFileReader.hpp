//
// Created by Andy Tang on 10/11/2018.
//

#ifndef PAGERANK_TEXTFILEREADER_HPP
#define PAGERANK_TEXTFILEREADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class TextFileReader {
public:
    // Reads a text file and returns a vector of each word in the text file
    static std::vector<std::string> read_file(const char *fileName);
};


#endif //PAGERANK_TEXTFILEREADER_HPP
