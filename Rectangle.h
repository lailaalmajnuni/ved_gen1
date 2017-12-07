#pragma once

#include "global.h"
#include "Object.h"

class Rectangle : public Object {
public:
    Rectangle(int w, int h, byte r, byte g, byte b, int x, int y);

    virtual void draw() const;
    virtual void update(double dt);

    void setVelocity(double dx, double dy);
private:
    int w;
    int h;
    int x;
    int y;
    int dx;
    int dy;
    byte r;
    byte g;
    byte b;
};
