#include "pathfinding.h"
#include "game.h"
#include "world.h"

#include <algorithm>

bool Path::contains(const Vector2& pos) const {
    return std::find(steps.begin(), steps.end(), pos) != steps.end();
}

Pathfinding::Pathfinding() {
}

Pathfinding::~Pathfinding() {

}

Path Pathfinding::findPath(const Vector2& start, const Vector2& end) {
    frontier.clear();
    Path seed;
    seed.steps.push_back(start);
    frontier.push_back(seed);

    Vector2 offsets[4];
    offsets[0].x = 1;
    offsets[1].x = -1;
    offsets[2].y = 1;
    offsets[3].y = -1;

    while(!frontier.empty()) {
        std::sort(frontier.begin(), frontier.end(), 
            [](const Path& a, const Path& b) {
                return a > b;
            });
        Path path = frontier.back();
        frontier.pop_back();
        if(path.steps.back() == end) {
            return path;
        }
        for(int i = 0; i < 4; ++i) {
            Vector2 newPos = path.steps.back() + offsets[i];
            if(validStep(path, newPos)) {
                Path newPath = getPath(path, newPos);
                frontier.push_back(newPath);
            }
        }
    }
    return seed;
}

Path Pathfinding::getPath(const Path& path, const Vector2& newPos) {
    Path newPath = path;
    newPath.steps.push_back(newPos);
    return newPath;
}

bool Pathfinding::validStep(const Path& path, const Vector2& newPos) {
    World* world = Game::get()->world();
    return world->isInBounds(newPos) && world->at(newPos) == nullptr && !path.contains(newPos);
}
