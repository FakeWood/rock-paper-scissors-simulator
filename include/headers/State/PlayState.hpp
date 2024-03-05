#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "State\GameState.hpp"

class Entity;
class Unit;

class PlayState : public GameState
{
public:
    static PlayState *get();

    bool enter() override;
    bool exit() override;

    void handleEvent(SDL_Event &p_e) override;
    void update() override;
    void render() override;

private:
    static PlayState sPlayState;

    PlayState();

    std::vector<Unit *> units;
    Entity *background = nullptr;

    std::pair<double, double> randBorn(int centerX, int centerY, int p_diameter); // random a pos in a circle
    void updateUnits();
};

#endif
