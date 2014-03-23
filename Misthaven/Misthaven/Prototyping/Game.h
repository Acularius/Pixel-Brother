#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include "Objects.h"
#include "Timer.h"
#include <algorithm>
#include <cmath>

#include "Constraints.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* these are enumerated types (just names) of game states
   that the game can be in at any moment.  These help you
   manage the flow of the game.  Especially if you want 
   to do different updates (call different update functions)
   or have different behaviour for input (i.e. mouse and keyboard
   functions might have different behaviour in-game (STATE_GAMEPLAY)
   versus when in the Menu (STATE_MAINMENU)
*/
enum {
	STATE_GAMEPLAY=0, 
	STATE_MAINMENU, 
	STATE_CREDITS
};

// input information related to mouse
// you could add keyboard info in here too if you need to know if a key is currently pressed down
typedef struct _InputInfo
{
	bool mouseDown; // is the mouse down?
	int button; // which mouse button
	float clickX,clickY; // where the mouse was clicked
	float currentX,currentY;
}InputInfo;

// convenience structure to hold rgb values
typedef struct _RGBColor
{
	float red,green,blue;
}RGBColor;

// GameStateInfo
// this stores anything related to the state of the game
// i.e. what level are we on?, what is the score? etc.
typedef struct _GameStateInfo
{
	int gameState; // the game state, see enum's above
	RGBColor bgClearColor; // the default clear color of the background

	// window width/height are the actual size of the window
	int windowWidth, windowHeight;

	// screen width/height are the apparent size of the window
	// i.e. you can have a 640x480 game screen stretched to 1280x1024
	// your calculations for actual pixel locations will depend on the ratio
	//   between screen and window width/height
	int screenWidth, screenHeight;

	float ratioWidth,ratioHeight;
}GameStateInfo;

/* 
 * Game.h
 * This is the main Game class of the base sprite lib starter code
 * it handles input, game loop update, display
 */
class Game
{
public:
	/* initialization */
	Game(void);
	~Game(void);
	void initializeGame();
	void loadLevel01();

	/* convenience functions */
	// screen size is the apparent size in pixels
	// i.e. this is what your game calculations should use
	void setScreenSize(int w, int h)
	{
		stateInfo.screenWidth = w;
		stateInfo.screenHeight = h;
	}
	// sets the screen-to-window pixel coordinates ratio
	void updateScreenRatio()
	{
		stateInfo.ratioWidth = stateInfo.screenWidth/(float)stateInfo.windowWidth;
		stateInfo.ratioHeight = stateInfo.screenHeight/(float)stateInfo.windowHeight;
		/* these are only really used for the mouse function
		   to get actual screen pixel coordinates from the window coordinates */
	}

	// sets the window size in pixels for the window itself
	void setNewWindowSize(int width,int height)
	{
		stateInfo.windowWidth = width;
		stateInfo.windowHeight = height;
	}


	// add a sprite to the draw list
	// only sprites in the draw list will be drawn
	void addSpriteToDrawList(Sprite *s);



	//Unless otherwise specified

	/* draw/rendering routines */
	void draw(); // called from the main

	void PreDraw(); // prior to drawing
	void DrawGame(); // actual drawing the frame
	void PostDraw(); // cleanup and prepare for next frame
	
	void drawSprites(); // draw the sprite list
	void drawTestPrimitives(); // Test function for GDWII milestone

	/* update routines, the game loop */
	void update(); // called from main frequently

	/* input callback functions */
	void keyboardDown(unsigned char key, int mouseX, int mouseY);
	void keyboardUp(unsigned char key, int mouseX, int mouseY);


	/*********************************/
	/* DATA */
	/*********************************/
	
	/* game state info */
	GameStateInfo stateInfo;

	/* Player Sprite */
	MainCharacter *Player;
	
	Objects *Health;

		//Background Sprite Test
	Objects *Map01Base;
	Objects *Map01Objects;
	Objects *WaterBackground;


	Constraints MapConstraints;

	InputInfo input;



	/* sprite list to draw */
	std::vector<Sprite*> spriteListToDraw;

	/* Object list for movement */
	std::vector<Objects*> objectsList;

		//Add things to the Object List

		void addToObjectsList(Objects *o);

		/* you could have more lists of sprite pointers */
	/* such as spritesToUpdateForPhysics  
	   or      spritesToUpdateForCollisions 
	   etc....
    */


	// Objects to a list for movement
	
	void moveObjectsKeyboardUp(unsigned char key);
	void moveObjectsKeyboardDown(unsigned char key);
	void movement();

	void allowMovement(); //checks constraints to allow for player movement

	// Update Objects
	void updateObjects();

	/* timer's for rendering and animation/physics update */
	Timer *renderingTimer;
	Timer *updateTimer; // for physics/collisions etc.

	//std::string sScore;
	//int iScore;
};