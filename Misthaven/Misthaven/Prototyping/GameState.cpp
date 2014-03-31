//###########################################################################################
//
//									    GAME STATE.cpp
//																			|Aaron Alphonso|
//###########################################################################################

			#include "GameState.h"

//-------------------------------------------------------------------------------------------
//  Uses GameState.h to implement the game states and define their respective functions. 
//-------------------------------------------------------------------------------------------

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//									 SPRITE ITERATOR									   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||

	void GameState::addSpriteToDrawList(Sprite *s)
	{
		if(s) /* Push the sprite to the back of the list */
		{
			std::cout<<"||";	//Loading Screen.

			this->spriteListToDraw.push_back(s);
		}
	}


	void GameState::Draw()
	{
		std::vector<Sprite*>::iterator it; 
		for(it=spriteListToDraw.begin(); it != spriteListToDraw.end(); it++)
		{ 
			Sprite *s = (*it);
			s->draw();
		}
	}

	/*All things related to adding to the ObjectsList*/
void GameState::addToObjectsList(Objects *o)
{
	if(o)
	{
		/* push the Object to the back of the list */
		this->objectsList.push_back(o);
	}
}

// To streamline the code, update all the Objects from object list at once.
void GameState::updateObjects()
{
			std::vector<Objects*>::iterator itUpdate; 
		for(itUpdate= objectsList.begin() ; itUpdate !=objectsList.end() ; itUpdate++)
	{
		Objects *o = (*itUpdate);
		o-> update();
	}
}

void GameState::moveObjectsKeyboardDown(unsigned char key)
{

		std::vector<Objects*>::iterator itMoveGo; 
		for(itMoveGo=objectsList.begin() ; itMoveGo !=objectsList.end() ; itMoveGo++)
	{
		Objects *o = (*itMoveGo);
		o-> movementGo(key);
	}
}

void GameState::moveObjectsKeyboardUp(unsigned char key)
{

		std::vector<Objects*>::iterator itMoveStop; 
		for(itMoveStop= objectsList.begin() ; itMoveStop !=objectsList.end() ; itMoveStop++)
	{
		Objects *o = (*itMoveStop);
		o-> movementStop(key);
	}
}

