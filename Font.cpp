#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cerrno>
#include "Font.h"
#include "Frame.h"
#include "Glyph.h"

using namespace std;

extern Frame frame;

Font::Font() : w(384), h(384) {
	pixels = new byte[w * h * 3];

	const char * cmd = 
		"ffmpeg           "
		"-i arial50.bmp   "
		"-f rawvideo      "
		"-pix_fmt rgb24   "
		"-                ";

#ifdef _WIN32
	FILE * pipe = _popen(cmd, "rb");
#else
	FILE * pipe = popen(cmd, "r");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << std::endl;
		exit(1);
	}
	fread(pixels, 3, w * h, pipe);

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
}

void Font::draw(const string & text, double x, double y) const {
	for (int i = 0;  i< text.size(); ++i){
    	Glyph gly(text[i]);
		for (int j = 0; j< gly.fw; ++j) {
			for (int k = 0; k < gly.fh; ++k) {
				byte r = pixels[(gly.fy + k) * w * 3 + (gly.fx + j) * 3 + 0];
				byte g = pixels[(gly.fy + k) * w * 3 + (gly.fx + j) * 3 + 1];
				byte b = pixels[(gly.fy + k) * w * 3 + (gly.fx + j) * 3 + 2];
				frame.setPixel(x + j, y + k, r, g, b);
			}
		}
		x += gly.xAdvance;
	}
}
