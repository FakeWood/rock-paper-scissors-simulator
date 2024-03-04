#include "Entity\Unit.hpp"

Unit::Unit(Type p_type, int p_xPos, int p_yPos)
{
    type = p_type;

    switch (p_type)
    {
    case ROCK:
        winType = SCISSORS;
        loseType = PAPER;
        break;
    case PAPER:
        winType = ROCK;
        loseType = SCISSORS;
        break;
    case SCISSORS:
        winType = PAPER;
        loseType = ROCK;
        break;
    }

    srcRect = {0, 0, 18, 18};
    xPos = p_xPos;
    yPos = p_yPos;
    width = 36;
    height = 36;

    destRect = {(int)xPos, (int)yPos, width, height};

    if (imgs[ROCK] == nullptr)
    {
        imgs[ROCK] = IMG_LoadTexture(Global::gRenderer, "./res/unit/rock.png");
        if (imgs[ROCK] == nullptr)
        {
            printf("Failed to load Rock Texture!\nError: %s\n", IMG_GetError());
        }
    }

    if (imgs[PAPER] == nullptr)
    {
        imgs[PAPER] = IMG_LoadTexture(Global::gRenderer, "./res/unit/paper.png");
        if (imgs[PAPER] == nullptr)
        {
            printf("Failed to load Paper Texture!\nError: %s\n", IMG_GetError());
        }
    }

    if (imgs[SCISSORS] == nullptr)
    {
        imgs[SCISSORS] = IMG_LoadTexture(Global::gRenderer, "./res/unit/scissors.png");
        if (imgs[SCISSORS] == nullptr)
        {
            printf("Failed to load Scissors Texture!\nError: %s\n", IMG_GetError());
        }
    }
}

void Unit::update()
{
    Entity::update();
}

void Unit::render()
{
    SDL_RenderCopy(Global::gRenderer, imgs[type], &srcRect, &destRect);
}