void GameState::movement()
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
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 MAIN MENU ----- STATE 1								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void MainMenu::Init(Game* Local)
	{
			StateNum=1;
			LocalGame=Local;
			menuSpeed=0;
			active=true;

		//	LocalGame -> playSound(); //PLAY'S FMOD LOOP BACKGROUND SOUND.

				//Sprite - Menu Background.
				MenuBG = new Sprite("images/Menu Background.png");
				MenuBG -> setNumberOfAnimations(1);
				MenuBG -> setSpriteFrameSize(960,260);
				MenuBG -> setPosition(0,0);
				MenuBG -> setCenter(0,0);
				MenuBG -> setLayerID(1);
				MenuBG -> addSpriteAnimRow(0,0,0,960,260,1);
				MenuBG -> setCurrentAnimation(1);
				this -> addSpriteToDrawList(MenuBG);

				//Sprite - Menu Overlay.
				MenuOverlay = new Sprite("images/Menu Overlay.png");
				MenuOverlay -> setNumberOfAnimations(1);
				MenuOverlay -> setSpriteFrameSize(480,260);
				MenuOverlay -> setPosition(0,0);
				MenuOverlay -> setCenter(0,0);
				MenuOverlay -> setLayerID(6);
				MenuOverlay -> addSpriteAnimRow(0,0,0,480,260,1);
				MenuOverlay -> setCurrentAnimation(1);
				this -> addSpriteToDrawList(MenuOverlay);

				//Sprite - Menu Strip.
				MenuStrip = new Sprite("images/Menu Strip.png");
				MenuStrip -> setNumberOfAnimations(5);
				MenuStrip -> setSpriteFrameSize(1400,35);
				MenuStrip -> setPosition(0,80);
				MenuStrip -> setCenter(0,0);
				MenuStrip -> setLayerID(5);
				MenuStrip -> addSpriteAnimRow(4,0,0,1400,0,1);
				MenuStrip -> addSpriteAnimRow(3,0,0,1400,35,1);
				MenuStrip -> addSpriteAnimRow(2,0,0,1400,70,1);
				MenuStrip -> addSpriteAnimRow(1,0,0,1400,105,1);
				MenuStrip -> addSpriteAnimRow(0,0,0,1400,140,1);
				MenuStrip -> setCurrentAnimation(0);
				this -> addSpriteToDrawList(MenuStrip);

				//Main Character - PlayerSprite.
				Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 28,48);
				this->addSpriteToDrawList(Player);
				Player->setPosition(230,90);
				Player->setCurrentAnimation(1);
				Player->setLayerID(4);



	}


	void MainMenu::ResetMap()
	{ 
			MenuBG -> setPosition(0,0);
			MenuStrip -> setPosition(0,80);
			Player->setPosition(230,90);
			Player->setCurrentAnimation(1);
	}


	MainMenu::~MainMenu(void) 
	{ 
		/*Default deconstructor */
	}


	void MainMenu::Update()
	{

				if ( test==true )
				{ MenuStrip -> positionX+=menuSpeed; } //Scrolling the menu strip.

				if ( MenuStrip -> positionX > -65 )
				{ MenuStrip -> setPosition(-65,60); } //Setting contraints for strip.
					else
				if ( MenuStrip -> positionX < -875 )
				{ MenuStrip -> setPosition(-875,60); } //Setting contraints for strip.

				//SCROLLING BACKGROUND:
				MenuBG -> positionX-=1; //Setting scrolling speed for background.

				if ( MenuBG -> positionX < -480 )
				{ MenuBG -> setPosition(0,0); } //Looping the scrolling background.


	}


	void MainMenu::KeyDown(unsigned char key)
	{
		switch(key)
			{   case 'd':  { 	test = true; //Going Horozontal
							
								if ( 0 < MenuStrip -> positionX < 866 )
								{ menuSpeed = -10; } //Menu Strip Speed.

								Player->setCurrentAnimation(3);
								Player->nextFrame();

								//Option: calculated based on PositionX of Strip.
								option=int((MenuStrip -> positionX/200)*-1)+1;
								MenuStrip->setCurrentAnimation(option-1); 
								break;
						   }

				case 'a':  {    test = true; //Going Horozontal
								
								if ( 0 < MenuStrip -> positionX < 866 )
								{ menuSpeed = +10; } //Menu Strip Speed.
								
								Player->setCurrentAnimation(4);
								Player->nextFrame();

								//Option: calculated based on PositionX of Strip.
								option=int((MenuStrip -> positionX/200)*-1)+1;
								MenuStrip->setCurrentAnimation(option-1); 
								break;
						   }

				case 13: {		//since int will down to option;
								option=int((MenuStrip -> positionX/200)*-1)+1;
								//MenuControl(option);
								break;}
			}
	}


	void MainMenu::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 'a':
					menuSpeed = 0;
					break;

				case 'd':
					menuSpeed = 0;
					break;
			}
	}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 LEVEL HOME ----- STATE 2								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void LevelHome::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=2;
		LocalGame=Local;
		active=false;
		loadcheck=false;

		    //Sprite - Water Background.
			WaterBackgroundHome = new Objects ("images/Backgrounds/Water Sprite.png", 2500, 2000);
			WaterBackgroundHome -> setNumberOfAnimations(1);
			WaterBackgroundHome -> setPosition(-1700,-750);
			WaterBackgroundHome -> setCenter(0,0);
			WaterBackgroundHome -> setLayerID (1);
			WaterBackgroundHome ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackgroundHome -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackgroundHome);
			this->addToObjectsList(WaterBackgroundHome);

			//Sprite - Map 1 Base.
			Map1_Base = new Objects ("images/Levels/Map 1 Base.png", 2500, 2000);
			Map1_Base -> setNumberOfAnimations(1);
			Map1_Base -> setPosition(-1422,-1033);
			Map1_Base -> setCenter(0,0);
			Map1_Base -> setLayerID (2);
			Map1_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map1_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map1_Base);
			this->addToObjectsList(Map1_Base);

			//Sprite - Player Sprites.
			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 28,48);
			
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);
			
			//Sprite - Map 1 Objects.
			Map1_Objects = new Objects ("images/Levels/Map 1 Objects.png", 2500, 2000);
			Map1_Objects -> setNumberOfAnimations(1);
			Map1_Objects -> setPosition(-1422,-1033);  //-1422, -1033
			Map1_Objects -> setCenter(0,0);
			Map1_Objects -> setLayerID (6);
			Map1_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map1_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map1_Objects);
			this->addToObjectsList(Map1_Objects);

			//Sprite - UI Sample.
			UISample = new Sprite ("images/Test UI.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(480,261);
			UISample -> setPosition(0,0);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (7);
			UISample ->addSpriteAnimRow(0,0,0,480,261,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);

			std::cout << "Before Biscuit" << std::endl;
			MapConstraintsHome = Constraints("images/Levels/Map 1 Constraints.bmp");
			std::cout << "At Biscuit" << std::endl;
			std::cout << "Location of 919, 1047: " << MapConstraintsHome.vConstraintVector[919][1047] << std::endl;

	}


	void LevelHome::ResetMap()
	{ 
				WaterBackgroundHome -> setPosition(-1700,-750);
				Map1_Base -> setPosition(-1422,-1033); // -1422, -1033
				Player->setPosition(230,130);
				Player->setCurrentAnimation(1);
				Map1_Objects -> setPosition(-1422,-1033); //-1422, -1033
				std::cout << "Player's position (x,y): (" << Player->positionX << ", " << Player->positionY << ")" <<std::endl;
				std::cout << "Corners, left x: " << Player->ObjectHitbox->leftCornerX << ", right x: " << Player->ObjectHitbox->rightCornerX << std::endl;
				std::cout << "Corners cont,  bottom y: " << Player->ObjectHitbox->bottomCornerY << ", top y: " << Player->ObjectHitbox->topCornerY << std::endl;
	}


	LevelHome::~LevelHome(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelHome::Update()
	{

		updateObjects();
		allowMovement();
		movement();

	}


	void LevelHome::KeyDown(unsigned char key)
	{
		moveObjectsKeyboardDown(key);
	}


	void LevelHome::KeyUp(unsigned char key)
	{
		moveObjectsKeyboardUp(key);
	}

	void LevelHome::allowMovement()
{
	//std::cout << "allowmovementcheck begin" << std::endl;
	int interception; //Counts the occurences of interception
	float stop = 0.f; //stops all movement when interception >=1
	float newMapPositionX, newMapPositionY;
	int indexStartX,indexStartY, indexEndX,indexEndY;

	int vecindexX, vecindexY;
	interception = 0;

	//std::cout << " initialize allowMovement variables" << std::endl;
	newMapPositionX = (Map1_Base->positionX) + (Map1_Base->inMotionSpeedX);
	newMapPositionY = (Map1_Base->positionY) + (Map1_Base->inMotionSpeedY);

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
			if (MapConstraintsHome.vConstraintVector[vecindexX][vecindexY] == true)
			{
				/* Nothing */
			} else if (MapConstraintsHome.vConstraintVector[vecindexX][vecindexY] == false) {
				interception++;
				break; //ends the loop

			} else{
				//Nothing
			};

		};
	//std::cout << "Checked constraint vector" << std::endl;
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
		//	std::cout << "No intercept detected" << std::endl;
		};
	//std::cout << "Yay! Success!" << std::endl;
	interception = 0;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 LEVEL ONE ----- STATE 3								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void LevelOne::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=3;
		LocalGame=Local;
		active=false;
		loadcheck=false;

		    //Sprite - Water Background.
			WaterBackgroundOne = new Objects ("images/Backgrounds/Water Sprite 2.png",2500,2000);
			WaterBackgroundOne -> setNumberOfAnimations(1);
			WaterBackgroundOne -> setPosition(-1700,-750);
			WaterBackgroundOne -> setCenter(0,0);
			WaterBackgroundOne -> setLayerID (1);
			WaterBackgroundOne ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackgroundOne -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackgroundOne);
			this->addToObjectsList(WaterBackgroundOne);

			//Sprite - Map 2 Base.
			Map2_Base = new Objects ("images/Levels/Map 2 Base.png", 2500,2000);
			Map2_Base -> setNumberOfAnimations(1);
			Map2_Base -> setPosition(-475,-1410);
			Map2_Base -> setCenter(0,0);
			Map2_Base -> setLayerID (2);
			Map2_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map2_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map2_Base);
			this->addToObjectsList(Map2_Base);

			//Sprite - Player Sprites.
			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 28,48);

			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);
			
			//Sprite - Map 1 Objects.
			Map2_Objects = new Objects ("images/Levels/Map 2 Objects.png" , 2500, 2000);
			Map2_Objects -> setNumberOfAnimations(1);
			Map2_Objects -> setPosition(-475,-1410);
			Map2_Objects -> setCenter(0,0);
			Map2_Objects -> setLayerID (6);
			Map2_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map2_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map2_Objects);
			this->addToObjectsList(Map2_Objects);

			//Sprite - UI Sample.
			UISample = new Sprite ("images/Test UI.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(480,261);
			UISample -> setPosition(0,0);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (7);
			UISample ->addSpriteAnimRow(0,0,0,480,261,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);

			std::cout << "Before Biscuit One" << std::endl;
			MapConstraintsOne = Constraints("images/Levels/Map 2 Constraints.bmp");
			std::cout << "At Biscuit One" << std::endl;
	}


	void LevelOne::ResetMap()
	{ 
				WaterBackgroundOne -> setPosition(-1700,-750);
				Map2_Base -> setPosition(-475,-1410);
				Player-> setPosition(230,130);
				Player-> setCurrentAnimation(1);
				Map2_Objects -> setPosition(-475,-1410);
	}


	LevelOne::~LevelOne(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelOne::Update()
	{
		updateObjects();
		allowMovement();
		movement();
	}


	void LevelOne::KeyDown(unsigned char key)
	{
		moveObjectsKeyboardDown(key);
	}


	void LevelOne::KeyUp(unsigned char key)
	{
		moveObjectsKeyboardUp(key);
	}

	void LevelOne::allowMovement()
{
	//std::cout << "allowmovementcheck begin" << std::endl;
	int interception; //Counts the occurences of interception
	float stop = 0.f; //stops all movement when interception >=1
	float newMapPositionX, newMapPositionY;
	int indexStartX,indexStartY, indexEndX,indexEndY;

	int vecindexX, vecindexY;
	interception = 0;

	//std::cout << " initialize allowMovement variables" << std::endl;
	newMapPositionX = (Map2_Base->positionX) + (Map2_Base->inMotionSpeedX);
	newMapPositionY = (Map2_Base->positionY) + (Map2_Base->inMotionSpeedY);

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
			if (MapConstraintsOne.vConstraintVector[vecindexX][vecindexY] == true)
			{
				/* Nothing */
			} else if (MapConstraintsOne.vConstraintVector[vecindexX][vecindexY] == false) {
				interception++;
				break; //ends the loop

			} else{
				//Nothing
			};

		};
	//std::cout << "Checked constraint vector" << std::endl;
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
		//	std::cout << "No intercept detected" << std::endl;
		};
	//std::cout << "Yay! Success!" << std::endl;
	interception = 0;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 LEVEL TWO ----- STATE 4								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void LevelTwo::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=4;
		LocalGame=Local;
		active=false;
		loadcheck=false;

		    //Sprite - Water Background.
			WaterBackgroundTwo = new Objects ("images/Backgrounds/Water Sprite 5.png",2500,2000);
			WaterBackgroundTwo -> setNumberOfAnimations(1);
			WaterBackgroundTwo -> setPosition(-1700,-750);
			WaterBackgroundTwo -> setCenter(0,0);
			WaterBackgroundTwo -> setLayerID (1);
			WaterBackgroundTwo ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackgroundTwo -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackgroundTwo);
			this->addToObjectsList(WaterBackgroundTwo);

			//Sprite - Map 2 Base.
			Map3_Base = new Objects ("images/Levels/Map 3 Base.png",2500,2000);
			Map3_Base -> setNumberOfAnimations(1);
			Map3_Base -> setSpriteFrameSize(2500,2000);
			Map3_Base -> setPosition(-1552,-1402);
			Map3_Base -> setCenter(0,0);
			Map3_Base -> setLayerID (2);
			Map3_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map3_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map3_Base);
			this->addToObjectsList(Map3_Base);

			//Sprite - Player Sprites.
			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 28,48);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);
			
			//Sprite - Map 1 Objects.
			Map3_Objects = new Objects ("images/Levels/Map 3 Objects.png",2500,2000);
			Map3_Objects -> setNumberOfAnimations(1);
			Map3_Objects -> setPosition(-1552,-1402);
			Map3_Objects -> setCenter(0,0);
			Map3_Objects -> setLayerID (6);
			Map3_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map3_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map3_Objects);
			this->addToObjectsList(Map3_Objects);

			//Sprite - UI Sample.
			UISample = new Sprite ("images/Test UI.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(480,261);
			UISample -> setPosition(0,0);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (7);
			UISample ->addSpriteAnimRow(0,0,0,480,261,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);

			std::cout << "Before Biscuit Two" << std::endl;
			MapConstraintsTwo = Constraints("images/Levels/Map 3 Constraints.bmp");
			std::cout << "At Biscuit Two" << std::endl;

	}


	void LevelTwo::ResetMap()
	{ 
				WaterBackgroundTwo -> setPosition(-1700,-750);
				Map3_Base -> setPosition(-1552,-1402);
				Player-> setPosition(230,130);
				Player-> setCurrentAnimation(1);
				Map3_Objects -> setPosition(-1552,-1402);
	}


	LevelTwo::~LevelTwo(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelTwo::Update()
	{
		updateObjects();
		allowMovement();
		movement();	
	}


	void LevelTwo::KeyDown(unsigned char key)
	{
		moveObjectsKeyboardDown(key);
	}


	void LevelTwo::KeyUp(unsigned char key)
	{
		moveObjectsKeyboardUp(key);
	}

	void LevelTwo::allowMovement()
{
	//std::cout << "allowmovementcheck begin" << std::endl;
	int interception; //Counts the occurences of interception
	float stop = 0.f; //stops all movement when interception >=1
	float newMapPositionX, newMapPositionY;
	int indexStartX,indexStartY, indexEndX,indexEndY;

	int vecindexX, vecindexY;
	interception = 0;

	//std::cout << " initialize allowMovement variables" << std::endl;
	newMapPositionX = (Map3_Base->positionX) + (Map3_Base->inMotionSpeedX);
	newMapPositionY = (Map3_Base->positionY) + (Map3_Base->inMotionSpeedY);

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
			if (MapConstraintsTwo.vConstraintVector[vecindexX][vecindexY] == true)
			{
				/* Nothing */
			} else if (MapConstraintsTwo.vConstraintVector[vecindexX][vecindexY] == false) {
				interception++;
				break; //ends the loop

			} else{
				//Nothing
			};

		};
	//std::cout << "Checked constraint vector" << std::endl;
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
		//	std::cout << "No intercept detected" << std::endl;
		};
	//std::cout << "Yay! Success!" << std::endl;
	interception = 0;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 LEVEL THREE ----- STATE 5								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void LevelThree::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=5;
		LocalGame=Local;
		active=false;
		loadcheck=false;

		    //Sprite - Water Background.
			WaterBackgroundThree = new Objects ("images/Backgrounds/Water Sprite 5.png",2500,2000);
			WaterBackgroundThree -> setNumberOfAnimations(1);
			WaterBackgroundThree -> setPosition(-1700,-750);
			WaterBackgroundThree -> setCenter(0,0);
			WaterBackgroundThree -> setLayerID (1);
			WaterBackgroundThree ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackgroundThree -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackgroundThree);
			this->addToObjectsList(WaterBackgroundThree);

			//Sprite - Map 2 Base.
			Map4_Base = new Objects ("images/Levels/Map 4 Base.png",2500,2000);
			Map4_Base -> setNumberOfAnimations(1);
			Map4_Base -> setPosition(-1404,-1384);
			Map4_Base -> setCenter(0,0);
			Map4_Base -> setLayerID (2);
			Map4_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map4_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map4_Base);
			this->addToObjectsList(Map4_Base);

			//Sprite - Player Sprites.
			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 28,48);

			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);
			
			//Sprite - Map 1 Objects.
			Map4_Objects = new Objects ("images/Levels/Map 4 Objects.png",2500,2000);
			Map4_Objects -> setNumberOfAnimations(1);
			Map4_Objects -> setSpriteFrameSize(2500,2000);
			Map4_Objects -> setPosition(-1404,-1384);
			Map4_Objects -> setCenter(0,0);
			Map4_Objects -> setLayerID (6);
			Map4_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map4_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map4_Objects);
			this->addToObjectsList(Map4_Objects);

			//Sprite - UI Sample.
			UISample = new Sprite ("images/Test UI.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(480,261);
			UISample -> setPosition(0,0);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (7);
			UISample ->addSpriteAnimRow(0,0,0,480,261,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);

			
			std::cout << "Before Biscuit Three" << std::endl;
			MapConstraintsThree = Constraints("images/Levels/Map 4 Constraints.bmp");
			std::cout << "At Biscuit Three" << std::endl;

	}


	void LevelThree::ResetMap()
	{ 
				WaterBackgroundThree -> setPosition(-1700,-750);
				Map4_Base -> setPosition(-1404,-1384);
				Player-> setPosition(230,130);
				Player-> setCurrentAnimation(1);
				Map4_Objects -> setPosition(-1404,-1384);
	}


	LevelThree::~LevelThree(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelThree::Update()
	{
		updateObjects();
		allowMovement();
		movement();	
	}


	void LevelThree::KeyDown(unsigned char key)
	{
		moveObjectsKeyboardDown(key);
	}


	void LevelThree::KeyUp(unsigned char key)
	{
		moveObjectsKeyboardUp(key);
	}

		void LevelThree::allowMovement()
{
	//std::cout << "allowmovementcheck begin" << std::endl;
	int interception; //Counts the occurences of interception
	float stop = 0.f; //stops all movement when interception >=1
	float newMapPositionX, newMapPositionY;
	int indexStartX,indexStartY, indexEndX,indexEndY;

	int vecindexX, vecindexY;
	interception = 0;

	//std::cout << " initialize allowMovement variables" << std::endl;
	newMapPositionX = (Map4_Base->positionX) + (Map4_Base->inMotionSpeedX);
	newMapPositionY = (Map4_Base->positionY) + (Map4_Base->inMotionSpeedY);

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
			if (MapConstraintsThree.vConstraintVector[vecindexX][vecindexY] == true)
			{
				/* Nothing */
			} else if (MapConstraintsThree.vConstraintVector[vecindexX][vecindexY] == false) {
				interception++;
				break; //ends the loop

			} else{
				//Nothing
			};

		};
	//std::cout << "Checked constraint vector" << std::endl;
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
		//	std::cout << "No intercept detected" << std::endl;
		};
	//std::cout << "Yay! Success!" << std::endl;
	interception = 0;
}
//																			|Aaron Alphonso|
//###########################################################################################