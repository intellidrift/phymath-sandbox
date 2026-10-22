#include "Application.h"

#include "Body.h"

Application::Application()
    : mode({3550, 2440})
    , window(mode, "hello world")
{}

void Application::run()
{
    const Body box({2500, 1440}, {100, 100}, 50);

    while (window.isOpen()) {
        tick();

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

        window.clear(Color(50, 50, 50));
        window.draw(box);
        window.display();
    }
}

void Application::tick()
{
    if (dt > 0.1)
        dt = 0.1;
    dt = clock.restart().asSeconds();
}