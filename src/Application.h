#ifndef PHYMATH_SANDBOX_APPLICATION_H
#define PHYMATH_SANDBOX_APPLICATION_H

#include "Body.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Application final
{
private:
    VideoMode mode;
    RenderWindow window;
    Clock clock;

    int screenWidth;
    int screenHeight;
    vector<Body> bodies; // temp
    float dt = 0.f;

    void processEvents();
    void update();
    void render();
    void resolveScreenBounce(Body &body);
public:
    Application();
    ~Application() = default;
    void run();
    void tick();
};

using namespace sf;

#endif //PHYMATH_SANDBOX_APPLICATION_H
