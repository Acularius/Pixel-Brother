//====================================================================================================================================================
//	   Once Upon a Time in	   _____  .___  _______________________ ___    _________   _______________ _______										||
//	    					  /     \ |   |/   _____/\__    ___/   |   \  /  _  \   \ /   /\_   _____/ \      \										||
//	    					 /  \ /  \|   |\_____  \   |    | /    ~    \/  /_\  \   Y   /  |    __)_  /   |   \									||
//	    					/    Y    \   |/        \  |    | \    Y    /    |    \     /   |        \/    |    \									||
//	    					\____|__  /___/_______  /  |____|  \___|_  /\____|__  /\___/   /_______  /\____|__  /									||
//	    						    \/            \/                 \/         \/                 \/         \/                                    ||
//====================================================================================================================================================


				#include "Header.h"


//====================================================================================================================================================
//		GLOBAL VARIABLES:                                                          (0) - All global variables.
//====================================================================================================================================================


		// SAVE FILE DATA.
		int Xpos=21,Ypos=32;			// Map Positioning. 
		int PlayerPosX, PlayerPosY;     // Character Positioning.
		int Health;						// Health.
		int stagenum;					// Stage Number
		int currency;					// Currency

		// LOADED GRAPHICS.
		char mapread[65][145];			// Map - Hometown
		char mapread2[4*78][223];		// Map - Levels (x-78)
		char mapread2copy[4*78][223];   // Map - Levels Copy (Used to reset map).
		char avatar[17][72];			// Avatars.
		char logoread[9][64];			// Logo.
		char inventory[15][80];			// Inventory.
		char gamestory[500][65];		// Game Story. 

		// RUNTIME VARIABLES.
		int EnemyPosX, EnemyPosY;       // Enemy Positioning. 
		int turn, turncurrency;			// Turns, Turn Currency.
		int ParalizeEnemy;				// Play Ability - Freeze Enemy.
		int randv;						// Enemy probability value. (Function 15).
		bool charactermoved=1;			// Freeze game if no movemnt. (Function 13).
		bool op;						// Control Invert Trap Switch.
		bool PlayerInput;				// Input needs to be turned OFF for some situations.

		//PROGRESS VARIABLES.
		bool ITEM_necklace=false;       // ITEM: Necklace.
		bool ITEM_photograph=false;     // ITEM: Photograph.
		bool ITEM_scarf=false;			// ITEM: Scarf.
		bool ITEM_knife=false;			// ITEM: Knife.


//====================================================================================================================================================
//		CHANGE DEFAULT CONSOLE SIZE AND FONT:                                      (Changes default console window size and font size to 12x16)
//====================================================================================================================================================

		void setwindow(short Width, short Height) 
		{ 
			string first,second; 
		    stringstream ss; 
			ss << Width; first = ss.str(); //first = first.c_str ();

			stringstream sd; 
			sd << Height; 
			second = sd.str(); //second = second.c_str ();

			string final = "mode " + first + ","+second;

			system( final.c_str()); //Set mode to ensure window does not exceed buffer size 
			
			SMALL_RECT WinRect = {0, 0, Width, Height}; //New dimensions for window in 8x12 pixel chars 
			SMALL_RECT* WinSize = &WinRect; 
			SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize); //Set new size for window

		}


		void setFontSize() 
		{ 
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
			PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX(); 
			lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX); 
			GetCurrentConsoleFontEx(hConsole, 0 , lpConsoleCurrentFontEx); 

			lpConsoleCurrentFontEx->dwFontSize.X = 12; 
			lpConsoleCurrentFontEx->dwFontSize.Y = 16; 

			SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx); 
		}

//====================================================================================================================================================
//		MAIN FUNCTION:                                                             (1) - Main() : Menu & Prestartup function calls.
//====================================================================================================================================================


			void main ()
			{ 
				setwindow(80, 27);
				setFontSize();


				playSound();
				txtloader();

			    gamemenuexe(1);

				printstory(5,0,7);
				printstory(5,7,14);

				system("CLS");
				cout<<"\n\n\n\n\t\t CONTROLS \n\n\n\n\t\t w,a,s,d - Controls \n\n\t\t x - In-game menu \n\n\t\t e - Progress \n\n\t\t b - Spellbook";
				cout<<"\n\n\n\t\t MAKE SURE YOU TALK TO THE TOWNSFOLK !! "; PRINTMAPCHAR('L'); cout<<" "; PRINTMAPCHAR('Q'); cout<<"\n\n\n\n\t";
				system("pause");

			    gamebody();
			 }

//====================================================================================================================================================
//		COLORING FUNCTION:                                                         (2) - Used to add color to ascii in the next function.
//====================================================================================================================================================
			

		 void ColorAscii(int INTASCII, WORD text_color) 
		 {
				HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

				WORD default_dos_color = FOREGROUND_RED   |
										 FOREGROUND_GREEN |
										 FOREGROUND_BLUE  |
										 FOREGROUND_INTENSITY;

				SetConsoleTextAttribute(output_handle, text_color);

				cout<<char(INTASCII);

			    SetConsoleTextAttribute(output_handle, default_dos_color);
		 }

