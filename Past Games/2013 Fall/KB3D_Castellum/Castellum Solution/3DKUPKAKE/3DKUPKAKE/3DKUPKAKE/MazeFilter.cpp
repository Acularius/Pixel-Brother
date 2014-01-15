#include "MazeFilter.h"
#include "CreateObject.h"
#include "Object.h"
#include "GlobalVars.h"
#include "DrawWindows.h"

int Index(int x, int y);//Prototype for "Index" function
int BlockVal(int x, int y);//Prototype for "BlockVal" function
int SetBlockObj(int x, int y);//Prototype for "SetBlock" function
int SetBlockSprite(int x, int y);//Prototype for "SetBlock" function

const int MAP_HEIGHT = 11;
const int MAP_WIDTH = 22;
const int SPRITE_HEIGHT = 6;
const int SPRITE_WIDTH = 9;

void MazeFilter()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++) //This ultimately checks all map spaces
		{
			if (currentLevel.roomObject[Index(j,i)].GetObjIndex() != 0)//If a block is not empty, assign it to what it should be.
			{
				int ani[4] = {0,0,0,0};
				currentLevel.roomObject[Index(j,i)] = DefineObject(SetBlockSprite(j,i)-1,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,i*SPRITE_HEIGHT,j*SPRITE_WIDTH),0,0,i,j,0,SetBlockObj(j,i));
			}
			else if (currentLevel.roomObject[Index(j,i)].GetObjIndex() == 0)
			{
				int ani[4] = {0,0,0,0};
				currentLevel.roomObject[Index(j,i)] = DefineObject(200,-1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,i*SPRITE_HEIGHT,j*SPRITE_WIDTH),0,0,i,j,0,0);
			}
		}
	}
}

int Index(int x, int y)
{
	return (y * MAP_WIDTH) + x;
}

int BlockVal (int x, int y)//Prevents calling a window that doesn't exist
{
	if (x >= 0 && x < 21 && y >= 0 && y < 11)
	{
		return (currentLevel.roomObject[Index(x,y)].GetObjIndex());
	}
	else return (0);
}

int SetBlockObj(int x, int y)//Returns the value for the 'object' parameter
{
	if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)//  -|-    Left, right, up, and down
		return (82);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0)// -,-    Left, right, and down
		return (83);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -'-    Left, right, and up
		return (84);
	else if (BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -|     Left, up, and down
		return (85);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x,y-1) != 0)//  |-    Right, up, and down
		return (86);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0)//  ,-    Right and down
		return (89);
	else if (BlockVal (x-1,y) != 0 && BlockVal (x,y+1) != 0)// -,     Left and down
		return (90);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y-1) != 0)//  '-    Right and up
		return (91);
	else if (BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -'     Left and up
		return (92);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x-1,y) != 0)// - -    Left and right
		return (79);
	else if (BlockVal (x,y+1) != 0 && BlockVal (x,y-1) != 0)//  |     Up and down
		return (73);
	else if (BlockVal (x,y-1) != 0)//   '     Up
		return (76);
	else if (BlockVal (x,y+1) != 0)//   ,     Down
		return (72);
	else if (BlockVal (x+1,y) != 0)//    -    Right
		return (81);
	else if (BlockVal (x-1,y) != 0)//  -      Left
		return (80);
	else
		return (93);//         None
}

int SetBlockSprite(int x, int y)//Returns the value for the 'sprite' parameter
{
	if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)//  -|-    Left, right, up, and down
		return (165);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0)// -,-    Left, right, and down
		return (166);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -'-    Left, right, and up
		return (167);
	else if (BlockVal (x,y+1) != 0 && BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -|     Left, up, and down
		return (168);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0 && BlockVal (x,y-1) != 0)//  |-    Right, up, and down
		return (169);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y+1) != 0)//  ,-    Right and down
		return (173);
	else if (BlockVal (x-1,y) != 0 && BlockVal (x,y+1) != 0)// -,     Left and down
		return (174);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x,y-1) != 0)//  '-    Right and up
		return (175);
	else if (BlockVal (x-1,y) != 0 && BlockVal (x,y-1) != 0)// -'     Left and up
		return (176);
	else if (BlockVal (x+1,y) != 0 && BlockVal (x-1,y) != 0)// - -    Left and right
		return (162);
	else if (BlockVal (x,y+1) != 0 && BlockVal (x,y-1) != 0)//  |     Up and down
		return (156);
	else if (BlockVal (x,y-1) != 0)//   '     Up
		return (159);
	else if (BlockVal (x,y+1) != 0)//   ,     Down
		return (155);
	else if (BlockVal (x+1,y) != 0)//    -    Right
		return (164);
	else if (BlockVal (x-1,y) != 0)//  -      Left
		return (163);
	else
		return (177);//         None
}