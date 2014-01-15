//Includes
#include "Object.h"
#include "GlobalVars.h"
#include "DrawWindows.h"
#include "RoomController.h"
#include <curses.h>
#include <math.h>
#include <Windows.h>
#pragma comment (lib , "winmm.lib")

//Prototypes
Object DefineObject(int spr, int img, int ani[4], WINDOW *local_win, int v, int h, int y, int x, int dir, int object);
int distance(int x1, int y1, int x2, int y2);

//Variables
const int SPRITE_HEIGHT = 6;
const int SPRITE_WIDTH = 9;
const int MAP_HEIGHT = 11;
const int MAP_WIDTH = 22;

void Object::SetSprite(int spr, int img, int ani[4], WINDOW *local_win)
{	//Set the sprites
	spriteIndex = spr;
	imageIndex = img;
	for (int i = 0; i < 4; i++)
		animations[i] = ani[i];
	objectWindow = local_win;
}

void Object::SetSpeed(int v, int h)
{	//Set the speed
	vspeed = v;
	hspeed = h;
}

void Object::SetDirection(int dir, int y, int x)
{	//Set position and orientation
	direction = dir;
	position[0] = y;
	position[1] = x;
}

Object DefineObject(int spr, int img, int ani[4], WINDOW *local_win, int v, int h, int y, int x, int dir, int local_objIndex)
{	//Constructor
	Object local_object;
	int _ani[4];
	for (int i = 0; i < 4; i++)
		_ani[i] = ani[i];
	local_object.SetSprite(spr, img, _ani, local_win);
	local_object.SetSpeed(v, h);
	local_object.SetDirection(dir, y, x);
	local_object.SetObjIndex(local_objIndex);
	return local_object;
}

Object boulderXY(int x, int y)
{
	for (int i = 0; i < MAP_HEIGHT; i ++)
	{
		for (int j = 0; j < MAP_WIDTH; j ++)
		{
			if (currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetX() == x && currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetY() == y)
				return currentLevel.puzzleObject[(i*MAP_WIDTH)+j];
		}
	}
	return currentLevel.puzzleObject[0];
}

Object boulderXYS(int x, int y, int v, int h)
{
	for (int i = 0; i < MAP_HEIGHT; i ++)
	{
		for (int j = 0; j < MAP_WIDTH; j ++)
		{
			if (currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetX() == x && currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetY() == y)
			{
				if (v == 0 && h == 0)
				{
					currentLevel.puzzleObject[(i*MAP_WIDTH)+j].SetDirection(0,currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetY()/SPRITE_HEIGHT,currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetX()/SPRITE_WIDTH);
					currentLevel.puzzleObject[(i*MAP_WIDTH)+j].SetSpeed(0,0);
				}
				else
				{
					currentLevel.puzzleObject[(i*MAP_WIDTH)+j].SetDirection(0,currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetY()*SPRITE_HEIGHT,currentLevel.puzzleObject[(i*MAP_WIDTH)+j].GetX()*SPRITE_WIDTH);
					currentLevel.puzzleObject[(i*MAP_WIDTH)+j].SetSpeed(v,h);
				}
			}
		}
	}
	return currentLevel.puzzleObject[0];
}

int Object::DrawSprite(Object local_object, int animationIndex)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	
	int x1, x2, y1, y2;
		
	wborder(local_object.objectWindow, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	int k = local_object.spriteIndex + local_object.animations[(animationIndex + local_object.imageIndex)%4];
	if (local_object.GetImageIndex() == -1) // Don't animate
		k = local_object.spriteIndex;

	if (local_object.GetImageIndex() == -2) // Don't draw
		return 0;

	k += local_object.direction * 3;

	x2 = Player.position[1]/SPRITE_WIDTH;
	y2 = Player.position[0]/SPRITE_HEIGHT;
	
	if (!currentLevel.AreLightsOn())
	{
		x1 = local_object.position[1];
		y1 = local_object.position[0];

		if (distance(x1, y1, x2, y2) > 31)
			return 0;
		if (distance(x1, y1, x2, y2) == 30 || distance(x1, y1, x2, y2) == 31 || distance(x1, y1, x2, y2) == 28 )
		{
			for (int i=0; i < SPRITE_HEIGHT; i++)
			{
				for (int j=0; j < SPRITE_WIDTH; j++)
				{
					mvwaddch(local_object.objectWindow,i,j,ASCII_ART[k][i][j] | COLOR_PAIR(2));
				}
			}
			wnoutrefresh(local_object.objectWindow);
			return 1;
		}
	}

	for (int i=0; i < SPRITE_HEIGHT; i++)
	{
		for (int j=0; j < SPRITE_WIDTH; j++)
		{
			if (local_object.GetObjIndex() == 1000)
			{
				attron(COLOR_PAIR(3));
				mvwprintw(local_object.objectWindow,1,1,"Score\n%d",Step);
				attroff(COLOR_PAIR(3));
				wnoutrefresh(local_object.objectWindow);
			}
			else
				mvwaddch(local_object.objectWindow,i,j,ASCII_ART[k][i][j] | COLOR_PAIR(1));
		}
	}

	wnoutrefresh(local_object.objectWindow);
	return 1;
}

int Object::DrawLayerSprite(Object local_object, int animationIndex)
{
	wborder(local_object.objectWindow, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	int index, x, y, k = local_object.spriteIndex + local_object.animations[(animationIndex + local_object.imageIndex)%4];

	if (local_object.GetImageIndex() == -1) // Don't animate
		k = local_object.spriteIndex;
	if (local_object.GetImageIndex() == -2) // Don't Draw
		return 0;
	
	k += local_object.direction * 3;

	for (int i=0; i < SPRITE_HEIGHT; i++)
	{
		for (int j=0; j < SPRITE_WIDTH; j++)
		{
			x = local_object.position[1] + j;
			y = local_object.position[0] + i;

			index = ((y-(y%SPRITE_HEIGHT))/SPRITE_HEIGHT);
			index = index * MAP_WIDTH;
			index += ((x-(x%SPRITE_WIDTH))/SPRITE_WIDTH);

			clear();

			if (ASCII_ART[k][i][j] != 'g')
				mvwaddch(local_object.objectWindow,i,j,ASCII_ART[k][i][j]);
			else
				mvwaddch(local_object.objectWindow,i,j,mvwinch(currentLevel.roomObject[index].objectWindow, y%SPRITE_HEIGHT, x%SPRITE_WIDTH));
		}
	}
	wnoutrefresh(local_object.objectWindow);
	return 1;
}

int distance(int x1, int y1, int x2, int y2)
{
	int distance = 0;
	double formula = ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));

	formula = sqrt(formula);

	distance = int(floor(formula * 10));
	return distance;
}