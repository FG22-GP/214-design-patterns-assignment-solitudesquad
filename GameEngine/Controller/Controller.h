#pragma once

#include "../Model/CookieClicker.h"
#include "../View/View.h"

// class CookieClicker;
class Controller
{
public:
    
    
    // void SetCookiePoints(int CP);
    int GetKukiPoint(const CookieClicker& CC);
    int AddKukiPoint(CookieClicker& CC);
    bool Victory(const CookieClicker& CC);

    // void RunGame(CookieClicker& CC, SDL_Renderer* renderer);
    void RunGame(CookieClicker& cc, View& view);
    
};
