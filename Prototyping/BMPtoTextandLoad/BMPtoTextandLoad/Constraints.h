#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "CImg.h"

class Constraints
{
public:
	Constraints();
	Constraints(std::string mapConstraintFileName);
	~Constraints(void);

	const char *fileLocation;
	std::vector< std::vector<bool> > vConstraintVector ;
	std::vector< std::vector<bool> > vConstraintVectorCompare ;

	void createResizeWriteVector();
	void constraintMessageBegin();
	void constraintMessageEnd();

	void writeToFile();
	void loadFromFile();

	void compareConstraintVectors(); 
	//std::string acessVector(int coordX, int coordY);


	

};

