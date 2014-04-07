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

// Stage 1: check for combat initiation
// Stage 2: check for all non-immortal objects for intercept
// Stage 3: If intercept, proceed to combat
void GameState::combatSystem() // 
{
	std::vector<Objects*>::iterator initCombatant; // Initiator combatant
	for(initCombatant= objectsList.begin() ; initCombatant !=objectsList.end() ; initCombatant++)
	{
		(*initCombatant)->bInitiator = true;
		Objects *oInitiator = (*initCombatant);
		if ((oInitiator->ObjectActBox->active == true) && (oInitiator->ObjectActBox->attack == true) )
		{
			std::cout << "Stage 1 - Combat Search" << std::endl;
			std::vector<Objects*>::iterator oppoCombatant; // Opponents
			for(oppoCombatant= objectsList.begin(); oppoCombatant !=objectsList.end() ; oppoCombatant++)
			{
				(*oppoCombatant)->bOpponent = true;
				Objects *oOpponent = (*oppoCombatant);

				if(oOpponent->bInitiator == false)
				{
					if ((oOpponent->immortal == false))
					{
						std::cout << "Combat Initiated" << std::endl;
						if( (((oInitiator->ObjectActBox->bottomCornerY) >= (oOpponent->ObjectHitbox->bottomCornerY) ) && ((oInitiator->ObjectActBox->bottomCornerY) <= (oOpponent->ObjectHitbox->topCornerY) ) || ((oInitiator->ObjectActBox->topCornerY) >= (oOpponent->ObjectHitbox->bottomCornerY) ) && ((oInitiator->ObjectActBox->topCornerY) <= (oOpponent->ObjectHitbox->topCornerY) ) ) && 
							( ( (oInitiator->ObjectActBox->leftCornerX) >= (oOpponent->ObjectHitbox->leftCornerX)  ) && ((oInitiator->ObjectActBox->leftCornerX ) <= (oOpponent->ObjectHitbox->rightCornerX)) || ((oInitiator->ObjectActBox->rightCornerX) >= (oOpponent->ObjectHitbox->leftCornerX) ) && ((oInitiator->ObjectActBox->rightCornerX) <= (oOpponent->ObjectHitbox->rightCornerX)) ) )
						{
							std::cout<< "You wound me~!" << std::endl;
							//Damage Resolution
							(oOpponent->hP) -= (oInitiator->dam); 
							if (oOpponent->player==true && oOpponent->hP <= 0)
							{
								std::cout<< "You dead sucka!" << std::endl;
								oOpponent->hP = 10;
							}
							if(oInitiator->player==true) // Update Player's score
							{
								oInitiator->scoreStorage += oInitiator->dam;
							}
						}else{
							std::cout<< "Nothing was found" << std::endl;
						}
					}
					else{
					// Its immortal, No Combat.
					};
					(*oppoCombatant)->bOpponent = false;
				}
				else{
					(*oppoCombatant)->bOpponent = false;
				}
			} // end of for oOpponent statement
			
		}
		else{
			//No combat
		}
		(*initCombatant)->bInitiator = false;
	}; // End of oInitiator for statement 




}

