#include "Frame.h"
#include "Glyph.h"

using namespace std;

extern Frame frame;

Glyph::Glyph(char c){
    if (c == '0'){
        fx = 344;
        fy = 98;
        fw = 30;
        fh = 42;
        xOffset  = 4;
        yOffset  = 8;
        xAdvance = 28;
    }
    else if (c == '1'){
        fx = 354;
        fy = 56;
        fw = 22;
        fh = 40;
        xOffset  = 8;
        yOffset  = 10;
        xAdvance = 28;
    }
    else if (c == '2'){
        int fx = 178;
        int fy = 142;
        int fw = 30;
        int fh = 40;
        int xOffset  = 3;
        int yOffset  = 10;
        int xAdvance = 28;
    }
    else if (c == '3'){
        int fx = 312;
        int fy = 98;
        int fw = 30;
        int fh = 42;
        int xOffset  = 3;
        int yOffset  = 8;
        int xAdvance = 28;
    }
    else if (c == '4'){
        int fx = 146;
        int fy = 320;
        int fw = 30;
        int fh = 40;
        int xOffset  = 3;
        int yOffset  = 10;
        int xAdvance = 28;
    }
    else if (c == '5'){
        int fx = 146;
        int fy = 278;
        int fw = 30;
        int fh = 42;
        int xOffset  = 4;
        int yOffset  = 10;
        int xAdvance = 28;
    }
    else if (c == '6'){
        int fx = 280;
        int fy = 98;
        int fw = 30;
        int fh = 42;
        int xOffset  = 5;
        int yOffset  = 8;
        int xAdvance = 28;
    }
    else if (c == '7'){
        int fx = 210;
        int fy = 142;
        int fw = 28;
        int fh = 40;
        int xOffset  = 7;
        int yOffset  = 10;
        int xAdvance = 28;
    }
    else if (c == '8'){
        int fx = 248;
        int fy = 98;
        int fw = 30;
        int fh = 42;
        int xOffset  = 4;
        int yOffset  = 8;
        int xAdvance = 28;
    }
    else if (c == '9'){
        int fx = 216;
        int fy = 98;
        int fw = 30;
        int fh = 42;
        int xOffset  = 4;
        int yOffset  = 8;
        int xAdvance = 28;
    }
    else if (c == ':'){
        int fx = 298;
        int fy = 258;
        int fw = 16;
        int fh = 30;
        int xOffset  = 3;
        int yOffset  = 20;
        int xAdvance = 14;
    }
    else if (c == 'A'){
        int fx = 160;
        int fy = 56;
        int fw = 36;
        int fh = 40;
        int xOffset  = -1;
        int yOffset  = 10;
        int xAdvance = 34;
    }
    else if (c == 'p'){
        int fx = 84;
        int fy = 186;
        int fw = 32;
        int fh = 42;
        int xOffset  = 0;
        int yOffset  = 17;
        int xAdvance = 28;
    }
    else if (c == 'l'){
        int fx = 264;
        int fy = 258;
        int fw = 16;
        int fh = 40;
        int xOffset  = 2;
        int yOffset  = 10;
        int xAdvance = 12;
    }
    else { //e
        int fx = 328;
        int fy = 184;
        int fw = 28;
        int fh = 32;
        int xOffset  = 3;
        int yOffset  = 18;
        int xAdvance = 28;
    }
}
