#pragma once
#include "global.h"

class Rectangle {
public:
    Rectangle(int w, int h, byte r, byte g, byte b, int x, int y);
    void draw(double dt);
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