//###########################################################################################
//
//										  OBJECTS.cpp
//																		|Sprite lib||Donald|
//###########################################################################################

	#include "Objects.h"

//-------------------------------------------------------------------------------------------
//  Object Class:
// The Work horse of the game, should never use sprite to load anything. 
// Use this to derive more specialized objects, but it comes equipped with all the data members that are needed to be inherited.
//-------------------------------------------------------------------------------------------

	Objects::Objects(std::string filename, int width, int height)
		: Sprite(filename)
	{
		this-> setSpriteFrameSize(width, height);
		this-> AI = false;
		this-> stationary = false;
		this-> player = false;
		this-> collidable = false;
		this-> ghost = false;
		this->award = false;

		//Movement speeds
		this-> inMotion = false;
		this-> inMotionSpeed = 10.f;
		this-> respectiveSpeed = 0.f;

		this-> setPosition(0,0);

		//Tick to slow down frame.

		this->tickFrame = 0;

		//Combat
		immortal = true;
		hP = 0;
		dam= 0;
		coolDown = false;
		coolDTicking = 0;
		attackTicking = 0;

		bOpponent = false;
		bInitiator = false;
		separComSys = false;
	

		direction = 0;
		// Interactbox
		attack= false;
		attackanim = false;
		talk = false;
		interboxactive = false;

		//Movement - Object starts NOT moving
		inMotionSpeedX = 0; 
		inMotionSpeedY = 0;
		respectiveSpeedX = 0;
		respectiveSpeedY = 0;

		// Hitbox for objects
		ObjectHitbox = new Hitbox(width,height, positionX,positionY);
		ObjectActBox = new InteractBox;

	}


	Objects::~Objects()
	{
		/* Deconstructor */
	}

//-------------------------------------------------------------------------------------------
//  Using an iterator of the object, update all the functions below.
//-------------------------------------------------------------------------------------------

	void Objects::update() 
	{
		tickFrame++;

	if(player == true && inMotion == true)
	{
		this-> nextFrame();
	}
	else if(tickFrame >= 2)
	{
		this->nextFrame();
		tickFrame = 0;
	}
	else
	{
	};

	this-> ObjectHitbox->updateHitbox(positionX,positionY, player);
		//Combat system
		attackUpdate();
		coolDownfunc();
	
		if(player ==true)
		{
		ObjectActBox->InteractBoxActive(interboxactive, talk, attack, direction, (ObjectHitbox->leftCornerX), (ObjectHitbox->bottomCornerY));
		}else
		{
		ObjectActBox->InteractBoxActive(interboxactive, talk, attack, direction, positionX, positionY);
		}
}

