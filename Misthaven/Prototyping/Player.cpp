//###########################################################################################
//
//										  PLAYER.cpp
//																		|Sprite lib||Donald|
//###########################################################################################

		#include "Objects.h"

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	MainCharacter::MainCharacter(std::string filename, int width, int height)
		:Characters(filename, width, height)
	{
		this->setNumberOfAnimations(16);
		//Set up
		this->addSpriteAnimRow(1,0,0,60,0,4);
		this->addSpriteAnimRow(2,0,60,60,0,4);
		this->addSpriteAnimRow(3,0,120,60,0,4);
		this->addSpriteAnimRow(4,0,180,60,0,4);
		this->addSpriteAnimRow(5,0,240,60,0,4);
		this->addSpriteAnimRow(6,0,300,60,0,4);
		this->addSpriteAnimRow(7,0,360,60,0,4);
		this->addSpriteAnimRow(8,0,420,60,0,4);
		this->setPosition(210,100); 
		this->setCurrentAnimation(1);

		this->direction = 1; // Facing down

		this-> speedX = 0; // Character starts NOT moving
		this-> speedY = 0;
		this-> player = true;
		this-> stationary = false;
		this-> collidable = true;


		//Combat information
		hP= 10;
		dam = 1;
		GameCheckpoint = 3; //Setting the portal to take the player to level 1. 

		this->immortal=false;

		tickHPRegen = 0;

		//Score
		scoreStorage = 0;

		// Hitbox for objects
		ObjectHitbox = new Hitbox(20,25, positionX+20,positionY+10); 
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	MainCharacter::~MainCharacter(void)
	{
		/* Deconstructor */
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void MainCharacter::playerUpdate()
	{
		healthRegen();
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void MainCharacter::healthRegen()
	{
		if(hP < 10)
		{
			if(tickHPRegen < 400)
			{
				tickHPRegen++;
			}else if(tickHPRegen >= 200 )
			{
				hP++;
				tickHPRegen = 0;
			}else
			{
				//nothing
			}
		}
		else{
			//No regen
		}
	}
//																		|Sprite lib||Donald|
//###########################################################################################