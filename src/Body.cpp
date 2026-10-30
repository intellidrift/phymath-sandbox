#include "Body.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

Body::Body(const Vector2f &position, const Vector2f &velocity, const float mass)
    : pos(position)
    , vel(velocity)
    , acc({0, 0})
    , mass(mass)
    , invMass(1.0f / mass) // TODO: fix me
{
    box.setPosition(position);
    box.setSize({100, 100});
    box.setFillColor(Color(0x886176));
}

void Body::integrate(const float dt)
{
    vel += acc * dt;
    pos += vel * dt;
    resetAcceleration();
}

void Body::update(const float dt)
{
    integrate(dt);
    box.setPosition(pos);
}

void Body::applyForce(const Vector2f &force)
{
    if (force == VEC2_ZERO) {
        return;
    }
    acc += force * invMass;
}

void Body::draw(RenderWindow &window) const
{
    window.draw(box);
}

void Body::draw(RenderTarget &target, const RenderStates states) const
{
    target.draw(box, states);
}