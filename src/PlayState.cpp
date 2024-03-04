#include "State\PlayState.hpp"
#include "State\StateMachine.hpp"

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
    if (!scorePanel->getActive())
    {
        player->update();

        // tHeight->setText( ( "Height:  " + std::to_string( (int)(Global::gGROUND_LEVEL - player->getY()) / 100 ) ).c_str() );
        // tHeight->update();
    }

    if (player->checkLanded())
        scorePanel->open(player->getSafe());

    scorePanel->update();
}

void PlayState::render()
{
    background->render();
    player->render();
    // tHeight->render();
    scorePanel->render();
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