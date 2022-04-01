#include <iostream>
#include <fstream>
#include <list>
#include <cstring>

#include "mirrorer.hpp"

void printHelp(std::string programName) {
    std::cout << "Usage: " << programName << " [option] <file1> [files...] [options...]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "\t-o [files...]: Output without writing after each character. Default if no option is specified." << std::endl;
    std::cout << "\t-f [files...]: Output with writing after each character." << std::endl;
}

int main(int argc, char** argv) {

    std::list<std::pair<std::string, bool>> outputFilePaths;

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        printHelp(argv[0]);
        return 0;
    }

    bool flush = false;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (strcmp(argv[i], "-o") == 0) {
                flush = false;
            }
            else if (strcmp(argv[i], "-f") == 0) {
                flush = true;
            }
            else {
                std::cerr << "Unknown option: " << argv[i] << std::endl;
                printHelp(argv[0]);
                return 1;
            }
        }
        else {
            std::pair<std::string, bool> file(argv[i], flush);
            outputFilePaths.push_back(file);
        }
    }

    Mirrorer mirrorer;

    for (auto it = outputFilePaths.begin(); it != outputFilePaths.end(); ++it) {
        if (!mirrorer.addOutputFile(it->first, it->second)) {
            std::cerr << "Could not open file: " << it->first << std::endl;
            return 2;
        }
    }

    mirrorer.mirrorInput(std::cin);
    return 0;

}