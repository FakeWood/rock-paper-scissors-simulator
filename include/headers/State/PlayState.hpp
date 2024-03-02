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
};

#endif
