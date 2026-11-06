#ifndef PHYMATH_SANDBOX_WORLD_H
#define PHYMATH_SANDBOX_WORLD_H

#include "Body.h"
#include <iostream>
#include <vector>

using namespace std;

class World
{
    Vector2u bounds;

private:
    vector<unique_ptr<Body>> bodies;

public:
    explicit World(const Vector2u &bounds);
    virtual ~World() = default;
    void addBody(unique_ptr<Body> &&body);
    void resolveWalls(Body &body);

    virtual void handleEvent(const optional<Event> &event);
    virtual void step(float dt);
    virtual void render(RenderWindow &window);
};

#endif //PHYMATH_SANDBOX_WORLD_H
