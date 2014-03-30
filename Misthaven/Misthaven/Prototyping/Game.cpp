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
	std::cout<<"\n\n    BOOT UP: LOADING SPRITES: "; //Loading Text

	MainMenu* MenuState = new MainMenu();
	MenuState->Init(this);
	states.push_back(MenuState);

	LevelHome* StateHome = new LevelHome();
	StateHome->Init(this);
	states.push_back(StateHome);

	LevelOne* StateOne = new LevelOne();
	StateOne->Init(this);
	states.push_back(StateOne);

	LevelTwo* StateTwo = new LevelTwo();
	StateTwo->Init(this);
	states.push_back(StateTwo);

	LevelThree* StateThree = new LevelThree();
	StateThree->Init(this);
	states.push_back(StateThree);
	

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
//	std::vector<Sprite*>::iterator it; 
//	for(it=spriteListToDraw.begin(); it != spriteListToDraw.end(); it++)
//	{
//		Sprite *s = (*it);
//		s->draw();
//	}
//

//===========================================================================================
//								 SPRITE ITERATOR
//===========================================================================================
	std::vector<GameState*>::iterator it;
	for (it = states.begin(); it != states.end(); it++)
	{
		if (*it)
		{  
			  GameState* s = (*it);
			  if(s->active==true)
			  s->Draw();
		}

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

		/* Beginning of integration*/
			std::vector<GameState*>::iterator it;
	for (it = states.begin(); it != states.end(); it++)
	{
		if (*it)
		{  
			  GameState* s = (*it);
			  if(s->active==true)
			  s->Update();
		}

	}

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
	case 32: // the space bar
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}

	//===========================================================================================
//								 KEYDOWN ITERATOR
//===========================================================================================

	std::vector<GameState*>::iterator it;
	for (it = states.begin(); it != states.end(); it++)
	{
		if (*it)
		{
			GameState* s = (*it);
			if(s->active==true)
			s->KeyDown(key);
		}
	}

//===========================================================================================
//								 TESTING KEYS (StateChanges)
//===========================================================================================

			switch(key)
			{
			case '1': {		SwitchStateTo (StateHome, 1);
							break;  }
			case '2': {		SwitchStateTo (StateHome, 2);
							break;  }
			case '3': {		SwitchStateTo (StateHome, 3);
							break;  }
			case '4': {		SwitchStateTo (StateHome, 4);
							break;  }
			case '5': {		SwitchStateTo (StateHome, 5);
							break;  }
			case 't': {     std::cout<<"YOLO\n"; break; }
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

		std::vector<GameState*>::iterator it;
	for (it = states.begin(); it != states.end(); it++)
	{
		if (*it)
		{
			GameState* s = (*it);
			if(s->active==true)
			s->KeyUp(key);
		}
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
	////std::cout << "allowmovementcheck begin" << std::endl;
	//int interception; //Counts the occurences of interception
	//float stop = 0.f; //stops all movement when interception >=1
	//float newMapPositionX, newMapPositionY;
	//int indexStartX,indexStartY, indexEndX,indexEndY;

	//int vecindexX, vecindexY;
	//interception = 0;

	////std::cout << " initialize allowMovement variables" << std::endl;
	//newMapPositionX = (Map01Base->positionX) + (Map01Base->inMotionSpeedX);
	//newMapPositionY = (Map01Base->positionY) + (Map01Base->inMotionSpeedY);

	//indexStartX = 0 + (Player->ObjectHitbox->leftCornerX) - newMapPositionX; 
	//indexStartY = 0 + (Player->ObjectHitbox->bottomCornerY) - newMapPositionY;
	//indexEndX = 0 + (Player->ObjectHitbox->rightCornerX) - newMapPositionX; 
	//indexEndY = 0 + (Player->ObjectHitbox->topCornerY) - newMapPositionY;

	////std::cout << "Index starts (x,y): (" << indexStartX << ", " << indexStartY << ") " << std::endl;
	////std::cout << "Index end (x,y): (" << indexEndX << ", " << indexEndY << ") " << std::endl;
	////std::cout << "Check constraint vector" << std::endl;
	//for (vecindexX = indexStartX; vecindexX <= indexEndX; vecindexX++)
	//	for(vecindexY = indexStartY; vecindexY <= indexEndY; vecindexY++)
	//	{
	//		if (MapConstraints.vConstraintVector[vecindexX][vecindexY] == true)
	//		{
	//			/* Nothing */
	//		} else if (MapConstraints.vConstraintVector[vecindexX][vecindexY] == false) {
	//			interception++;
	//			break; //ends the loop

	//		} else{
	//			//Nothing
	//		};

	//	};
	//std::cout << "Checked constraint vector" << std::endl;
	//	if(interception >= 1){
	//	//	std::cout << "Intercept detected" << std::endl;
	//		std::vector<Objects*>::iterator itNoMove;
	//		for(itNoMove= objectsList.begin(); itNoMove !=objectsList.end() ; itNoMove++)
	//		{
	//			Objects *o = (*itNoMove);
	//			o-> inMotionSpeedX = stop;
	//			o-> inMotionSpeedY = stop;
	//		};
	//	}else
	//	{
	//		std::cout << "No intercept detected" << std::endl;
	//	};
	////std::cout << "Yay! Success!" << std::endl;
	//interception = 0;
}

void Game::movement()
{

	//std::vector<Objects*>::iterator itMovement;
	//for(itMovement= objectsList.begin() ; itMovement !=objectsList.end() ; itMovement++)
	//{
	//	float newPositionX, newPositionY;
	//	float currentPositionX, currentPositionY;
	//	float currentSpeedX, currentSpeedY;
	//	Objects *o = (*itMovement);

	//	currentPositionX = (o-> positionX); currentPositionY = (o-> positionY);
	//	currentSpeedX = (o-> inMotionSpeedX) + (o-> respectiveSpeedX); 
	//	currentSpeedY = (o-> inMotionSpeedY) + (o-> respectiveSpeedY);

	//	newPositionX = currentPositionX + currentSpeedX;
	//	newPositionY = currentPositionY + currentSpeedY;

	//	o-> positionX = newPositionX;
	//	o-> positionY = newPositionY;
	//};

}

