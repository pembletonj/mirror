#include "mirrorer.hpp"

bool Mirrorer::addOutputFile(std::string path, bool flush) {
    MirroredOutput* output = new MirroredOutput(path, flush);
    outputs.push_back(output);
    return output->isOpen();
}

void Mirrorer::mirrorInput(std::istream &input) {

    while (!input.eof() && !input.bad()) {
        char c;
        input.read(&c, sizeof(c));
        for (auto it = outputs.begin(); it != outputs.end(); ++it) {
            (*it)->write(c);
        }
    }

}

Mirrorer::~Mirrorer() {
    for (auto it = outputs.begin(); it != outputs.end(); ++it) {
        delete *it;
    }
}