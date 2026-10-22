#ifndef PHYMATH_SANDBOX_APPLICATION_H
#define PHYMATH_SANDBOX_APPLICATION_H

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

    float dt = 0.f;

public:
    Application();
    ~Application() = default;
    void run();
    void tick();
};

#endif //PHYMATH_SANDBOX_APPLICATION_H
