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
//	iScore = 0;
	
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
	float fMirrorX, fMirrorY; //Where I desire the map and object layer of the map to be in relation to the player and their origin point

	Player = new MainCharacter ("images/Player&HUD/PlayerSprite.png", 28,48);
	this->addSpriteToDrawList(Player);

	fMirrorX = -687;
	fMirrorY= -891;

	Map01Base = new Objects ("images/Levels/Map 1 Base.png", 2500,2000);
	Map01Base -> setNumberOfAnimations(1);
	Map01Base -> setPosition(fMirrorX,fMirrorY);
	Map01Base -> setLayerID (2);
	Map01Base -> addSpriteAnimFrame(0,0,0);
	Map01Base -> setCurrentAnimation(0);
	this->addSpriteToDrawList(Map01Base);

	Map01Objects = new Objects ("images/Levels/Map 1 Objects.png", 2500,2000);
	Map01Objects-> setNumberOfAnimations(1);
	Map01Objects -> setPosition(fMirrorX,fMirrorY);
	Map01Objects -> setLayerID (3);
	Map01Objects -> addSpriteAnimFrame(0,0,0);
	Map01Objects -> setCurrentAnimation(0);
	this->addSpriteToDrawList(Map01Objects);


	WaterBackground = new Objects ("images/Water Sprite.png",2860,1488);
	WaterBackground -> setNumberOfAnimations(1);
	WaterBackground -> setPosition(fMirrorX,fMirrorY);
	WaterBackground -> setLayerID (1);
	WaterBackground -> addSpriteAnimFrame(0,0,0);
	WaterBackground -> setCurrentAnimation(0);
	this->addSpriteToDrawList(WaterBackground);

	Health = new Objects ("images/Player&HUD/Hearts.png",132,32);
	Health -> setNumberOfAnimations(1);
	Health -> setPosition(0,216);
	Health -> setLayerID (4);
	Health -> addSpriteAnimFrame(0,0,0);
	Health -> setCurrentAnimation(0);
	Health -> stationary = true;
	this->addSpriteToDrawList(Health);

	MapConstraints = new Constraints("images/Levels/Map01Constraints.bmp");
	std::cout << "At Biscuit" << std::endl;
	/*
	if (MapConstraints->vConstraintVector[919][1047] == true)
	{
		std::cout << "True" <<std::endl;
	} else if(MapConstraints->vConstraintVector[919][1047] == false )
	{ 
		std::cout << "False" <<std::endl;
	}
	else
	{
		std::cout << "WAT?!" <<std::endl;
	};
	*/
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
	//drawTestPrimitives();  // Test draw the primitives

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
	/* Score */
//	setColor(1,1,1);
//	drawText("SCORE: ",350,290);
//	drawNum(iScore,430,290);
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
		// Time
		updateTimer->tick();

		// Player
		Player->update();
		
		

		//Characters

		// Static
		Map01Base->update();
		Map01Objects->update();
		WaterBackground->update();
		Health->update();

		//Score
//		iScore++;
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