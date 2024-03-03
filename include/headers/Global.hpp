#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Global
{
    static const int FPS;
    static const int timeStep;
    static int frameCounter;

    static int gSCREEN_WIDTH;
    static int gSCREEN_HEIGHT;

    static SDL_Window *gWindow;
    static SDL_Renderer *gRenderer;
    static const Uint8 *gCurrentKeyState;
};

#endif