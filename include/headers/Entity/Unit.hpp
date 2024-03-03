#ifndef UNIT
#define UNIT

#include "Entity/Entity.hpp"

enum Type
{
    ROCK,
    PAPER,
    SCISSORS
};

class Unit : Entity
{
public:
    Type getType();
    void setType(Type p_type);

private:
    Type type;
    Type weakType;
    static SDL_Texture *imgs[3];

    Unit *findShortest();
    void chase();
};

#endif