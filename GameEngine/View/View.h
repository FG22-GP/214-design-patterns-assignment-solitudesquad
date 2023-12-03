#pragma once
#include <SDL_render.h>

class View
{
public:

    View();
    void SetupScreen();

    SDL_Renderer* renderer; // the window's rendering surface

    
};