//-------------------------------------------------------------------------------------------
//		Combat Function:
//-------------------------------------------------------------------------------------------

	void Objects::coolDownfunc()
	{
		if (coolDown == true && coolDTicking < 1)
		{
			coolDTicking++;
		}
		else if (coolDown == true && coolDTicking >=1)
		{
			coolDown=false;
			coolDTicking = 0;
		}
		else
		{
		};
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Objects::attackBreakDown()
	{
		std::cout<< "BOOM! " << std::endl;
		if(coolDown ==true)
		{
			attackanim = false;
			attack = false;
			interboxactive = true;
			std::cout << "I'm tired" << std::endl;
		}
		else{
			if(attackTicking == 0)
			{
				attackTicking++;
				interboxactive = true;
				attackanim = true;
				this-> setCurrentAnimation(direction+4);
				AudioLibPlaySound("Sounds/Woosh.mp3",false);

			}
			else
			{
			}
		}
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Objects::attackBreakUp()
	{

		std::cout<< "BOOOOOM! HEADSHOT! end" << std::endl;
		attackTicking = 0;
		attack = false;
		interboxactive = false;
		attackanim = false;
		coolDown = true;
		this-> setCurrentAnimation(direction);


	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Objects::attackUpdate()
	{
		if(coolDown == true && separComSys == false)
		{
			attackanim = false;
			interboxactive = false;
			attack = false;
		//	std::cout << "I'm le tired" << std::endl;
		}
		else
		{
			if(attackTicking == 1 && separComSys ==false)
			{
				attackTicking++;
				interboxactive = true;
				attack = true;
				attackanim = true;
			}
			else if (attackTicking > 1 && attackTicking <= 5 && separComSys==false)
			{
				attackTicking++;
				interboxactive = false;
				attack = false;
				attackanim = true;
			}else if(attackTicking > 5 && separComSys==false)
			{
				attackTicking = 0;
				coolDown = true;
				attackanim = false;
				if (player == true)
				this-> setCurrentAnimation(direction);
			}
			else
			{
				// Nothing to see here
			}
		}
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Objects::movementGo(unsigned char key) //Keyboard down
	{
		float stop;
		float speed;
		speed = inMotionSpeed;
		if ((player==true) || (stationary==true))
		{
			speed = 0.f;
		} else
		{
			speed = -speed;
		}
		stop = 0.f;

		switch (key) 
		{
			//Up (walk) = 5; +Y 
		case 'w':
			{
				this-> inMotionSpeedY = speed;
				this-> inMotionSpeedX = stop;
				if(player == true)
				{
					this->setCurrentAnimation(2);
					this->direction = 2;
					this->inMotion = true;
				};
				break;
			};
			// Down (walk) = 7; -Y
		case 's':
			{
				this-> inMotionSpeedY = -speed;
				this-> inMotionSpeedX = stop;
				if(player == true)
				{
					this-> setCurrentAnimation(1);
					this-> direction = 1;
					this->inMotion = true;
				};
				break;
			};
			// Left (walk) = 6; -X
		case 'a':
			{
				this-> inMotionSpeedY = stop;
				this-> inMotionSpeedX = -speed;
				if(player == true)
				{
					this->setCurrentAnimation(4);
					this-> direction=4;
					this->inMotion = true;
				};
				break;
			};
			// right (walk) = 4; +X
			//this->setCurrentAnimation(4);
		case 'd':
			{
				this-> inMotionSpeedY = stop;
				this-> inMotionSpeedX = speed;
				if(player == true)
				{
					this-> setCurrentAnimation(3);
					this-> direction=3;
					this->inMotion = true;
				};
				break;
			};
		case 32:
			{
				if(player == true){
				this-> inMotion = true;
				};
			};
			break;

		};
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Objects::movementStop(unsigned char key) //Keyboard Up
	{
		float stop;
		float speed;
		speed = inMotionSpeed;
		if ((player==true) || (stationary==true))
		{
			speed = 0.f;
		} else
		{
			speed = -speed;
		}
		stop = 0.f;
	switch (key)
	{
		//Up (stationary) = 1; Y
	case 'w':
		{
			this-> inMotionSpeedY = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(2);
				this-> direction = 2;
				this->inMotion = false;
			};
			break;
		};
		// Down (stationary) = 3; Y	
	case 's':
		{
			this-> inMotionSpeedY = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(1);
				this-> direction = 1;
				this->inMotion = false;
			};
			break;
		};
		// Left (stationary) = 2; X
	case 'a':
		{
			this-> inMotionSpeedX = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(4);
				this-> direction = 4;
				this-> inMotion = false;
			};
		break;
			 };
		// right (stationary) = 0; X
	case 'd':
		{
			this-> inMotionSpeedX = stop;
			if(player==true)
			{
				this-> setCurrentAnimation(3);
				this-> direction=3;
				this->inMotion = false;
			}
			break;
		};

	case 32:
			{
				if(player==true){
			this-> setCurrentAnimation(direction);
			this->inMotion = false;
				};
			break;
			};
	}

}

//-------------------------------------------------------------------------------------------
// Creation of Characters: It will be derived into the Player (human) class, NPC's & enemies.
//-------------------------------------------------------------------------------------------

	Characters::Characters(std::string filename, int width, int height)
		:Objects(filename, width, height)
	{

	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	Characters::~Characters(void)
	{
		/* Deconstructor */
	}

//																		|Sprite lib||Donald|
//###########################################################################################


