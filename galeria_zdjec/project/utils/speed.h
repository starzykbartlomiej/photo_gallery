#pragma once

class Speed
{
public:
    float get() const;
    void notify(float x);
    Speed();
private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
};
