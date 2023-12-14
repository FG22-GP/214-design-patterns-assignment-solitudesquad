#pragma once

#include <SDL_events.h>
#include <SDL_ttf.h>

#include "../Model/KukiClicker.h"
// #include "../View/View.h"

// class CookieClicker;
class Controller
{
public:
    SDL_Texture* TextTexture;
    SDL_Event event;

    void HandlesEvent(SDL_Event Event) { event = Event; }
    // void SetCookiePoints(int CP);
    int GetKukiPoint(const KukiClickerModel& CC);
    int AddKukiPoint(KukiClickerModel& CC);
    bool Victory(const KukiClickerModel& CC);
    
    void ClickEvent(SDL_Event& e, bool& quit, KukiClickerModel& cc, KukiClickerModel* ccSubject, SDL_Renderer* renderer, SDL_Texture*
                    kukiSurprise);

    void SetTextTexture(SDL_Texture* textTexture);
    SDL_Texture* GetTextTexture() const;

    
    
    

    // void RunGame(CookieClicker& CC, SDL_Renderer* renderer);
    // void RunGame(KukiClicker& cc, View& view);
    
};
