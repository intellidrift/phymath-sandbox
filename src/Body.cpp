#include "Body.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

Body::Body(const Vector2f position, const Vector2f velocity, const float mass)
    : position(position)
    , velocity(velocity)
    , mass(mass)
{
    std::cout << "hello body!" << std::endl;
}

void Body::update(float dt)
{
    // NOTE: not implemented,,,
}

void Body::draw(RenderTarget &target, const RenderStates states) const
{
    RectangleShape box({100, 100});
    box.setPosition({1000, 1000});
    target.draw(box, states);
}