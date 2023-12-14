#pragma once
#include <SDL_render.h>
#include "../Controller/Controller.h"
#include "../Observer/Observer.h"



class CookieModel
{
private:
    int cookie;
public:
    void addObserver(Observer* observer);
    void setCookies(int newValue); // notifies observers
};

class CookieController
{
    CookieController(CookieModel* model); // so we can set cookies on click
    void handleInput(SDL_Event& e); // on click -> mode.setCookies(mode.getCookies+1);
};

class CookieView
{
    CookieView(CookieModel* model); // add observer so we get notified, create initial count texture
    SDL_Texture* cookieCountText;
    void onCookiesChanged(int newCookies); // uodate cookieCountText when cookies changed
    void render(); // called by main game loop
};


class View
{
public:

    View();
    void SetupScreen();
    void RenderOnScreen(SDL_Renderer* renderer, SDL_Texture* textTexture, SDL_Texture* kukiSurprise);
    SDL_Texture* OnSwapImage(KukiClickerModel* ccSubject, SDL_Texture* kukiPissedOff, SDL_Texture* kukiSurprise);
    void RunGame(KukiClickerModel& cc, Controller& controller);
    SDL_Texture* OnCounterChanged(Controller& controller,
                                  KukiClickerModel& cc, int kukiPoint, std::string kukiPointText, TTF_Font* font, const SDL_Color textColor, SDL_Surface*
                                  textSurface, SDL_Texture* textTexture);
    
    SDL_Renderer* renderer; // the window's rendering surface
    // bool SetQuit(bool Quit){ return quit = Quit; }

    // bool quit;
    
};
