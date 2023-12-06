#pragma once

#include "..\Model\KukiClicker.h"
#include "../View/View.h"

// class CookieClicker;
class Controller
{
public:
    
    
    // void SetCookiePoints(int CP);
    int GetKukiPoint(const KukiClicker& CC);
    int AddKukiPoint(KukiClicker& CC);
    bool Victory(const KukiClicker& CC);

    // void RunGame(CookieClicker& CC, SDL_Renderer* renderer);
    void RunGame(KukiClicker& cc, View& view);
    
};