//====================================================================================================================================================
//		ASCII CHARACTER MAPPING SWITCH:                                            (3) - Char to ASCII: Parsing, Printing, Color, Constraint.
//====================================================================================================================================================
	

		void PRINTMAPCHAR (char mapcharnum)
		{  switch(mapcharnum)
		   {  

			 //************************************* NUMERICALS ( NON CONSTRAINED CHARACTERS) *******************************************

			 case '.': {cout<<" ";break;}																			 //.   WALKING PATH
			 case '_': {ColorAscii(char(219),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);break;}	     //_    OUTER SPACE
	         case '1': {ColorAscii(char(176),FOREGROUND_GREEN | FOREGROUND_INTENSITY);break;}						 //1  ░ 
		     case '2': {cout<<char(177);break;}																         //2   ▒
		     case '3': {cout<<char(178);break;}																	     //3    ▓
			 case '4': {cout<<char(219);break;}																	     //4    █
			 case '5': {ColorAscii(char(03), FOREGROUND_RED | FOREGROUND_INTENSITY);break;}				     		 //5    ♥
			 case '6': {ColorAscii(char(03), FOREGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);break;}	 //6    STORY ITEMS
			 case '7': {ColorAscii(char(176), BACKGROUND_RED | FOREGROUND_GREEN );break;}                             //    MUD ROAD																 //7    OFF
			 case '8': {ColorAscii(char(15),FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);break;}		 //8    ♣
			 case '9': {ColorAscii(char(04), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);break;}		 //9    ♦
			 case '0': {ColorAscii(char(178),FOREGROUND_RED | BACKGROUND_BLUE);break;}                               //0    Traps


			 //************************************* ALPHABETS ( NON CONSTRAINED CHARACTERS) *******************************************

			case 'A': {cout<<" ";break;}																    		 //A    SPACE
			case 'B': {cout<<char(176);break;}																		 //B  ░
			case 'C': {cout<<char(177);break;}																		 //C   ▒
			case 'D': {cout<<char(178);break;}																		 //D    ▓
			case 'E': {cout<<char(219);break;}																		 //E    █
			case 'F': {cout<<char(223);break;}																		 //F    ▀
			case 'G': {cout<<char(220);break;}																		 //G    ▄
			case 'H': {cout<<char(206);break;}																		 //H    ╬
			case 'I': {cout<<char(186);break;}																		 //I    ║
			case 'J': {ColorAscii(char(176),FOREGROUND_GREEN | FOREGROUND_INTENSITY);break;}		     			 //J    Lite Green
			case 'K': {ColorAscii(char(176),FOREGROUND_GREEN);break;}       				     			    	 //K    Dark Green
			case 'L': {ColorAscii(char(02), FOREGROUND_RED  | FOREGROUND_INTENSITY);break;}	                         //L    NPC.
			case 'M': {ColorAscii(char(176),BACKGROUND_GREEN  | FOREGROUND_BLUE);break;}							 //B  ░
			case 'N': {ColorAscii(char(177),BACKGROUND_GREEN  | FOREGROUND_BLUE);break;}	     					 //C   ▒
			case 'O': {ColorAscii(char(178),BACKGROUND_GREEN  | FOREGROUND_BLUE);break;}							 //D    ▓
			case 'P': {ColorAscii(char(219),FOREGROUND_RED  | FOREGROUND_GREEN | FOREGROUND_BLUE);break;}			 //E    █
		    case 'Q': {ColorAscii(char(01), FOREGROUND_BLUE | FOREGROUND_RED   | FOREGROUND_GREEN);break;}           //     NPC (Tutorial).
			case 'R': {ColorAscii(char(176), BACKGROUND_RED | FOREGROUND_BLUE  | FOREGROUND_GREEN );break;}          //     DEAD GRASS.
			case 'V': {ColorAscii(char(03), FOREGROUND_RED | FOREGROUND_INTENSITY);break;}						     //V    ♥
			case 'W': {ColorAscii(char(178), FOREGROUND_GREEN | FOREGROUND_BLUE);break;}							 //W    WATER

		  }
		}

//====================================================================================================================================================
//		PRINT AVATAR FUNCTION:                                                     (4) - Prints Unformatted text in formatted form. 
//====================================================================================================================================================


			void printavatars (int avatarnum)
			{ 
				LockWindowUpdate(GetConsoleWindow());
			    system("CLS");
			    cout<<"\n\n\n\n\t\t\t     ";
				for(int i=0;i<17;i++)			
				{  
					for(int j=((18*avatarnum)-18);j<(18*avatarnum);j++)
			        {  PRINTMAPCHAR(avatar[i][j]); }
				    cout<<endl<<"\t\t\t     ";
				}
			    LockWindowUpdate(NULL);
			    Sleep(500);
			}	

//====================================================================================================================================================
//		COMPLETE GAME FILE LOADER:                                                 (5) - Load maps, logos, assets & defauly Initialization.
//====================================================================================================================================================
		

			void txtloader ()
			{ 
			 //********************************************* AVATAR FILE LOADING (A) *************************************************

				    ifstream INAVATAR; 
					INAVATAR.open("avatar.txt");
					for(int i=0;i<17;i++)	
					{ 
						for(int j=0;j<72;j++)
					    { INAVATAR>>avatar[i][j]; }
					}
					INAVATAR.close();						   printavatars(1); // 25 % Loading Complete. 
				
			 //********************************************** LOGO FILE LOADING (B) ***************************************************

					ifstream INLOGO; 
					INLOGO.open("logo.txt");
					for(int i=0;i<9;i++)			
					{
						for(int j=0;j<64;j++)
						{ INLOGO>>logoread[i][j];}
				    }
					INLOGO.close();

			 //****************************************** MAP - HOME TOWN - FILE LOADING (C) *****************************************
					
					ifstream INMAP;	
					INMAP.open("map - hometown.txt");
					for(int i=0;i<65;i++)			
					{
						for(int j=0;j<150;j++)
						{INMAP>>mapread[i][j];}
					}
					INMAP.close();							   printavatars(2); // 50% Loading Complete. 

			 //****************************************** MAP - LEVEL 1 - FILE LOADING (D) *******************************************

					ifstream INMAP2;
					INMAP2.open("map - levels.txt");
					for(int i=0;i<4*78;i++)	//2 Levels		
					{
						for(int j=0;j<223;j++)
						{INMAP2>>mapread2[i][j];}
						
					}
					
					INMAP2.close();

			 //********************************************* GAME STORY - FILE LOADING (E) *******************************************

					ifstream INSTORY;
					INSTORY.open("story.txt");
					for(int i=0;i<500;i++)			
					{
						for(int j=0;j<65;j++)
						{INSTORY.get(gamestory[i][j]);}
					}
					INSTORY.close();							printavatars(3); // 75% Loading Complete. 

			 //******************************************* DEFAULT INITIALIZATION BELOW (F)*******************************************


			   		for(int i=0;i<4*78;i++)			// Creates a copy of the levels to reset after player leaves region. 
			        {  for(int j=0;j<223;j++)
			            {mapread2copy[i][j]=mapread2[i][j];}  }

						stagenum=1;
						currency=0;
						Health=5;
						op=true;
						PlayerInput=true;
						
																printavatars(4); //100% Loading Completed.
			 }
			
