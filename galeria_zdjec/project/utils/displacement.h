#pragma once


class Displacement
{
public:
    Displacement() = default;
    ~Displacement() = default;
    void set(float x);
    float getX();
private:
    float value;
};
