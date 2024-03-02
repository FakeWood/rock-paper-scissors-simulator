#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "Global.hpp"
#include "State/GameState.hpp"
#include "State/HomeState.hpp"
#include "State/PlayState.hpp"
#include "State/ExitState.hpp"

class StateMachine
{
public:
    static GameState *currentState;
    static GameState *nextState;

    static void setNextState(GameState *p_nextState);
    static void changeState();

    static bool init();
    static bool close();
};

#endif