//====================================================================================================================================================
//		GOTO X,Y FUNCTION:                                                         (6) - Windows move console curser to screen position (x,y).
//====================================================================================================================================================


			void gotoxy(int x, int y)
		  {
				static HANDLE h = NULL;  
				if(!h)
				h = GetStdHandle(STD_OUTPUT_HANDLE);
				COORD c = { x, y };  

				SetConsoleCursorPosition(h,c);
		  }

//====================================================================================================================================================
//		GAME STORY FUNCTION:													   (7) - Fully formats bulk text into paragraphs and positions it.
//====================================================================================================================================================


			void printstory (int numberofnewlines, int from, int to) 
			{  
						 //********************************************* CHAINGING TEXT COLOR.
						 HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE); 
						 WORD default_dos_color = FOREGROUND_RED	  | 
					  	 						  FOREGROUND_GREEN | 
												  FOREGROUND_BLUE  | 
												  FOREGROUND_INTENSITY;

						 SetConsoleTextAttribute(output_handle, FOREGROUND_BLUE | FOREGROUND_RED);


						 //********************************************* INITIAL FORMATING ('numberofnewlines').
						 system("CLS");
						 for (int i=0;i<numberofnewlines;i++)
						 { cout<<"\n"; }
						   cout<<"\t ";


						//********************************************* VARIABLES FOR PARAGRAPH FORMATTING.
						int j=0;
						bool newlineencountered=0;


						//********************************************* PRINTS OUT THE STORY PARAGRAPH.
						for(int i=from;i<to;i++) 		
					    {	j=0; 
							newlineencountered=0;
							while(j<65)
							{  if(isspace(gamestory[i][j])&&j>60)
							   { cout<<"\n\n\t"; 
								 newlineencountered=1; 
								 Sleep(150); }
							if(gamestory[i][j]=='#')
								cout<<" ";
							else
							    cout<<gamestory[i][j];
							j++;
							}
							if (newlineencountered==0)
							{cout<<"\n\n\t";
							Sleep(150);} 
						}
						
						//********************************************* SETTING COLORS TO DEFAULT.
						SetConsoleTextAttribute(output_handle, default_dos_color);
						cout<<" ";
						system("pause");
						system("CLS");
			}	

//====================================================================================================================================================
//		CUT SCENE LOOPS:    (***Not Used***)                                       (X) - Menu, continue, new game etc.
//====================================================================================================================================================


			/*void cutscene(int x1, int y1, int x2, int y2, int mapx, int mapy) //(10,50,40,50,30,50)
			{ 
			  bool decrement=false; int XFROMPOS=x1, XTOPOS=x2, YPOS=y2;
			  if(x1>x2)
			  { decrement=true;
			     XFROMPOS=x2;
				 XTOPOS=x1; }
			  while(XFROMPOS<XTOPOS)
			  { Sleep(100);
			   	LockWindowUpdate(GetConsoleWindow());
				system("CLS");
				cout<<"\t";
				for(int i=mapx; i<(20+mapx); i++)
				{for (int j=mapy; j<(64+mapy); j++)
				{if(i==XFROMPOS && j==YPOS)
				    cout<<char(01);
				 else
					PRINTMAPCHAR(mapread[i][j]);}
			    cout<<endl<<"\t";}
					    XFROMPOS++;
					LockWindowUpdate(NULL);}
			  }*/

//====================================================================================================================================================
//		SAVE AND LOAD FUNCTION:                                                    (8) - SAVE = filesave(1) . LOAD = filesave(0).
//====================================================================================================================================================


			void filesave (int saveorload)
			{   
				//********************************************* (0) LOAD GAME.
				if ( saveorload==0 ) 
				{  
					ifstream INFILE;
					INFILE.open("save.txt");
					INFILE>>Xpos;
					INFILE>>Ypos;
					INFILE>>stagenum;
					INFILE>>currency;
					INFILE>>Health;
					INFILE>>ITEM_necklace;
				    INFILE>>ITEM_knife;
					INFILE>>ITEM_photograph;
					INFILE>>ITEM_scarf;
					INFILE.close(); 
				}
		  
			  //********************************************* (1) SAVE GAME.
			  if ( saveorload==1 ) 
				 { 
					ofstream OUTFILE;
					OUTFILE.open("save.txt");
					OUTFILE<<Xpos<<endl;
					OUTFILE<<Ypos<<endl;
					OUTFILE<<stagenum<<endl;
					OUTFILE<<currency<<endl;
					OUTFILE<<Health<<endl;
					OUTFILE<<ITEM_necklace<<endl;
				    OUTFILE<<ITEM_knife<<endl;
					OUTFILE<<ITEM_photograph<<endl;
					OUTFILE<<ITEM_scarf;
					OUTFILE.close(); 
				  }

				//********************************************* (1) SAVE GAME.
				if ( saveorload==2 ) 
				 { 
					ofstream OUTFILE;

					OUTFILE.open("save.txt");
					OUTFILE<<16<<endl;
					OUTFILE<<18<<endl;
					OUTFILE<<1<<endl;
					OUTFILE<<100<<endl;
					OUTFILE<<6<<endl;
					OUTFILE<<0<<endl;
				    OUTFILE<<0<<endl;
					OUTFILE<<0<<endl;
					OUTFILE<<0;

					OUTFILE.close();
				 }
			}

//====================================================================================================================================================
//	    PROGRESS MENU:                                                             (9) - Prints progress scree, Shows Key items found.
//====================================================================================================================================================


			void progressmenu()
			{ 
				system("CLS");
				cout<<"\n\n\n\n\n\n";

				cout<<"\t\t\tITEMS FOUND ("; PRINTMAPCHAR('6'); cout<<")\n\n\n\n";

				if(ITEM_necklace==true)
					cout<<"\t\t\t1. NECKLACE "<<"\n\n";
				else
					cout<<"\t\t\t1. xxxxxxxx "<<"\n\n";

				if(ITEM_knife==true)
					cout<<"\t\t\t2. KNIFE    "<<"\n\n";
				else
					cout<<"\t\t\t2. xxxxxxxx "<<"\n\n";

				if(ITEM_photograph==true)
					cout<<"\t\t\t3. PHOTO    "<<"\n\n";
				else
					cout<<"\t\t\t3. xxxxxxxx "<<"\n\n";

				if(ITEM_scarf==true)
					cout<<"\t\t\t4. SCARF    "<<"\n\n";
				else
					cout<<"\t\t\t4. xxxxxxxx "<<"\n\n";

				cout<<"\n\n\t\t";
				system("pause");

			}

