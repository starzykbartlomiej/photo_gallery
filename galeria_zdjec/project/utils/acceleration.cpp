#include "acceleration.h"

Acceleration::Acceleration() : hasFirstValue(false), hasSecondValue(false),hasThirdValue(false),
                                         firstValue(0), secondValue(0),thirdValue(0) {}

float Acceleration::get() const
{
    if(hasFirstValue && hasSecondValue && hasThirdValue )
           return thirdValue - 2*secondValue + firstValue;
       else
           return 0;
}

void Acceleration::notify(float x)
{
    if(!hasFirstValue && !hasSecondValue && !hasThirdValue)
    {
        hasFirstValue = true;
        firstValue = x;
    }
    else if(hasFirstValue && !hasSecondValue && !hasThirdValue)
    {
        hasSecondValue = true;
        secondValue = x;
    }
    else if(hasFirstValue && hasSecondValue && !hasThirdValue)
    {
        hasThirdValue = true;
        thirdValue = x;
    }
    else if(hasFirstValue && hasSecondValue && hasThirdValue)
    {
        firstValue = secondValue;
        secondValue = thirdValue;
        thirdValue = x;
    }
}


