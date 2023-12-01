#pragma once
#include <SDL_render.h>

#include "../Model/CookieClicker.h"
#include "../View/View.h"

// class CookieClicker;
class Controller
{
public:
    
    CookieClicker cookieClicker;
    // View view;
    
    void SetCookiePoints(int CP);
    int GetCookiePoints(const CookieClicker& CC);
    int AddCookiePoints(CookieClicker& CC);
    bool Victory(CookieClicker& CC);

    void RunGame(CookieClicker& CC, SDL_Renderer* renderer);
    // bool quitGame = false;
    
};
