#ifndef PHYMATH_SANDBOX_WORLD_H
#define PHYMATH_SANDBOX_WORLD_H

#include "Body.h"
#include <iostream>
#include <vector>

using namespace std;

class World
{
private:
    vector<Body> bodies;

public:
    World();
    virtual ~World() = default;
    void addBody(const Body &body);
    // void resolveScreenBounce(Body &body);

    virtual void handleEvent(const optional<Event> &event);
    virtual void step(float dt);
    virtual void render(RenderWindow &window);
};

#endif //PHYMATH_SANDBOX_WORLD_H
