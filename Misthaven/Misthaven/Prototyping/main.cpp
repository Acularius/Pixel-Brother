//###########################################################################################
//
//										  MAIN.cpp
//																			   |Sprite Lib|
//###########################################################################################

		#include <windows.h>
		#include "Game.h"

//-------------------------------------------------------------------------------------------
//  Global Variables:
//-------------------------------------------------------------------------------------------

	#define WINDOW_SCREEN_WIDTH 480
	#define WINDOW_SCREEN_HEIGHT 260
	#define WINDOW_WIDTH 480
	#define WINDOW_HEIGHT 260

//-------------------------------------------------------------------------------------------
//  Global Sprite Info:
//-------------------------------------------------------------------------------------------

	#define FRAMES_PER_SECOND 20
	const int FRAME_DELAY_SPRITE=1000/FRAMES_PER_SECOND;

	/* the Game */
	Game *theGame;

//-------------------------------------------------------------------------------------------
// Function DisplayCallbackFunction(void) 
//	Description:
//  - this is the openGL display routine
//  - this draws the sprites appropriately
//-------------------------------------------------------------------------------------------

	void DisplayCallbackFunction(void)
	{
		theGame->draw();
	}

//-------------------------------------------------------------------------------------------
// Function void KeyboardCallbackFunction(unsigned char, int,int) 
//	 Description:
//   - this handles keyboard input when a button is pressed
//-------------------------------------------------------------------------------------------

	void KeyboardCallbackFunction(unsigned char key, int x, int y)
	{

		std::cout << "Keycode:"<<(int)key<<std::endl;
		theGame->keyboardDown(key,x,y);	
	}

//-------------------------------------------------------------------------------------------
//  function void KeyboardUpCallbackFunction(unsigned char, int,int)
//  Description:
//   - this handles keyboard input when a button is lifted.
//-------------------------------------------------------------------------------------------

	void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
	{
		theGame->keyboardUp(key,x,y);
	}

//-------------------------------------------------------------------------------------------
//  function initImageLibrary()
//  Description:
//  - initialize the DevIL library properly.
//-------------------------------------------------------------------------------------------

	void initImageLibrary()
	{
		glEnable(GL_TEXTURE_2D);
		ilInit();
		iluInit();
		ilutRenderer(ILUT_OPENGL);
	}

//-------------------------------------------------------------------------------------------
// function TimerCallbackFunction(int value)
// Description: 
//  - this is called many times per second
//  - this enables you to animate things
//  - no drawing, just changing the state
//  - changes the frame number and calls for a redisplay
//  - FRAME_DELAY_SPRITE is the number of milliseconds to wait before calling the timer again.
//-------------------------------------------------------------------------------------------

	void TimerCallbackFunction(int value)
	{
		theGame->update();

		glutPostRedisplay();
		glutTimerFunc(FRAME_DELAY_SPRITE,TimerCallbackFunction,0);
	}

//-------------------------------------------------------------------------------------------
// function WindowReshapeCallbackFunction()
// Description: 
//  - this is called whenever the window is resized 
//  - and sets up the projection matrix properly
//  - currently set up for an orthographic view (2D only).
//-------------------------------------------------------------------------------------------

	void WindowReshapeCallbackFunction(int w,int h)
	{
		float asp = (float)w/(float)h;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,WINDOW_SCREEN_WIDTH,0,WINDOW_SCREEN_HEIGHT);
	
		theGame->setNewWindowSize(w,h);
		theGame->setScreenSize(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT);
		theGame->updateScreenRatio();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

//-------------------------------------------------------------------------------------------
// function main()
// Description:
//  - this is the main function
//  - does initialization and then calls glutMainLoop() to start the event handler
//	- argv2 will eventually be for OpenCV.
//-------------------------------------------------------------------------------------------

	int main(int argc, char **argv, char **argv2) 
	{
		/* initialize the window and OpenGL properly */
		glutInit(&argc,argv);
		glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
		glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
		glutCreateWindow("Misthaven");

		/* set up our function callbacks */
		bool ignoreRepeats = false;
		glutDisplayFunc(DisplayCallbackFunction);
		glutKeyboardFunc(KeyboardCallbackFunction);
		glutKeyboardUpFunc(KeyboardUpCallbackFunction);
		glutReshapeFunc(WindowReshapeCallbackFunction);
		glutTimerFunc(1,TimerCallbackFunction,0);
	
		/* initialize the image library engine */
		initImageLibrary();

		/* init the game */
		theGame = new Game();
		theGame->initializeGame();

		/* start the event handler */
		glutMainLoop();
		return 0;
	}
//																				|Sprite Lib|
//###########################################################################################