#pragma once
#include "IObserver.h"
#include "../Model/KukiClicker.h"

class Observer : public IObserver {
public:
    Observer(KukiClickerModel &cc) : cc(cc)
    {
        this->cc.Attach(this);
        std::cout << "Observer" << ++Observer::static_number_ << " created\n";
        this->number_ = Observer::static_number_;
    }

    void UpdateCounter(const int& counterValue) override
    {
        counter_from_CC_ = counterValue;
        // PrintCounter();
    }
    
    void RemoveMeFromTheList()
    {
        cc.Detach(this);
        // subject_.Detach(this);
        std::cout << "Observer" << number_ << " removed from the list.\n";
    }

    void PrintCounter()
    {
        std::cout << "Observer" << this->number_ << ": number of clicks --> " << this->counter_from_CC_ << "\n";
    }

private:
    static int static_number_;
    int number_;

    KukiClickerModel &cc;
    int counter_from_CC_ = 0;
};
