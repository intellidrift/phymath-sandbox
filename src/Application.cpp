#include "Application.h"
#include "Body.h"
#include <iostream>

Application::Application()
    : mode({3550, 2440})
    , window(mode, "Phymath-sandbox")
    , screenWidth(mode.size.x)
    , screenHeight(mode.size.y)
{
    const Body box({2500, 1440}, {500, 300}, 50); // temp to some
    bodies.push_back(box);                        // temp to some
}

void Application::run()
{
    while (window.isOpen()) {
        tick();
        processEvents();
        update(); // temp to sim
        render(); // temp to sim
    }
}

void Application::processEvents()
{
    while (const optional<Event> event = window.pollEvent()) {
        if (event->is<Event::Closed>()) {
            window.close();
        }
        if (const auto *key = event->getIf<Event::KeyPressed>()) {
            if (key->code == Keyboard::Key::Escape) {
                window.close();
            }
        }
    }
}

void Application::update()
{
    for (auto &box : bodies) {
        box.update(dt);
        resolveBounds(box);
    }
}

void Application::render()
{
    window.clear(Color(50, 50, 50));
    for (const auto &box : bodies) {
        window.draw(box);
    }
    window.display();
}

void Application::tick()
{
    if (dt > 0.1f) {
        return;
    }
    dt = clock.restart().asSeconds();
}

void Application::resolveBounds(Body &body)
{
    // Needs of convenient api for body magnitudes..
}