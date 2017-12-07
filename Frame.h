#pragma once

#include <stdio.h>

#include "global.h"

class Frame {
public:
	Frame(int w, int h);
	~Frame();
	void setPixel(int x, int y, byte r, byte g, byte blue);
	void clear();
	bool isOutside(int x, int y) const;
	void write(FILE * file) const;
	
private:
    int w;
    int h;
    unsigned char * pixels;
};
