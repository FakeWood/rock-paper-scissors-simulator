#include "State\PlayState.hpp"
#include "State\StateMachine.hpp"
#include "State\ExitState.hpp"
#include "Entity\Unit.hpp"

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
    srand(time(NULL));
    Unit::imgsInit();
    for (int i = 0; i < 10; i++)
    {
        std::pair<double, double> pos = randBorn(200, 400, 200);
        entities.emplace_back(new Unit(ROCK, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 10; i++)
    {
        std::pair<double, double> pos = randBorn(400, 150, 200);
        entities.emplace_back(new Unit(PAPER, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 10; i++)
    {
        std::pair<double, double> pos = randBorn(600, 450, 200);
        entities.emplace_back(new Unit(SCISSORS, (int)pos.first, (int)pos.second));
    }
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
    for (Entity *e : entities)
    {
        e->render();
    }
    // background->render();
}

std::pair<double, double> PlayState::randBorn(int centerX, int centerY, int p_diameter)
{
    double X, Y;
    double length;
    double degree;

    length = rand() % (p_diameter / 2);
    degree = rand() % 360;
    sincos(degree * M_PI / 180, &Y, &X);
    X = X * length + centerX;
    Y = Y * length + centerY;
    return std::pair<double, double>(X, Y);
}