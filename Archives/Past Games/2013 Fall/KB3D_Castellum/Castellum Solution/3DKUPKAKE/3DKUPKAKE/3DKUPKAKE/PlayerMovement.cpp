//Includes
#include "Object.h"
#include "DrawWindows.h"
#include "GlobalVars.h"
#include "Interactions.h"
#include <Windows.h>

//Prototypes
int PlayerMove(Object &boulder);
void MoveToSnap(Object &local_object);
bool CheckFree(int dir, Object &local_object, int d);
void Move(int dir, Object &local_object);
void Door(Object &boulder);
int BoulderMove(Object &boulder);

//Variables
const int MAP_WIDTH = 22;
const int MAP_HEIGHT = 11;
const int SPRITE_WIDTH = 9;
const int SPRITE_HEIGHT = 6;

int PlayerMove(Object &player_object)
{
	Switch(roomX, roomY, player_object);
	if (EnterWasPressed())
		Door(player_object);

	if (player_object.GetY()%SPRITE_HEIGHT == 0 && player_object.GetX()%SPRITE_WIDTH == 0)
	{
		player_object.SetImageIndex(-1);
		Move(0, player_object); //All Directions
	}
	else if (player_object.GetY()%SPRITE_HEIGHT == 0)
		Move(1, player_object); //Horizontal Only
	else if (player_object.GetX()%SPRITE_WIDTH == 0)
		Move(2, player_object); //Vertical Only
	
	MoveToSnap(player_object);
	return 0;
}

void MoveToSnap(Object &local_object)
{
	if (local_object.GetHSpeed() != 0 || local_object.GetVSpeed() != 0)
	{
		destroy_win(local_object.objectWindow);
		local_object.SetY(local_object.GetY()+local_object.GetVSpeed());
		local_object.SetX(local_object.GetX()+local_object.GetHSpeed());
		local_object.SetDirection(local_object.GetDirection(),local_object.GetY(),local_object.GetX());
		local_object.objectWindow = create_win(6,9,local_object.GetY(),local_object.GetX());
	}
}

bool CheckFree(int dir, Object &local_object, int d)
{
	int i = local_object.GetY()/SPRITE_HEIGHT;
	int j = local_object.GetX()/SPRITE_WIDTH;
	int index, indexF;

	switch (dir)
	{

	case 0: // Down
		i += 1;
		index = (i*MAP_WIDTH)+j;
		i += 1;
		indexF = (i*MAP_WIDTH)+j;

		if (boulderXY(j,i-1).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() <= 0 || currentLevel.roomObject[indexF].GetObjIndex() == 55) && boulderXY(j,i).GetObjIndex() != 45 && d == 0)
		{
			boulderXYS(j,i-1,1,0);
			return false;
		}
		else if (boulderXY(j,i-1).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() > 0 || boulderXY(j,i).GetObjIndex() == 45) && d == 0)
			return false;
		else if (currentLevel.roomObject[index].GetObjIndex() <= 0)
			return true;
		break;

	case 1: // Up
		i -= 1;
		index = (i*MAP_WIDTH)+j;
		i -= 1;
		indexF = (i*MAP_WIDTH)+j;
		
		if (boulderXY(j,i+1).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() <= 0 || currentLevel.roomObject[indexF].GetObjIndex() == 55) && boulderXY(j,i).GetObjIndex() != 45 && d == 0)
		{
			boulderXYS(j,i+1,-1,0);
			return false;
		}
		else if (boulderXY(j,i+1).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() > 0 || boulderXY(j,i).GetObjIndex() == 45) && d == 0)
			return false;
		else if (currentLevel.roomObject[index].GetObjIndex() <= 0)
			return true;
		break;

	case 2: // Right
		j += 1;
		index = (i*MAP_WIDTH)+j;
		j += 1;
		indexF = (i*MAP_WIDTH)+j;
		
		if (boulderXY(j-1,i).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() <= 0 || currentLevel.roomObject[indexF].GetObjIndex() == 55) && boulderXY(j,i).GetObjIndex() != 45 && d == 0)
		{
			boulderXYS(j-1,i,0,1);
			return false;
		}
		else if (boulderXY(j-1,i).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() > 0 || boulderXY(j,i).GetObjIndex() == 45) && d == 0)
			return false;
		else if (currentLevel.roomObject[index].GetObjIndex() <= 0)
			return true;
		break;

	case 3: // Left
		j -= 1;
		index = (i*MAP_WIDTH)+j;
		j -= 1;
		indexF = (i*MAP_WIDTH)+j;

		if (boulderXY(j+1,i).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() <= 0 || currentLevel.roomObject[indexF].GetObjIndex() == 55) && boulderXY(j,i).GetObjIndex() != 45 && d == 0)
		{
			boulderXYS(j+1,i,0,-1);
			return false;
		}
		else if (boulderXY(j+1,i).GetObjIndex() == 45 && (currentLevel.roomObject[indexF].GetObjIndex() > 0 || boulderXY(j,i).GetObjIndex() == 45) && d == 0)
			return false;
		else if (currentLevel.roomObject[index].GetObjIndex() <= 0)
			return true;
		break;

	}

	return false;
}