//====================================================================================================================================================
//	    MAIN & IN GAME MENU:                                                      (10) - Only prints: main / in-game menu. 
//====================================================================================================================================================


			void gamemenu(int opt)
			{  
				 system("CLS");
				

				 
    			    cout<<"\n\n\n\t      Once upon a time at\n\n\t";

				    for(int i=0;i<9;i++) // **** Printing Game Logo. 
				    {  for(int j=0;j<64;j++)
					   {  PRINTMAPCHAR(logoread[i][j]); }
					   cout<<endl<<"\t"; }

				//********************************************* MAIN GAME MENU.
				if (opt==1)
				{
					cout<<"\n\n\n";
					cout<<"\t\t 1. CONTINUE GAME\n\n";
					cout<<"\t\t 2. NEW GAME\n\n";
					cout<<"\t\t 3. EXIT GAME\n\n\t\t ";
				 }

				 //********************************************* IN GAME MENU.
				 if (opt==2)
				 {  
					cout<<"\n\n\n\t\t GAME PAUSED\n\n";
				    cout<<"\t\t 1. CONTINUE\n\n";
					cout<<"\t\t 2. SAVE GAME\n\n";
					cout<<"\t\t 3. SAVE & EXIT\n\n\t\t ";
				 }
			}

//====================================================================================================================================================
//	    MAIN & IN GAME MENU EXECUTIONS:                                           (11) - Executes all main / in-game menu options.
//====================================================================================================================================================


			void gamemenuexe(int opt)
			{   
				char confirm;
				int choice;

				restart:

			    gamemenu(opt);
				cin>>choice;

				if( opt==1)
				{  
					switch(choice)
				  { 
					     case 1: { filesave(0); break; }

						 case 2: {  cout<<"\n\t\t Are you sure? All previous Data will be lost! (Y/N)";

									cin>>confirm;

									if( confirm=='Y' || confirm=='y')
									{ filesave(2); 
									  filesave(0); }

									else
								        goto restart;
									
								    break;
								  }
						  case 3: {  cout<<"\n\t\t Are you sure you want to exit game? (Y/N)";
									cin>>confirm;
									if( confirm=='Y' || confirm=='y')
										exit(1);
									else
							            goto restart; break;}

						  default: goto restart;
					}}

				
				if( opt==2)
				{  
					switch(choice)
				  { 
					      case 1: { break; }

						  case 2: {  filesave(1);
							         cout<<"Game Saved!"; 
									 _getch(); break; }

						  case 3: {  cout<<"\n\t\t Are you sure you want to save and exit game? (Y/N)";
									cin>>confirm;
									if( confirm=='Y' || confirm=='y')
										{ filesave(1);
									      exit(1); }
									else
										goto restart;break;}

						  default: goto restart;
					}}
			}

//====================================================================================================================================================
//		PRINT HEADER:                                                             (12) - Prints Header: Health, Currency, Items, Turns.
//====================================================================================================================================================


			void printheader ()
			{ 
				  cout<<"\n\n\t HEALTH ";
				  for (int i=0; i<Health; i++) 
				  PRINTMAPCHAR ('V');

				  cout<<"\t     PLASMA ";
				  PRINTMAPCHAR ('9');
				  cout<<currency;
				  

				  cout<<"\t";
				  PRINTMAPCHAR('6');
				  { cout<<":"<<(int(ITEM_necklace)+int(ITEM_knife)+int(ITEM_photograph)+int(ITEM_scarf))<<"/4"; }


			      if (stagenum==2)
				  { 
					cout<<"\t     TURNS ";
				    cout<<char(01);
				    cout<<turncurrency; 
				  }

				  cout<<"\n";
				  //cout <<"\tx:"<<PlayerPosX<<"("<<Xpos<<") "<<"y:"<<PlayerPosY<<"("<<Ypos<<")\n"; //Player Coordinate Check. (OFF - For developer.)
				  
			}

//====================================================================================================================================================
//		SPELL BOOK:																  (13) - In-Game Spellbook menu with Operations.
//====================================================================================================================================================


		void powers(int opt)
		{  
		   int PowerChoice;
		   char Confirm;

		   if (opt==1)
		   {     menu: //GOTO LABEL. 

			     system("CLS");
				 printheader();

				 cout << "\n\n\n\t\tSPELL BOOK:"; cout<<"\t\t You Have (" << turncurrency << " turns)\n\n";
				 cout << "\t\t1. Freeze Enemy for some time: (15"; PRINTMAPCHAR('9') ; cout<< ")(100 turns)\n\n";
				 cout << "\t\t2. Destroy Most of the traps: (15"; PRINTMAPCHAR('9') ; cout<< ")(110 turns)\n\n";
				 cout << "\t\t3. Return Home to Misthaven : (15"; PRINTMAPCHAR('9') ; cout<< ")\n\n";
				 cout << "\t\t4. Exit SpellBook!\n\n\t\t>> ";
					 
				 cin>>PowerChoice;

			switch(PowerChoice)
			{     
				//**************************************************** CASE 1 ***********************************************************

				  case 1:    { cout<<"\n\n\tSpend (30";PRINTMAPCHAR('9');cout<<") to paralize the spirit? (Y/N)\n\n\t>>";
						       Confirm=_getch();
						       
							   if ( Confirm=='Y'||Confirm=='y' && (currency>30) && (turncurrency>100) )
						       {    
								    ParalizeEnemy=turn+40;
							        currency=currency-15;
								    turncurrency=turncurrency-100;
								    cout<<" A deal has been made!";
							   } 
							   break;
							 }

				  //**************************************************** CASE 2 ***********************************************************

				  case 2:    { cout<<"\n\n\tSpend (30";PRINTMAPCHAR('9');cout<<") to paralize the spirit? (Y/N)\n\n\t>>";
						       Confirm=_getch();
						 
							   if ( Confirm=='Y'||Confirm=='y' && (currency>30) && (turncurrency>110) )
							   {
								    for(int i=0;i<78;i++) // Re-initializes map to default (Map2copy). 
						            {  for(int j=0;j<223;j++)
						               { mapread2[i][j]=mapread2copy[i][j]; }
								    }

									currency=currency-15;
									turncurrency=turncurrency-110;
									cout<<" A deal has been made!";
							   }
							   break;
							 }

				  //**************************************************** CASE 3 ***********************************************************

				  case 3:    { cout<<"\n\n\tSpend (30";PRINTMAPCHAR('9');cout<<") to go back home to Misthaven? (Y/N)\n\n\t>>";
						       Confirm=_getch();
						 
							   if ( Confirm=='Y'||Confirm=='y' && (currency>30))
							   {	
									 currency=currency-15;
									 stagenum=1;
									 Xpos=30; 
									 Ypos=50;
									 Health=6;
							   		 cout<<" A deal has been made!";} break; } 

				  //**************************************************** DEFAULT CASE *****************************************************
					
				  case 4: break;
				  default:   goto menu;
			
			} cout<<"\n\n\n\n\t";

		   }}

