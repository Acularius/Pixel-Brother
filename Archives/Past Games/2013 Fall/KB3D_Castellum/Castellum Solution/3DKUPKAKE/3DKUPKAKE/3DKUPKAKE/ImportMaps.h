#include <string>
#include <Windows.h>
#include "Object.h"

#ifndef IMPORT_MAPS
#define IMPORT_MAPS

class Level
{ 
private:
    bool lights;
	int id;

public:
	Level(); //Default Constructor

	Object roomObject[242];
	Object puzzleObject[242];

	bool AreLightsOn() { return lights; }
	int GetLevelID() { return id; }
	int ImportMap(int x, int y, std::string mapName);
	void ToggleLights();
	void GenerateMaze();
};

#endif