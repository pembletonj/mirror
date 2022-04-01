#pragma once

#include <fstream>
#include <list>

class Mirrorer {
public:
    bool addOutputFile(std::string path);
    void mirrorInput(std::istream &input);
    ~Mirrorer();
private:
    std::list<std::ofstream*> outputFiles;
};