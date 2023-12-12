#pragma once
#include <SDL_render.h>
#include "../Controller/Controller.h"
#include "../Observer/Observer.h"



class View
{
public:

    View();
    void SetupScreen();
    // void UpdateKukiPointsToScreen(int cookiePoint, std::string cookiePointText, SDL_Surface* textSurface, SDL_Texture* textTexture);


    void RunGame(KukiClicker& cc, Controller& controller);
    
    SDL_Renderer* renderer; // the window's rendering surface
    // bool SetQuit(bool Quit){ return quit = Quit; }
    
    // bool quit;
    
};
