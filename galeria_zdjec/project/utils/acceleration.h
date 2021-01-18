#pragma once


class Acceleration
{
public:
    float get() const;
    void notify(float x);
    Acceleration();
private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
};
