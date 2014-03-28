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
	this->addToObjectsList(Player);

	Ghosty1 = new Ghost ("images/Water Sprite.png", 28,48);
	Ghosty1 -> setPosition(0,0);
	this->addSpriteToDrawList(Ghosty1);
	this->addToObjectsList(Ghosty1);

	Ghosty2 = new Ghost ("images/Water Sprite.png", 28,48);
	Ghosty2 -> setPosition(0,0);
	this->addSpriteToDrawList(Ghosty2);
	this->addToObjectsList(Ghosty2);

	Ghosty3 = new Ghost ("images/Water Sprite.png", 28,48);
	Ghosty3 -> setPosition(0,0);
	this->addSpriteToDrawList(Ghosty3);
	this->addToObjectsList(Ghosty3);

	Ghosty4 = new Ghost ("images/Water Sprite.png", 28,48);
	Ghosty4 -> setPosition(0,0);
	this->addSpriteToDrawList(Ghosty4);
	this->addToObjectsList(Ghosty4);

	fMirrorX = -687;
	fMirrorY= -891;

	Map01Base = new Objects ("images/Levels/Map 1 Base.png", 2500,2000);
	Map01Base -> setNumberOfAnimations(1);
	Map01Base -> setPosition(fMirrorX,fMirrorY);
	Map01Base -> setLayerID (3);
	Map01Base -> addSpriteAnimFrame(0,0,0);
	Map01Base -> setCurrentAnimation(0);
	this->addSpriteToDrawList(Map01Base);
	this->addToObjectsList(Map01Base);

	Map01Objects = new Objects ("images/Levels/Map 1 Objects.png", 2500,2000);
	Map01Objects-> setNumberOfAnimations(1);
	Map01Objects -> setPosition(fMirrorX,fMirrorY);
	Map01Objects -> setLayerID (15);
	Map01Objects -> addSpriteAnimFrame(0,0,0);
	Map01Objects -> setCurrentAnimation(0);
	this->addSpriteToDrawList(Map01Objects);
	this->addToObjectsList(Map01Objects);


	WaterBackground = new Objects ("images/Water Sprite.png",2860,1488);
	WaterBackground -> setNumberOfAnimations(1);
	WaterBackground -> setPosition(fMirrorX,fMirrorY);
	WaterBackground -> setLayerID (1);
	WaterBackground -> addSpriteAnimFrame(0,0,0);
	WaterBackground -> setCurrentAnimation(0);
	this->addSpriteToDrawList(WaterBackground);
	this->addToObjectsList(WaterBackground);

	Health = new Objects ("images/Player&HUD/Hearts.png",132,32);
	Health -> setNumberOfAnimations(1);
	Health -> setPosition(5,5);
	Health -> setLayerID (20);
	Health -> addSpriteAnimFrame(0,0,0);
	Health -> setCurrentAnimation(0);
	Health -> stationary = true;
	this->addSpriteToDrawList(Health);
	this->addToObjectsList(Health);
	
	// vvvv Works vvvv
	std::cout << "Map01Base position (x,y) : (" << (Map01Base->positionX) << ", " << (Map01Base->positionY)<< ") " << std::endl;
	std::cout << "Map01Base speed for x: " << (Map01Base->speedX) << " and for y: " << (Map01Base->speedY) << std::endl;
	std::cout << "Map 01 width and height, width : " << (Map01Base->sz.width) << " and height: " << (Map01Base->sz.height) << std::endl; 

	// No work
	std::cout << "Player corners, bottom left X: " << (Player->ObjectHitbox->leftCornerX) << ", bottom right X: " << (Player->ObjectHitbox->rightCornerX) << std::endl;
	std::cout << "bottom cornerY: " << (Player->ObjectHitbox->bottomCornerY) << ", and top corner Y: " << (Player->ObjectHitbox->topCornerY) << std::endl;

	// vvvv Works vvvv
	std::cout << "Before Biscuit" << std::endl;
	MapConstraints = Constraints("images/Levels/Map01Constraints.bmp");
	std::cout << "At Biscuit" << std::endl;
	std::cout << "Location of 919, 1047: " << MapConstraints.vConstraintVector[919][1047] << std::endl;

	/*
	newMapPositionX = (Map01Base->positionX) + (Map01Base->speedX);
	newMapPositionY = (Map01Base->positionY) + (Map01Base->speedY);

	indexStartX = (Map01Base->sz.width) + (Player->ObjectHitbox->leftCornerX) + newMapPositionX; 
	indexStartY = (Map01Base->sz.normalizedHeight) + (Player->ObjectHitbox->bottomCornerY) + newMapPositionY;
	indexEndX = indexStartX + (Player->ObjectHitbox->rightCornerX); indexEndY = indexStartY + (Player->ObjectHitbox->topCornerY);
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


		//Update all in-game Objects
		updateObjects();
		allowMovement();
		movement();

		Ghosty1->movementGhost((Player->positionX),(Player->positionY));
		Ghosty2->movementGhost((Player->positionX),(Player->positionY));
		Ghosty3->movementGhost((Player->positionX),(Player->positionY));
		Ghosty4->movementGhost((Player->positionX),(Player->positionY));
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


/*ALL THINGS RELATED TO THE OBJECT LIST*/

