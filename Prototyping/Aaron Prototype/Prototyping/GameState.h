#include "Sprite.h"
#include <vector>
#ifndef GAMESTATE_H
#define GAMESTATE_H

//===========================================================================================
// GAME STATE ----- PARENT VIRTUAL CLASS
//===========================================================================================

class Game; //declaring; 

class GameState
{

public: 

	void InitGameState();
	virtual void Init(Game* Local)=0;
	virtual void Update()=0;
	virtual void KeyUp(unsigned char key)=0;
	virtual void KeyDown(unsigned char key)=0;
	void Draw();
	bool active;
	void StateControl(int option);
	Game* LocalGame;

	std::vector<Sprite*> spriteListToDraw;
	void addSpriteToDrawList(Sprite *s);



	//game state should have a vector of sprites it draws itself

};

//===========================================================================================
// MAIN MENU ----- STATE 1
//===========================================================================================

class MainMenu: public GameState
{
public:

	 void Init(Game* Local);
	 ~MainMenu(void);
	 void Update();
	 void KeyUp(unsigned char key);
	 void KeyDown(unsigned char key);
	 void MainMenu::MenuControl (int opt);
	 Sprite* MenuBG;
	 Sprite* MenuOverlay;
	 Sprite* MenuStrip;
	 Sprite* Player;
	 int menuSpeed;
	 int option;
	 bool test;
	 		
		int	speedX;
		int speedY;
	 

};

//===========================================================================================
// LEVEL HOME ----- STATE 2
//===========================================================================================

class LevelHome:public GameState
{
public:

	 void Init(Game* Local);
	 void Update();
	 void KeyUp(unsigned char key);
	 void KeyDown(unsigned char key);

	Sprite *Map1_Base;
	Sprite *Map1_Objects;
	Sprite *WaterBackground;
	Sprite *Player;
	Sprite *UISample;
	int gameState;
	int mapSpeed;
	int WaterSpeed;
	bool test;
	 		
		int	speedX;
		int speedY;
	 

};

//===========================================================================================
// LEVEL ONE ----- STATE 3
//===========================================================================================

class LevelOne:public GameState
{
public:

	 void Init(Game* Local);
	 void Update();
	 void KeyUp(unsigned char key);
	 void KeyDown(unsigned char key);

	Sprite *Map2_Base;
	Sprite *Map2_Objects;
	Sprite *WaterBackground;
	Sprite *Player;
	Sprite *UISample;
	int gameState;
	int mapSpeed;
	int WaterSpeed;
	bool test;
	 		
		int	speedX;
		int speedY;
	 

};

//===========================================================================================
// LEVEL TWO ----- STATE 4
//===========================================================================================

class LevelTwo:public GameState
{
public:

	 void Init(Game* Local);
	 void Update();
	 void KeyUp(unsigned char key);
	 void KeyDown(unsigned char key);

	Sprite *Map3_Base;
	Sprite *Map3_Objects;
	Sprite *WaterBackground;
	Sprite *Player;
	Sprite *UISample;
	int gameState;
	int mapSpeed;
	int WaterSpeed;
	bool test;
	 		
		int	speedX;
		int speedY;
	 

};

//===========================================================================================
// LEVEL THREE ----- STATE 5
//===========================================================================================

class LevelThree:public GameState
{
public:

	 void Init(Game* Local);
	 void Update();
	 void KeyUp(unsigned char key);
	 void KeyDown(unsigned char key);

	Sprite *Map4_Base;
	Sprite *Map4_Objects;
	Sprite *WaterBackground;
	Sprite *Player;
	Sprite *UISample;
	int gameState;
	int mapSpeed;
	int WaterSpeed;
	bool test;
	 		
		int	speedX;
		int speedY;
	 

};

#endif