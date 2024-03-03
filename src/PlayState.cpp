#include "State\PlayState.hpp"

std::pair<double, double> PlayState::randBorn(int centerX, int centerY, int p_diameter)
{
    double X, Y;
    double length;
    double degree;

    srand(time(NULL));
    length = rand() % (p_diameter / 2);
    degree = rand() % 360;
    sincos(degree * M_PI / 180, &Y, &X);
    X *= length;
    Y *= length;
    return std::pair(X, Y);
}