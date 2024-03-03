#include "Entity\Unit.hpp"

Unit::Unit(Type p_type, int p_srcWidth, int p_srcHeight, int p_xPos, int p_yPos, int p_destWidth, int p_destHeight)
{
    type = p_type;

    switch (p_type)
    {
    case ROCK:
        winType = SCISSORS;
        loseType = PAPER;
        break;
    case PAPER:
        winType = ROCK;
        loseType = SCISSORS;
        break;
    case SCISSORS:
        winType = PAPER;
        loseType = ROCK;
        break;
    }

    srcRect = {0, 0, p_srcWidth, p_srcHeight};
    xPos = p_xPos;
    yPos = p_yPos;
    width = p_destWidth;
    height = p_destHeight;

    destRect = {(int)xPos, (int)yPos, width, height};
}

std::pair<double, double> Unit::randBorn(int centerX, int centerY, int p_diameter)
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