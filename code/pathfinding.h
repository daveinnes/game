#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <vector>

#include "vector.h"

struct Path {
    Path() {}

    Path(const Path& rhs) {
        for(const Vector2& step : rhs.steps) {
            steps.push_back(step);
        }
    }
    bool operator == (const Path& rhs) const {
        if(steps.size() != rhs.steps.size()) {
            return false;
        }
        for(int i = 0; i < steps.size(); ++i) {
            if(steps[i] != rhs.steps[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator != (const Path& rhs) const {
        return !(*this == rhs);
    }
    bool operator < (const Path& rhs) const
    {
        return distance() < rhs.distance();
    }
    bool operator > (const Path& rhs) const {
        return !(*this < rhs);
    }
    int distance() const {
        return steps.size();
    }

    bool contains(const Vector2& pos) const;

    std::vector<Vector2> steps;
};

class Pathfinding
{
public:
    Pathfinding();
    ~Pathfinding();

    Path findPath(const Vector2& start, const Vector2& end);
private:
    bool validStep(const Path& path, const Vector2& step);
    Path getPath(const Path& path, const Vector2& step);
    std::vector<Path> frontier;

};
#endif