//Sprite - UI Score.
	void GameState::ScoreUpdate(int inScore)
	{
		int tempScore;
		tempScore=inScore;
		for(int i=6 ; i>0; i--)
		{	
			UIScore[i]->setCurrentAnimation(tempScore%10);
			tempScore=tempScore/10;
		}
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

			//Sprite - Player Sprites.
			Player = new Sprite("images/Player&HUD/PlayerSprite.png"); //Layer 4- Player Sprite.
			Player->setSpriteFrameSize(60, 60);
			Player->setNumberOfAnimations(8);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,60,0,4);
			Player->addSpriteAnimRow(2,0,60,60,0,4);
			Player->addSpriteAnimRow(3,0,120,60,0,4);
			Player->addSpriteAnimRow(4,0,180,60,0,4);
			Player->setPosition(210,86);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
	}


	void MainMenu::ResetMap()
	{ 
			MenuBG -> setPosition(0,0);
			MenuStrip -> setPosition(0,80);
			Player->setPosition(210,85);
			Player->setCurrentAnimation(1);
			MenuStrip -> setCurrentAnimation(0);
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
				case 'w':{		//since int will down to option;
								option=int((MenuStrip -> positionX/200)*-1)+1;
								MenuControl(option);
								break;}

				case 13: {		//since int will down to option;
								option=int((MenuStrip -> positionX/200)*-1)+1;
								MenuControl(option);
								break;}
				case 8:  {      ResetMap();
								break;}
				case 's':{		ResetMap();
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

	void MainMenu::MenuControl (int opt)
	{  
		switch(opt)
	   { 
		  case 1: { LocalGame->SwitchStateTo (LocalGame->StateTwo, 4);
					//LocalGame->playEnvironment();
					LocalGame->MessageControl(LocalGame->Msg, 4, 7);
					std::cout<<"OPTION 1 \a"<<std::endl;
					break;
				  }
		  case 2: { 
					LocalGame->SwitchStateTo (LocalGame->StateHome, 2);
					//LocalGame->playEnvironment();
					LocalGame->MessageControl(LocalGame->Msg, 1, 7);
					std::cout<<"OPTION 2 \a"<<std::endl;
					break;
				  }
		  case 3: { std::cout<<"OPTION 3 \a"<<std::endl;
					//CALL THE KEYBINDING STATE HERE JUST LIKE ABOVE; 
					break;
				  }
		  case 4: { std::cout<<"OPTION 4 \a"<<std::endl;
					LocalGame->MessageControl(LocalGame->Msg, 4, 7);
					break;
				  }
		  case 5: exit(1); break;
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
		tutorialDone = false;
		tickstime = 0;
		ticksX = 0;


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

			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 60,60); //Layer 4- Player Sprite.
			Player->setCurrentAnimation(1);
			Player->direction= 1;
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);
			
			
			//Sprite - Map 1 Objects.
			Map1_Objects = new Objects ("images/Levels/Map 1 Objects.png", 2500, 2000);
			Map1_Objects -> setNumberOfAnimations(1);
			Map1_Objects -> setPosition(-1422,-1033);  //-1422, -1033
			Map1_Objects -> setCenter(0,0);
			Map1_Objects -> setLayerID (6);
			Map1_Objects -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map1_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map1_Objects);
			this->addToObjectsList(Map1_Objects);


			TransitionHomeOne = new Transition ("images/Backgrounds/Water Sprite.png",50,50);
			TransitionHomeOne-> setNumberOfAnimations(1);
			TransitionHomeOne-> addSpriteAnimFrame(0,0,50);
			TransitionHomeOne-> setCurrentAnimation(0);
			TransitionHomeOne-> setLayerID(7);
			TransitionHomeOne-> setPosition(-595,-54);
			TransitionHomeOne-> toLevel = 2;
			this->addSpriteToDrawList(TransitionHomeOne);
			this->addToObjectsList(TransitionHomeOne);

			Ghosty1 = new Ghost("images/Enemy Sprite.png",40,40);
			this->addSpriteToDrawList(Ghosty1);
			this->addToObjectsList(Ghosty1);

			Ghosty2 = new Ghost("images/Enemy Sprite.png",40,40);
			this->addSpriteToDrawList(Ghosty2);
			this->addToObjectsList(Ghosty2);

			Ghosty3 = new Ghost("images/Enemy Sprite.png",40,40);
			this->addSpriteToDrawList(Ghosty3);
			this->addToObjectsList(Ghosty3);

			Ghosty4 = new Ghost("images/Enemy Sprite.png",40,40);
			this->addSpriteToDrawList(Ghosty4);
			this->addToObjectsList(Ghosty4);

				//Sprite - UI Score.
						for(int i=0 ; i<7; i++)
			{ 	
			UIScore[i] = new Sprite("images/Player&HUD/UIScore.png"); //Layer 13- Score
			UIScore[i]->setSpriteFrameSize(16,16);
			UIScore[i]->setNumberOfAnimations(10); //0-9
			UIScore[i]->setCenter(0,0);
			UIScore[i]->addSpriteAnimFrame(1,16,16);
				for(int j=0 ; j<10 ; j++)
				{
					UIScore[i]->addSpriteAnimRow(j,0,j*16,16,0,1);
				}
			UIScore[i]->setLayerID(13);
			UIScore[i]->setCurrentAnimation(i);
			UIScore[i]->setPosition((380+(i*12)),233);
			this->addSpriteToDrawList(UIScore[i]); 
			}




					// UI Health
			UIHealth = new Health("images/Player&HUD/UIHealth.png", 184, 24); //Layer 12- Health
			this->addSpriteToDrawList(UIHealth);	

			std::cout << "Before Biscuit" << std::endl;
			MapConstraintsHome = Constraints("images/Levels/Map 1 Constraints.bmp");
			std::cout << "At Biscuit" << std::endl;
			std::cout << "Location of 919, 1047: " << MapConstraintsHome.vConstraintVector[919][1047] << std::endl;



	}


	void LevelHome::ResetMap()
	{ 
		
		
				LocalGame->stateInfo.storePlayerHp = 10;
				LocalGame->stateInfo.storePlayerScore = 0; 
				

				WaterBackgroundHome -> setPosition(-1700,-750);
				Map1_Base -> setPosition(-1422,-1033); // -1422, -1033
				Map1_Objects -> setPosition(-1422,-1033); //-1422, -1033
				TransitionHomeOne->setPosition(-595,-54);
				Ghosty1 ->setPosition(0,2000);
				Ghosty2 ->setPosition(2500,0);
				Ghosty3 ->setPosition(0,-2000);
				Ghosty4 ->setPosition(-2500,0);

				Player->hP = LocalGame->stateInfo.storePlayerHp;
				Player->scoreStorage = LocalGame->stateInfo.storePlayerScore; 



	}


	LevelHome::~LevelHome(void) 
	{ 
		/*Default deconstructor */
	}

	
	void LevelHome::Update()
	{
		tickstime++;
		combatSystem();

		tutorialLoad1();
		tutorialLoad2();
		tutorialLoad3();
		tutorialLoad4();
		tutorialLoad5();
		Ghosty1->getPlayerPos(Player->positionX, Player->positionY);
		Ghosty1->ghUpdate();
		Ghosty2->getPlayerPos(Player->positionX, Player->positionY);
		Ghosty2->ghUpdate();
		Ghosty3->getPlayerPos(Player->positionX, Player->positionY);
		Ghosty3->ghUpdate();
		Ghosty4->getPlayerPos(Player->positionX, Player->positionY);
		Ghosty4->ghUpdate();

		//Movement
		updateObjects();
		allowMovement();
		movement();
		transitionCheck();

		

		//UI Update
		ScoreUpdate(Player->scoreStorage);
		UIHealth->inputHealth(Player->hP);

	}


	void LevelHome::KeyDown(unsigned char key)
	{
		moveObjectsKeyboardDown(key);

		switch(key)
		{
		case 'e':
			{
				Player-> interboxactive = true;
				Player-> talk = true;
				std::cout<< "I am talking" << std::endl;
				break;
			};
		case 32:
			{
				Player-> interboxactive = true;
				Player->attackBreakDown();
				std::cout<< "I am attacking" << std::endl;	
			};
			break;
		};
	}


	void LevelHome::KeyUp(unsigned char key)
	{
		moveObjectsKeyboardUp(key);
		switch(key)
		{
		case 'e':
			{
				Player-> interboxactive = false;
				Player-> talk = false;
				std::cout<< "Done talking" << std::endl;
			};
			break;
		case 32:
			{
				Player-> interboxactive = false;
				Player-> attackBreakUp();
				std::cout<< "Done attacking" << std::endl;
			};
			break;
		};

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

	void LevelHome::transitionCheck()
	{
		float tranBotY,tranTopY,tranLeftX,tranRightX;
		float playBotY,playTopY,playLeftX,playRightX;

		tranBotY = TransitionHomeOne->ObjectHitbox->bottomCornerY; tranTopY = TransitionHomeOne->ObjectHitbox->topCornerY;
		tranLeftX = TransitionHomeOne->ObjectHitbox->leftCornerX; tranRightX = TransitionHomeOne->ObjectHitbox->rightCornerX;

		playBotY = Player->ObjectHitbox->bottomCornerY; playTopY = Player->ObjectHitbox->topCornerY;
		playLeftX= Player->ObjectHitbox->leftCornerX; playRightX = Player->ObjectHitbox->rightCornerX;
// work on
		if( ( (playBotY >= tranBotY  ) && (playBotY <= tranTopY) || ( playTopY >= tranBotY ) && ( playTopY <= tranTopY) ) && 
			( (playLeftX >= tranLeftX  ) && (playLeftX <= tranRightX) || (playRightX >= tranLeftX  ) && (playRightX <= tranRightX) ) )
		{
			//Transfer points
			LocalGame->stateInfo.storePlayerHp = Player->hP;
			LocalGame->stateInfo.storePlayerScore = Player->scoreStorage;

			std::cout << "BING!" << std::endl;
			this->LocalGame->SwitchStateTo(this, 3); // To Level 3~!
			this->LocalGame->MessageControl(this->LocalGame->Msg, 2,7);
		}
		else
		{
			//NOTHING!
		};
	}



void LevelHome::tutorialLoad1()
	{

		if (tutorialDone ==false && tickstime < 30 && ticksX < 1){ 
		LocalGame->MessageControl(LocalGame->Msg, 4, 7);
		}
		else
		{

		}
	}
void LevelHome::tutorialLoad2()
	{

		if (tutorialDone ==false && tickstime < 60 && ticksX  < 2){
			LocalGame->MessageControl(LocalGame->Msg, 5, 7);
		}
		else
		{
		
		}
	}
void LevelHome::tutorialLoad3()
	{

		if (tutorialDone ==false && tickstime < 90 && ticksX < 3){
			
			LocalGame->MessageControl(LocalGame->Msg, 6, 7);
		}
		else
		{
		}
	}
void LevelHome::tutorialLoad4()
	{

		if (tutorialDone ==false && tickstime < 120 && ticksX < 4){
			LocalGame->MessageControl(LocalGame->Msg, 7, 7);
		}
		else
		{
		}
	}
void LevelHome::tutorialLoad5()
	{

		if (tutorialDone ==false && tickstime < 150 && ticksX < 5){
			LocalGame->MessageControl(LocalGame->Msg, 8, 7);
			tutorialDone= true;
		}
		else
		{
		}
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
			WaterBackgroundOne -> addSpriteAnimRow(0,0,0,2500,2000,1);
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

			
			//Sprite - Map 2 Objects.
			Map2_Objects = new Objects ("images/Levels/Map 2 Objects.png" , 2500, 2000);
			Map2_Objects -> setNumberOfAnimations(1);
			Map2_Objects -> setPosition(-475,-1410);
			Map2_Objects -> setCenter(0,0);
			Map2_Objects -> setLayerID (6);
			Map2_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map2_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map2_Objects);
			this->addToObjectsList(Map2_Objects);

			//Sprite - Player Sprites.

			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 60,60); //Layer 4- Player Sprite.
			Player->setCurrentAnimation(1);
			Player->direction= 1;
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);

			//Sprite - UI Score.
			for(int i=0 ; i<7; i++)
			{ 	
			UIScore[i] = new Sprite("images/Player&HUD/UIScore.png"); //Layer 13- Score
			UIScore[i]->setSpriteFrameSize(16,16);
			UIScore[i]->setNumberOfAnimations(10); //0-9
			UIScore[i]->setCenter(0,0);
			UIScore[i]->addSpriteAnimFrame(1,16,16);
				for(int j=0 ; j<10 ; j++)
				{
					UIScore[i]->addSpriteAnimRow(j,0,j*16,16,0,1);
				}
			UIScore[i]->setLayerID(13);
			UIScore[i]->setCurrentAnimation(i);
			UIScore[i]->setPosition((380+(i*12)),233);
			this->addSpriteToDrawList(UIScore[i]); 
			}

					//Sprite - UI Health
			UIHealth = new Health("images/Player&HUD/UIHealth.png", 184, 24); //Layer 12- Health
			this->addSpriteToDrawList(UIHealth);	

			std::cout << "Before Biscuit One" << std::endl;
			MapConstraintsOne = Constraints("images/Levels/Map 2 Constraints.bmp");
			std::cout << "At Biscuit One" << std::endl;


	}


	void LevelOne::ResetMap()
	{ 
				WaterBackgroundOne -> setPosition(-1700,-750);
				Map2_Base -> setPosition(-475,-1410);
				Map2_Objects -> setPosition(-475,-1410);

				
				
				Player->hP = LocalGame->stateInfo.storePlayerHp;
				Player->scoreStorage = LocalGame->stateInfo.storePlayerScore; 
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

		//UI Update
		ScoreUpdate(Player->scoreStorage);
		UIHealth->inputHealth(Player->hP);


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

			//Sprite - Player Sprites.

			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 60,60); //Layer 4- Player Sprite.
			Player->setCurrentAnimation(1);
			Player->direction= 1;
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);

			//Sprite - UI Score.
			for(int i=0 ; i<7; i++)
			{ 	
			UIScore[i] = new Sprite("images/Player&HUD/UIScore.png"); //Layer 13- Score
			UIScore[i]->setSpriteFrameSize(16,16);
			UIScore[i]->setNumberOfAnimations(10); //0-9
			UIScore[i]->setCenter(0,0);
			UIScore[i]->addSpriteAnimFrame(1,16,16);
				for(int j=0 ; j<10 ; j++)
				{
					UIScore[i]->addSpriteAnimRow(j,0,j*16,16,0,1);
				}
			UIScore[i]->setLayerID(13);
			UIScore[i]->setCurrentAnimation(i);
			UIScore[i]->setPosition((380+(i*12)),233);
			this->addSpriteToDrawList(UIScore[i]); 
			}

					//Sprite - UI Health
			UIHealth = new Health("images/Player&HUD/UIHealth.png", 184, 24); //Layer 12- Health
			this->addSpriteToDrawList(UIHealth);	

			std::cout << "Before Biscuit Two" << std::endl;
			MapConstraintsTwo = Constraints("images/Levels/Map 3 Constraints.bmp");
			std::cout << "At Biscuit Two" << std::endl;

	}


	void LevelTwo::ResetMap()
	{ 
				WaterBackgroundTwo -> setPosition(-1700,-750);
				Map3_Base -> setPosition(-1552,-1402);
				Map3_Objects -> setPosition(-1552,-1402);

				Player->hP = LocalGame->stateInfo.storePlayerHp;
				Player->scoreStorage = LocalGame->stateInfo.storePlayerScore; 
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

		//UI Update
		ScoreUpdate(Player->scoreStorage);
		UIHealth->inputHealth(Player->hP);
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

			//Sprite - Player Sprites.

			Player = new MainCharacter("images/Player&HUD/PlayerSprite.png", 60,60); //Layer 4- Player Sprite.
			Player->setCurrentAnimation(1);
			Player->direction= 1;
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			this->addToObjectsList(Player);

						//Sprite - UI Score.
			for(int i=0 ; i<7; i++)
			{ 	
			UIScore[i] = new Sprite("images/Player&HUD/UIScore.png"); //Layer 13- Score
			UIScore[i]->setSpriteFrameSize(16,16);
			UIScore[i]->setNumberOfAnimations(10); //0-9
			UIScore[i]->setCenter(0,0);
			UIScore[i]->addSpriteAnimFrame(1,16,16);
				for(int j=0 ; j<10 ; j++)
				{
					UIScore[i]->addSpriteAnimRow(j,0,j*16,16,0,1);
				}
			UIScore[i]->setLayerID(13);
			UIScore[i]->setCurrentAnimation(i);
			UIScore[i]->setPosition((380+(i*12)),233);
			this->addSpriteToDrawList(UIScore[i]); 
			}

					//Sprite - UI Health
			UIHealth = new Health("images/Player&HUD/UIHealth.png", 184, 24); //Layer 12- Health
			this->addSpriteToDrawList(UIHealth);	

			std::cout << "Before Biscuit Three" << std::endl;
			MapConstraintsThree = Constraints("images/Levels/Map 4 Constraints.bmp");
			std::cout << "At Biscuit Three" << std::endl;

	}


	void LevelThree::ResetMap()
	{ 
				WaterBackgroundThree -> setPosition(-1700,-750);
				Map4_Base -> setPosition(-1404,-1384);
				Player-> setPosition(160,95);
				Player-> setCurrentAnimation(1);
				Player->direction=1;
				Map4_Objects -> setPosition(-1404,-1384);
				
				Player->hP = LocalGame->stateInfo.storePlayerHp;
				Player->scoreStorage = LocalGame->stateInfo.storePlayerScore; 
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

		//UI Update
		ScoreUpdate(Player->scoreStorage);
		UIHealth->inputHealth(Player->hP);
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
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 UI STATE ------- STATE 6								   ||
//			Eventually work into its own class											   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void UIState::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=6;
		LocalGame=Local;
		active=false;
		loadcheck=false;

		Health=10; //Player at full health.
		Score=0;   //Player at zero score.




			//Sprite - UI Health
			UIHealth = new Sprite("images/UIHealth.png"); //Layer 12- Health
			UIHealth->setSpriteFrameSize(184, 24);
			UIHealth->setNumberOfAnimations(11);
			UIHealth->setCenter(0,0);
				for(int i=0 ; i<11 ; i++)
				{
					UIHealth->addSpriteAnimRow(i,0,i*24,184,0,1);
				}
			UIHealth->setPosition(8,227);
			UIHealth->setCurrentAnimation(Health);
			UIHealth->setLayerID(12);
			this->addSpriteToDrawList(UIHealth);

			//Sprite - UI Score.
			for(int i=0 ; i<7; i++)
			{ 	
			UIScore[i] = new Sprite("images/UIScore.png"); //Layer 13- Score
			UIScore[i]->setSpriteFrameSize(16,16);
			UIScore[i]->setNumberOfAnimations(10); //0-9
			UIScore[i]->setCenter(0,0);
			UIScore[i]->addSpriteAnimFrame(1,16,16);
				for(int j=0 ; j<10 ; j++)
				{
					UIScore[i]->addSpriteAnimRow(j,0,j*16,16,0,1);
				}
			UIScore[i]->setLayerID(13);
			UIScore[i]->setCurrentAnimation(i);
			UIScore[i]->setPosition((380+(i*12)),233);
			this->addSpriteToDrawList(UIScore[i]); 
			}

			ScoreUpdate();

			//Sprite - UI Actionbar.
			UISample = new Sprite ("images/UIActionbar.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(200,50);
			UISample -> setPosition(140,10);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (14);
			UISample ->addSpriteAnimRow(0,0,0,200,50,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);
			
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

	}


	void UIState::ResetMap()
	{ 

	}


	UIState::~UIState(void) 
	{ 
		/*Default deconstructor */
	}

	void UIState::ScoreUpdate()
	{
		tempscore=Score;
		for(int i=6 ; i>0; i--)
		{	
			UIScore[i]->setCurrentAnimation(tempscore%10);
			tempscore=tempscore/10;
		}
	}

	void UIState::Update()
	{


	}


	void UIState::KeyDown(unsigned char key)
	{

			switch(key)
			{
				case 32: // the space bar
					     break;
				case 27: // the escape key
					     break;
				case 45: if(0<Health)
						 Health--;
						 UIHealth->setCurrentAnimation(Health);
						 break;
				case 61: if(Health<10)
						 Health++;
						 UIHealth->setCurrentAnimation(Health);
						 break;
				case 'o': Score--;
						  UIScore[6]->setCurrentAnimation(Score);
						  ScoreUpdate();
						  break;
				case 'p': Score++;
						  UIScore[6]->setCurrentAnimation(Score);
						  ScoreUpdate();
						  break;
			}
	}


	void UIState::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
						 break;
			}
	}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 UI STATE ------- STATE 6								   ||