//====================================================================================================================================================
//		PRINT MAPS:                                                               (14) - Prints different levels / Game screen.
//====================================================================================================================================================


		void printmap (int opt)
		{      
		  //********************************************* .PRINT: LEVEL 1. *********************************************
				 if ( opt==1)
			     {	  for (int i=Xpos; i<(20+Xpos); i++)
						  {   for (int j=Ypos; j<(64+Ypos); j++)
								  {   
										if(i==(PlayerPosX) && j==(PlayerPosY))
								        cout<<char(01);
								        else
								        PRINTMAPCHAR(mapread[i][j]);
									}
									cout<<endl<<"\t";  }}

		 //********************************************* .PRINT: LEVEL 1. *********************************************
				 
			     if (opt==2)
							   {	for (int i=Xpos; i<(20+Xpos); i++)
								{   for (int j=Ypos; j<(64+Ypos); j++)
									{   if(i==(PlayerPosX) && j==(PlayerPosY))
								        cout<<char(01);
								        else
								        if(i==(EnemyPosX) && j==(EnemyPosY))
								        cout<<char(02);
								        else
								        PRINTMAPCHAR(mapread2[i][j]);
							        }
								    cout<<endl<<"\t"; 
							     }}
		 }

//====================================================================================================================================================
//		DIRECTION MOVEMENT:                                                       (15) - Alters movements by DIRECTION, sets Constraints!
//====================================================================================================================================================


		            void directionfunct(char DIRECTION, int opt,bool reverse)
		            {  int checkxmovement=Xpos,
					       checkymovement=Ypos;

					DIRECTION=tolower(DIRECTION);//always convert to lower case.

					//**************************************************** CASE 1 ***********************************************************

					   if(opt==1)
					{  switch(DIRECTION)
					{  case 'w': {  if(!isalpha(mapread[PlayerPosX-1][PlayerPosY]))
									Xpos--; break;}
					   case 's': {  if(!isalpha(mapread[PlayerPosX+1][PlayerPosY]))
									Xpos++; break;}
					   case 'd': {  if(!isalpha(mapread[PlayerPosX][PlayerPosY+1]))
									Ypos++; break;}
					   case 'a': {  if(!isalpha(mapread[PlayerPosX][PlayerPosY-1]))
									Ypos--; break;    }}}
					
					//**************************************************** CASE 1 ***********************************************************

					   if(opt==2 && op==true)
					{  switch(DIRECTION)
					{  case 'w': {  if(!isalpha(mapread2[PlayerPosX-1][PlayerPosY]))
									Xpos--;break;}
					   case 's': {  if(!isalpha(mapread2[PlayerPosX+1][PlayerPosY]))
									Xpos++; break;}
					   case 'd': {  if(!isalpha(mapread2[PlayerPosX][PlayerPosY+1]))
									Ypos++; break;}
					   case 'a': {  if(!isalpha(mapread2[PlayerPosX][PlayerPosY-1]))
						            Ypos--; break;}}}	

					//**************************************************** CASE 1 ***********************************************************

					   if(opt==2 && op==false)
					{  switch(DIRECTION)
					{  case 's': {  if(!isalpha(mapread2[PlayerPosX-1][PlayerPosY]))
									Xpos--; break;}
					   case 'w': {  if(!isalpha(mapread2[PlayerPosX+1][PlayerPosY]))
									Xpos++; break;}
					   case 'a': {  if(!isalpha(mapread2[PlayerPosX][PlayerPosY+1]))
									Ypos++; break;}
					   case 'd': {  if(!isalpha(mapread2[PlayerPosX][PlayerPosY-1]))
									Ypos--; break; }}}	

					//**************************************************** CASE 1 ***********************************************************

					   switch(DIRECTION)
					   {	
					     case 'x': {  system("CLS");
									  gamemenuexe(2);
									  break; }
					     case 'b': {  if ( stagenum==2)
									  {    powers(1);
									       system("PAUSE"); break; }}
						 case 'e': {  progressmenu(); break; }
						 default:     break; }  
					
					if(checkxmovement==Xpos && checkymovement==Ypos)
				    charactermoved=0;
					else
				    charactermoved=1;
					}

//====================================================================================================================================================
//		CHECKS X,Y COORDINATE VICINITY:                                           (16) - Checks if player is anywhere around (x,y). T/F;
//====================================================================================================================================================


					bool checkXYvicinity(int X, int Y)
					{

					    if ( ( PlayerPosX+1==X && PlayerPosY==Y ) || //if player is on the right of coordinate.
							 ( PlayerPosX-1==X && PlayerPosY==Y ) || //if player is on the  left of coordinate.
							 ( PlayerPosX==X && PlayerPosY+1==Y ) || //if player is below the given coordinate.
						     ( PlayerPosX==X && PlayerPosY-1==Y ))   //if player is above the given coordinate.
							return (true);
					   else
							return (false); }

//====================================================================================================================================================
//		CHECKS ENEMY VICINITY:                                                    (17) - Checks if the enemy is around the player. T/F;
//====================================================================================================================================================


					bool checkEnemyvicinity()
					{
					    if (( (EnemyPosX==PlayerPosX+1) && (EnemyPosY==PlayerPosY) )|| //if enemy is on the right of player
							( (EnemyPosX==PlayerPosX-1) && (EnemyPosY==PlayerPosY) )|| //if enemy is on the left  if player
							( (EnemyPosY==PlayerPosY+1) && (EnemyPosX==PlayerPosX) )|| //if enemy is bellow the player
						    ( (EnemyPosY==PlayerPosY-1) && (EnemyPosX==PlayerPosX) ))  //if enemy is above  the player
							return (true);
					   else
							return (false); 
					} 

