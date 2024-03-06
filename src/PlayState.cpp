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
    for (int i = 0; i < 7; i++)
    {
        std::pair<double, double> pos = randBorn(Global::gSCREEN_WIDTH / 2, Global::gSCREEN_HEIGHT / 2, 600);
        units.emplace_back(new Unit(ROCK, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 7; i++)
    {
        std::pair<double, double> pos = randBorn(Global::gSCREEN_WIDTH / 2, Global::gSCREEN_HEIGHT / 2, 600);
        units.emplace_back(new Unit(PAPER, (int)pos.first, (int)pos.second));
    }

    for (int i = 0; i < 7; i++)
    {
        std::pair<double, double> pos = randBorn(Global::gSCREEN_WIDTH / 2, Global::gSCREEN_HEIGHT / 2, 600);
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
        double loseDist = Global::gSCREEN_WIDTH;
        double sameDist = Global::gSCREEN_WIDTH;

        double tempDist = 0.0;

        Unit *winUnitNear = nullptr;
        Unit *loseUnitNear = nullptr;
        Unit *sameUnitNear = nullptr;

        // Find the nearest
        for (Unit *u : units)
        {

            tempDist = hypot(u->getX() - cur->getX(), u->getY() - cur->getY()); // caculate the distance

            if (cur->getType() == u->getType() && cur != u && tempDist < sameDist)
            {
                sameDist = tempDist;
                sameUnitNear = u;
            }
            else if (cur->getWinType() == u->getType() && tempDist < winDist)
            {
                winDist = tempDist;
                winUnitNear = u;
            }
            else if (cur->getLoseType() == u->getType() && tempDist < loseDist)
            {
                loseDist = tempDist;
                loseUnitNear = u;
            }
        }

        double x, chaseX, runX, awayX;
        double y, chaseY, runY, awayY;

        if (winUnitNear != nullptr)
        {
            if (winDist < cur->getColli().radius * 2)
            {
                winUnitNear->setType(cur->getType());
                continue;
            }

            chaseX = (winUnitNear->getX() - cur->getX()) / winDist;
            chaseY = (winUnitNear->getY() - cur->getY()) / winDist;
        }
        else
        {
            chaseX = chaseY = winDist = 0;
        }

        if (loseUnitNear != nullptr)
        {
            runX = (cur->getX() - loseUnitNear->getX()) / loseDist;
            runY = (cur->getY() - loseUnitNear->getY()) / loseDist;
        }
        else
        {
            runX = runY = loseDist = 0;
        }

        // not too close
        if (sameDist < cur->getColli().radius * 2)
        {
            awayX = (cur->getX() - sameUnitNear->getX()) * Global::gSCREEN_WIDTH;
            awayY = (cur->getY() - sameUnitNear->getY()) * Global::gSCREEN_WIDTH;
        }
        else
        {
            awayX = awayY = 0;
        }

        // closer -> faster
        if (winDist != 0)
        {
            runX *= winDist;
            runY *= winDist;
        }

        if (loseDist != 0)
        {
            chaseX *= loseDist;
            chaseY *= loseDist;
        }

        // turn into unit direction
        x = chaseX + runX + awayX;
        y = chaseY + runY + awayY;

        double dist = hypot(x, y);

        if (dist != 0)
        {
            x /= dist;
            y /= dist;
        }

        cur->setDir(std::pair<double, double>(x, y));
    }
}
