//Includes
#include <curses.h>
#include <string.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include "GlobalVars.h"
#include "ImportMaps.h"
#include "Object.h"
#include "Interactions.h"

//Prototypes
WINDOW *create_win(int height, int width, int starty, int startx);
void DrawMenuOptions(WINDOW *local_win);
void destroy_win(WINDOW *local_win);
void PrintInMiddle(WINDOW *window, int y, int width, char* string, int color);
int do_selection(int sel, int men, WINDOW *local_win);
void SetAnimations( int a, int b, int c, int d);
void DrawMessage(int y, int x, int w, int h, char* message);

Object Player;

//Variables
WINDOW *my_win;
const int SPRITE_HEIGHT = 6;
const int SPRITE_WIDTH = 9;
int playerx, playery, ac_playery, ac_playerx;
char* word;

int selection = 0, ch = 0, whichMenu = 0;
int player_ani[4] = {0,1,2,1};

char* string;
//Options for the menus stored in arrays. If a menu is longer than the 4 options, a back
//"more" option should be made available
char* MAIN_MENU[] = { " Start New Game ",
	" Continue Saved Game ",
	" Maze Race ",
	" Exit Game " };
char* START_NEW_GAME[] = { " Overwrite Save 1 ",
	" Overwrite Save 2 ",
	" Overwrite Save 3 ", 
	" Back " };
char* CONTINUE[] = { " Continue Save 1 ",
	" Continue Save 2 ",
	" Continue Save 3 ", 
	" Back " };

int MainMenu()
{
	int row, col;
	getmaxyx(stdscr,row,col); //Get the max rows and columns
	
	my_win = create_win(11,40,(row/2)-15,(col/2)-20); //Create a window
	wborder(my_win, '|', '|', '-', '-', '*', '*', '*', '*');

	DrawMenuOptions(my_win); //Draw the options

	ch = getch();

	//Test for which key has been pressed
	switch(ch)
	{
	case KEY_UP:
		selection --;
		break;
	case KEY_DOWN:
		selection ++;
		break;
	case 13: //because KEY_ENTER returns \n
		return do_selection((selection % 4), whichMenu, my_win);
		break;
	case 27: //Escape
		gameState = -1;
		destroy_win(my_win);
	default:
		break;
	}

	return 1;
}

WINDOW *create_win(int height, int width, int starty, int startx)
{ //This creates a window of specified height and width at the y and x coordinates
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	//custom border for the window
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wnoutrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win)
{ //Destroy the window function
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	werase(local_win);
	wnoutrefresh(local_win);
	delwin(local_win);
}

void DrawMenuOptions(WINDOW *local_win)
{
	if (selection == 0) //This is needed because for some reason,
	{//modulos doesnt work with negative numbers that aren't of the multiple you are testing..
		selection = 4;
	}

	for (int i=0; i < 4; i++) //Check which menu to draw, and draw all 4 options
	{
		if ((selection % 4) == i) //Selected
		{
			switch(whichMenu)
			{
			case 0: // Main Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, MAIN_MENU[i], 1);
				break;

			case 1: // NewGame Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, START_NEW_GAME[i], 1);
				break;

			case 2: // ContinueGame Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, CONTINUE[i], 1);
				break;

			}			
		}
		else //Not selected
		{
			switch(whichMenu)
			{
			case 0: // Main Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, MAIN_MENU[i], 2);
				break;

			case 1: // NewGame Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, START_NEW_GAME[i], 2);
				break;

			case 2: // ContinueGame Menu
				PrintInMiddle(my_win, 2 + (i*2), 40, CONTINUE[i], 2);
				break;

			}	
		}
	}
	wrefresh(local_win); //Refresh the window
}

void PrintInMiddle(WINDOW *local_win, int y, int width, char* string, int color)
{// A simple function to print in the given color, in the middle of the given window (stdscr is no window)
	wattron(local_win, COLOR_PAIR(color));
	
	int middleX = (width/2)-strlen(string)/2;

	mvwprintw(local_win,y,middleX, "%s", string);

	wattroff(local_win, COLOR_PAIR(color));
	wrefresh(local_win); //Refresh the window
}