//====================================================================================================================================================
//		CHECKS OBJECT VICINITY:                                                   (18) - Checks if player is anywhere around an object. T/F;
//====================================================================================================================================================


					bool checkObjvicinity(char Obj)
					{

					    if ((mapread[PlayerPosX+1][PlayerPosY]==Obj) || //if player is on the right of coordinate.
							(mapread[PlayerPosX-1][PlayerPosY]==Obj) || //if player is on the  left of coordinate.
							(mapread[PlayerPosX][PlayerPosY+1]==Obj) || //if player is below the given coordinate.
						    (mapread[PlayerPosX][PlayerPosY-1]==Obj))   //if player is above the given coordinate.
							return (true);
					   else
							return (false); }

//====================================================================================================================================================
//		ENEMY CHASE FUNCTION:                                                     (19) - Enemy X,Y Increment/decrement (& Optional Porbability).
//====================================================================================================================================================
					

					 void enemychase()
					 {    
						 randv = rand() % 100 + 1; //Creates Probability. 

					     if((PlayerPosX>EnemyPosX)&&(randv<=85)) //(randv<=100) Probability: OFF
							EnemyPosX++;
						 else
							EnemyPosX--;
						 
						 if((PlayerPosY>EnemyPosY)&&(randv<=85))
							EnemyPosY++;
						 else
							EnemyPosY--; 
						 
					 }

//====================================================================================================================================================
//		RANDOM OBJECT PLACEMENT ALGORITHM:                                        (20) - Places any object randomly on the map.
//====================================================================================================================================================
		

					void RandObject (char Obj,int mapnum,int xprobvalue, int yprobvalue,int totalprobvalue)
					{	  
						  int objrand = (rand() % 100)+1; //so the srand does not overlap for different objects;

						  srand((unsigned)time(0)+objrand); // Random seeding using system time. 

						  int nProbability= (rand() % 100)+1;

						  if(stagenum==mapnum && nProbability>totalprobvalue)

						  {     
								int n= (rand() % xprobvalue)+5;
								//srand((unsigned)time(0));
								int m= (rand() % yprobvalue)+5;
								//srand((unsigned)time(0));
								int o= (rand() % 4)+1;

						  switch(o)
						  { case 1: { if ( mapread2[PlayerPosX-n][PlayerPosY-m]=='.' )
										   mapread2[PlayerPosX-n][PlayerPosY-m]=Obj;
										   break; }
							case 2: { if ( mapread2[PlayerPosX-n][PlayerPosY+m]=='.' )
										   mapread2[PlayerPosX-n][PlayerPosY+m]=Obj;
										   break; }
							case 3: { if ( mapread2[PlayerPosX+n][PlayerPosY-m]=='.' )
										   mapread2[PlayerPosX+n][PlayerPosY-m]=Obj;
										   break; }
							case 4: { if ( mapread2[PlayerPosX+n][PlayerPosY+m]=='.')
										   mapread2[PlayerPosX+n][PlayerPosY+m]=Obj;
										   break; }
						  }}
					}

//====================================================================================================================================================
//		LEVEL SELECT MENU:                                                        (21) - Triangle Portal trigger and Initialization. 
//====================================================================================================================================================


					void levelmenu()
					{ 

					  if ( PlayerPosX==32 && PlayerPosY==109 && stagenum==1)
				
						 { char choice;
						   gotoxy(40, 9);   cout<<"                      ";
						   gotoxy(40,10);   cout<<"    SELECT LEVEL:     ";
						   gotoxy(40,11);   cout<<"                      ";
						   gotoxy(40,12);   cout<<" 1. Frostmist Swamp   ";
						   gotoxy(40,13);   cout<<"                      ";
						   gotoxy(40,14);   cout<<" 2. Forsaken Capital  ";
						   gotoxy(40,15);   cout<<"                      ";
						   if ((int(ITEM_necklace)+int(ITEM_knife)+int(ITEM_photograph)+int(ITEM_scarf))==4)
						  {gotoxy(40,16);   cout<<" 3. Exit              ";
						   gotoxy(40,17);   cout<<"                      ";
						   gotoxy(40,18);   cout<<" 4. Final Frontier    ";
						   gotoxy(40,19);   cout<<"                      ";}
						   else
						  {gotoxy(40,16);   cout<<" 3. Exit              ";
						   gotoxy(40,17);   cout<<"                      ";}

						   choice=_getch();

						   turn=0;
						   turncurrency=0;
						   PlayerInput=false;
			
						switch(choice)
						{ 
						  case '1': { playBeepSound();
									  stagenum=2;
									  Xpos=22;
									  Ypos=13; break; }
						  case '2': { playBeepSound();
									  stagenum=2;
									  Xpos=100;
									  Ypos=13; break; }
						  case '3': { Xpos=26;
									  Ypos=94; break; }
						  case '4': { playBeepSound();
									  stagenum=2;
									  Xpos=194;
									  Ypos=13; break; }
				
						}

						   PlayerPosX=Xpos+5;	    // SETTING INITIAL PLAYER POSITION
						   PlayerPosY=Ypos+15;
						   

						   EnemyPosX=PlayerPosX-10;  // SETTING INITIAL ENEMY POSITION
						   EnemyPosY=PlayerPosY; 

						   ParalizeEnemy=0; // RESETING PARALYSIS

			
					  }}
			  
//====================================================================================================================================================
//		TRIGGERS: RUNTIME                                                         (22) - Triggers: Runtime.
//====================================================================================================================================================


					void triggers_runtime(int PlayerPosX, int PlayerPosY)
					{ 
						if(PlayerInput==false)
							PlayerInput=true;

					  //******************** VARIABLE INITIALIZATION STAGE ***********************

								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;

								if( stagenum!=1)
								{   turn++;
								    if(charactermoved==true)
								    { turncurrency++; }
								}


					  //****************** ENEMY CHASE PLAYER EVERY OTHER TURN ********************
					  
						    if( stagenum==2 && (turn%3==0))
						    { if( ParalizeEnemy<turn)
							      enemychase(); }

					  //*********** IF ENEMY CATCHES THE PLAYER, INSTANT KILL PLAYER **************
					
						  if( stagenum==2 && (checkEnemyvicinity()==true))
						    { Health=0; 
						      PlayerInput=false;}
					}

