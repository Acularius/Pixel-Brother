#include "Objects.h"


Objects::Objects(std::string filename, int width, int height)
	: Sprite(filename)
{
	this-> setSpriteFrameSize(width, height);
	this-> AI = false;
	this-> stationary = false;
	this-> player = false;
	this-> collidable = false;

	this-> inMotion = false;
	this-> inMotionSpeed = 10.f;
	this-> respectiveSpeed = 0.f;

	this-> setPosition(0,0);

	//Movement - Object starts NOT moving
	inMotionSpeedX = 0; 
	inMotionSpeedY = 0;
	respectiveSpeedX = 0;
	respectiveSpeedY = 0;

	// Hitbox for objects
	ObjectHitbox = new Hitbox(width,height, positionX,positionY);


}

Objects::~Objects()
{
	/* Deconstructor */
}
void Objects::update() 
{

this-> nextFrame();
this-> ObjectHitbox->updateHitbox(positionX,positionY);

}

/* Movement */
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
				this-> inMotionSpeedX = stop;
				this-> inMotionSpeedY = speed;
				if(player == true)
				{
					this->setCurrentAnimation(5);
				};
				break;
			};
			// Down (walk) = 7; -Y
		case 's':
			{
				this-> inMotionSpeedX = stop;
				this-> inMotionSpeedY = -speed;
				if(player == true)
				{
					this->setCurrentAnimation(7);
				};
				break;
			};
			// Left (walk) = 6; -X
		case 'a':
			{
				this-> inMotionSpeedX = -speed;
				this-> inMotionSpeedY = stop;
				if(player == true)
				{
					this->setCurrentAnimation(6);
				};
				break;
			};
			// right (walk) = 4; +X
			//this->setCurrentAnimation(4);
		case 'd':
			{
				this-> inMotionSpeedX = speed;
				this-> inMotionSpeedY = stop;
				if(player == true)
				{
					this-> setCurrentAnimation(4);
				};
				break;
			};
		};
	}
	
void Objects::movementStop(unsigned char key) //Keyboard Up
	{
	float stop = 0.f;
	switch (key)
	{
		//Up (stationary) = 1; Y
	case 'w':
		{
			this-> inMotionSpeedX = stop;
			this-> inMotionSpeedY = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(1);
			};
			break;
		};
		// Down (stationary) = 3; Y	
	case 's':
		{
			this-> inMotionSpeedX = stop;
			this-> inMotionSpeedY = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(3);
			};
			break;
		};
		// Left (stationary) = 2; X
	case 'a':
		{
			this-> inMotionSpeedX = stop;
			this-> inMotionSpeedY = stop;
			if(player == true)
			{
				this-> setCurrentAnimation(2);
			};
		break;
			 };
		// right (stationary) = 0; X
	case 'd':
		{
			this-> inMotionSpeedX = stop;
			this-> inMotionSpeedY = stop;
			if(player==true)
			{
				this-> setCurrentAnimation(0);
			}
			break;
		};
	}

}


/* Creation of Characters
* It will be derived into the Player (human) class, NPC's and enemies
*/


Characters::Characters(std::string filename, int width, int height)
	:Objects(filename, width, height)
{

}

Characters::~Characters(void)
{
	/* Deconstructor */
}



