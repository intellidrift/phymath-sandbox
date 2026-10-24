#include "Application.h"
#include "Body.h"

Application::Application()
    : mode({3550, 2440})
    , window(mode, "hello world")
{
    const Body box({2500, 1440}, {500, 500}, 50);
    bodies.push_back(box);
}

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
    }
}

void Application::update()
{
    for (auto &box : bodies) {
        box.integrate(dt);
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
    // NOTE: lag protection.
    if (dt > 0.1f) {
        return;
    }
    dt = clock.restart().asSeconds();
}