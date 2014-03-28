#include "Constraints.h"

Constraints::Constraints(std::string mapConstraintFileName)
{
	fileLocation = mapConstraintFileName.c_str();
	this -> createResizeWriteVector(vConstraintVector);

}

Constraints::~Constraints(void)
{
	/*Default Constructor*/
}

std::vector<std::vector<bool> > Constraints::createResizeWriteVector(std::vector<std::vector<bool> > vectorinput)
{
	int iWidth, iHeight;
	cimg_library::CImg<unsigned char> imgload(fileLocation);
	iWidth = imgload.width();
	iHeight = imgload.height();
	std::vector< std::vector<bool> > vConstraintVector (iWidth, std::vector<bool>(iHeight));

	int iVx,iVy; //Writing the Vector
float fVRed, fVGreen, fVBlue;

for (iVx=0; iVx<=iWidth-1; iVx++)
	for(iVy=0; iVy<=iHeight-1; iVy++)
	{
		int revVy = iHeight - 1 - iVy; //Reverses the y copying
		fVRed = imgload(iVx,revVy,0, 0);
		fVGreen = imgload(iVx,revVy,0, 1);
		fVBlue = imgload(iVx,revVy,0, 2);

		if ( (fVRed==0) && (fVGreen==255) && (fVBlue==0) ) //Green = traversable
		{
			vConstraintVector[iVx][iVy] = true;
		}
		else{
			vConstraintVector[iVx][iVy] = false;
		};
	};
	return vConstraintVector;
}

bool Constraints::acessVector(int coordX, int coordY)
{
	return vConstraintVector[coordX][coordY];
}
