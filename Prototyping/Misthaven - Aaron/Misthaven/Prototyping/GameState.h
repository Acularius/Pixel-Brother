//###########################################################################################
//
//									    GAME STATE.h
//																			|Aaron Alphonso|
//###########################################################################################

			#include "Sprite.h"
			#include "Game.h"
			#include "AudioLib.h"
			#include <vector>

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

			/* Object list for movement */
	std::vector<Objects*> objectsList;

			// Update Objects
	void updateObjects();
	
	void moveObjectsKeyboardUp(unsigned char key); // Affects the inMotionSpeed modifiers, movement in respect to player.
	void moveObjectsKeyboardDown(unsigned char key); // Stops the inMotionSpeed modifiers, movement in respect to player.
	void movement(); // Basically adds respectiveMoveSpeeds in order to have overall movement on the map.

//	void allowMovement(); //checks constraints to allow for player movement

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

		 //* Player Sprite */
		 //	 MainCharacter *Player;
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
		 void AddNpcTile(int i, int PosX, int PosY);
		 void AddTutorialTile(int i, int PosX, int PosY);
		 void NpcCheck();
		 void TutorialCheck();
		 ~LevelHome(void);

		 void allowMovement();
		 void transitionCheck();
		 void ghostPlayCollide();

		 void tutorialLoad1();
		 void tutorialLoad2();
		 void tutorialLoad3();
		 void tutorialLoad4();
		 void tutorialLoad5();
		 bool tutorialDone;

			 //SPRITE DECLARATIONS
			 Objects *NPCDialogue;
			 Objects *Map1_Base;
			 Objects *Map1_Objects;
			 Objects *NPC_Objects;
			 Objects *NPC[16];
			 Objects *Tutorial[5];
			 Transition *TransitionHomeOne;
			// Sprite *Player;
			 Sprite *UISample;
			 Sprite *TutorialSprite;

		int anynumber2;
	    void PrintTutorial();

		MainCharacter *Player;
		Constraints MapConstraintsHome;
		Ghost *Ghosty1;
		Ghost *Ghosty2;
		Ghost *Ghosty3;
		Ghost *Ghosty4;

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

			 //SPRITE DECLARATIONS
			 Objects *Map2_Base;
			 Objects *Map2_Objects;
			// Sprite *Player;
			 Sprite *UISample;

			 MainCharacter *Player;
			 Constraints MapConstraintsOne;



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

			 //SPRITE DECLARATIONS
			 Objects *Map3_Base;
			 Objects *Map3_Objects;

			 //Sprite *Player;
			 MainCharacter *Player;
			 Constraints MapConstraintsTwo;

			 Sprite *UISample;

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

			 //Sprite *Player;
			 MainCharacter *Player;
			 Constraints MapConstraintsThree;

			 Sprite *UISample;


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

			 MainCharacter *Player;

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