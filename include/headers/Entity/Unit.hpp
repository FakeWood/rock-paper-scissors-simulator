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
    Unit(Type p_type, int p_xPos, int p_yPos);
    ~Unit();

    Type getType() { return type; }
    void setType(Type p_type);
    void update() override;
    void render() override;

private:
    Type type;
    Type winType;
    Type loseType;
    static SDL_Texture *imgs[3];

    static Unit *findShortest();
    static void chase();
};

#endif