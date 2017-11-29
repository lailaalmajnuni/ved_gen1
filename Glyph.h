#pragma once

#include <string>

using namespace std;

typedef unsigned char byte;

class Glyph {
private:
    Glyph(char c);
    int fx;
    int fy;
	int fw;  
    int fh;
    int xOffset;
    int yOffset;
    int xAdvance;

    friend class Font;
};
