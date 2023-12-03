#pragma once
#include <SDL_pixels.h>
#include <SDL_ttf.h>

#include "Model.h"

class CookieClicker : Model
{
public:
    int cookiePoints;
    const int victoryAmount;
    bool quitGame;
    const SDL_Color textColor;
    const char* fontFile;
    const int fontSize;
    const char* kukiSurprise;
    const char* kukiPissedOff;

    CookieClicker();
    
};
