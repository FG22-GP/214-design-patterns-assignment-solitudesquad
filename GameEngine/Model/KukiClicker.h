#pragma once
#include <list>
#include <SDL_pixels.h>
#include "Model.h"
#include "../Observer/Subject.h"

// controller ->  model
// click      ->  model.cookies++

// view       ->  model
// cotr()     ->  addObserver(this)


// ctr.click() -> model.cookies++ -> notifyobserver -> update label


class KukiClicker : ISubject, Model
{
public:
    KukiClicker() :
    kukiPoints(0),
    victoryAmount(6),
    quitGame(false),
    textColor(50, 50, 50),
    fontFile("font/lazy.ttf"),
    fontSize(10),
    kukiSurprise("img/Kuki_Surprise_Emote.png"),
    kukiPissedOff("img/kukishinobu-pissed.png"),
    cookieImage("cookie-clicker_Icon.png")
    {}


    int kukiPoints;
    const int victoryAmount;
    bool quitGame;
    const SDL_Color textColor;
    const char* fontFile;
    const int fontSize;
    const char* kukiSurprise;
    const char* kukiPissedOff;
    const char* cookieImage;


    void Attach(IObserver* observer) override
    {
        list_observer_.push_back(observer);
    }

    void Detach(IObserver* observer) override
    {
        list_observer_.remove(observer);
    }

    void IncrementCounter()
    {
        ++counter_;
        std::cout << "Counter incremented. New Value: " << counter_ << "\n";
        NotifyCounter();
    }

    void NotifyCounter() override
    {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        // HowManyObserver();
        while (iterator != list_observer_.end())
        {
            (*iterator)->UpdateCounter(counter_);
            ++iterator;
        }
    }

    void HowManyObserver()
    {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

private:
    std::list<IObserver*> list_observer_;
    int counter_ = 0;
};
