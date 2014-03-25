#include "GameState.h"
#include "Game.h"
#include "Sprite.h"



	void GameState::addSpriteToDrawList(Sprite *s)
{
	if(s)
	{
		/* push the sprite to the back of the list */
		std::cout<<"||";	//Loading Screen.
		//if(active==true)
		this->spriteListToDraw.push_back(s);
	}
}

	void GameState::Draw()
	{
		std::vector<Sprite*>::iterator it; 
		for(it=spriteListToDraw.begin(); it != spriteListToDraw.end(); it++)
		{ 
			Sprite *s = (*it);
			//if(active==true)
			s->draw();
		}
	}



//===========================================================================================
// MAIN MENU ----- STATE 1
//===========================================================================================



void MainMenu::Init(Game* Local)
{
			LocalGame=Local;
			menuSpeed=0;
			active=false;

			LocalGame -> playSound();

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
			speedX = 0; // Character starts NOT moving
			speedY = 0;

}

MainMenu::~MainMenu(void) { /*Default deconstructor */}

void MainMenu::Update()
{

			if (test==true)
			{ MenuStrip -> positionX+=menuSpeed; }

			if (MenuStrip -> positionX > -65 )
			{ MenuStrip -> setPosition(-65,60); }

			else
			if (MenuStrip -> positionX < -875)
			{ MenuStrip -> setPosition(-875,60); }

			MenuBG -> positionX-=1;
			if (MenuBG -> positionX < -480)
			{ MenuBG -> setPosition(0,0); }


}


/*void MainMenu::MenuControl (int opt)
{  
	switch(opt)
   { 
      case 1: { 
				std::cout<<"OPTION 1 \a"<<std::endl;
				active=false;
			    break;
				

		        break;
			  }
      case 2: { std::cout<<"OPTION 2 \a"<<std::endl;
			    break;
			  }
      case 3: { std::cout<<"OPTION 3 \a"<<std::endl;
			    break;
			  }
      case 4: { std::cout<<"OPTION 4 \a"<<std::endl;
			    break;
			  }
	  case 5: exit(1); break;
   }
}*/ 
   

