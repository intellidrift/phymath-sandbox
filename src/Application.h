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
    const String title = "Phymath-sandbox";
    const int screenWidth = 3550;
    const int screenHeight = 2440;

    VideoMode mode;
    RenderWindow window;
    Clock clock;

    float dt = 0.f;

    World world;
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