//																						   ||
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||


	void MessageState::Init(Game* Local)
	{
		//INITIALIZATION:
		StateNum=7;
		LocalGame=Local;
		active=true;
		ticked=false;
		ticks= 0;
		loadcheck=false;
		anynumber=4;

		transitionTimer = new Timer("TRANSITION");

			//Sprite - Transition Sprites
			Transition = new Sprite("images/Transition Sprites.png"); //Layer 17- Transition.
			Transition->setSpriteFrameSize(480,260);
			Transition->setNumberOfAnimations(16);
			Transition->setCenter(0,0);
			Transition->addSpriteAnimRow(0,0,0,480,0,1);
			Transition->addSpriteAnimRow(1,0,260,480,0,1);
			Transition->addSpriteAnimRow(2,0,520,480,0,1);
			Transition->addSpriteAnimRow(3,0,780,480,0,1);
			Transition->addSpriteAnimRow(4,0,1040,480,0,1);
			Transition->addSpriteAnimRow(5,0,1300,480,0,1);
			Transition->addSpriteAnimRow(6,0,1560,480,0,1);
			Transition->addSpriteAnimRow(7,0,1820,480,0,1);
			Transition->addSpriteAnimRow(8,0,2080,480,0,1);
			Transition->setPosition(0,0);
			Transition->setCurrentAnimation(6);
			Transition->setLayerID(16);
			this->addSpriteToDrawList(Transition);

			//Sprite - Tutorials.
			Tutorials = new Sprite("images/Tutorials.png"); //Layer 17- Transition.
			Tutorials->setSpriteFrameSize(480,261);
			Tutorials->setNumberOfAnimations(5);
			Tutorials->setCenter(0,0);
			Tutorials->addSpriteAnimRow(4,0,0,480,0,1);
			Tutorials->addSpriteAnimRow(3,0,261,480,0,1);
			Tutorials->addSpriteAnimRow(2,0,522,480,0,1);
			Tutorials->addSpriteAnimRow(1,0,783,480,0,1);
			Tutorials->addSpriteAnimRow(0,0,1044,480,0,1); //Transparent Layer
			Tutorials->setPosition(0,0);
			Tutorials->setCurrentAnimation(0);
			Tutorials->setLayerID(16);
			this->addSpriteToDrawList(Tutorials);


	}


	void MessageState::ResetMap()
	{ 

	}


	MessageState::~MessageState(void) 
	{ 
		/*Default deconstructor */
	}

	void MessageState::MCtrl()
	{ 

	}

	void MessageState::Update()
	{
		
		
		Transition->setCurrentAnimation(anynumber);

		if (active == true && ticked == false )
		{
			transitionTimer->tick();
			ticked = true;
			ticks++;
		}
		else if(active == true && ticked == true)
		{
			if (ticks >= 35)
			{
				active = false;
				ticked = false;
				ticks = 0;
			}
			else{
				ticks++;
			};

		}
		else
		{};


	}


	void MessageState::KeyDown(unsigned char key)
	{

			switch(key)
			{
			    case 'x': active=false; //need at least 1 case.
				default: {
							//active=false; //if active=false is here, "press any key to continue doesn't work,
							//program just skipps through the switch. 
						 }
			}
	}


	void MessageState::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
						 break;
		
				case 'w':
						break;
				case 'a':
						break;
				case 'd':
						break;
				case 's':
						break;
			}
	}

//																			|Aaron Alphonso|
//###########################################################################################