#include <iostream>
#include "CImg.h"
using namespace cimg_library;
int main()
{


CImg<unsigned char> img("images/redsplotch.bmp"); // Reads from .bmp files natively

int width = img.width();
int height = img.height();
float red = img(100,125,0, 0); // in theory should be red
float green = img(100,125,0, 1); // in theory should be green
float blue = img(100,125,0, 2); // in theory the channel should be blue
int numChannels = img.spectrum(); // Number of Channels

std::cout << "The file is  " << width << " pixels wide" << std::endl;
std::cout << "The file is  " << height << " pixels high" << std::endl;
std::cout << "Number of Channels: " << numChannels << std::endl;
std::cout << "This much Red: " << red << std::endl;
std::cout << "This much Green: " << green << std::endl;
std::cout << "This much Blue: " << blue << std::endl;

system("pause");
return 0;

}

/* What I have learned:
'image'(x,y,z, channel)
x,y,z represent the location of the pixel.
In terms of channel.
Red is channel = 0
Green, channel = 1
Blue, channel = 2
*/