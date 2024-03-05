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
        units.emplace_back(new Unit(ROCK, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 10; i++)
    {
        std::pair<double, double> pos = randBorn(400, 150, 200);
        units.emplace_back(new Unit(PAPER, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 10; i++)
    {
        std::pair<double, double> pos = randBorn(600, 450, 200);
        units.emplace_back(new Unit(SCISSORS, (int)pos.first, (int)pos.second));
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
    updateUnits();
    for (Unit *u : units)
    {
        u->update();
    }
}

void PlayState::render()
{
    for (Unit *u : units)
    {
        u->render();
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

void PlayState::updateUnits()
{
    for (Unit *cur : units)
    {
        double winDist = Global::gSCREEN_WIDTH;
        double tempDist = 0.0;

        Unit *winUnitNear = nullptr;

        // Find the nearest
        for (Unit *u : units)
        {
            if (cur->getType() == u->getType())
            {
                continue;
            }

            tempDist = hypot(u->getX() - cur->getX(), u->getY() - cur->getY()); // caculate the distance

            if (cur->getWinType() == u->getType() && tempDist < winDist)
            {
                winDist = tempDist;
                winUnitNear = u;
            }
        }

        if (winUnitNear == nullptr)
        {
            continue;
        }

        double x;
        double y;

        if (winDist < cur->getColli().radius * 2)
        {
            winUnitNear->setType(cur->getType());
        }
        else
        {
            x = (winUnitNear->getX() - cur->getX()) / winDist;
            y = (winUnitNear->getY() - cur->getY()) / winDist;
            cur->setDir(std::pair<double, double>(x, y));
        }
    }
}
