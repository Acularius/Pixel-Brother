#include <string>
#include <vector>

#include "CImg.h"

class Constraints
{
public:

	Constraints(std::string mapConstraintFileName);
	~Constraints(void);

	const char *fileLocation;
	std::vector<std::vector<bool> > vConstraintVector;

	std::vector<std::vector<bool> > createResizeWriteVector(std::vector<std::vector<bool> > vectorinput);

	bool acessVector(int coordX, int coordY);


	

};

