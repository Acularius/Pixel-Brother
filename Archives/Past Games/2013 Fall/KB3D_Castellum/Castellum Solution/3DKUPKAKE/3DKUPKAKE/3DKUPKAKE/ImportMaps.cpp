//Includes
#include <curses.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include "ImportMaps.h"
#include "CreateObject.h"
#include "DrawWindows.h"
#include "GlobalVars.h"
#include "MazeFilter.h"

//Prototypes
std::string int_to_string(int number);
int CurrentCell(char xory, int SmallIndex);
bool Visited(int x, int y);
int SmallIndex(int x, int y);

//Variables
const int MAP_WIDTH = 22;
const int MAP_HEIGHT = 11;

//MazeGeneration
bool visited[10][5]; //each cell
int currentCell;
int visitedCells;
int randomNum;
int randomCells[4];
int cX, cY, toErase;

int Level::ImportMap(int x, int y, std::string mapName)
{
	std::string file;
	int word;

	if (mapName == "NULL") //Concatenation process
	{
		std::string result = "Maps\\" + int_to_string(x) + "," + int_to_string(y) + ".txt";
		//Concatate the file location.
		file = result;
		id = 1;
	}
	else
	{
		std::string result = "Maps\\" + mapName + ".txt";
		//Concatate the file location
		file = result;
		id = 0;
	}

	std::ifstream fileName;
	fileName.open(file); //Open the File
	if (fileName.is_open())
	{
		while (fileName.good())
		{
			for (int i=0; i < MAP_HEIGHT; i++)
			{
				for (int j=0; j < MAP_WIDTH; j++)
				{
					fileName >> word;
					DefineObjects(word,i,j);
				}
			}
			fileName.close(); //Close the file
		}
	}
	else
	{
		printf("The Map File the computer is trying to load doesn't exist\n"); //Apologize
		printf("Try re-installing the game\n");
		getch();
		return 0; //Close game if can't import file
	}
	return 1;
}

void Level::ToggleLights()
{
	lights = !lights;
}

std::string int_to_string (int number)
{
	std::stringstream ss;
	ss << number;
	std::string newString = ss.str();
	return newString;
}

 /*	From Wikipedia - Recursive Backtrack method

	Make the initial cell the current cell and mark it as visited
    While there are unvisited cells
        If the current cell has any neighbours which have not been visited
            Choose randomly one of the unvisited neighbours
            Push the current cell to the stack
            Remove the wall between the current cell and the chosen cell
            Make the chosen cell the current cell and mark it as visited
        Else if stack is not empty
            Pop a cell from the stack
            Make it the current cell
        Else
            Pick a random cell, make it the current cell and mark it as visited */

void Level::GenerateMaze()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 5; j++)	//everything will be a wall (1)
			visited[j][i] = false;
	visitedCells = 1;

	//make a blank maze of all walls
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 22; j++)	//everything will be a wall (1)
		{
			if (j != 21)
				currentLevel.roomObject[(i*22)+j].SetObjIndex(1);
			else
				currentLevel.roomObject[(i*22)+j].SetObjIndex(0);
		}

	//"Make the initial cell the current cell and mark it as visited"
	visited[0][0] = true;
	currentCell = 0;
	currentLevel.roomObject[23].SetObjIndex(0);
	
	srand (static_cast<unsigned int>(time(NULL))); //new random number

	//"While there are unvisited cells"
	while (visitedCells != 50)
	{
		cX = CurrentCell('x', currentCell);
		cY = CurrentCell('y', currentCell);

		//"If the current cell has any neighbours which have not been visited"
		if (!(Visited(cX,cY-1) == true && Visited(cX,cY+1) == true && Visited(cX+1,cY) == true && Visited(cX-1,cY) == true))
		{
			randomNum = 0;
			//"Choose randomly one of the unvisited neighbours"
			if (Visited(cX,cY-1) == false) // Above
			{
				randomCells[randomNum] = 0;
				randomNum ++;
			}
			if (Visited(cX,cY+1) == false) // Below
			{
				randomCells[randomNum] = 1;
				randomNum ++;
			}
			if (Visited(cX+1,cY) == false) // Right
			{
				randomCells[randomNum] = 2;
				randomNum ++;
			}
			if (Visited(cX-1,cY) == false) // Left
			{
				randomCells[randomNum] = 3;
				randomNum ++;
			}

			randomNum = rand() % randomNum;
			//"Push the current cell to the stack"
			//"Remove the wall between the current cell and the chosen cell"

			switch (randomCells[randomNum])
			{
			case 0:
				currentCell = SmallIndex(cX,cY-1);
				cY --;
				toErase = (((cY*2)+2)*22)+(cX*2)+1;
				currentLevel.roomObject[toErase].SetObjIndex(0);
				break;
			case 1:
				currentCell = SmallIndex(cX,cY+1);
				cY ++;
				toErase = ((cY*2)*22)+(cX*2)+1;
				currentLevel.roomObject[toErase].SetObjIndex(0);
				break;
			case 2:
				currentCell = SmallIndex(cX+1,cY);
				cX ++;
				toErase = (((cY*2)+1)*22)+(cX*2);
				currentLevel.roomObject[toErase].SetObjIndex(0);
				break;
			case 3:
				currentCell = SmallIndex(cX-1,cY);
				cX --;
				toErase = (((cY*2)+1)*22)+(cX*2)+2;
				currentLevel.roomObject[toErase].SetObjIndex(0);
				break;
			}
			//"Make the chosen cell the current cell and mark it as visited"
			visited[CurrentCell('x', currentCell)][CurrentCell('y', currentCell)] = true;

			toErase = (((cY*2)+1)*22)+((cX*2))+1;
			currentLevel.roomObject[toErase].SetObjIndex(0);
			visitedCells ++;
		}
		//"Else if stack is not empty"
		else
		{
			for(int i = 0; i < 10; i ++)
			{
				for(int j = 0; j < 5; j ++)
				{
					if (visited[i][j] == true && !(Visited(i,j-1) == true && Visited(i,j+1) == true && Visited(i+1,j) == true && Visited(i-1,j) == true))
					{
						currentCell = SmallIndex(i,j);
					}
				}
			}
		}
	}
	MazeFilter();
}

int CurrentCell(char xory, int index)
{
	if (xory == 'x')
	{
		return index % MAP_WIDTH;
	}
	else if (xory == 'y')
	{
		return (index - (index % MAP_WIDTH)) / 10;
	}
	return 0;
}

bool Visited (int x, int y)
{
	if (x >= 0 && x <= 9 && y >= 0 && y <= 4)
		return visited[x][y];
	return true;
}

int SmallIndex(int x, int y)
{
	return (y * MAP_WIDTH) + x;
}

Level::Level()
{
	lights = true;
}