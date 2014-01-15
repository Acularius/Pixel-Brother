#include "ImportMaps.h"
//These variables can be accessed throughout all cpp files
#ifndef GLOBAL_VARS
#define GLOBAL_VARS
	extern Level currentLevel;
	extern int gameState;
	extern int roomX;
	extern int roomY;
	extern int Step;
	extern char* global_item[4];
	extern int money;
	extern int save;

	bool EnterWasPressed();
	bool InventoryWasPressed();
#endif