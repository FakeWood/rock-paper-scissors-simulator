#include "Global.hpp"

const int Global::FPS = 60;
const int Global::timeStep = 1000 / FPS;
int Global::frameCounter = 0;

int Global::gSCREEN_WIDTH = 800;
int Global::gSCREEN_HEIGHT = 640;

SDL_Window *Global::gWindow = nullptr;
SDL_Renderer *Global::gRenderer = nullptr;
const Uint8 *Global::gCurrentKeyState = SDL_GetKeyboardState(NULL);