void MainMenu::KeyDown(unsigned char key)
{
	switch(key)
		{   case 'd':  { 	test = true;
							
							if (0< MenuStrip -> positionX <866)
							{menuSpeed = -10;}

							Player->setCurrentAnimation(3);
							Player->nextFrame();

						    option=int((MenuStrip -> positionX/200)*-1)+1;
					        MenuStrip->setCurrentAnimation(option-1); 
					        break;
					   }

			case 'a':  {    test = true;
								
							if (0< MenuStrip -> positionX <866)
							{menuSpeed = +10;}
								
							Player->setCurrentAnimation(4);
							Player->nextFrame();

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

//===========================================================================================
// LEVEL HOME ----- STATE 2
//===========================================================================================


void LevelHome::Init(Game* Local)
{
	LocalGame=Local;
	active=false;

	//LocalGame -> playSound();

			Player = new Sprite("images/PlayerSprite.png");
			this->addSpriteToDrawList(Player);
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
			speedX = 0;
			speedY = 0;

		Map1_Base = new Sprite ("images/Map 1 Base.png");
		Map1_Base -> setNumberOfAnimations(1);
		Map1_Base -> setSpriteFrameSize(2500,2000);
		Map1_Base -> setPosition(-1422,-1033);
		Map1_Base -> setCenter(0,0);
		Map1_Base -> setLayerID (2);
		Map1_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
		Map1_Base -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map1_Base);

		Map1_Objects = new Sprite ("images/Map 1 Objects.png");
		Map1_Objects -> setNumberOfAnimations(1);
		Map1_Objects -> setSpriteFrameSize(2500,2000);
		Map1_Objects -> setPosition(-1422,-1033);
		Map1_Objects -> setCenter(0,0);
		Map1_Objects -> setLayerID (6);
		Map1_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
		Map1_Objects -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map1_Objects);

		WaterBackground = new Sprite ("images/Water Sprite.png");
		WaterBackground -> setNumberOfAnimations(1);
		WaterBackground -> setSpriteFrameSize(2500,2000);
		WaterBackground -> setPosition(-1700,-750);
		WaterBackground -> setCenter(0,0);
		WaterBackground -> setLayerID (1);
		WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
		WaterBackground -> setCurrentAnimation(1);
		this->addSpriteToDrawList(WaterBackground);

		UISample = new Sprite ("images/Test UI.png");
		UISample -> setNumberOfAnimations(1);
		UISample -> setSpriteFrameSize(480,261);
		UISample -> setPosition(0,0);
		UISample -> setCenter(0,0);
		UISample -> setLayerID (7);
		UISample ->addSpriteAnimRow(0,0,0,480,261,1);
		UISample -> setCurrentAnimation(1);
		this->addSpriteToDrawList(UISample);
	

		/*initialization*/

		mapSpeed = 0;
		WaterSpeed = 0;
}


void LevelHome::Update()
 {
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

			std::cout<<"x:"<<Map1_Base->positionX<<" ""y:"<<Map1_Base->positionY<<std::endl;

 }


void LevelHome::KeyDown(unsigned char key)
	 {

			switch(key)
			{
			case 32: // the space bar
				break;
			case 27: // the escape key
			//case 'q': // the 'q' key
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

			case 'o':
				gameState=3;
				break;}
	 }


void LevelHome::KeyUp(unsigned char key)
	 {

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


//===========================================================================================
// LEVEL ONE ----- STATE 3
//===========================================================================================


void LevelOne::Init(Game* Local)
{
	LocalGame=Local;
	active=false;

	//LocalGame -> playSound();

			Player = new Sprite("images/PlayerSprite.png");
			this->addSpriteToDrawList(Player);
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
			speedX = 0;
			speedY = 0;

		Map2_Base = new Sprite ("images/Map 2 Base.png");
		Map2_Base -> setNumberOfAnimations(1);
		Map2_Base -> setSpriteFrameSize(2500,2000);
		Map2_Base -> setPosition(-475,-1410);
		Map2_Base -> setCenter(0,0);
		Map2_Base -> setLayerID (2);
		Map2_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
		Map2_Base -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map2_Base);

		Map2_Objects = new Sprite ("images/Map 2 Objects.png");
		Map2_Objects -> setNumberOfAnimations(1);
		Map2_Objects -> setSpriteFrameSize(2500,2000);
		Map2_Objects -> setPosition(-475,-1410);
		Map2_Objects -> setCenter(0,0);
		Map2_Objects -> setLayerID (6);
		Map2_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
		Map2_Objects -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map2_Objects);

		WaterBackground = new Sprite ("images/Water Sprite 2.png");
		WaterBackground -> setNumberOfAnimations(1);
		WaterBackground -> setSpriteFrameSize(2500,2000);
		WaterBackground -> setPosition(-1700,-750);
		WaterBackground -> setCenter(0,0);
		WaterBackground -> setLayerID (1);
		WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
		WaterBackground -> setCurrentAnimation(1);
		this->addSpriteToDrawList(WaterBackground);

		UISample = new Sprite ("images/Test UI.png");
		UISample -> setNumberOfAnimations(1);
		UISample -> setSpriteFrameSize(480,261);
		UISample -> setPosition(0,0);
		UISample -> setCenter(0,0);
		UISample -> setLayerID (7);
		UISample ->addSpriteAnimRow(0,0,0,480,261,1);
		UISample -> setCurrentAnimation(1);
		this->addSpriteToDrawList(UISample);
	

		/*initialization*/

		mapSpeed = 0;
		WaterSpeed = 0;
}


