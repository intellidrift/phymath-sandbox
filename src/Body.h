#ifndef PHYMATH_SANDBOX_BODY_H
#define PHYMATH_SANDBOX_BODY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

class Body : public Drawable
{
private:
    const Vector2f VEC2_ZERO {0, 0};

    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    float mass;
    float invMass;

    RectangleShape box; // temporary

    void resetAcceleration() { acceleration = VEC2_ZERO; };

public:
    Body(const Vector2f &position, const Vector2f &velocity, float mass);
    void integrate(float dt);
    void applyForce(const Vector2f &force);

protected:
    void draw(RenderTarget &target, RenderStates states) const override;
};

#endif //PHYMATH_SANDBOX_BODY_H