#ifndef UNIT
#define UNIT

#include "Entity\Entity.hpp"

enum Type
{
    ROCK,
    PAPER,
    SCISSORS
};

class Unit : public Entity
{
public:
    Unit(Type p_type, int p_srcWidth, int p_srcHeight, int p_xPos, int p_yPos, int p_destWidth, int p_destHeight);
    ~Unit();

    Type getType() { return type; }
    void setType(Type p_type);

private:
    Type type;
    Type winType;
    Type loseType;
    static SDL_Texture *imgs[3];

    static std::pair<double, double> randBorn(int centerX, int centerY, int p_diameter); // random a pos in a circle
    static Unit *findShortest();
    static void chase();
};

#endif