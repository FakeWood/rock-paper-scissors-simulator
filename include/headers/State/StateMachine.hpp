#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

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