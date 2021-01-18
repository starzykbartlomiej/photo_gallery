#include "speed.h"

Speed::Speed() : hasFirstValue(false), hasSecondValue(false), firstValue(0), secondValue(0) {}

float Speed::get() const
{
    if(hasFirstValue && hasSecondValue)
           return secondValue-firstValue;
       else
           return 0;
}

void Speed::notify(float x)
{
    if(!hasFirstValue && !hasSecondValue)
    {
        hasFirstValue = true;
        firstValue = x;
    }
    else if(hasFirstValue && !hasSecondValue)
    {
        hasSecondValue = true;
        secondValue = x;
    }
    else if(hasFirstValue && hasSecondValue)
    {
        firstValue = secondValue;
        secondValue = x;
    }
}


