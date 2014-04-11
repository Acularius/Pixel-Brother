//###########################################################################################
//
//									    GAME STATE.h
//																			|Aaron Alphonso|
//###########################################################################################

			#include "Sprite.h"
			#include "Game.h"
			#include <vector>
			#include "AudioLib.h"

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

		//Scrolling Background Variables:
		bool Vertical;
		int WaterSpeed;
		Objects *WaterBackground;
		void ScrollingBackgroundUpdate();
		void ScrollingBackgroundKeyDown(unsigned char key);
		void ScrollingBackgroundKeyUp(unsigned char key);


//-------------------------------------------------------------------------------------------

	
		//SPRITE ITERATOR FUNCTIONS:
		std::vector<Sprite*> spriteListToDraw;
		void Draw();
		void addSpriteToDrawList(Sprite *s);
		

//-------------------------------------------------------------------------------------------
	void addToObjectsList(Objects *o);
	void addToGhostList(Ghost *g);
	void addToSeagullList(Seagull *sg);

	// Score UI
	Sprite *UIScore[7];
	void ScoreUpdate(int inScore);

			/* Object list for movement */
	std::vector<Objects*> objectsList;
	std::vector<Ghost*> ghostList;
	std::vector<Seagull*> gullList;

			// Update Objects
	void updateObjects();
	void updateGhost(float inPlayPosX, int inPlayPosY);
	void updateSeagull(float inPlayPosX, int inPlayPosY);
	
	void moveObjectsKeyboardUp(unsigned char key); // Affects the inMotionSpeed modifiers, movement in respect to player.
	void moveObjectsKeyboardDown(unsigned char key); // Stops the inMotionSpeed modifiers, movement in respect to player.
	void movement(); // Basically adds respectiveMoveSpeeds in order to have overall movement on the map.

			// Combat
	void combatSystem();

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

		 void allowMovement();
		 void transitionCheck();

		 void AddNpcTile(int i, int PosX, int PosY);
		 void AddTutorialTile(int i, int PosX, int PosY);
		 void NpcCheck();
		 void TutorialCheck();

		 int anynumber2; // tick sound - no repeat

		 
//		 void ScoreUpdate(int inScore);

			 //SPRITE DECLARATIONS
			 Objects *Map1_Base;
			 Objects *Map1_Objects;
			 Transition *TransitionHomeOne;

			 Objects *NPCDialogue;
			 Objects *NPC_Objects;
			 Objects *NPC[16];
			 Objects *Tutorial[5];
			 Sprite *TutorialSprite;
		
		
		MainCharacter *Player;
		Constraints MapConstraintsHome;
		Health *UIHealth;
		Seagull *Gull1;
		Seagull *Gull2;
		Seagull *Gull3;
		Seagull *Gull4;

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

		 void allowMovement();
		 void transitionCheck();

		 //void ScoreUpdate(int inScore);

			 //SPRITE DECLARATIONS
			 Objects *Map2_Base;
			 Objects *Map2_Objects;
			 Transition *TransitionOneTwo;

			 MainCharacter *Player;
			 Constraints MapConstraintsOne;
			 Health *UIHealth;
			 
		Ghost *Ghosty1;
		Ghost *Ghosty2;
		Ghost *Ghosty3;
		Ghost *Ghosty4;
		Ghost *Ghosty5;
		Ghost *Ghosty6;
		Ghost *Ghosty7;
		Ghost *Ghosty8;
			 


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

		 void allowMovement();
		 void transitionCheck();


			 //SPRITE DECLARATIONS
			 Objects *Map3_Base;
			 Objects *Map3_Objects;
			 Transition *TransitionTwoMenu;

			 MainCharacter *Player;
			 Constraints MapConstraintsTwo;
			 Health *UIHealth;
			 
		
		Ghost *Ghosty1;
		Ghost *Ghosty2;
		Ghost *Ghosty3;
		Ghost *Ghosty4;
		Ghost *Ghosty5;
		Ghost *Ghosty6;
		Ghost *Ghosty7;
		Ghost *Ghosty8;

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

		 void allowMovement();

			 //SPRITE DECLARATIONS
			 Objects *Map4_Base;
			 Objects *Map4_Objects;
		     Objects *WaterBackgroundThree;

			 MainCharacter *Player;
			 Constraints MapConstraintsThree;
			 Health *UIHealth;



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

		bool test;      // To test movement control;
		int MsgType;
		int MsgNumber;
		bool ticked;
		int ticks;

		Timer *transitionTimer;

	};


#endif
//																			|Aaron Alphonso|
//###########################################################################################