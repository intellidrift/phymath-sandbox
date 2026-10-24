#ifndef PHYMATH_SANDBOX_APPLICATION_H
#define PHYMATH_SANDBOX_APPLICATION_H

#include "Body.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Application
{
private:
    VideoMode mode;
    RenderWindow window;
    Clock clock;

    vector<Body> bodies;
    float dt = 0.f;

    void processEvents();
    void update();
    void render();

public:
    Application();
    ~Application() = default;
    void run();
    void tick();
};

#endif //PHYMATH_SANDBOX_APPLICATION_H
