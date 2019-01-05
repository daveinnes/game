#include "tuning.h"
#include <fstream>

Tuning::Tuning()
: mData(nullptr) {

}

Tuning::~Tuning() {
    delete mData;
}

void Tuning::load(const char* path) {
    if(mData != nullptr) {
        delete mData;
    }
    
    mData = new Json::Value();
    std::ifstream ifs(path);
    Json::Reader reader;
    reader.parse(ifs, *mData);
}

const Json::Value& Tuning::get(const char* key) {
    return (*mData)[key];
}

