#ifndef _TUNING_H_
#define _TUNING_H_

#include <json/json.h>

class Tuning
{
public:
    Tuning();
    ~Tuning();

    void load(const char* path);
    const Json::Value& get(const char* name);
private:
    Json::Value* mData;
};

#endif