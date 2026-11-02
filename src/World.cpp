#include "World.h"
#include <optional>
#include <utility>

using namespace std;

World::World(const Vector2u &bounds)
    : bounds(bounds)
{}

World::~World() {}

void World::addBody(unique_ptr<Body> &&body)
{
    bodies.push_back(std::move(body));
}

void World::resolveScreenBounce(Body &body)
{
    constexpr float correction = 5;

    if (body.position().y > bounds.y - body.box().getSize().y) {
        body.setVelocity(Vector2f(body.velocity().x, -body.velocity().y));
        body.setPosition({body.position().x, body.position().y - correction});

    } else if (body.position().x > bounds.x - body.box().getSize().x) {
        body.setVelocity(Vector2f(-body.velocity().x, body.velocity().y));
        body.setPosition({body.position().x - correction, body.position().y});

    } else if (body.position().y < 0) {
        body.setVelocity(Vector2f(body.velocity().x, -body.velocity().y));
        body.setPosition({body.position().x, body.position().y + correction});

    } else if (body.position().x < 0) {
        body.setVelocity(Vector2f(-body.velocity().x, body.velocity().y));
        body.setPosition({body.position().x + correction, body.position().y});
    }
}

void World::handleEvent(const optional<Event> &event)
{
    if (event->getIf<Event::KeyPressed>()) {
        // TODO: Not implemented.
    }
}

void World::step(const float dt)
{
    for (const auto &body : bodies) {
        body->update(dt);
        resolveScreenBounce(*body);
    }
}

void World::render(RenderWindow &window)
{
    for (const auto &body : bodies) {
        window.draw(*body);
    }
}