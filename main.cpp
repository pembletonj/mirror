#include <iostream>
#include <fstream>
#include <list>
#include <cstring>

#include "mirrorer.hpp"

int main(int argc, char** argv) {

    std::list<std::string> outputFilePaths;

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        std::cout << "Usage: " << argv[0] << " <file1> [more files...]" << std::endl;
        std::cout << "Input will be read from stdin and written to each of the output files as it is read." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        outputFilePaths.push_back(argv[i]);
    }

    Mirrorer mirrorer;

    for (auto it = outputFilePaths.begin(); it != outputFilePaths.end(); ++it) {
        if (!mirrorer.addOutputFile(*it)) {
            std::cerr << "Could not open file: " << *it << std::endl;
            return 2;
        }
    }

    mirrorer.mirrorInput(std::cin);
    return 0;

}