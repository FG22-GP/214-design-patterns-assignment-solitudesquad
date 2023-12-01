#include "Controller.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_timer.h>


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
        }

        SDL_SetRenderDrawColor(renderer, 61, 255, 224, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(0);
    }
}