/*All things related to adding to the ObjectsList*/
void Game::addToObjectsList(Objects *o)
{
	if(o)
	{
		/* push the Object to the back of the list */
		this->objectsList.push_back(o);
	}
}

// To streamline the code, update all the Objects from object list at once.
void Game::updateObjects()
{
			std::vector<Objects*>::iterator itUpdate; 
		for(itUpdate= objectsList.begin() ; itUpdate !=objectsList.end() ; itUpdate++)
	{
		Objects *o = (*itUpdate);
		o-> update();
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
	case 'e':
		{
			std::cout<< updateTimer->getCurrentTime() << std::endl;
			std::cout<< updateTimer->getElapsedTimeSeconds() << std::endl;
			std::cout<< updateTimer->tick() << std::endl;
			break;
		};
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

void Game::moveObjectsKeyboardDown(unsigned char key)
{

		std::vector<Objects*>::iterator itMoveGo; 
		for(itMoveGo=objectsList.begin() ; itMoveGo !=objectsList.end() ; itMoveGo++)
	{
		Objects *o = (*itMoveGo);
		o-> movementGo(key);
	}
}

void Game::moveObjectsKeyboardUp(unsigned char key)
{

		std::vector<Objects*>::iterator itMoveStop; 
		for(itMoveStop= objectsList.begin() ; itMoveStop !=objectsList.end() ; itMoveStop++)
	{
		Objects *o = (*itMoveStop);
		o-> movementStop(key);
	}
}

/*Checks player's hitbox, current map position, and constraints*/
void Game::allowMovement()
{
	//std::cout << "allowmovementcheck begin" << std::endl;
	int interception; //Counts the occurences of interception
	float stop = 0.f; //stops all movement when interception >=1
	float newMapPositionX, newMapPositionY;
	int indexStartX,indexStartY, indexEndX,indexEndY;

	int vecindexX, vecindexY;
	interception = 0;

	//std::cout << " initialize allowMovement variables" << std::endl;
	newMapPositionX = (Map01Base->positionX) + (Map01Base->inMotionSpeedX);
	newMapPositionY = (Map01Base->positionY) + (Map01Base->inMotionSpeedY);

	indexStartX = 0 + (Player->ObjectHitbox->leftCornerX) - newMapPositionX; 
	indexStartY = 0 + (Player->ObjectHitbox->bottomCornerY) - newMapPositionY;
	indexEndX = 0 + (Player->ObjectHitbox->rightCornerX) - newMapPositionX; 
	indexEndY = 0 + (Player->ObjectHitbox->topCornerY) - newMapPositionY;

	//std::cout << "Index starts (x,y): (" << indexStartX << ", " << indexStartY << ") " << std::endl;
	//std::cout << "Index end (x,y): (" << indexEndX << ", " << indexEndY << ") " << std::endl;
	//std::cout << "Check constraint vector" << std::endl;
	for (vecindexX = indexStartX; vecindexX <= indexEndX; vecindexX++)
		for(vecindexY = indexStartY; vecindexY <= indexEndY; vecindexY++)
		{
			if (MapConstraints.vConstraintVector[vecindexX][vecindexY] == true)
			{
				/* Nothing */
			} else if (MapConstraints.vConstraintVector[vecindexX][vecindexY] == false) {
				interception++;
				break; //ends the loop

			} else{
				//Nothing
			};

		};
	std::cout << "Checked constraint vector" << std::endl;
		if(interception >= 1){
		//	std::cout << "Intercept detected" << std::endl;
			std::vector<Objects*>::iterator itNoMove;
			for(itNoMove= objectsList.begin(); itNoMove !=objectsList.end() ; itNoMove++)
			{
				Objects *o = (*itNoMove);
				o-> inMotionSpeedX = stop;
				o-> inMotionSpeedY = stop;
			};
		}else
		{
			std::cout << "No intercept detected" << std::endl;
		};
	//std::cout << "Yay! Success!" << std::endl;
	interception = 0;
}

void Game::movement()
{

	std::vector<Objects*>::iterator itMovement;
	for(itMovement= objectsList.begin() ; itMovement !=objectsList.end() ; itMovement++)
	{
		float newPositionX, newPositionY;
		float currentPositionX, currentPositionY;
		float currentSpeedX, currentSpeedY;
		Objects *o = (*itMovement);

		currentPositionX = (o-> positionX); currentPositionY = (o-> positionY);
		currentSpeedX = (o-> inMotionSpeedX) + (o-> respectiveSpeedX); 
		currentSpeedY = (o-> inMotionSpeedY) + (o-> respectiveSpeedY);

		newPositionX = currentPositionX + currentSpeedX;
		newPositionY = currentPositionY + currentSpeedY;

		o-> positionX = newPositionX;
		o-> positionY = newPositionY;
	};

}