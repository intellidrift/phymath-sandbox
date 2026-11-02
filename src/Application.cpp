#include "Application.h"
#include "Body.h"
#include <iostream>

Application::Application()
    : mode({3550, 2440})
    , window(mode, "Phymath-sandbox")
    , screenWidth(mode.size.x)
    , screenHeight(mode.size.y)
    , world(Vector2u(screenWidth, screenHeight))
{
    const Body box({2500, 1440}, {1000, 300}, 50);
    world.addBody(std::move(make_unique<Body>(box)));
}

Application::~Application() {}

void Application::run()
{
    while (window.isOpen()) {
        tick();
        processEvents();
        update();
        render();
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

        world.handleEvent(event);
    }
}

void Application::update()
{
    world.step(dt);
}

void Application::render()
{
    window.clear(Color(50, 50, 50));
    world.render(window);
    window.display();
}

void Application::tick()
{
    dt = clock.restart().asSeconds();
    if (dt > 0.1f) {
        dt = 0.1f;
    }
}