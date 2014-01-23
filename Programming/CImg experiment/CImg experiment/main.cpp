#include <iostream>
#include "CImg.h"
using namespace cimg_library;
int main()
{


CImg<unsigned char> img("images/splotches.bmp"); // Reads from .bmp files natively

int width = img.width();
int height = img.height();
float red = img(99,99,0, 0); // Red Channel
float green = img(99,99,0, 1); // Green Channel
float blue = img(99,99,0, 2); // Blue Channel
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
CImg<unsigned char> image("location/of/image/here.bmp")
image(x,y,z, channel)
x,y,z represent the location of the pixel.
In terms of channel.
Red is channel = 0
Green, channel = 1
Blue, channel = 2

Therefore, the program starts from the top left.
In a 200 by 200 file. Ignore z
0-199
0,0 = Purple Corner ( Red and Blue > Green)
0,199 = Blue Corner
99,99 = Red Center
199,0 = Green Corner
199,199 = Not sure what colour Corner (Red and Green > Blue)

 Cimg stores from the top left
OpenGL reads pixel coords from the bottom left.

OpenGl will start from 0 and end at image.height()-1;
Cimg will start from image.height() - 1 to 0.

*/