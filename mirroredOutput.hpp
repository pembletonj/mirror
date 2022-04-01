#pragma once

#include <fstream>

class MirroredOutput {
public:
    MirroredOutput(std::string path, bool flush);
    ~MirroredOutput();
    bool open(std::string path, bool flush);
    bool isOpen();
    void write(char c);
private:
    std::ofstream output;
    bool flush;
};