#ifndef PHYMATH_SANDBOX_UTILS_H
#define PHYMATH_SANDBOX_UTILS_H
#include <SFML/System/Vector2.hpp>
#include <random>

using namespace std;
using namespace sf;

class Gen
{
private:
    random_device rd;
    std::mt19937 gen;
    uniform_real_distribution<float> dist;

public:
    Gen();
    Vector2f vec(float lo = -500.f, float hi = 500.f);
};

#endif //PHYMATH_SANDBOX_UTILS_H
