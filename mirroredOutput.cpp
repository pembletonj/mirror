#include "mirroredOutput.hpp"

MirroredOutput::MirroredOutput(std::string path, bool flush) {
    open(path, flush);
}

MirroredOutput::~MirroredOutput() {
    if (output.is_open()) {
        output.close();
    }
}

bool MirroredOutput::open(std::string path, bool flush) {
    output.open(path, std::ios::binary);
    this->flush = flush;
    return isOpen();
}

bool MirroredOutput::isOpen() {
    return output.is_open();
}

void MirroredOutput::write(char c) {
    output.write(&c, sizeof(c));
    if (flush) {
        output.flush();
    }
}