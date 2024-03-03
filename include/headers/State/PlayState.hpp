#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "State/GameState.hpp"

class Entity;
class TextTure;
class Player;
class Animator;
class ScorePanel;

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

    std::vector<Entity *> entities;

    Player *player = nullptr;
    // TextTure* tHeight = nullptr;
    ScorePanel *scorePanel = nullptr;
    Entity *background = nullptr;

    static std::pair<double, double> randBorn(int centerX, int centerY, int p_diameter); // random a pos in a circle
};

#endif
