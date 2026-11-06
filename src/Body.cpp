#include "Body.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

Body::Body(const Vector2f &position, const Vector2f &velocity, const float mass)
    : pos(position)
    , vel(velocity)
    , acc({0, 0})
    , mass(mass)
    , invMass(1.0f / mass)
{
    invMass = mass > 0.f ? 1.f / mass : 0.f;

    boxShape.setPosition(position);
    boxShape.setSize({100, 100});
    boxShape.setFillColor(Color(255, 0, 0));
    boxShape.setOutlineColor(Color(0, 0, 0));
    boxShape.setOutlineThickness(2);
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
    boxShape.setPosition(pos);
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
    window.draw(boxShape);
}

void Body::draw(RenderTarget &target, const RenderStates states) const
{
    target.draw(boxShape, states);
}