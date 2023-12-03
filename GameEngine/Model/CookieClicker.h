#pragma once
#include <SDL_pixels.h>
#include <SDL_ttf.h>

#include "Model.h"

class CookieClicker : Model
{
public:
    const int victoryAmount;
    int cookiePoints;
    bool quitGame;
    const SDL_Color textColor;
    const char* fontFile;
    const int fontSize;
    

    CookieClicker();
    
};
