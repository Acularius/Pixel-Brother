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

			LocalGame -> playSound(false); //PLAY'S FMOD LOOP BACKGROUND SOUND.

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
			Player = new Sprite("images/PlayerSprite.png"); //Layer 4- Player Sprite.
			Player->setSpriteFrameSize(60, 60);
			Player->setNumberOfAnimations(16);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,60,0,4);
			Player->addSpriteAnimRow(2,0,60,60,0,4);
			Player->addSpriteAnimRow(3,0,120,60,0,4);
			Player->addSpriteAnimRow(4,0,180,60,0,4);
			Player->addSpriteAnimRow(5,0,240,60,0,4);
			Player->addSpriteAnimRow(6,0,300,60,0,4);
			Player->addSpriteAnimRow(7,0,360,60,0,4);
			Player->addSpriteAnimRow(8,0,420,60,0,4);
			Player->setPosition(210,85);
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
					LocalGame->playEnvironment();
					LocalGame->StateControl(LocalGame->UI,true,6);
					LocalGame->MessageControl(LocalGame->Msg, 4, 7);
					std::cout<<"OPTION 1 \a"<<std::endl;
					break;
				  }
		  case 2: { 
					LocalGame->SwitchStateTo (LocalGame->StateHome, 2);
					LocalGame->playEnvironment();
					LocalGame->StateControl(LocalGame->UI,true,6);
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
		mapSpeed = 0;
		WaterSpeed = 0;

		    //Sprite - Water Background.
			WaterBackground = new Sprite ("images/Water Sprite.png");
			WaterBackground -> setNumberOfAnimations(1);
			WaterBackground -> setSpriteFrameSize(2500,2000);
			WaterBackground -> setPosition(-1700,-750);
			WaterBackground -> setCenter(0,0);
			WaterBackground -> setLayerID (1);
			WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackground -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackground);

			//Sprite - Map 1 Base.
			Map1_Base = new Sprite ("images/Map 1 Base.png");
			Map1_Base -> setNumberOfAnimations(1);
			Map1_Base -> setSpriteFrameSize(2500,2000);
			Map1_Base -> setPosition(-1422,-1033);
			Map1_Base -> setCenter(0,0);
			Map1_Base -> setLayerID (2);
			Map1_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map1_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map1_Base);
			
			//Sprite - Map 1 Objects.
			Map1_Objects = new Sprite ("images/Map 1 Objects.png");
			Map1_Objects -> setNumberOfAnimations(1);
			Map1_Objects -> setSpriteFrameSize(2500,2000);
			Map1_Objects -> setPosition(-1422,-1033);
			Map1_Objects -> setCenter(0,0);
			Map1_Objects -> setLayerID (6);
			Map1_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map1_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map1_Objects);

			LocalGame->MessageControl(LocalGame->Msg, 4, 7);
			LocalGame->MessageControl(LocalGame->Msg, 5, 7);
			LocalGame->MessageControl(LocalGame->Msg, 6, 7);
			LocalGame->MessageControl(LocalGame->Msg, 7, 7);
			LocalGame->MessageControl(LocalGame->Msg, 8, 7);


	}


	void LevelHome::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
				Map1_Base -> setPosition(-1422,-1033);
				Map1_Objects -> setPosition(-1422,-1033);
				LocalGame -> playSound(true);
	}


	LevelHome::~LevelHome(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelHome::Update()
	{
	 		if (test == true) //Horozontal Movement:
			{
				// MAP SPEED:
				Map1_Base -> positionX+=mapSpeed;
				Map1_Objects -> positionX+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY-=1;
				WaterBackground -> positionX+=WaterSpeed;
			}
			else //Vertical Movement:
			{
				// MAP SPEED:
				Map1_Base ->positionY+=mapSpeed;
				Map1_Objects ->positionY+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY+=(WaterSpeed-1);
			}

			if (WaterBackground-> positionY < -1000)
			{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			// ENABLE TO PRINT (X,Y) PLAYER (MAP) COORDINATES:
			// std::cout<<"x:"<<Map1_Base->positionX<<" ""y:"<<Map1_Base->positionY<<std::endl;
					std::vector<Sprite*>::iterator it; 
		for(it=spriteListToDraw.begin(); it != spriteListToDraw.end(); it++)
		{ 
			Sprite *s = (*it);
			s->update();
		}
	}


	void LevelHome::KeyDown(unsigned char key)
	{

			switch(key)
			{
				case 32: // the space bar
					     break;
				case 27: { //escape key
							 break; }

				case 'w':
					     test = false;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 'a':
						 test = true;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;

				case 'd':
						 test = true;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 's':
						 test = false;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;
			}
	}


	void LevelHome::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
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
		mapSpeed = 0;
		WaterSpeed = 0;

		    //Sprite - Water Background.
			WaterBackground = new Sprite ("images/Water Sprite 2.png");
			WaterBackground -> setNumberOfAnimations(1);
			WaterBackground -> setSpriteFrameSize(2500,2000);
			WaterBackground -> setPosition(-1700,-750);
			WaterBackground -> setCenter(0,0);
			WaterBackground -> setLayerID (1);
			WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackground -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackground);

			//Sprite - Map 2 Base.
			Map2_Base = new Sprite ("images/Map 2 Base.png");
			Map2_Base -> setNumberOfAnimations(1);
			Map2_Base -> setSpriteFrameSize(2500,2000);
			Map2_Base -> setPosition(-475,-1410);
			Map2_Base -> setCenter(0,0);
			Map2_Base -> setLayerID (2);
			Map2_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map2_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map2_Base);
			
			//Sprite - Map 1 Objects.
			Map2_Objects = new Sprite ("images/Map 2 Objects.png");
			Map2_Objects -> setNumberOfAnimations(1);
			Map2_Objects -> setSpriteFrameSize(2500,2000);
			Map2_Objects -> setPosition(-475,-1410);
			Map2_Objects -> setCenter(0,0);
			Map2_Objects -> setLayerID (6);
			Map2_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map2_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map2_Objects);

	}


	void LevelOne::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
				Map2_Base -> setPosition(-475,-1410);
				Map2_Objects -> setPosition(-475,-1410);
	}


	LevelOne::~LevelOne(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelOne::Update()
	{
	 		if (test == true) //Horozontal Movement:
			{
				// MAP SPEED:
				Map2_Base -> positionX+=mapSpeed;
				Map2_Objects -> positionX+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY-=1;
				WaterBackground -> positionX+=WaterSpeed;
			}
			else //Vertical Movement:
			{
				// MAP SPEED:
				Map2_Base ->positionY+=mapSpeed;
				Map2_Objects ->positionY+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY+=(WaterSpeed-1);
			}

			if (WaterBackground-> positionY < -1000)
			{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			// ENABLE TO PRINT (X,Y) PLAYER (MAP) COORDINATES:
			// std::cout<<"x:"<<Map1_Base->positionX<<" ""y:"<<Map1_Base->positionY<<std::endl;
	}


	void LevelOne::KeyDown(unsigned char key)
	{

			switch(key)
			{
				case 32: // the space bar
					     break;
				case 27: // the escape key
					     break;

				case 'w':
					     test = false;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 'a':
						 test = true;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;

				case 'd':
						 test = true;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 's':
						 test = false;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;
			}
	}


	void LevelOne::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
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
		mapSpeed = 0;
		WaterSpeed = 0;

		    //Sprite - Water Background.
			WaterBackground = new Sprite ("images/Water Sprite 5.png");
			WaterBackground -> setNumberOfAnimations(1);
			WaterBackground -> setSpriteFrameSize(2500,2000);
			WaterBackground -> setPosition(-1700,-750);
			WaterBackground -> setCenter(0,0);
			WaterBackground -> setLayerID (1);
			WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackground -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackground);

			//Sprite - Map 2 Base.
			Map3_Base = new Sprite ("images/Map 3 Base.png");
			Map3_Base -> setNumberOfAnimations(1);
			Map3_Base -> setSpriteFrameSize(2500,2000);
			Map3_Base -> setPosition(-1552,-1402);
			Map3_Base -> setCenter(0,0);
			Map3_Base -> setLayerID (2);
			Map3_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map3_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map3_Base);
			
			//Sprite - Map 1 Objects.
			Map3_Objects = new Sprite ("images/Map 3 Objects.png");
			Map3_Objects -> setNumberOfAnimations(1);
			Map3_Objects -> setSpriteFrameSize(2500,2000);
			Map3_Objects -> setPosition(-1552,-1402);
			Map3_Objects -> setCenter(0,0);
			Map3_Objects -> setLayerID (6);
			Map3_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map3_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map3_Objects);

	}


	void LevelTwo::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
				Map3_Base -> setPosition(-1552,-1402);
				Map3_Objects -> setPosition(-1552,-1402);
	}


	LevelTwo::~LevelTwo(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelTwo::Update()
	{
	 		if (test == true) //Horozontal Movement:
			{
				// MAP SPEED:
				Map3_Base -> positionX+=mapSpeed;
				Map3_Objects -> positionX+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY-=1;
				WaterBackground -> positionX+=WaterSpeed;
			}
			else //Vertical Movement:
			{
				// MAP SPEED:
				Map3_Base ->positionY+=mapSpeed;
				Map3_Objects ->positionY+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY+=(WaterSpeed-1);
			}

			if (WaterBackground-> positionY < -1000)
			{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			// ENABLE TO PRINT (X,Y) PLAYER (MAP) COORDINATES:
			// std::cout<<"x:"<<Map1_Base->positionX<<" ""y:"<<Map1_Base->positionY<<std::endl;
	}


	void LevelTwo::KeyDown(unsigned char key)
	{

			switch(key)
			{
				case 32: // the space bar
					     break;
				case 27: // the escape key
					     break;

				case 'w':
					     test = false;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 'a':
						 test = true;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;

				case 'd':
						 test = true;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 's':
						 test = false;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;
			}
	}


	void LevelTwo::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
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
		mapSpeed = 0;
		WaterSpeed = 0;

		    //Sprite - Water Background.
			WaterBackground = new Sprite ("images/Water Sprite 5.png");
			WaterBackground -> setNumberOfAnimations(1);
			WaterBackground -> setSpriteFrameSize(2500,2000);
			WaterBackground -> setPosition(-1700,-750);
			WaterBackground -> setCenter(0,0);
			WaterBackground -> setLayerID (1);
			WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
			WaterBackground -> setCurrentAnimation(1);
			this->addSpriteToDrawList(WaterBackground);

			//Sprite - Map 2 Base.
			Map4_Base = new Sprite ("images/Map 4 Base.png");
			Map4_Base -> setNumberOfAnimations(1);
			Map4_Base -> setSpriteFrameSize(2500,2000);
			Map4_Base -> setPosition(-1404,-1384);
			Map4_Base -> setCenter(0,0);
			Map4_Base -> setLayerID (2);
			Map4_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
			Map4_Base -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map4_Base);
			
			//Sprite - Map 1 Objects.
			Map4_Objects = new Sprite ("images/Map 4 Objects.png");
			Map4_Objects -> setNumberOfAnimations(1);
			Map4_Objects -> setSpriteFrameSize(2500,2000);
			Map4_Objects -> setPosition(-1404,-1384);
			Map4_Objects -> setCenter(0,0);
			Map4_Objects -> setLayerID (6);
			Map4_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
			Map4_Objects -> setCurrentAnimation(1);
			this->addSpriteToDrawList(Map4_Objects);

	}


	void LevelThree::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
				Map4_Base -> setPosition(-1404,-1384);
				Map4_Objects -> setPosition(-1404,-1384);
	}


	LevelThree::~LevelThree(void) 
	{ 
		/*Default deconstructor */
	}


	void LevelThree::Update()
	{
	 		if (test == true) //Horozontal Movement:
			{
				// MAP SPEED:
				Map4_Base -> positionX+=mapSpeed;
				Map4_Objects -> positionX+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY-=1;
				WaterBackground -> positionX+=WaterSpeed;
			}
			else //Vertical Movement:
			{
				// MAP SPEED:
				Map4_Base ->positionY+=mapSpeed;
				Map4_Objects ->positionY+=mapSpeed;
				// PARALAX SCROLLING:
				WaterBackground -> positionY+=(WaterSpeed-1);
			}

			if (WaterBackground-> positionY < -1000)
			{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			// ENABLE TO PRINT (X,Y) PLAYER (MAP) COORDINATES:
			// std::cout<<"x:"<<Map1_Base->positionX<<" ""y:"<<Map1_Base->positionY<<std::endl;
	}


	void LevelThree::KeyDown(unsigned char key)
	{

			switch(key)
			{
				case 32: // the space bar
					     break;
				case 27: // the escape key
					     break;

				case 'w':
					     test = false;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 'a':
						 test = true;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;

				case 'd':
						 test = true;
						 mapSpeed = -9;
						 WaterSpeed = -4;
						 break;

				case 's':
						 test = false;
						 mapSpeed = 9;
						 WaterSpeed = 4;
						 break;
			}
	}


	void LevelThree::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: // the space bar
						 break;
				case 27: // the escape key
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

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX||
//																						   ||
//								 UI STATE ------- STATE 6								   ||
//																						   ||
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
		anynumber=1;


			//Sprite - Player Sprites.
			Player = new Sprite("images/PlayerSprite.png"); //Layer 4- Player Sprite.
			Player->setSpriteFrameSize(60, 60);
			Player->setNumberOfAnimations(16);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,60,0,4);
			Player->addSpriteAnimRow(2,0,60,60,0,4);
			Player->addSpriteAnimRow(3,0,120,60,0,4);
			Player->addSpriteAnimRow(4,0,180,60,0,4);
			Player->addSpriteAnimRow(5,0,240,60,0,4);
			Player->addSpriteAnimRow(6,0,300,60,0,4);
			Player->addSpriteAnimRow(7,0,360,60,0,4);
			Player->addSpriteAnimRow(8,0,420,60,0,4);
			Player->setPosition(160,95);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);

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
			/*UISample = new Sprite ("images/UIActionbar.png");
			UISample -> setNumberOfAnimations(1);
			UISample -> setSpriteFrameSize(200,50);
			UISample -> setPosition(140,10);
			UISample -> setCenter(0,0);
			UISample -> setLayerID (14);
			UISample ->addSpriteAnimRow(0,0,0,200,50,1);
			UISample -> setCurrentAnimation(1);
			this->addSpriteToDrawList(UISample);*/
			
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
				Player->setPosition(210,110);
				Player-> setCurrentAnimation(1);
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

	

	 		if (test == true) //Horozontal Movement:
			{
				
			}
			else //Vertical Movement:
			{
				
			}

	}


	void UIState::KeyDown(unsigned char key)
	{

			switch(key)
			{

				case 27: // the escape key
					     break;

				case 'w':
						 Player->setCurrentAnimation(2);
						 anynumber=2;
						 Player->nextFrame();
						 break;

				case 'a':
						 Player->setCurrentAnimation(4);
						 Player->nextFrame();
						 anynumber=4;
						 break;

				case 's':
						 Player->setCurrentAnimation(1);
						 Player->nextFrame();
						 anynumber=1;
						 break;

				case 'd':
						 Player->setCurrentAnimation(3);
						 Player->nextFrame();
						 anynumber=3;
						 break;

				case 45: if(0<Health)
						 Health--;
						 UIHealth->setCurrentAnimation(Health);
						 break;
				case 61: if(Health<10)
						 Health++;
						 UIHealth->setCurrentAnimation(Health);
						 break;
				case 32: Player->setCurrentAnimation(anynumber+4);
						 Player->nextFrame();
					     break;

				case 'o': Score--;
						  //UIScore[6]->setCurrentAnimation(Score);
						  ScoreUpdate();
						  break;
				case 'p': Score++;
						  //UIScore[6]->setCurrentAnimation(Score);
						  ScoreUpdate();
						  break;
			}
	}


	void UIState::KeyUp(unsigned char key)
	{
			switch(key)
			{
				case 32: Player->setCurrentAnimation(anynumber);
						 break;
				case 27: // the escape key
						 break;

			}
	}//Aaron's a prodigy

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
		loadcheck=false;
		anynumber=4;


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