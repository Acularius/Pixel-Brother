#include <iostream>
#include <vector>
#include <string>
#include "CImg.h"
// using namespace cimg_library;

int main()
{


cimg_library::CImg<unsigned char> img("images/splotches.bmp"); // Reads from .bmp files natively

int iWidth = img.width(); // X coords to create an array
int iHeight = img.height(); //Y coords to create an array
float fRed = img(99,99,0, 0); // Red Channel
float fGreen = img(99,99,0, 1); // Green Channel
float fBlue = img(99,99,0, 2); // Blue Channel
int iNumChannels = img.spectrum(); // Number of Channels
std::vector< std::vector<std::string> > vTestVector (iWidth, std::vector<std::string>(iHeight));


int iVx,iVy; //Writing the Vector
float fTestVRed, fTestVGreen, fTestVBlue;

for (iVx=0; iVx<=iWidth-1; iVx++)
	for(iVy=0; iVy<=iHeight-1; iVy++)
	{
		int revVy = iHeight - 1 - iVy; //Reverses the y copying
		fTestVRed = img(iVx,revVy,0, 0);
		fTestVGreen = img(iVx,revVy,0, 1);
		fTestVBlue = img(iVx,revVy,0, 2);

		if ( (fTestVRed==255) && (fTestVGreen==0) && (fTestVBlue==0) ) // Red - Center
		{
			vTestVector[iVx][iVy] = "Red";
		} else if((fTestVRed==147) && (fTestVGreen==50) && (fTestVBlue==144)){ // Purple - Top Left
			vTestVector[iVx][iVy] = "Purple";
		} else if ((fTestVRed==0) && (fTestVGreen==255) && (fTestVBlue==0)){ // Green - Top Right
			vTestVector[iVx][iVy] = "Green";
		} else if((fTestVRed==1) && (fTestVGreen==1) && (fTestVBlue==255)){ // Blue - Bottom Left
			vTestVector[iVx][iVy] = "Blue";
		} else if ((fTestVRed==143) && (fTestVGreen==140) && (fTestVBlue==79)){ // Brown ? - Bottom Right
			vTestVector[iVx][iVy] = "Brown?";
		}
		else{
			vTestVector[iVx][iVy] = "Nothing to Report";
		};


	};

	// Accessing information
	int iAccessX, iAccessY, iAccessOpenGLy;
	float fAccessRed, fAccessGreen, fAccessBlue; // cImg location of pixel colour
	float fGLAccessRed, fGLAccessGreen, fGLAccessBlue; // Where it would be on OpenGL
	std::string sOutputVector;
	bool bAccess = 1;
	



std::cout << "The file is  " << iWidth << " pixels wide" << std::endl;
std::cout << "The file is  " << iHeight << " pixels high" << std::endl;
std::cout << "Number of Channels: " << iNumChannels << std::endl;
std::cout << "This much Red: " << fRed << std::endl;
std::cout << "This much Green: " << fGreen << std::endl;
std::cout << "This much Blue: " << fBlue << std::endl;
while (bAccess == 1)
{
	std::cout << "Asking for X-Coordinate: " << std::endl;
	std::cin >> iAccessX;
	std::cout << "Asking for Y-Coordinate: " <<std::endl;
	std::cin >> iAccessY;
	iAccessOpenGLy = iHeight - 1 - iAccessY;
	fAccessRed = img(iAccessX,iAccessY,0, 0); // Red Channel for cImg location
	fAccessGreen = img(iAccessX,iAccessY,0, 1); // Green Channel for cImg location
	fAccessBlue = img(iAccessX,iAccessY,0, 2); // Blue Channel for cImg location
	fGLAccessRed = img(iAccessX,iAccessOpenGLy,0, 0); // Red Channel for OpenGL location
	fGLAccessGreen = img(iAccessX,iAccessOpenGLy,0, 1); // Green Channel for OpenGL location
	fGLAccessBlue = img(iAccessX,iAccessOpenGLy,0, 2); // Blue Channel for OpenGL location
	sOutputVector = vTestVector[iAccessX][iAccessY];
	std::cout << "Red at cImg (" << iAccessX << ", " << iAccessY << ") is: " << fAccessRed << std::endl;
	std::cout << "Green at cImg (" << iAccessX << ", " << iAccessY << ") is: " << fAccessGreen << std::endl;
	std::cout << "Blue at cImg (" << iAccessX << ", " << iAccessY << ") is: " << fAccessBlue << std::endl;
	std::cout << "Compared to vTestVector at (" << iAccessX << ", " << iAccessY << ") which reads: " << sOutputVector << std::endl;
	std::cout << "Red at OpenGL (" << iAccessX << ", " << iAccessY << ") is: " << fGLAccessRed << std::endl;
	std::cout << "Green at OpenGL (" << iAccessX << ", " << iAccessY << ") is: " << fGLAccessGreen << std::endl;
	std::cout << "Blue at OpenGL (" << iAccessX << ", " << iAccessY << ") is: " << fGLAccessBlue << std::endl;
	
	std::cout << "Continue? (1 = yes, 0 = no)" << std::endl;
	std::cin >> bAccess;
};




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