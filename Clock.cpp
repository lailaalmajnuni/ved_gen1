#include "Clock.h"
#include <sstream>
#include "Frame.h"
#include "Font.h"

extern Frame frame;

Font font;

using namespace std;

Clock::Clock(int x, int y){
  this->x = x;
  this->y = y;
  elapsedSeconds = 0; 
}

void Clock::draw() const{
    stringstream ss;
    ss << (int)elapsedSeconds;
    string s = ss.str();
    font.draw(ss.str(), 170, 90);
}

void Clock::update(double dt){
    elapsedSeconds = elapsedSeconds + dt;
}