//====================================================================================================================================================
//		TRIGGERS: HOMETOWN                                                        (23) - Triggers: Hometown (mapread).
//====================================================================================================================================================


					void triggers_hometown (int PlayerPosX, int PlayerPosY)
					{ 		
								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;

					  //********************* COLLECT CURRENCY, REMOVE FROM MAP *******************

						  if ( stagenum==1 &&  mapread[PlayerPosX][PlayerPosY]=='9') //Map 1
						     { mapread[PlayerPosX][PlayerPosY]='.'; 
							   currency++; }

					  //************** TELEPORT PLAYER TO MAZE 1, AND INITIALIZE ******************

						//levelmenu(); // CALLS THE LEVEL MENU

					}

//====================================================================================================================================================
//		TRIGGERS: LEVEL 1                                                         (24) - Triggers: Level 1.
//====================================================================================================================================================


					void triggers_level1 (int PlayerPosX, int PlayerPosY)
					{

								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;

				      //********************* COLLECT CURRENCY, REMOVE FROM MAP *******************

						  if ( stagenum==2 && mapread2[PlayerPosX][PlayerPosY]=='9') //Map 2
						     { mapread2[PlayerPosX][PlayerPosY]='.'; 
							   currency++; }

					  //********************* IF POSITION IS TRAP, DEAL DAMAGE ********************

						  if ( stagenum==2 && mapread2[PlayerPosX][PlayerPosY]=='8')
							 { mapread2[PlayerPosX][PlayerPosY]='.';
							   Health--; }

					  //********************* COLLECT KEY ITEM, REMOVE FROM MAP *******************

						  if ( stagenum==2 && mapread2[PlayerPosX][PlayerPosY]=='0')
						     { mapread2[PlayerPosX][PlayerPosY]='.';
							   op=!op; }

					  //************************ INITIALIZE ENEMY POSITION ************************
					  


					  //********** TELEPORT FROM END OF MAZE 1 TO HOMETOWN & INITIALIZE ***********
					  
						  if ( PlayerPosX==35 && PlayerPosY==183)
						     { stagenum=1;
						       Xpos=30; 
							   Ypos=50;
							   Health=6;
						                          
						       for( int i=0;i<(3*78);i++) //Reseting map back to default below.
						       {    for( int j=0;j<223;j++)
						            {    mapread2[i][j]=mapread2copy[i][j]; }}}


					}

//====================================================================================================================================================
//		TRIGGERS: LEVEL 2                                                         (25) - Triggers: Level 2.
//====================================================================================================================================================


					void triggers_level2 (int PlayerPosX, int PlayerPosY)
					{

								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;

					
						    if ( PlayerPosX==175 && PlayerPosY==60)
						     { Xpos = 203;
							   Ypos = 137;}
						    if ( PlayerPosX==200 && PlayerPosY==152)
						     { Xpos = 203;
							   Ypos = 95;}
							if ( PlayerPosX==216 && PlayerPosY==152)
						     { Xpos = 177;
							   Ypos = 124;}
							 if ( PlayerPosX==218 && PlayerPosY==73)
						     { Xpos = 177;
							   Ypos = 106;}
     					     if ( PlayerPosX==216 && PlayerPosY==144)
						     { Xpos = 178;
							   Ypos = 45;}											    
							 if( PlayerPosX==172 && PlayerPosY==138)
						     { Xpos = 174;
							   Ypos = 72;}
							 if( PlayerPosX==189 && PlayerPosY==100)
						     { Xpos = 169;
							   Ypos = 144;}
							 if( PlayerPosX==182 && PlayerPosY==139)
						     { Xpos = 203;
							   Ypos = 137;}
							 if( PlayerPosX==185 && PlayerPosY==71)
						     { Xpos = 164;
							   Ypos = 97;}
							 if( PlayerPosX==191 && PlayerPosY==183)
							 {   system("CLS");
							     cout<<"\n\n\n\n\n\n\n\n\t\t\t";
								 cout<<"To be continued in part 2\n\n\n\n\n\n\t\t\t";
								 stagenum=1;
							     Xpos=30;
							     Ypos=50;
							     system("pause");}
						                     

					}

//====================================================================================================================================================
//		DIALOGUE BOX FUNTION:                                                     (26) - Prints out a black box so text can be printed over.
//====================================================================================================================================================


					void dialoguebox ()
					{ gotoxy(0,20);

					  // Prints black box on game screen for text.
					  for( int i=0;i<3;i++) 
					  {    for( int j=0;j<79;j++)
					       {    cout<<" "; }
					  cout<<endl;
					  }

					  gotoxy(10,21); // curser ready to print at centre of box.
					}

//====================================================================================================================================================
//		DIALOGUE TRIGGERS:                                                        (27) - Complete dialogue triggers (Body).
//====================================================================================================================================================


					void dialoguetrigger()
					{
								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;

						
						if(stagenum==1)
						{   
							LockWindowUpdate(GetConsoleWindow());

							if (checkXYvicinity(24,77)==true)
							{   dialoguebox(); cout<<" Collect Plasma ! It will help you on your journey! "; PRINTMAPCHAR('9');}

							if (checkXYvicinity(27,77)==true)
							{   dialoguebox(); cout<<" When your out there, Press 'B' to access your spellbook! ";}

							if (checkXYvicinity(30,77)==true)
							{   dialoguebox(); cout<<" I hear it's dangerous out there, don't step on traps! "; PRINTMAPCHAR('0');}

							if (checkXYvicinity(33,77)==true)
							{   dialoguebox(); cout<<" Press 'X' at anytime to access the menu!";}

							if (checkXYvicinity(36,77)==true)
							{   dialoguebox(); cout<<" Find clues! Press 'E' to open your Inventory!"; PRINTMAPCHAR('6');}

							if (checkXYvicinity(39,77)==true)
							{   dialoguebox(); cout<<" When you're ready, walk east to the triangular portal!";}

							if (checkXYvicinity(26,47)==true)
							{   dialoguebox(); cout<<" This portal will be finished soon! ";}

						    if (checkXYvicinity(26,50)==true)
							{   dialoguebox(); cout<<" Ha, If I were you I would kill that girl... traitor ";}

							if (checkXYvicinity(36,47)==true)
							{   dialoguebox(); cout<<" Get that girl soon so we can conquer this world !";}

						    if (checkXYvicinity(36,50)==true)
							{   dialoguebox(); cout<<" Mwhahahahaha Oh, ahem *cough* What are you looking at?";}

							if (checkXYvicinity(31,41)==true)
							{   dialoguebox(); cout<<" Those who have left Misthaven have not returned... ";}

							if (checkXYvicinity(31,56)==true)
							{   dialoguebox(); cout<<" I don't remember anything... This portal needs building!";}
							
							LockWindowUpdate(NULL);
						}}

