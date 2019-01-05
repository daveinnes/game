#ifndef _RESOURCE_H_
#define _RESOURCE_H_

namespace Json {
    class Value;
}

struct Resource {
    Resource(const Json::Value& v);
    Resource() : money(0), research(0) {}
    Resource(int m, int r) : money(m), research(r) {}
    
    Resource& operator+=(const Resource& rhs) {
        money += rhs.money;
        research += rhs.research;
        return *this;
    }

    Resource& operator-=(const Resource& rhs) {
        money -= rhs.money;
        research -= rhs.research;
        return *this;
    }

    int money;
    int research;
};

#endif