void Move(int dir, Object &local_object)
{
	if (currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15)
		if (local_object.GetY()%SPRITE_HEIGHT == 0 && local_object.GetX()%SPRITE_WIDTH == 0)
		{
			if (local_object.GetVSpeed() == 1 && !CheckFree(0,local_object, dir))
			{
				local_object.SetSpeed(0,0);
				if (currentLevel.roomObject[0].GetObjIndex() == 999)
					Step ++;
			}
			if (local_object.GetVSpeed() == -1 && !CheckFree(1,local_object, dir))
			{
				local_object.SetSpeed(0,0);
				if (currentLevel.roomObject[0].GetObjIndex() == 999)
					Step ++;
			}
			if (local_object.GetHSpeed() == 1 && !CheckFree(2,local_object, dir))
			{
				local_object.SetSpeed(0,0);
				if (currentLevel.roomObject[0].GetObjIndex() == 999)
					Step ++;
			}
			if (local_object.GetHSpeed() == -1 && !CheckFree(3,local_object, dir))
			{
				local_object.SetSpeed(0,0);
				if (currentLevel.roomObject[0].GetObjIndex() == 999)
					Step ++;
			}
		}

	if (dir == 0 && currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15)
	{
		if (local_object.GetHSpeed() != 0 || local_object.GetVSpeed() != 0)
			if (currentLevel.roomObject[0].GetObjIndex() == 999)
				Step ++;
		local_object.SetSpeed(0,0);
	}
	
	if (dir == 0 || dir == 1)
	{
		if (GetAsyncKeyState(VK_RIGHT) && 0x8000)
		{
			local_object.SetDirection(2);
			if (CheckFree(2, local_object, dir))
			{
				if (currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15 || 
					(currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15 &&
					local_object.GetHSpeed() == 0 && local_object.GetVSpeed() == 0))
					local_object.SetHSpeed(1);
				local_object.SetDirection(2);
				local_object.SetImageIndex(0);
			}
		}
		
		if (GetAsyncKeyState(VK_LEFT) && 0x8000)
		{
			local_object.SetDirection(3);
			if (CheckFree(3, local_object, dir))
			{
				if (currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15 || 
					(currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15 &&
					local_object.GetHSpeed() == 0 && local_object.GetVSpeed() == 0))
					local_object.SetHSpeed(-1);
				local_object.SetDirection(3);
				local_object.SetImageIndex(0);
			}
		}
	}

	if (dir == 0 || dir == 2)
	{
		if (GetAsyncKeyState(VK_DOWN) && 0x8000 && local_object.GetHSpeed() == 0)
		{
			local_object.SetDirection(0);
			if (CheckFree(0, local_object, dir))
			{
				if (currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15 || 
					(currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15 &&
					local_object.GetHSpeed() == 0 && local_object.GetVSpeed() == 0))
					local_object.SetVSpeed(1);
				local_object.SetDirection(0);
				local_object.SetImageIndex(0);
			}
		}

		if (GetAsyncKeyState(VK_UP) && 0x8000 && local_object.GetHSpeed() == 0)
		{
			local_object.SetDirection(1);
			if (CheckFree(1, local_object, dir))
			{
				if (currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15 || 
					(currentLevel.roomObject[((local_object.GetY()/SPRITE_HEIGHT) * MAP_WIDTH) + (local_object.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15 &&
					local_object.GetHSpeed() == 0 && local_object.GetVSpeed() == 0))
					local_object.SetVSpeed(-1);
				local_object.SetDirection(1);
				local_object.SetImageIndex(0);
			}
		}
	}
}

void Door(Object &player_object)
{
	int i,j, index;
	
	i = player_object.GetX()/SPRITE_WIDTH;
	j = player_object.GetY()/SPRITE_HEIGHT;

	switch (player_object.GetDirection())
	{
	case 0: //Down
		j += 1;
		break;
	case 1: //Up
		j -= 1;
		break;
	case 2: //Right
		i += 1;
		break;
	case 3: //Left
		i -= 1;
		break;
	}

	index = (j*MAP_WIDTH) + i;

	Interaction(currentLevel.roomObject[index].GetObjIndex(), index);
}

int BoulderMove(Object &boulder)
{
	switch (boulder.GetVSpeed())
	{
	case -1:
		boulder.SetDirection(1);
		break;
	case 0:
		switch (boulder.GetHSpeed())
		{
		case -1:
			boulder.SetDirection(3);
			break;
		case 0:
			break;
		case 1:
			boulder.SetDirection(2);
			break;
		}
		break;
	case 1:
		boulder.SetDirection(0);
		break;
	}
	
	if (boulder.GetHSpeed() != 0 || boulder.GetVSpeed() != 0)
	{
		MoveToSnap(boulder);
		if (boulder.GetX()%SPRITE_WIDTH == 0 && boulder.GetY()%SPRITE_HEIGHT == 0)
		{
			printf("\a");
			if (currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)].GetObjIndex() == 55)
			{
				int ani[4] = { 0, 0, 1, 1};
				currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)] = DefineObject(83,1,ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,boulder.GetY(),boulder.GetX()),0,0,boulder.GetY()/SPRITE_HEIGHT,boulder.GetX()/ 9,0,-16);
				currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)].DrawSprite(currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)],0);
				boulder.SetObjIndex(0);
				boulder.SetImageIndex(-2);
			}
			else if ((currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)].GetObjIndex() == -15 && !CheckFree(boulder.GetDirection(),boulder,0)) ||
				currentLevel.roomObject[((boulder.GetY()/SPRITE_HEIGHT)*MAP_WIDTH)+(boulder.GetX()/SPRITE_WIDTH)].GetObjIndex() != -15)
			{
				boulder.SetSpeed(0,0);
				boulder.SetX(boulder.GetX()/SPRITE_WIDTH);
				boulder.SetY(boulder.GetY()/SPRITE_HEIGHT);
			}
		}
	}
	boulder.SetDirection(0);
	boulder.SetImageIndex(-1);
	return 0;
}