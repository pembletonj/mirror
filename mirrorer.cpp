#include "mirrorer.hpp"

bool Mirrorer::addOutputFile(std::string path) {
    std::ofstream* output = new std::ofstream(path, std::ios::binary);
    outputFiles.push_back(output);
    return output->is_open();
}

void Mirrorer::mirrorInput(std::istream &input) {

    while (!input.eof() && !input.bad()) {
        char c;
        input.read(&c, sizeof(c));
        for (auto it = outputFiles.begin(); it != outputFiles.end(); ++it) {
            (*it)->write(&c, sizeof(c));
            (*it)->flush();
        }
    }

}

Mirrorer::~Mirrorer() {
    for (auto it = outputFiles.begin(); it != outputFiles.end(); ++it) {
        if ((*it)->is_open()) {
            (*it)->close();
        }
        delete *it;
    }
}