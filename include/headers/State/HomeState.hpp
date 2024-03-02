#ifndef HOMESTATE_HPP
#define HOMESTATE_HPP

#include "State/GameState.hpp"

class Entity;
class TextTure;
class Button;

class HomeState : public GameState
{
public:
    static HomeState *get();

    bool enter() override;
    bool exit() override;

    void handleEvent(SDL_Event &p_e) override;
    void update() override;
    void render() override;

private:
    static HomeState sHomeState;
    HomeState();

    std::vector<Entity *> entities;
};

#endif