#include "Game.h"
#include "DrawPrimitives.h"

/* this is called by std::sort to sort the list based on layerID 
 *  for drawing in the proper order 
 */
bool spriteSortingFunction(Sprite *s1, Sprite *s2)
{
	// return true if s1's layerID is less than s2's layerID
	return (s1->layerID < s2->layerID);
}

/* constructor */
Game::Game(void)
{
	/* green background */
	stateInfo.bgClearColor.red = 0;
	stateInfo.bgClearColor.green = 0;
	stateInfo.bgClearColor.blue = 0;

	/* init state */
	stateInfo.gameState = STATE_GAMEPLAY;
	renderingTimer = new Timer("RENDER");
	updateTimer = new Timer("UPDATE");

	gameState=1;
	option=1;
}

/* destructor */
Game::~Game(void)
{
	/* deallocate memory and clean up here. if needed */
}

/* 
 * initializeGame()
 * - this function is called in the constructor to initialize everything related
 *   to the game, i..e loading sprites etc.
 * - MUST be called prior to any drawing/updating (you should add in checks to ensure this occurs in the right order)
 */


void Game::initializeGame()
{
	if (gameState==1)
	{
		Menu = new Sprite("images/MenuSprites.png");

		Menu -> setNumberOfAnimations(4);
		Menu -> setSpriteFrameSize(480,260);
		Menu -> setPosition(0,0);
		Menu -> setCenter(0,0);
		Menu -> setLayerID(1);

		Menu -> addSpriteAnimRow(3,0,0,480,0,1);
		Menu -> addSpriteAnimRow(2,0,0,480,260,1);
		Menu -> addSpriteAnimRow(1,0,0,480,520,1);

		Menu -> setCurrentAnimation(1);

		this -> addSpriteToDrawList(Menu);
	}

	if (gameState==2)
	{

	Player = new MainCharacter("images/PlayerSprite.png", 28,48);
	this->addSpriteToDrawList(Player);

	Map1_Base = new Sprite ("images/Map 1 Base.png");
	Map1_Base -> setNumberOfAnimations(1);
	Map1_Base -> setSpriteFrameSize(2500,2000);
	//Background -> setPosition(0,0);
	Map1_Base -> setPosition(-1450,-1050);
	Map1_Base -> setCenter(0,0);
	Map1_Base -> setLayerID (2);
	Map1_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
	Map1_Base -> setCurrentAnimation(1);
	this->addSpriteToDrawList(Map1_Base);

	Map1_Objects = new Sprite ("images/Map 1 Objects.png");
	Map1_Objects -> setNumberOfAnimations(1);
	Map1_Objects -> setSpriteFrameSize(2500,2000);
	//Background -> setPosition(0,0);
	Map1_Objects -> setPosition(-1450,-1050);
	Map1_Objects -> setCenter(0,0);
	Map1_Objects -> setLayerID (2);
	Map1_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
	Map1_Objects -> setCurrentAnimation(1);
	this->addSpriteToDrawList(Map1_Objects);

	WaterBackground = new Sprite ("images/Water Sprite.png");
	WaterBackground -> setNumberOfAnimations(1);
	WaterBackground -> setSpriteFrameSize(2860,1488);
	//WaterBackground -> setPosition(0,0);
			WaterBackground -> setPosition(-1700,-750);
	WaterBackground -> setCenter(0,0);
	WaterBackground -> setLayerID (1);
	WaterBackground ->addSpriteAnimRow(0,0,0,2860,1488,1);
	WaterBackground -> setCurrentAnimation(1);
	this->addSpriteToDrawList(WaterBackground);
	
	/*initialization*/
	mapSpeed = 0;
	WaterSpeed = 0;

	Health = new Sprite ("images/Hearts.png");
	Health -> setNumberOfAnimations(1);
	Health -> setSpriteFrameSize(132,32);
	Health -> setPosition(10,260);
	Health -> setCenter(0,0);
	Health -> setLayerID (3);
	Health ->addSpriteAnimRow(0,0,0,132,32,1);
	Health -> setCurrentAnimation(1);
	this->addSpriteToDrawList(Health);
	}
}

/* draw()
 * - this gets called automatically about 30 times per second
 * - this function just draws the sprites 
 */
void Game::draw()
{
	/* pre-draw - setup the rendering */
	PreDraw();

	/* draw - actually render to the screen */
	DrawGame();
	
	/* post-draw - after rendering, setup the next frame */
	PostDraw();
}

/*
 * Pre-Draw() is for setting up things that need to happen in order to draw
 *    the game, i.e. sorting, splitting things into appropriate lists etc.
 */
