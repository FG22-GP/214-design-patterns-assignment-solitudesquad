#include "Controller.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <string>

#include "../Observer/NewDirectory1/Observer.h"


int Controller::GetKukiPoint(const KukiClicker& CC) { return CC.kukiPoints; }

int Controller::AddKukiPoint(KukiClicker& CC)
{
    int CP = GetKukiPoint(CC);
    CP++;
    CC.kukiPoints = CP;
    return CP;
}

bool Controller::Victory(const KukiClicker& CC)
{
    const int victoryCP = GetKukiPoint(CC);
    return (victoryCP >= CC.victoryAmount);
}

void Controller::RunGame(KukiClicker& cc, View& view)
{

    view.SetupScreen();

    //My observer to check how many clicks
    KukiClicker *ccSubject = new KukiClicker;
    Observer *observer = new Observer(*ccSubject);

    const auto renderer = view.renderer;
    
    // load font
    TTF_Font* font = TTF_OpenFont(cc.fontFile, cc.fontSize);
    const SDL_Color textColor = cc.textColor;
    
    SDL_Surface* textSurface = nullptr;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    const char* pikachuImagePath{ "img/pikachu.png" };
    // Load Pickachu image at specified path
    const char* kukiSurpriseImagePath = cc.kukiSurprise;
    SDL_Surface* loadedKukiSurpriseSurface = IMG_Load(kukiSurpriseImagePath);
    SDL_Texture* kukiSurprise = SDL_CreateTextureFromSurface(renderer, loadedKukiSurpriseSurface);
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedKukiSurpriseSurface);

    int kukiPoint = 0;
    std::string kukiPointText = std::to_string(kukiPoint);
    
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        SDL_GetTicks();

        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT: { quit = true; }
                break;

            case SDL_MOUSEBUTTONDOWN:
                AddKukiPoint(cc);

                ccSubject->IncrementCounter();
                kukiPoint = GetKukiPoint(cc);
                kukiPointText = std::to_string(kukiPoint);
                textSurface = TTF_RenderText_Solid(font, kukiPointText.c_str(), textColor);
                textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                
                // std::cout << "Kuki point: " << kukiPoint << std::endl;
                break;
                
            case SDL_MOUSEBUTTONUP:
                quit = Victory(cc);

                if (quit)
                    std::cout << "You win!" << std::endl;
                break;
            // case SDL_MOUSEMOTION:
            //     std::cout << "Mouse moved" << std::endl;
            //     break;
                
            }
        }
        
        SDL_RenderClear(renderer);
        
        SDL_Rect textRectangle = {0, 0, 200, 200};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRectangle);
        
        SDL_SetRenderDrawColor(renderer, 61, 255, 224, 255);
        SDL_Rect imageRectangle{300,350,200,200};
        SDL_RenderCopy(renderer, kukiSurprise, NULL, &imageRectangle);
        
        
        SDL_RenderPresent(renderer);

        SDL_Delay(0);
    }
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    observer->RemoveMeFromTheList();
    
    delete observer;
    delete ccSubject;

    SDL_Delay(5);
}
