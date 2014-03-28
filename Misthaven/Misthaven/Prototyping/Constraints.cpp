#include "Constraints.h"

Constraints::Constraints()
{

}

Constraints::Constraints(std::string mapConstraintFileName)
{
	constraintMessageBegin();
	fileLocation = mapConstraintFileName.c_str();
	createResizeWriteVector();
	constraintMessageEnd();

}

Constraints::~Constraints(void)
{
	/*Default Constructor*/
}

void Constraints::createResizeWriteVector( )
{
	int iWidth, iHeight;
	cimg_library::CImg<unsigned char> imgload(fileLocation);
	iWidth = imgload.width();
	iHeight = imgload.height();
	std::vector< std::vector<bool> > vWriteVector (iWidth, std::vector<bool>(iHeight));
	
	int iVx,iVy; //Writing the Vector
	float fVRed, fVGreen, fVBlue;

	for (iVx=0; iVx<=iWidth-1; iVx++)
		for(iVy=0; iVy<=iHeight-1; iVy++)
		{
			int revVy = iHeight - 1 - iVy; //Reverses the y copying
			fVRed = imgload(iVx,revVy,0, 0);
			fVGreen = imgload(iVx,revVy,0, 1);
			fVBlue = imgload(iVx,revVy,0, 2);

			if ( (fVRed==0) && (fVGreen==255) && (fVBlue==0) ) //Green = traversable = true
			{
				vWriteVector[iVx][iVy] = true;
			}
			else{
				vWriteVector[iVx][iVy] = false;
			};
		};
		vConstraintVector = vWriteVector;
		~imgload; //Deletes imgload
}

void Constraints::constraintMessageBegin()
{
	std::cout << "Creating Constraints class" << std::endl;
}

void Constraints::constraintMessageEnd()
{
	std::cout << "Created Constraints class" << std::endl;
}

//std::string Constraints::acessVector(int coordX, int coordY)
//{
//	return vConstraintVector[coordX][coordY];
//}
