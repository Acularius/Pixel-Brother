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

			LocalGame -> playSound(); //PLAY'S FMOD LOOP BACKGROUND SOUND.

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
				Player = new Sprite("images/PlayerSprite.png");
				this->addSpriteToDrawList(Player);
				Player->setSpriteFrameSize(28, 48);
				Player->setNumberOfAnimations(8);
				Player->setCenter(0,0);
				Player->addSpriteAnimRow(1,0,0,28,0,5);
				Player->addSpriteAnimRow(2,0,48,28,0,5);
				Player->addSpriteAnimRow(3,0,96,28,0,5);
				Player->addSpriteAnimRow(4,0,144,28,0,5);
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

			//Sprite - Player Sprites.
			Player = new Sprite("images/PlayerSprite.png");
			Player->setSpriteFrameSize(28, 48);
			Player->setNumberOfAnimations(8);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,28,0,5);
			Player->addSpriteAnimRow(2,0,48,28,0,5);
			Player->addSpriteAnimRow(3,0,96,28,0,5);
			Player->addSpriteAnimRow(4,0,144,28,0,5);
			Player->setPosition(230,130);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			
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


	void LevelHome::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
				Map1_Base -> setPosition(-1422,-1033);
				Player->setPosition(230,130);
				Player->setCurrentAnimation(1);
				Map1_Objects -> setPosition(-1422,-1033);
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
	}


	void LevelHome::KeyDown(unsigned char key)
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

			//Sprite - Player Sprites.
			Player = new Sprite("images/PlayerSprite.png");
			Player->setSpriteFrameSize(28, 48);
			Player->setNumberOfAnimations(8);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,28,0,5);
			Player->addSpriteAnimRow(2,0,48,28,0,5);
			Player->addSpriteAnimRow(3,0,96,28,0,5);
			Player->addSpriteAnimRow(4,0,144,28,0,5);
			Player->setPosition(230,130);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			
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


	void LevelOne::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
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

			//Sprite - Player Sprites.
			Player = new Sprite("images/PlayerSprite.png");
			Player->setSpriteFrameSize(28, 48);
			Player->setNumberOfAnimations(8);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,28,0,5);
			Player->addSpriteAnimRow(2,0,48,28,0,5);
			Player->addSpriteAnimRow(3,0,96,28,0,5);
			Player->addSpriteAnimRow(4,0,144,28,0,5);
			Player->setPosition(230,130);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			
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


	void LevelTwo::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
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

			//Sprite - Player Sprites.
			Player = new Sprite("images/PlayerSprite.png");
			Player->setSpriteFrameSize(28, 48);
			Player->setNumberOfAnimations(8);
			Player->setCenter(0,0);
			Player->addSpriteAnimRow(1,0,0,28,0,5);
			Player->addSpriteAnimRow(2,0,48,28,0,5);
			Player->addSpriteAnimRow(3,0,96,28,0,5);
			Player->addSpriteAnimRow(4,0,144,28,0,5);
			Player->setPosition(230,130);
			Player->setCurrentAnimation(1);
			Player->setLayerID(4);
			this->addSpriteToDrawList(Player);
			
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


	void LevelThree::ResetMap()
	{ 
				WaterBackground -> setPosition(-1700,-750);
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

//																			|Aaron Alphonso|
//###########################################################################################