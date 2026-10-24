#include "Body.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

Body::Body(const Vector2f &position, const Vector2f &velocity, const float mass)
    : position(position)
    , velocity(velocity)
    , acceleration({0, 0})
    , mass(mass)
    , invMass(1.0f / mass)
{
    box.setPosition(position);
    box.setSize({100, 100});
    box.setFillColor(Color(0x886176));
}

void Body::integrate(const float dt)
{
    velocity += acceleration * dt;
    position += velocity * dt;
    resetAcceleration();
    box.setPosition(position);
}

void Body::applyForce(const Vector2f &force)
{
    if (force == VEC2_ZERO) {
        return;
    }
    acceleration += force / mass;
}

void Body::draw(RenderTarget &target, const RenderStates states) const
{
    target.draw(box, states);
}