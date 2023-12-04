#pragma once
#include <SDL_render.h>
#include <string>

class View
{
public:

    View();
    void SetupScreen();
    void UpdateKukiPointsToScreen(int cookiePoint, std::string cookiePointText, SDL_Surface* textSurface, SDL_Texture* textTexture);

    SDL_Renderer* renderer; // the window's rendering surface

    
};
