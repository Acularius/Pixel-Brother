#include <string>
#include <vector>
#include <iostream>

#include "CImg.h"

class Constraints
{
public:
	Constraints();
	Constraints(std::string mapConstraintFileName);
	~Constraints(void);

	const char *fileLocation;
	std::vector< std::vector<bool> > vConstraintVector ;

	void createResizeWriteVector();
	void constraintMessageBegin();
	void constraintMessageEnd();

	//std::string acessVector(int coordX, int coordY);


	

};

