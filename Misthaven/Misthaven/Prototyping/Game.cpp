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
	stateInfo.bgClearColor.green = 1;
	stateInfo.bgClearColor.blue = 0;

	/* init state */
	stateInfo.gameState = STATE_GAMEPLAY;
	renderingTimer = new Timer("RENDER");
	updateTimer = new Timer("UPDATE");
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
	Player = new MainCharacter("images/PlayerSprite.png", 28,48);
	this->addSpriteToDrawList(Player);

	/* Will place what Aaron has currently here until I integrate it properly*/

	Background = new Sprite ("images/Background Sprite.png");
	Background -> setNumberOfAnimations(1);
	Background -> setSpriteFrameSize(2860,1488);
	//Background -> setPosition(0,0);
	Background -> setPosition(-1700,-750);
	Background -> setCenter(0,0);
	Background -> setLayerID (2);
	Background ->addSpriteAnimRow(0,0,0,2860,1488,1);
	Background -> setCurrentAnimation(1);
	this->addSpriteToDrawList(Background);
	mapSpeed = 0;


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
	mapSpeed = 0;
	WaterSpeed = 0;

	Health = new Sprite ("images/Hearts.png");
	Health -> setNumberOfAnimations(1);
	Health -> setSpriteFrameSize(132,32);
	Health -> setPosition(0,0);
	Health -> setCenter(0,0);
	Health -> setLayerID (3);
	Health -> addSpriteAnimRow(0,0,0,132,32,1);
	Health -> setCurrentAnimation(1);
	this->addSpriteToDrawList(Health);
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
	setLineWidth(5.f);
	setColor(1,0,0);
	drawLine(100,100,200,200);
	setLineWidth(1.f);

	/* Draw rectangle */
	setColor(1,1,0);
	drawRectangle(true, 200,200,50,50,45.f);
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
		Player->update();
		Player->movement();

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
void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
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
	switch(key)
	{
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}