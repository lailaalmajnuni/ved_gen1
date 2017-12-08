#pragma once

#include "Object.h"

class Clock : public Object{
public:
    Clock(int x, int y);
     
    virtual void draw() const;
    virtual void update(double dt);

private:
    double elapsedSeconds;
    int x;
    int y;
};