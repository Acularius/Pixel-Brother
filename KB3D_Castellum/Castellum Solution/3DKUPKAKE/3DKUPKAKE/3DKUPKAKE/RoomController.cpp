//Includes
#include "Object.h"
#include "DrawWindows.h"
#include "PlayerMovement.h"
#include "GlobalVars.h"
#include <curses.h>
#include <string>
#include <Windows.h>
#include <fstream>

//Prototypes
void BoulderFunctions(int index);

//Variables
const int MAP_HEIGHT = 11;
const int MAP_WIDTH = 22;
const int SPRITE_HEIGHT = 6;
const int SPRITE_WIDTH = 9;
int updatedSprite = 0, k, l;
char ASCII_ART[400][6][9];

int RoomUpdate()//Code that updates all of the objects
{
	Sleep(30);
	int index;
	
	PlayerMove(Player);

	for (int i=0; i < MAP_HEIGHT; i++)
	{	//Nested for loops to check all 242 objects 
		for (int j=0; j < MAP_WIDTH; j++)
		{
			index = (i*MAP_WIDTH)+j;
			currentLevel.roomObject[index].DrawSprite(currentLevel.roomObject[index],updatedSprite); //Draw each of their sprites animated
		}
	}

	if (Player.GetHSpeed() != 0 || Player.GetVSpeed() != 0)
		Player.DrawLayerSprite(Player,updatedSprite); //Draw the player sprite animated
	else
		Player.DrawLayerSprite(Player,0); //Draw the player sprite animated

	for (int i=0; i < MAP_HEIGHT; i++)
	{	//Nested for loops to check all 242 objects 
		for (int j=0; j < MAP_WIDTH; j++)
		{
			index = (i*MAP_WIDTH)+j;
			if (currentLevel.puzzleObject[index].GetObjIndex() == 45)
			{
				BoulderMove(currentLevel.puzzleObject[index]);
				currentLevel.puzzleObject[index].DrawLayerSprite(currentLevel.puzzleObject[index],0); //Draw each of their sprites animated
			}
		}
	}

	if (currentLevel.roomObject[0].GetObjIndex() == 999)
	{
		for (int i = 0; i < SPRITE_HEIGHT; i ++)
			for (int j = 0; j < SPRITE_WIDTH; j ++)
				mvwaddch(currentLevel.roomObject[0].objectWindow,i,j,' ');
		attron(COLOR_PAIR(3));
		mvwprintw(currentLevel.roomObject[0].objectWindow,2,2,"Score");
		mvwprintw(currentLevel.roomObject[0].objectWindow,3,2,"%d",Step);
		attroff(COLOR_PAIR(3));
		wborder(currentLevel.roomObject[0].objectWindow, '|', '|', '-', '-', '*', '*', '*', '*');
		
		wnoutrefresh(currentLevel.roomObject[0].objectWindow);
	}
	
	doupdate();

	if (updatedSprite == 3)
		updatedSprite = -1;
	updatedSprite ++;

	if (InventoryWasPressed())
	{
		return DrawInventory("Inventory", -1, 1);
	}
	return 1;
}

int ImportAsciiArt(std::string file)
{
	std::string word;
	std::ifstream fileName;
	fileName.open(file);
	fileName >> word;

	if (fileName.is_open())
	{
		while (fileName.good())
		{
			for (int i=0; i< 400; i++)
			{
				for (int j=0; j < 6; j++)
				{
					for (int k=0; k < 9; k++)
					{
						if (word[k] == 'G')
							ASCII_ART[i][j][k] = ' ';//Blank if it is a G
						else
							ASCII_ART[i][j][k] = word[k];//Ascii_art[Sprite][Y][X]
					}
					fileName >> word;
				}
			}
		}	
		fileName.close();
	}
	else
	{
		printf("The Ascii Art the computer is trying to load doesn't exist\n"); //Apologize
		printf("Try re-installing the game\n");
		getch();
		return 0;
	}
	return 1;
}