void LevelOne::Update()
 {
	 	if (test == true)//left right
		{

			Map2_Base -> positionX+=mapSpeed;
			Map2_Objects -> positionX+=mapSpeed;
			WaterBackground -> positionY-=1;
			WaterBackground -> positionX+=WaterSpeed;

		}
		else //up down
		{


			Map2_Base ->positionY+=mapSpeed;
			Map2_Objects ->positionY+=mapSpeed;
			WaterBackground -> positionY+=(WaterSpeed-1);
			
		
		}

		if (WaterBackground-> positionY < -1000)
		{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			std::cout<<"x:"<<Map2_Base->positionX<<" ""y:"<<Map2_Base->positionY<<std::endl;

 }


void LevelOne::KeyDown(unsigned char key)
	 {

			switch(key)
			{
			case 32: // the space bar
				break;
			case 27: // the escape key
			//case 'q': // the 'q' key
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

			case 'o':
				gameState=3;
				break;}
	 }


void LevelOne::KeyUp(unsigned char key)
	 {

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

//===========================================================================================
// LEVEL TWO ----- STATE 4
//===========================================================================================

void LevelTwo::Init(Game* Local)
{
	LocalGame=Local;
	active=true;

	//LocalGame -> playSound();

			Player = new Sprite("images/PlayerSprite.png");
			this->addSpriteToDrawList(Player);
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
			speedX = 0;
			speedY = 0;

		Map3_Base = new Sprite ("images/Map 3 Base.png");
		Map3_Base -> setNumberOfAnimations(1);
		Map3_Base -> setSpriteFrameSize(2500,2000);
		Map3_Base -> setPosition(-1552,-1402);
		Map3_Base -> setCenter(0,0);
		Map3_Base -> setLayerID (2);
		Map3_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
		Map3_Base -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map3_Base);

		Map3_Objects = new Sprite ("images/Map 3 Objects.png");
		Map3_Objects -> setNumberOfAnimations(1);
		Map3_Objects -> setSpriteFrameSize(2500,2000);
		Map3_Objects -> setPosition(-1552,-1402);
		Map3_Objects -> setCenter(0,0);
		Map3_Objects -> setLayerID (6);
		Map3_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
		Map3_Objects -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map3_Objects);

		WaterBackground = new Sprite ("images/Water Sprite 5.png");
		WaterBackground -> setNumberOfAnimations(1);
		WaterBackground -> setSpriteFrameSize(2500,2000);
		WaterBackground -> setPosition(-1700,-750);
		WaterBackground -> setCenter(0,0);
		WaterBackground -> setLayerID (1);
		WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
		WaterBackground -> setCurrentAnimation(1);
		this->addSpriteToDrawList(WaterBackground);

		UISample = new Sprite ("images/Test UI.png");
		UISample -> setNumberOfAnimations(1);
		UISample -> setSpriteFrameSize(480,261);
		UISample -> setPosition(0,0);
		UISample -> setCenter(0,0);
		UISample -> setLayerID (7);
		UISample ->addSpriteAnimRow(0,0,0,480,261,1);
		UISample -> setCurrentAnimation(1);
		this->addSpriteToDrawList(UISample);
	

		/*initialization*/

		mapSpeed = 0;
		WaterSpeed = 0;
}


