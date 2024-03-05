#include "Entity\Unit.hpp"

SDL_Texture *Unit::imgs[3] = {0};

Unit::Unit(Type p_type, int p_xPos, int p_yPos)
{
    speed = 1.0;

    setType(p_type);

    srcRect = {0, 0, 18, 18};

    xPos = p_xPos;
    yPos = p_yPos;
    width = 18;
    height = 18;

    destRect = {(int)xPos, (int)yPos, width, height};

    shiftCollider();
}

void Unit::imgsInit()
{
    imgs[ROCK] = IMG_LoadTexture(Global::gRenderer, "./res/unit/rock.png");
    if (imgs[ROCK] == nullptr)
    {
        printf("Failed to load Rock Texture!\nError: %s\n", IMG_GetError());
    }

    imgs[PAPER] = IMG_LoadTexture(Global::gRenderer, "./res/unit/paper.png");
    if (imgs[PAPER] == nullptr)
    {
        printf("Failed to load Paper Texture!\nError: %s\n", IMG_GetError());
    }

    imgs[SCISSORS] = IMG_LoadTexture(Global::gRenderer, "./res/unit/scissors.png");
    if (imgs[SCISSORS] == nullptr)
    {
        printf("Failed to load Scissors Texture!\nError: %s\n", IMG_GetError());
    }
}

void Unit::update()
{
    move();
    shiftCollider();
    Entity::update();
}

void Unit::render()
{
    SDL_RenderCopy(Global::gRenderer, imgs[type], &srcRect, &destRect);
}

void Unit::setType(Type p_type)
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
}

void Unit::shiftCollider()
{
    cirCollider.x = xPos + (double)width / 2;
    cirCollider.y = yPos - (double)height / 2;
    cirCollider.radius = (double)(width + height) / 4;
}

void Unit::move()
{
    double tmpX;
    double tmpY;

    tmpX = speed * dir.first;
    tmpY = speed * dir.second;

    tmpX += xPos;
    tmpY += yPos;

    if (tmpX < 0 || (tmpX + width) > Global::gSCREEN_WIDTH)
    {
        dir.first = -dir.first;
    }
    else
    {
        xPos = tmpX;
    }

    if (tmpY < 0 || (tmpY + width) > Global::gSCREEN_HEIGHT)
    {
        dir.second = -dir.second;
    }
    else
    {
        yPos = tmpY;
    }
}