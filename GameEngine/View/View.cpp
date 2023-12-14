#include "View.h"

#include <iostream>
#include <SDL_video.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


View::View()
{
    // quit = false;
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

void View::RenderOnScreen(SDL_Renderer* renderer, SDL_Texture* textTexture, SDL_Texture* kukiSurprise)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 61, 255, 224, 255);

    // cookieView.render()
    SDL_Rect textRectangle = {0, 0, 200, 200};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRectangle);
        

    SDL_Rect imageRectangle{300,350,200,200};
    SDL_RenderCopy(renderer, kukiSurprise, NULL, &imageRectangle);
        
        
    SDL_RenderPresent(renderer);

    //TODO Play around with the frames (FPS)?
    SDL_Delay(0);
}

SDL_Texture* View::OnSwapImage(KukiClickerModel* ccSubject, SDL_Texture* kukiPissedOff, SDL_Texture* kukiSurprise)
{
    if (ccSubject->GetCounter() >= 3)
    {
        return kukiPissedOff;
    }
    else
    {
        return kukiSurprise;
    }
}

void View::RunGame(KukiClickerModel& cc, Controller& controller)
{
    SetupScreen();

    //My observer to check how many clicks
    KukiClickerModel *ccSubject = new KukiClickerModel;
    Observer *observer = new Observer(*ccSubject);

    
    // load font
    TTF_Font* font = TTF_OpenFont(cc.fontFile, cc.fontSize);
    const SDL_Color textColor = cc.textColor;
    
    SDL_Surface* textSurface = nullptr;
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    // Load Pikachu image at specified path
    const char* kukiPissedOffImagePath{ cc.kukiPissedOff };
    SDL_Surface* loadedKukiPissedOffSurface = IMG_Load(kukiPissedOffImagePath);
    SDL_Texture* kukiPissedOff = SDL_CreateTextureFromSurface(renderer, loadedKukiPissedOffSurface);
    SDL_FreeSurface(loadedKukiPissedOffSurface);

    const char* kukiSurpriseImagePath = cc.kukiSurprise;
    SDL_Surface* loadedKukiSurpriseSurface = IMG_Load(kukiSurpriseImagePath);
    SDL_Texture* kukiSurprise = SDL_CreateTextureFromSurface(renderer, loadedKukiSurpriseSurface);
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedKukiSurpriseSurface);

    int kukiPoint = 0;
    std::string kukiPointText = std::to_string(kukiPoint);

    
    // model
    // view(model)
    // controller(model)
    
    SDL_Event e;
    // controller.HandlesEvent(e);
    
    bool quit = false;
    while (!quit)
    {
        SDL_GetTicks();
        while (SDL_PollEvent(&e))
        {
            controller.ClickEvent(e, quit, cc, ccSubject, renderer, kukiSurprise);
            
            // cookieController.handleInput //TODO Marc wrote this comment
            
            textTexture = OnCounterChanged(controller, cc, kukiPoint,
                kukiPointText, font, textColor, textSurface, textTexture);

            kukiSurprise = OnSwapImage(ccSubject, kukiPissedOff, kukiSurprise);

        }
        
        // textTexture = controller.GetTextTexture(); //TODO why is this crashing the while loop?
        RenderOnScreen(renderer, textTexture, kukiSurprise);

        // //TODO Play around with the frames (FPS)?
        // SDL_Delay(0);
    }
    SDL_Delay(1000);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    observer->RemoveMeFromTheList();
    
    delete observer;
    delete ccSubject;



}

SDL_Texture* View::OnCounterChanged(Controller& controller, KukiClickerModel& cc 
    ,int kukiPoint, std::string kukiPointText, TTF_Font* font, const SDL_Color textColor
    ,SDL_Surface* textSurface, SDL_Texture* textTexture)
{
    kukiPoint = controller.GetKukiPoint(cc);
    kukiPointText = std::to_string(kukiPoint);
    textSurface = TTF_RenderText_Solid(font, kukiPointText.c_str(), textColor);
    return textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); 
}


