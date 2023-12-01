#include "Controller.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <string>


int Controller::GetCookiePoints(const CookieClicker& CC) { return CC.cookiePoints; }

int Controller::AddCookiePoints(CookieClicker& CC)
{
    int CP = GetCookiePoints(CC);
    CP++;
    CC.cookiePoints = CP;
    return CP;
}

bool Controller::Victory(CookieClicker& CC)
{
    int victoryCP = GetCookiePoints(CC);
    
    return (victoryCP >= CC.victoryAmount);
}

void Controller::RunGame(CookieClicker& CC, SDL_Renderer* renderer)
{
    int ten = 10;
    std::string text = std::to_string(ten);
    
    // load font
    TTF_Font* font = TTF_OpenFont("font/lazy.ttf", 10);
    SDL_Color textColor = { 50, 50, 50 };
     
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect destRect = {50, 50, 200, 200};
    SDL_FreeSurface(textSurface);


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
                AddCookiePoints(CC);
                std::cout << GetCookiePoints(CC) << std::endl;
                break;
                
            case SDL_MOUSEBUTTONUP:
                quit = Victory(CC);

                if (quit)
                    std::cout << "You win!" << std::endl;
                break;
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, textTexture, NULL, &destRect);
            SDL_RenderPresent(renderer);
            
        }

        SDL_SetRenderDrawColor(renderer, 61, 255, 224, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(0);
    }
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
