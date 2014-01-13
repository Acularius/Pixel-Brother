#include <string>

#ifndef ROOM_CONTROLLER
#define ROOM_CONTROLLER
	int ImportAsciiArt(std::string file);
	int RoomUpdate();

	extern char ASCII_ART[400][6][9];
#endif