#include "Rectangle.h"
#include "Frame.h"

extern Frame frame;

Rectangle::Rectangle(int w, int h, byte r, byte g, byte b, int x, int y){
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
}

void Rectangle::draw() const{
	if (frame.isOutside(x, y)) return;
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame.setPixel(x, y, r, g, b);
		}
	}
}

void Rectangle::update(double dt){
	x += dx * dt;
	y += dy * dt;
}

void Rectangle::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}
