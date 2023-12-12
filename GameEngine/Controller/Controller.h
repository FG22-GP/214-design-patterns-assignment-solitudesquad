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
    
    // void SetCookiePoints(int CP);
    int GetKukiPoint(const KukiClicker& CC);
    int AddKukiPoint(KukiClicker& CC);
    bool Victory(const KukiClicker& CC);
    
    void ClickEvent(SDL_Event& e, bool& quit, KukiClicker& cc, KukiClicker* ccSubject,
                    int& kukiPoint, std::string& kukiPointText, TTF_Font* font,
                    const SDL_Color textColor, SDL_Surface* textSurface,
                    SDL_Texture* textTexture);

    void SetTextTexture(SDL_Texture* textTexture);
    SDL_Texture* GetTextTexture() const;
    
    
    

    // void RunGame(CookieClicker& CC, SDL_Renderer* renderer);
    // void RunGame(KukiClicker& cc, View& view);
    
};
