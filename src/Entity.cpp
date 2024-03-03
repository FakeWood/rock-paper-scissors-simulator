#include "Entity\Entity.hpp"

Entity::Entity()
{
    xPos = 0;
    yPos = 0;
    objTexture = nullptr;
}

Entity::Entity(const char *p_textureDir, int p_srcWidth, int p_srcHeight, int p_xPos, int p_yPos, int p_destWidth, int p_destHeight)
{
    objTexture = IMG_LoadTexture(Global::gRenderer, p_textureDir);
    if (objTexture == nullptr)
    {
        printf("Failed to load objTexture!\nError: %s\n", IMG_GetError());
    }

    srcRect = {0, 0, p_srcWidth, p_srcHeight};

    xPos = p_xPos;
    yPos = p_yPos;
    width = p_destWidth;
    height = p_destHeight;

    destRect = {(int)xPos, (int)yPos, width, height};
}

Entity::~Entity()
{
}

void Entity::handleEvent(SDL_Event &p_event)
{
}

void Entity::update()
{
    destRect = {(int)xPos, (int)yPos, width, height};
}

void Entity::render()
{
    SDL_RenderCopy(Global::gRenderer, objTexture, &srcRect, &destRect);
}

void Entity::free()
{
    if (objTexture != nullptr)
    {
        SDL_DestroyTexture(objTexture);
        objTexture = nullptr;
    }
}

void Entity::setColorMod(Uint8 p_r, Uint8 p_g, Uint8 p_b)
{
    SDL_SetTextureColorMod(objTexture, p_r, p_g, p_b);
}
