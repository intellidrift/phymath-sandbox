#include "World.h"
#include <optional>

World::World() {}

void World::addBody(const Body &body)
{
    bodies.push_back(body);
}

// void World::resolveScreenBounce(Body &body)
// {
//     constexpr float correction = 5;
//
//     if (body.position().y > screenHeight - body.box().getSize().y) {
//         body.setVelocity(Vector2f(body.velocity().x, -body.velocity().y));
//         body.setPosition({body.position().x, body.position().y - correction});
//
//     } else if (body.position().x > screenWidth - body.box().getSize().x) {
//         body.setVelocity(Vector2f(-body.velocity().x, body.velocity().y));
//         body.setPosition({body.position().x - correction, body.position().y});
//
//     } else if (body.position().y < 0) {
//         body.setVelocity(Vector2f(body.velocity().x, -body.velocity().y));
//         body.setPosition({body.position().x, body.position().y + correction});
//
//     } else if (body.position().x < 0) {
//         body.setVelocity(Vector2f(-body.velocity().x, body.velocity().y));
//         body.setPosition({body.position().x + correction, body.position().y});
//     }
// }

void World::handleEvent(const optional<Event> &event)
{
    if (event->getIf<Event::KeyPressed>()) {
        cout << "Event: KeyPressed" << endl;
    }
}

void World::step(const float dt)
{
    for (Body &body : bodies) {
        body.update(dt);
    }
}

void World::render(RenderWindow &window)
{
    for (Body &body : bodies) {
        window.draw(body);
    }
}