#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cassert>
#include <cstring>
#include "global.h"
#include "Frame.h"
#include "Image.h"
#include "Rectangle.h"
#include <cerrno>
#include "Clock.h"

using namespace std;

const double frames_per_second = 60; 
const int duration_in_seconds = 10;

Frame frame(640, 480);

int main(int argc, char * argv[]) {
	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 640x480 "
		"-r 60               " // frames per second
		"-i -                " // read data from the standard input stream
		"-pix_fmt yuv420p    " // to render with Quicktime
		"-vcodec mpeg4       "
		"-an                 " // no audio
		"-q:v 5              " // quality level; 1 <= q <= 32
		"output.mp4          ";

	// Run the ffmpeg command and get pipe to write into its standard input stream.
#ifdef _WIN32
	FILE * pipe = _popen(cmd, "wb");
#else
	FILE * pipe = popen(cmd, "w");
#endif
	if (pipe == 0) {
		cout << "error: " << strerror(errno) << endl;
		return 1;
	}
     
	// Write video frames into the pipe.
	
	int num_frames = duration_in_seconds * frames_per_second;

	Clock clock(20,30);
	
	Rectangle r1 (150, 100, 225, 0, 100, 30, 30);
	r1.setVelocity(95, 95);

    Rectangle r2 (125, 75, 0, 225, 50, 290, 30);
	r2.setVelocity(80, 50);

	Image image1;
	image1.load("1.bmp", 100, 75);
	image1.setVelocity(0, 70);

	Image image2;
	image2.load("2.bmp", 100, 125);
	image2.setVelocity(70, 0);

	double dt = 1.0/frames_per_second;
	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		frame.clear();
		r1.draw();
		r1.update(dt);
		r2.draw();
		r2.update(dt);

		image1.update(dt);
		image1.draw();
		image2.update(dt);
		image2.draw();

		clock.update(dt);
		clock.draw();
		frame.write(pipe);
	}

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif

	cout << "num_frames: " << num_frames << endl;
	cout << "Done." << endl;

	return 0;
}
