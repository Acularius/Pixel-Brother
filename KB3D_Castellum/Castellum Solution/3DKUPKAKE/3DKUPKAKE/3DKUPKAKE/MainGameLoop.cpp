/* This is the Main Game loop. The code is repeated while loopGame is true. The switch
Statement checks to see the state of the game (if it is in menu, in a fight, or in the overworld)
and calls the corresponding function that is called each frame. */

// Includes
#include <stdio.h>
#include <Windows.h>
#include <curses.h>
#include "DrawWindows.h"
#include "ImportMaps.h"
#include "GlobalVars.h"
#include "RoomController.h"
#include "Interactions.h"

// Prototypes
void ResizeWindow(int _x, int _y);

// Variables
int loopGame = 1, gameState = -1, save = 1;
int roomX = 1, roomY = 1, Step = 0, money = 0;
bool enter = false, inv = false;

char* global_item[4] = { "Bomb", "Lantern", "Hammer", "mk II Lantern" };

Level currentLevel;

using namespace std;

void ResizeWindow(int _x, int _y) //Take the new sizes parameters
{
	resize_term(68,200);//The Lines and Columns needed
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, _x, _y, TRUE);
	ShowWindow( console, SW_MINIMIZE); //Minimize first, incase it is already maximized
	ShowWindow( console, SW_MAXIMIZE); //because maximizing twice messes it up
}

int main()
{
	initscr(); //Start Public Domain Curses
	
	if(has_colors() == FALSE) //Cekck if colors are supported
	{
		printf("Your terminal does not support color\n"); //Apologize
		printf("Closing Game, sorry\n");
		getch();
		loopGame = 0; //Never start the loop or initialize colors, if they arent supported
	}

	loopGame = ImportAsciiArt("Assets\\SpriteSheet.txt");
	noecho();
	curs_set(0); //Invisible cursor
	keypad(stdscr, TRUE); //Additional input
	nonl();

	ResizeWindow(1600,816); //This resizes the window first

	while(loopGame) //Loop while true
	{
		start_color(); //Start color

		init_pair(1, COLOR_BLACK, COLOR_WHITE); //WHITE
		init_pair(2, COLOR_WHITE, COLOR_BLACK); //Hightlighted Text

		switch (gameState)
		{
		case -1:
			loopGame = DrawBackground("Assets\\TowerBackground.txt", 1);
			break;

		case 0: //Main Menu
			loopGame = DrawBackground("Assets\\TowerBackground.txt", 0);
			loopGame = MainMenu();
			break;

		case 1: //Overworld
			loopGame = RoomUpdate();
			break;

		}
	}
	endwin();
	return 0; //End the game
}

bool EnterWasPressed()
{
	if (enter == false && (GetAsyncKeyState(VK_RETURN) && 0x8000))
	{
		enter = true;
		return true;
	}
	else if (enter == true && (!GetAsyncKeyState(VK_RETURN) && 0x8000))
	{
		enter = false;
		return false;
	}
	return false;
}

bool InventoryWasPressed()
{
	if (inv == false && (GetAsyncKeyState('I') && 0x8000))
	{
		inv = true;
		return true;
	}
	else if (inv == true && (!GetAsyncKeyState('I') && 0x8000))
	{
		inv = false;
		return false;
	}
	return false;
}