int do_selection(int sel, int men, WINDOW *local_win) //Do the action needed for the menu
{
	switch(men)
	{
	case 0: //Main Menu MENU
		switch(sel)
		{
		case 0://Start New Game
			printf("\a");
			whichMenu = 1;
			selection = 0;
			break;

		case 1://Continue Saved Game
			printf("\a");
			whichMenu = 2;
			selection = 0;
			break;

		case 2://MazeRace
			printf("\a");
			gameState = 1;
			destroy_win(local_win);
			//Create the player
			playerx = 1 * SPRITE_WIDTH;
			playery = 1 * SPRITE_HEIGHT;
			Player = DefineObject(13,-1,player_ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,playery,playerx),0,0,playery,playerx,0,0);
			//Draw the Map
			currentLevel.GenerateMaze();
			break;

		case 3://Exit Game
			printf("\a");
			return 0; //This value is sent all the way back to the MainGameLoop.cpp
			break; //and means the game loop is to be exited, and the game is quit

		}
		break;

	case 1: //Start New Game MENU
		switch(sel)
		{
		case 0://Overwrite save 1
			save = 1;
			printf("\a");
			gameState = 1;
			destroy_win(local_win);
			//Create the player
			playerx = 10 * SPRITE_WIDTH;
			playery = 4 * SPRITE_HEIGHT;
			Player = DefineObject(13,-1,player_ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,playery,playerx),0,0,playery,playerx,0,0);
			//Draw the Map
			return currentLevel.ImportMap(roomX,roomY,"playerhousebedroom1");
			break;

		case 1://Overwrite save 2
			save = 2;
			printf("\a");
			gameState = 1;
			destroy_win(local_win);
			//Create the player
			playerx = 10 * SPRITE_WIDTH;
			playery = 4 * SPRITE_HEIGHT;
			Player = DefineObject(13,-1,player_ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,playery,playerx),0,0,playery,playerx,0,0);
			//Draw the Map
			return currentLevel.ImportMap(roomX,roomY,"playerhousebedroom1");
			break;

		case 2://Overwrite save 3
			save = 3;
			printf("\a");
			gameState = 1;
			destroy_win(local_win);
			//Create the player
			playerx = 10 * SPRITE_WIDTH;
			playery = 4 * SPRITE_HEIGHT;
			Player = DefineObject(13,-1,player_ani,create_win(SPRITE_HEIGHT,SPRITE_WIDTH,playery,playerx),0,0,playery,playerx,0,0);
			//Draw the Map
			return currentLevel.ImportMap(roomX,roomY,"playerhousebedroom1");
			break;

		case 3://Back
			printf("\a");
			whichMenu = 0;
			selection = 0;
			break;

		}
		break;
	case 2: //Continue Saved Game MENU
		switch(sel)
		{
		case 0://Continue Save 1

			break;

		case 1://Continue Save 2
			printf("\a");
			break;

		case 2://Continue Save 3
			printf("\a");
			break;

		case 3://Back
			printf("\a");
			whichMenu = 0;
			selection = 1;
			break;

		}
		break;

	}
	return 1;
}

int DrawBackground(char* file, int doGet)
{
	std::string word;
	std::ifstream fileName;
	fileName.open(file); //Open the File
	fileName >> word;

	if (fileName.is_open())
	{
		while (fileName.good())
		{
			for (int i = 0; i < 66; i ++)//66 is the # of rows
			{
				for (int j = 0; j < 199; j ++)//199 is the # of columns
				{
					if (word[j] != 'G')
						mvwaddch(stdscr,i,j,word[j]);
				}
				fileName >> word;
			}
			fileName.close(); //Close the file
		}
	}
	else
	{
		printf("The File the computer is trying to load doesn't exist\n"); //Apologize
		printf("Try re-installing the game\n");
		return 0;
	}

	wnoutrefresh(stdscr);
	doupdate();

	if (doGet)
	{
		getch();
		gameState = 0;
	}
	return 1;
}

void DrawMessage(int y, int x, int w, int h, char* message)
{
	int row, col;
	getmaxyx(stdscr,row,col); //Get the max rows and columns
	int _x = x, _y = y;

	if (x == -1)
		_x = (col/2)-(w/2);
	if (y == -1)
		_y = (row/3)-(h/2);

	WINDOW *shadow_win;
	WINDOW *local_win;

	shadow_win = create_win(h+2,w+2,_y-1,_x-1);
	local_win = create_win(h,w,_y,_x);

	printf("\a");
	
	for (int i=0; i<h; i++)
	{
		for (int j=0; j<(w-4); j++)
		{
			if (i*(w-4)+j < strlen(message))
				mvwaddch(local_win,i+1,j+2,message[(i*(w-4))+j]);
		}
	}
	
	wborder(local_win, '|', '|', '-', '-', '*', '*', '*', '*');
	
	wrefresh(shadow_win);
	wrefresh(local_win);
	
	while (!EnterWasPressed())
		local_win = local_win;

	destroy_win(local_win);
}

int DrawInventory(char* title, int item, int price)
{
	keypad(stdscr, TRUE);
	
	WINDOW *shadow_win;
	WINDOW *local_win;
	
	shadow_win = create_win(42,122,1,1);
	local_win = create_win(40,120,2,2);

	printf("\a");
	
	mvwprintw(local_win,3,4,title);

	mvwprintw(local_win,6,4,"Press <ESC> to exit the game");
	mvwprintw(local_win,8,4,"Press <F1> to save your game");
	mvwprintw(local_win,10,4,"Press <F2> to return to the Main Menu");

	
	mvwprintw(local_win,14,4,"Helpful Information:"); // Help information
	mvwprintw(local_win,16,4,"Arrow Keys to move, and Enter to interact with objects"); // Help information
	mvwprintw(local_win,18,4,"[] : Walk into blocks to push them."); // Help information
	mvwprintw(local_win,19,4,"// : Walk on ice to slide."); // Help information
	if (item != -1)
		mvwprintw(local_win,12,4,"Press <Enter> to buy a %s for %d gold",global_item[item],price);
	
	mvwprintw(local_win,3,60,"Gold: %d", money);
	mvwprintw(local_win,3,80,"Save %d", save);
	mvwprintw(local_win,3,100,"Floor %d of %d",progress,totalfloors);
	
	wborder(local_win, '|', '|', '-', '-', '*', '*', '*', '*');
	nonl();

	int ch = getch();
	wrefresh(shadow_win);
	wrefresh(local_win);
	
	while (!InventoryWasPressed())
	{
		//Test for which key has been pressed
		switch(ch)
		{
		case KEY_F(1):
			//Damian, you need to add the save game here
			printf("\a");
			break;

		case KEY_F(2):
			gameState = 0;
			printf("\a");
			return 1;
			break;

		case 27: //Escape
			return 0;
			break;

		default:
			break;
		}
		
		ch = getch();
		wrefresh(shadow_win);
		wrefresh(local_win);
	}
	destroy_win(local_win);

	return 1;
}