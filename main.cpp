#include <iostream>
#include <fstream>
#include <list>

#include "mirrorer.hpp"

int main(int argc, char** argv) {

    std::list<std::string> outputFilePaths;

    for (int i = 1; i < argc; ++i) {
        outputFilePaths.push_back(argv[i]);
    }

    Mirrorer mirrorer;

    for (auto it = outputFilePaths.begin(); it != outputFilePaths.end(); ++it) {
        if (!mirrorer.addOutputFile(*it)) {
            std::cerr << "Could not open file: " << *it << std::endl;
            return 1;
        }
    }

    mirrorer.mirrorInput(std::cin);
    return 0;

}