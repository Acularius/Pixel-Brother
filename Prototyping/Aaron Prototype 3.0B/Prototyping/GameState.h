//###########################################################################################
//
//									    GAME STATE.h
//																			|Aaron Alphonso|
//###########################################################################################

			#include "Sprite.h"
			#include "Game.h"
			#include "StateManager.h"
			#include <vector>
			#include <cstdlib>

//-------------------------------------------------------------------------------------------
//   Game State is an abstract class from which other states can be derived. Such as menus,
// levels, cutscenes, dialogues etc. Each derived class can have it's down update function, 
// it's own controls, sprites, etc. "Active" toggle state transitioning Off//On.
//-------------------------------------------------------------------------------------------

	#ifndef GAMESTATE_H
	#define GAMESTATE_H

//===========================================================================================
//						   GAME STATE ----- PARENT VIRTUAL CLASS
//===========================================================================================

	class Game; //Redeclaring Game; 

	class GameState
	{

		public: 

		void InitGameState();
		Game* LocalGame;

//-------------------------------------------------------------------------------------------

		//CORE STATE FUNCTIONS:
		virtual void Init(Game* Local)=0;
		virtual void ResetMap()=0;
		virtual void Update()=0;
		virtual void KeyUp(unsigned char key)=0;
		virtual void KeyDown(unsigned char key)=0;

//-------------------------------------------------------------------------------------------

		bool active;    //Class ON/OFF Switch. 
		bool loadcheck; //Checks If already Initialized.
		int StateNum;   //State Number for transitioning.
		int anynumber;  //Various purpose number.

//-------------------------------------------------------------------------------------------

		//SPRITE ITERATOR FUNCTIONS:
		std::vector<Sprite*> spriteListToDraw;
		void Draw();
		void addSpriteToDrawList(Sprite *s);

//-------------------------------------------------------------------------------------------

};

//===========================================================================================
//								 MAIN MENU ----- STATE 1
//===========================================================================================

	class MainMenu: public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 void MenuControl (int opt);
		 ~MainMenu(void);

		 	 //SPRITE DECLARATIONS
			 Sprite* MenuBG;
			 Sprite* MenuOverlay;
			 Sprite* MenuStrip;
			 Sprite* Player;

		 int menuSpeed; // Speed of scrolling strip;
		 int option;    // Option: for menu control;
		 bool test;     // To test movement control;

	};

//===========================================================================================
//								 LEVEL HOME ----- STATE 2
//===========================================================================================

	class LevelHome:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 ~LevelHome(void);

			 //SPRITE DECLARATIONS
			 Sprite *Map1_Base;
			 Sprite *Map1_Objects;
		     Sprite *WaterBackground;

		//int mapSpeed;   // Speed of player (basically);
		int mapSpeedX;
		int mapSpeedY;
		int WaterSpeed; // Speed of scrolling water BG;
		bool test;      // To test movement control;

	};

//===========================================================================================
//								 LEVEL ONE ----- STATE 3
//===========================================================================================

	class LevelOne:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 ~LevelOne(void);

			 //SPRITE DECLARATIONS
			 Sprite *Map2_Base;
			 Sprite *Map2_Objects;
		     Sprite *WaterBackground;

		int mapSpeed;   // Speed of player (basically);
		int WaterSpeed; // Speed of scrolling water BG;
		bool test;      // To test movement control;

	};

//===========================================================================================
//								 LEVEL TWO ----- STATE 4
//===========================================================================================

	class LevelTwo:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 ~LevelTwo(void);

			 //SPRITE DECLARATIONS
			 Sprite *Map3_Base;
			 Sprite *Map3_Objects;
		     Sprite *WaterBackground;

		int mapSpeed;   // Speed of player (basically);
		int WaterSpeed; // Speed of scrolling water BG;
		bool test;      // To test movement control;

	};

//===========================================================================================
//								 LEVEL THREE ----- STATE 5
//===========================================================================================

	class LevelThree:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 ~LevelThree(void);

			 //SPRITE DECLARATIONS
			 Sprite *Map4_Base;
			 Sprite *Map4_Objects;
		     Sprite *WaterBackground;

		int mapSpeed;   // Speed of player (basically);
		int WaterSpeed; // Speed of scrolling water BG;
		bool test;      // To test movement control;

	};

//===========================================================================================
//								 UI STATE -------- STATE 6
//===========================================================================================

	class UIState:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 void ScoreUpdate();
		 ~UIState(void);

			 //SPRITE DECLARATIONS
		 	 Sprite *UISample;
			 Sprite *UIHealth;
			 Sprite *UIActionbar;
			 Sprite *UIScore[7];
			 Sprite *Player;

		int Health;		// PlayerHealth;
		int Score;		// PlayerScore;
		int tempscore;  // Variable for ScoreUpdate;
		bool test;      // To test movement control;

	};

//===========================================================================================
//								 ON SCREEN MSG STATE --- STATE 7
//===========================================================================================

	class MessageState:public GameState
	{
	  public:

		 void Init(Game* Local);
		 void ResetMap();
		 void Update();
		 void KeyUp(unsigned char key);
		 void KeyDown(unsigned char key);
		 void MCtrl();
		 ~MessageState(void);

			 //SPRITE DECLARATIONS
		 	 Sprite *Transition;
			 Sprite *Tutorials;

		bool test;      // To test movement control;
		int MsgType;
		int MsgNumber;

	};


#endif
//																			|Aaron Alphonso|
//###########################################################################################