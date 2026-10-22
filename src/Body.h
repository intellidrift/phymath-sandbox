#ifndef PHYMATH_SANDBOX_BODY_H
#define PHYMATH_SANDBOX_BODY_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

class Body : public Drawable
{
private:
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    float mass;

public:
    Body(Vector2f position, Vector2f velocity, float mass);
    void update(float dt);

protected:
    void draw(RenderTarget &target, RenderStates states) const override;
};

#endif //PHYMATH_SANDBOX_BODY_H