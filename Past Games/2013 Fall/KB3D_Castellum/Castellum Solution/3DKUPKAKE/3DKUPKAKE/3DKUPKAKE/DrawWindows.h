#include "Object.h"

#ifndef MENU
#define MENU
	int MainMenu();
	int DrawBackground(char* file, int doGet);
	WINDOW *create_win(int height, int width, int starty, int startx);
	void destroy_win(WINDOW *local_win);
	void DrawMessage(int y, int x, int w, int h, char* message);
	int DrawInventory(char* title, int item, int price);
	extern Object Player;
#endif