void LevelTwo::Update()
 {
	 	if (test == true)//left right
		{

			Map3_Base -> positionX+=mapSpeed;
			Map3_Objects -> positionX+=mapSpeed;
			WaterBackground -> positionY-=1;
			WaterBackground -> positionX+=WaterSpeed;

		}
		else //up down
		{


			Map3_Base ->positionY+=mapSpeed;
			Map3_Objects ->positionY+=mapSpeed;
			WaterBackground -> positionY+=(WaterSpeed-1);
			
		
		}

		if (WaterBackground-> positionY < -1000)
		{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			std::cout<<"x:"<<Map3_Base->positionX<<" ""y:"<<Map3_Base->positionY<<std::endl;

 }


void LevelTwo::KeyDown(unsigned char key)
	 {

			switch(key)
			{
			case 32: // the space bar
				break;
			case 27: // the escape key
			//case 'q': // the 'q' key
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

			case 'o':
				gameState=3;
				break;}
	 }


void LevelTwo::KeyUp(unsigned char key)
	 {

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

//===========================================================================================
// LEVEL THREE ----- STATE 5
//===========================================================================================

void LevelThree::Init(Game* Local)
{
	LocalGame=Local;
	active=false;

	//LocalGame -> playSound();

			Player = new Sprite("images/PlayerSprite.png");
			this->addSpriteToDrawList(Player);
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
			speedX = 0;
			speedY = 0;

		Map4_Base = new Sprite ("images/Map 4 Base.png");
		Map4_Base -> setNumberOfAnimations(1);
		Map4_Base -> setSpriteFrameSize(2500,2000);
		Map4_Base -> setPosition(-1404,-1384);
		Map4_Base -> setCenter(0,0);
		Map4_Base -> setLayerID (2);
		Map4_Base -> addSpriteAnimRow(0,0,0,2500,2000,1);
		Map4_Base -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map4_Base);

		Map4_Objects = new Sprite ("images/Map 4 Objects.png");
		Map4_Objects -> setNumberOfAnimations(1);
		Map4_Objects -> setSpriteFrameSize(2500,2000);
		Map4_Objects -> setPosition(-1404,-1384);
		Map4_Objects -> setCenter(0,0);
		Map4_Objects -> setLayerID (6);
		Map4_Objects ->addSpriteAnimRow(0,0,0,2500,2000,1);
		Map4_Objects -> setCurrentAnimation(1);
		this->addSpriteToDrawList(Map4_Objects);

		WaterBackground = new Sprite ("images/Water Sprite 5.png");
		WaterBackground -> setNumberOfAnimations(1);
		WaterBackground -> setSpriteFrameSize(2500,2000);
		WaterBackground -> setPosition(-1700,-750);
		WaterBackground -> setCenter(0,0);
		WaterBackground -> setLayerID (1);
		WaterBackground ->addSpriteAnimRow(0,0,0,2500,2000,1);
		WaterBackground -> setCurrentAnimation(1);
		this->addSpriteToDrawList(WaterBackground);

		UISample = new Sprite ("images/Test UI.png");
		UISample -> setNumberOfAnimations(1);
		UISample -> setSpriteFrameSize(480,261);
		UISample -> setPosition(0,0);
		UISample -> setCenter(0,0);
		UISample -> setLayerID (7);
		UISample ->addSpriteAnimRow(0,0,0,480,261,1);
		UISample -> setCurrentAnimation(1);
		this->addSpriteToDrawList(UISample);
	

		/*initialization*/

		mapSpeed = 0;
		WaterSpeed = 0;
}


void LevelThree::Update()
 {
	 	if (test == true)//left right
		{

			Map4_Base -> positionX+=mapSpeed;
			Map4_Objects -> positionX+=mapSpeed;
			WaterBackground -> positionY-=1;
			WaterBackground -> positionX+=WaterSpeed;

		}
		else //up down
		{


			Map4_Base ->positionY+=mapSpeed;
			Map4_Objects ->positionY+=mapSpeed;
			WaterBackground -> positionY+=(WaterSpeed-1);
			
		
		}

		if (WaterBackground-> positionY < -1000)
		{ WaterBackground -> setPosition(-1700,-750); } //RESETTING SCROLLING BACKGROUND. 

			std::cout<<"x:"<<Map4_Base->positionX<<" ""y:"<<Map4_Base->positionY<<std::endl;

 }


void LevelThree::KeyDown(unsigned char key)
	 {

			switch(key)
			{
			case 32: // the space bar
				break;
			case 27: // the escape key
			//case 'q': // the 'q' key
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

			case 'o':
				gameState=3;
				break;}
	 }


void LevelThree::KeyUp(unsigned char key)
	 {

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

