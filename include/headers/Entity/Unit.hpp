#ifndef UNIT
#define UNIT

#include "Entity\Entity.hpp"

enum Type
{
    ROCK,
    PAPER,
    SCISSORS
};

struct Circle
{
    double x;
    double y;
    double radius;
};

class Unit : public Entity
{
public:
    Unit(Type p_type, int p_xPos, int p_yPos);
    ~Unit();

    Type getType() { return type; }
    Type getWinType() { return winType; }
    Type getLoseType() { return loseType; }
    Circle getColli() { return cirCollider; }

    void setType(Type p_type);
    void setDir(std::pair<double, double> p_dir) { dir = p_dir; }
    void shiftCollider();

    void update() override;
    void render() override;
    static void imgsInit();

private:
    double speed;
    Type type;
    Type winType;
    Type loseType;
    std::pair<double, double> dir;
    Circle cirCollider;
    static SDL_Texture *imgs[3];
    static Unit *findShortest();
    void move();
};

#endif