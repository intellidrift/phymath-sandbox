
#include "Gen.h"

Gen::Gen()
    : gen(rd())
    , dist(-500.0f, 500.0f)
{}

Vector2f Gen::vec(const float lo, const float hi)
{
    uniform_real_distribution<float>::param_type(lo, hi);
    return vec(dist(gen), dist(gen));
}