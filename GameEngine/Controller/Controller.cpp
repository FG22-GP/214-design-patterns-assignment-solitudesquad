#include "Controller.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <string>


int Controller::GetKukiPoint(const CookieClicker& CC) { return CC.kukiPoints; }

int Controller::AddKukiPoint(CookieClicker& CC)
{
    int CP = GetKukiPoint(CC);
    CP++;
    CC.kukiPoints = CP;
    return CP;
}

bool Controller::Victory(const CookieClicker& CC)
{
    const int victoryCP = GetKukiPoint(CC);
    
    return (victoryCP >= CC.victoryAmount);
}

void Controller::RunGame(CookieClicker& cc, View& view)
{

    view.SetupScreen();
    
    const auto renderer = view.renderer;
    
    // load font
    TTF_Font* font = TTF_OpenFont(cc.fontFile, cc.fontSize);
    const SDL_Color textColor = cc.textColor;
    
    SDL_Texture* textTexture = NULL;
    SDL_Surface* textSurface = NULL;

    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    const char* kukiSurpriseImagePath = cc.kukiSurprise;
    // Load Pickachu image at specified path
    SDL_Surface* loadedKukiSurpriseSurface = IMG_Load(kukiSurpriseImagePath);
    SDL_Texture* kukiSurprise = SDL_CreateTextureFromSurface(renderer, loadedKukiSurpriseSurface);
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedKukiSurpriseSurface);

    int cookiePoint = 0;
    std::string cookiePointText = std::to_string(cookiePoint);
    
    SDL_Event e;
    bool quit = false;
    
    while (quit == false)
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

                cookiePoint = GetKukiPoint(cc);
                cookiePointText = std::to_string(cookiePoint);
                textSurface = TTF_RenderText_Solid(font, cookiePointText.c_str(), textColor);
                textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

                // view.UpdateCookiePointsToScreen(cookiePoint, cookiePointText, textSurface, textTexture); //TODO something with this
                
                std::cout << "Kuki point: " << cookiePoint << std::endl;
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
        
        SDL_Rect targetRectangle = {0, 0, 200, 200};
        SDL_RenderCopy(renderer, textTexture, NULL, &targetRectangle);
        
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
}
