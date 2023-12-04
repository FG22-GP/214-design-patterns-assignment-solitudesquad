#include "View.h"

#include <iostream>
#include <SDL_video.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


View::View()
{
    
}

void View::SetupScreen()
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    
    //The window we'll be rendering to
    SDL_Window* window{};
    // SDL_Renderer* renderer; // the window's rendering surface
    
    // initialize SDL_Image for image loading
    const int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    }
    // initialize SDL_ttf for font loading
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }
    //Start up SDL and create window
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    // Create Window and Renderer
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
    if (!window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
    SDL_RenderSetLogicalSize(renderer, SCREEN_HEIGHT, SCREEN_WIDTH);


    
}

void View::UpdateKukiPointsToScreen(int cookiePoint, std::string cookiePointText, SDL_Surface* textSurface, SDL_Texture* textTexture)
{
    // cookiePoint = GetCookiePoint(cc);
    // cookiePointText = std::to_string(cookiePoint);
    // textSurface;
    // textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
}
