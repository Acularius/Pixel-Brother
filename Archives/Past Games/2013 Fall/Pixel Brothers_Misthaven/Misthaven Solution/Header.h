//====================================================================================================================================================
//	   Once Upon a Time in	   _____  .___  _______________________ ___    _________   _______________ _______										||
//	    					  /     \ |   |/   _____/\__    ___/   |   \  /  _  \   \ /   /\_   _____/ \      \										||
//	    					 /  \ /  \|   |\_____  \   |    | /    ~    \/  /_\  \   Y   /  |    __)_  /   |   \									||
//	    					/    Y    \   |/        \  |    | \    Y    /    |    \     /   |        \/    |    \									||
//	    					\____|__  /___/_______  /  |____|  \___|_  /\____|__  /\___/   /_______  /\____|__  /									||
//	    						    \/            \/                 \/         \/                 \/         \/                                    ||
//====================================================================================================================================================


				#include <iostream>
				#include <stdio.h>
				#include <Windows.h>
				#include <fstream>
				#include <conio.h>
				#include <string.h>
				#include <cstring>
				#include <ctime>
				#include <cstdlib>

				#include <MMSystem.h> 
				#include <sstream>

				#include <fmod.h>
				#include <fmod.hpp>

				#pragma comment(lib, "user32") // Used for Lockdownbrowser.

				using namespace std;


//====================================================================================================================================================
//		FUNCTION PROTOTYPES:                                                         
//====================================================================================================================================================


					int playSound();

					int playBeepSound();

					void setwindow(short Width, short Height);

					void setFontSize();

					void gamebody();

					void ColorAscii(int INTASCII, WORD text_color); 

					void PRINTMAPCHAR (char mapcharnum);

					void printavatars (int avatarnum);

					void txtloader ();

					void gotoxy(int x, int y);

					void printstory (int numberofnewlines, int to, int from);

					void filesave (int saveorload);

					void progressmenu();

					void gamemenu(int opt);

					void gamemenuexe(int opt);

					void printheader ();

					void powers(int opt);

					void printmap (int opt);

					void directionfunct(char DIRECTION, int opt,bool reverse);

					bool checkXYvicinity(int X, int Y);

					bool checkEnemyvicinity();

					bool checkObjvicinity(char Obj);

					void enemychase();

					void RandObject (char Obj,int mapnum);

					void levelmenu();

					void triggers_runtime(int PlayerPosX, int PlayerPosY);

					void triggers_hometown (int PlayerPosX, int PlayerPosY);

					void triggers_level1 (int PlayerPosX, int PlayerPosY);

					void triggers_level2 (int PlayerPosX, int PlayerPosY);

					void dialoguebox ();

					void dialoguetrigger();

					//void storytrigger();

					void deathanimation ();





//====================================================================================================================================================
//		END OF CODE                                                                       (All work programmed by Aaron Alphonso, 2013)
//====================================================================================================================================================