//====================================================================================================================================================
//		STORY TRIGGERS:                                                           (28) - Complete story triggers (Body).
//====================================================================================================================================================


					void storytrigger()
					{  	
								PlayerPosX=Xpos+5;
								PlayerPosY=Ypos+15;


						if( stagenum==2 && turn ==10)
						{   printstory(6,14,22);  }

						
						if( PlayerPosX==28 && PlayerPosY==149 && stagenum==2 && ITEM_necklace==0) // Item 1 - Necklace.
						{   printstory(6,22,29);
						    ITEM_necklace=1;
							mapread2[PlayerPosX][PlayerPosY]='.';
						}
							

						if( PlayerPosX==33 && PlayerPosY==159 && stagenum==2 && ITEM_knife==0) // Item 2 - Knife.
						{   printstory(8,29,34); 
							ITEM_knife=1;
							mapread2[PlayerPosX][PlayerPosY]='.';
						}

						
						if( PlayerPosX==99 && PlayerPosY==142 && stagenum==2 && ITEM_photograph==0) // Item 3 - Photograph.
						{   printstory(8,34,39); 
							ITEM_photograph=1;
							mapread2[PlayerPosX][PlayerPosY]='.';
						}


						if( PlayerPosX==129 && PlayerPosY==151 && stagenum==2 && ITEM_scarf==0) // Item 4 - Scarf.
						{   printstory(7,39,44);
							ITEM_scarf=1;
							mapread2[PlayerPosX][PlayerPosY]='.';
						}
						
						if( PlayerPosX==175 && PlayerPosY==58 && stagenum==2 &&mapread2[PlayerPosX][PlayerPosY]=='6')
						{   printstory(8,50,56);
							mapread2[PlayerPosX][PlayerPosY]='.';
						}

						if( PlayerPosX==203 && PlayerPosY==119 && stagenum==2 &&mapread2[PlayerPosX][PlayerPosY]=='6')
						{   printstory(8,56,62); 
							mapread2[PlayerPosX][PlayerPosY]='.';
						}
						

						if (( PlayerPosX==35 && PlayerPosY==183) || ( PlayerPosX==113 && PlayerPosY==183))
						{    printstory(9,44,48);
							 printstory(10,48,52);  
						     stagenum=1;
						     Xpos=30; 
							 Ypos=50;
							 Health=6;
						                          
						       for( int i=0;i<(3*78);i++) //Reseting map back to default below.
						       {    for( int j=0;j<223;j++)
						            {    mapread2[i][j]=mapread2copy[i][j]; }}}
					}

//====================================================================================================================================================
//		DEATH ANIMATION:                                                          (29) - Resets variables after death. 
//====================================================================================================================================================


					void deathanimation ()
					{  if ( Health==0)
					   {    system("CLS");
						    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\tYOU DIED! YOU GAVE 20 PLASMA TO A WILD BEAST FOR RESCUEING YOU!\n\t";
						  
							for(int i=0;i<63;i++)
						    { PRINTMAPCHAR('V');
						      Sleep(50); }

						    cout<<"\n\n\n\n\n\n\n\n\n\n\t";
						    system("pause");
						    system("CLS");
						  
							stagenum=1;
							Xpos=30;Ypos=50;
						    Health=6;
						    op=true;
						    currency=currency-20;
							PlayerInput=false; //Turns OFF Input;
						  
							//Reseting map back to default below.
						    for(int i=0;i<3*78;i++)			
						    {  for(int j=0;j<223;j++)
						       { mapread2[i][j]=mapread2copy[i][j]; }}
					}}

//====================================================================================================================================================
//		MAIN GAME BODY:                                                           (30) - All game body execution / function calls here.
//====================================================================================================================================================


			void gamebody()
			{   ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
				char DIRECTION;					// FOR DIRECTIONAL KEY
				storytrigger();

				do  //************************** || MAIN LOOP STARTS HERE || ******************

			    {   
					storytrigger();							   // TRIGGERS STORY EVENTS.
					triggers_runtime(PlayerPosX,PlayerPosY);
					triggers_hometown(PlayerPosX,PlayerPosY);
					triggers_level1(PlayerPosX,PlayerPosY);
					triggers_level2(PlayerPosX,PlayerPosY);

					LockWindowUpdate(GetConsoleWindow());      // TURN ON LOCKDOWN.
					system("CLS");

					PlayerPosX=Xpos+5;
					PlayerPosY=Ypos+15;

					printheader();						       // PRINTS HEADER BAR.

					cout<<"\n\t";
					printmap(stagenum);					       // PRINTS MAP.
					LockWindowUpdate(NULL);				       // TURN OFF LOCKDOWN.


					dialoguetrigger();						   // TRIGGER - DIALOGUES.
					levelmenu();							   // MAIN PORTAL TRIGGER.

					Sleep(20*stagenum);

					if (_kbhit())
						{
						if( PlayerInput==true )
						  { DIRECTION=_getch();
							directionfunct(DIRECTION,stagenum,op); }
						}
					else
						charactermoved=false;


					deathanimation();					       // DEATH ANIMATION.

					RandObject('8',2,15,15,80);
					RandObject('9',2, 5, 5,20);
					

				} while(true); //***************** || MAIN LOOP ENDS HERE ||******************* 
			}


//====================================================================================================================================================
// END OF CODE                                                                       (All work programmed by Aaron Alphonso, 2013)
//====================================================================================================================================================