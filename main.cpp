#include <iostream>
#include <fstream>
#include <list>
#include <cstring>

#include "mirrorer.hpp"

enum ArgFlag {
    INPUT,
    OUTPUT
};

int main(int argc, char** argv) {

    std::string inputFilePath = "/dev/stdin";
    std::list<std::string> outputFilePaths;

    ArgFlag flag = OUTPUT;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            // Flag
            if (strncmp(argv[i], "-i", 2) == 0) {
                flag = INPUT;
            }
            else if (strncmp(argv[i], "-o", 2) == 0) {
                flag = OUTPUT;
            }
            else {
                std::cerr << "Unknown option: " << argv[i] << std::endl;
            }
        }
        else if (flag == INPUT) {
            inputFilePath = argv[i];
        }
        else {
            outputFilePaths.push_back(argv[i]);
        }
    }

    Mirrorer mirrorer;

    for (auto it = outputFilePaths.begin(); it != outputFilePaths.end(); ++it) {
        if (!mirrorer.addOutputFile(*it)) {
            std::cerr << "Could not open file: " << *it << std::endl;
            return 1;
        }
    }

    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << inputFilePath << std::endl;
        return 1;
    }

    mirrorer.mirrorInput(inputFile);
    
    inputFile.close();
    return 0;

}