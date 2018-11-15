#include "util.h"
#include <fstream>
#include <string>
#include <unistd.h>
#include <memory>
#include <cstdio>

std::string File::readText(const char* path) {
    std::string ostr;

    std::ifstream file(path);
    if (file.is_open())
    {
        std::string line;
        while(getline(file, line)) {
            ostr += line + '\n';
        }
    }

    return ostr;
}