void Game::PreDraw()
{
	/* clear the screen */
	glViewport(0,0,stateInfo.windowWidth,stateInfo.windowHeight);
	glClearColor(stateInfo.bgClearColor.red, 
				 stateInfo.bgClearColor.green, 
				 stateInfo.bgClearColor.blue, 0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // clear out the transformation matrix
	glEnable(GL_TEXTURE_2D); // turn on texturing

	// if we update our timer it will tell us the elapsed time since the previous 
	// frame that we rendered
	renderingTimer->tick();


	/* sort the sprites by layerID so we draw them in the right order */
	std::sort(spriteListToDraw.begin(), spriteListToDraw.end(), spriteSortingFunction);

}

/* 
 * DrawGame()
 *  - this is the actual drawing of the current frame of the game.
 */

void Game::DrawGame()
{
	/* here is where your drawing stuff goes */
	drawSprites();

	glDisable(GL_TEXTURE_2D);
	drawTestPrimitives();

	/* this makes it actually show up on the screen */
	glutSwapBuffers();
}

/*
 * PostDraw()
 *  - in here you should clean up and set up things for the next frame
 *  - i.e. once I've used my assets, I can change them to set up things for
 *    the next frame, usually just memory management or setting up game state 
 *    boolean values etc.  
 */
void Game::PostDraw()
{
	// nothing here at the moment
}

/* drawSprites()
 * - this function is what actually draws the sprites
 *   onto the screen at their appropriate location
 * - it actually loops through a list of active sprites
 *   and then sorts them by their layerID and then draws them
 * - the sorting has to happen so that you draw from back to front
 *   just like a painter and a canvas.
 */
void Game::drawSprites()
{
	/* we could just do the following to draw the three sprites
	   but that would be silly since we have a list of sprites to draw
	   stored, so all we need to do is go through the list and draw eaach 
	   sprite in the list */
	/* // silly way 
	testSprite->draw();
	animatedSprite->draw();
	animatedSprite2->draw();
	*/
	
	/* better way */
	/* this is better because it doesn't matter how many sprites we have, they will always be drawn */
	std::vector<Sprite*>::iterator it; 
	for(it=spriteListToDraw.begin(); it != spriteListToDraw.end(); it++)
	{
		Sprite *s = (*it);
		s->draw();
	}

}

/* For testing purposes for drawing primitives for GDWII
* milestone
*/


void Game::drawTestPrimitives()
{
	
	/*Draw ze line*/
	//setLineWidth(5.f);
	//setColor(1,0,0);
	//drawLine(100,100,200,200);
	//setLineWidth(1.f);

	/* Draw rectangle */
	//setColor(1,1,0);
	//drawRectangle(true, 200,200,50,50,45.f);

}


/* update()
  - this function is essentially the game loop
    it gets called often and as such you
	don't actually need a "loop" to define the game
	it happens behind the scenes
  - think of this function as one iteration of the game loop
  - if you need to update physics calculations, sprite animation info,
    or sound etc, it goes in here
*/
void Game::update()
{
		updateTimer->tick();
		//Player->update();
		//Player->movement();
		if (gameState==1)
		{


		}


		if (gameState==2)
		{
		int count=1;

		if (test == true)//left right
		{

			Map1_Base -> positionX+=mapSpeed;
			Map1_Objects -> positionX+=mapSpeed;
			WaterBackground -> positionY-=1;
			WaterBackground -> positionX+=WaterSpeed;


		}
		else //up down
		{


			Map1_Base ->positionY+=mapSpeed;
			Map1_Objects ->positionY+=mapSpeed;
			WaterBackground -> positionY+=(WaterSpeed-1);
			

		}

		if (WaterBackground-> positionY < -1000)
		{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 
		}
}

/* 
 * addSpriteToDrawList()
 * - this function simply pushes the sprite to the end of the list
 */
void Game::addSpriteToDrawList(Sprite *s)
{
	if(s)
	{
		/* push the sprite to the back of the list */
		this->spriteListToDraw.push_back(s);
	}
}

/*************************************************/
/* INPUT - keyboard/mouse functions below        */
/*************************************************/
/* keyboardDown()
   - this gets called when you press a key down
   - you are given the key that was pressed
     and where the (x,y) location of the mouse is when pressed
*/

//===========================================================================================
// MENU CONTROL - Menu Function Implementations. 
//===========================================================================================

void MenuControl (int opt, int &gameState)
{  switch(opt)
   { 
      case 1: { 
		        gameState=2; 
				
		        break;
			  }
      case 2: break;
	  case 3: exit(1); break;
   }
}
     

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{

//===========================================================================================
// MENU - Menu without control & Passing.
//===========================================================================================

	if (gameState==1)
	{
		switch(key)
		{   case 'd':  { if (option!=3)
						    { 
						        option++; 
						    }
					     Menu->setCurrentAnimation(option); 
					     break;
					   }

			case 'a':  { if (option!=1)
						    { 
						        option--; 
						    }
					     Menu->setCurrentAnimation(option); 
					     break;
					   }
			case 13: { MenuControl(option,gameState);initializeGame(); break;}
		}
	}



	if (gameState==2)
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;

	case 'w':
		test = false;
		mapSpeed = -9;
	    WaterSpeed = -4;
		Player->setCurrentAnimation(2);
		Player->nextFrame();
	break;

	case 'a':
		test = true;
		
		mapSpeed = 9;
	    WaterSpeed = 4;
		Player->setCurrentAnimation(4);
		Player->nextFrame();
	break;
	case 'd':
		test = true;
		mapSpeed = -9;
	    WaterSpeed = -4;
		
		Player->setCurrentAnimation(3);
		Player->nextFrame();

	break;


	case 's':
		test = false;
		mapSpeed = 9;
		WaterSpeed = 4;
		Player->setCurrentAnimation(1);
		Player->nextFrame();
		
		
	break;



	}
}



/* keyboardUp()
   - this gets called when you lift a key up
   - you are given the key that was pressed
     and where the (x,y) location of the mouse is when pressed
*/
void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
	if (gameState==1)
	{




	}

	if (gameState==2)
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;


		
	case 'w':
		mapSpeed = 0;
		WaterSpeed = 0;
	break;

	case 'a':
		mapSpeed = 0;
		WaterSpeed = 0;
	break;
	case 'd':
		mapSpeed = 0;
	    WaterSpeed = 0;
	break;


	case 's':
		mapSpeed = 0;
	    WaterSpeed = 0;
	break;

	}
}