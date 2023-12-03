#include "Controller.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <string>


int Controller::GetCookiePoint(const CookieClicker& CC) { return CC.cookiePoints; }

int Controller::AddCookiePoint(CookieClicker& CC)
{
    int CP = GetCookiePoint(CC);
    CP++;
    CC.cookiePoints = CP;
    return CP;
}

bool Controller::Victory(const CookieClicker& CC)
{
    const int victoryCP = GetCookiePoint(CC);
    
    return (victoryCP >= CC.victoryAmount);
}

void Controller::RunGame(CookieClicker& cc, View& view)
{

    view.SetupScreen();
    
    // //Screen dimension constants
    // const int SCREEN_WIDTH = 1024;
    // const int SCREEN_HEIGHT = 768;
    //
    // //The window we'll be rendering to
    // SDL_Window* window{};
    // SDL_Renderer* renderer; // the window's rendering surface
    //
    // // initialize SDL_Image for image loading
    // const int imgFlags = IMG_INIT_PNG;
    // if (!(IMG_Init(imgFlags) & imgFlags))
    // {
    // 	printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    // }
    // // initialize SDL_ttf for font loading
    // if (TTF_Init() == -1)
    // {
    // 	printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    // }
    // //Start up SDL and create window
    // //Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO))
    // {
    // 	printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    // 	return;
    // }
    // // Create Window and Renderer
    // SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
    // if (!window)
    // {
    // 	printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    // 	return;
    // }
    //
    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
    // SDL_RenderSetLogicalSize(renderer, 1024, 768);

    const auto renderer = view.renderer;
    
    
    // load font
    // TTF_Font* font = TTF_OpenFont("font/lazy.ttf", 10);
    TTF_Font* font = TTF_OpenFont(cc.fontFile, cc.fontSize);
    const SDL_Color textColor = cc.textColor;
    
    SDL_Surface* textSurface = NULL;
    SDL_Texture* textTexture = NULL;
    const SDL_Rect destRect = {400, 250, 200, 200};
    SDL_FreeSurface(textSurface);

    

    int cookiePoint = NULL;
    std::string cookiePointNumber = std::to_string(cookiePoint);
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
                AddCookiePoint(cc);

                cookiePoint = GetCookiePoint(cc);
                cookiePointNumber = std::to_string(cookiePoint);
                textSurface = TTF_RenderText_Solid(font, cookiePointNumber.c_str(), textColor);
                textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);


                
                std::cout << "Cookie point: " << cookiePoint << std::endl;
                break;
                
            case SDL_MOUSEBUTTONUP:
                quit = Victory(cc);

                if (quit)
                    std::cout << "You win!" << std::endl;
                break;
            }

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, textTexture, NULL, &destRect);
            SDL_RenderPresent(renderer);
            
        }
        textSurface = TTF_RenderText_Solid(font, cookiePointNumber.c_str(), textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);


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
