#pragma once

#include "Object.h"

typedef unsigned char byte;

class Image : public Object{
public:
 	Image() : pixels(0), w(0), h(0), x(0), y(0) { }
    ~Image() { delete [] pixels; }

    virtual void draw() const;
    virtual void update(double dt);

    void load( const char * filename, int w, int h );
    void setVelocity(double dx, double dy);

private:
    byte * pixels;
    int x;
    int y;
    int w;
    int h;
    int dx;
    int dy;
    double dt;
};
