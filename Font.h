#pragma once
#include "Glyph.h"
#include <string>

using namespace std;

typedef unsigned char byte;

class Font {
public:
	Font();
	~Font() { delete [] pixels; }
	void draw(const string & text, double x, double y) const;

private:
	byte * pixels;
	int w;  
    int h;  
    
    friend class Glyph;
};
