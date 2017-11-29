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
#include "Font.h"

using namespace std;

const double frames_per_second = 30; 
const int duration_in_seconds = 5;

Frame frame(370, 240);

int main(int argc, char * argv[]) {
	// Construct the ffmpeg command to run.
	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 370x240 "
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
/*	
	Rectangle r1 (100, 50, 225, 0, 100, 30, 30);
	r1.setVelocity(50, 50);

    Rectangle r2 (75, 25, 0, 225, 50, 290, 30);
	r2.setVelocity(0, 50);

    Rectangle r3 (125, 70, 50, 0, 225, 550, 30);
	r3.setVelocity(50, 0);
	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		frame.clear();
		r1.draw();
		r1.update(time_in_seconds);
		r2.draw();
		r2.update(time_in_seconds);
		r3.draw();
		r3.update(time_in_seconds);
		frame.write(pipe);
	}

	Image image1;
	image1.load("1.bmp", 202, 151);
	image1.setVelocity(50, 50);

	Image image2;
	image2.load("2.bmp", 144, 180);
	image2.setVelocity(50, 10);

	Image image3;
	image3.load("3.bmp", 150, 185);
	image3.setVelocity(10, 50);

	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		frame.clear();
		image1.update(time_in_seconds);
		image1.draw();
		image2.update(time_in_seconds);
		image2.draw();
		image3.update(time_in_seconds);
		image3.draw();
		frame.write(pipe);
	}
*/
	Font font;

	for (int i = 0; i < num_frames; ++i) {
		frame.clear();
		stringstream elapseSeconds;
		elapseSeconds << (int) (i / frames_per_second);
		font.draw(elapseSeconds.str(), 170, 90);
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
