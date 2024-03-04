#include "State\PlayState.hpp"
#include "State\StateMachine.hpp"
#include "State\ExitState.hpp"

PlayState PlayState::sPlayState;

PlayState::PlayState()
{
}

PlayState *PlayState::get()
{
    return &sPlayState;
}

bool PlayState::enter()
{
    return true;
}

bool PlayState::exit()
{
    // for ( Entity* E : entities )
    // {
    //     E->free();
    // }

    return true;
}

void PlayState::handleEvent(SDL_Event &p_e)
{

    if (false)
    {
        StateMachine::setNextState(ExitState::get());
    }
}

void PlayState::update()
{
}

void PlayState::render()
{
    // background->render();
}

std::pair<double, double> PlayState::randBorn(int centerX, int centerY, int p_diameter)
{
    double X, Y;
    double length;
    double degree;

    srand(time(NULL));
    length = rand() % (p_diameter / 2);
    degree = rand() % 360;
    sincos(degree * M_PI / 180, &Y, &X);
    X *= length;
    Y *= length;
    return std::pair<double, double>(X, Y);
}