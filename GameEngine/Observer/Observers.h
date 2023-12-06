#pragma once
#include <iostream>
#include <ostream>

class Observers
{
public:

    void Update(int numEvents)
    {
        if (numEvents > 5)
        {
            std::cout << "You deserve 5 Cookies" << std::endl;
        }
        //Updates something...
    }


    void AmountOfHeadPats(int headPats)
    {
        std::cout << "amount of head pats: " << headPats << std::endl;
    }
};
