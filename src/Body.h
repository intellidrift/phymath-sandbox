#ifndef PHYMATH_SANDBOX_BODY_H
#define PHYMATH_SANDBOX_BODY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ranges>

using namespace sf;
using namespace std;

class Body : public Drawable
{
private:
    const Vector2f VEC2_ZERO{0, 0};

    Vector2f pos;
    Vector2f vel;
    Vector2f acc;
    float mass;
    float invMass;

    RectangleShape boxShape; // temporary

public:
    Body(const Vector2f &position, const Vector2f &velocity, float mass);
    void resetAcceleration() { acc = VEC2_ZERO; }

    void integrate(float dt);
    void update(float dt);
    void applyForce(const Vector2f &force);
    void draw(RenderWindow &window) const;

    Vector2f position() { return pos; }
    Vector2f velocity() { return vel; }
    RectangleShape box() { return boxShape; }
    void setBox(const RectangleShape &value) { this->boxShape = value; }
    void setPosition(const Vector2f &value) { this->pos = value; }
    void setVelocity(const Vector2f &value) { this->vel = value; }

protected:
    void draw(RenderTarget &target, RenderStates states) const override;
};

#endif //PHYMATH_SANDBOX_BODY_H