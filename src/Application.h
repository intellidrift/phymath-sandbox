#ifndef PHYMATH_SANDBOX_APPLICATION_H
#define PHYMATH_SANDBOX_APPLICATION_H

#include "Body.h"
#include "World.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Application final
{
private:
    VideoMode mode;
    RenderWindow window;
    Clock clock;

    int screenWidth;
    int screenHeight;
    World world;
    float dt = 0.f;

    void processEvents();
    void update();
    void render();

public:
    Application();
    ~Application();
    void run();
    void tick();
};

#endif //PHYMATH_SANDBOX_APPLICATION_H
