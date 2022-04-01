#pragma once

#include <fstream>
#include <list>

#include "mirroredOutput.hpp"

class Mirrorer {
public:
    bool addOutputFile(std::string path, bool flush);
    void mirrorInput(std::istream &input);
    ~Mirrorer();
private:
    std::list<MirroredOutput*> outputs;
};