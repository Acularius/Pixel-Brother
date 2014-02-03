#include "Objects.h"


Objects::Objects(std::string filename, int width, int height)
	: Sprite(filename)
{
	this->setSpriteFrameSize(width, height);
	this-> human = false;
	this-> stationary = false;
	this->player = false;

	//Movement - Object starts NOT moving
	speedX = 0; 
	speedY = 0;


}
Objects::~Objects()
{
	/* Deconstructor */
}
void Objects::update() 
{

this->nextFrame();
this->movement();

}


/* Movement
*/
void Objects::movementGo(unsigned char key) //Keyboard down
	{
		float move = 3;
		if(human == true) // Direct Player control
		{
			move = move;
		} else if(stationary == true) // For static objects like the HUD
		{
			move = 0;
		} else { // Movement in relation to the Player's control
			move = -move;
		};

		if (key == 'w')//Up (walk) = 5; +Y
	{
		this->speedY = move;
		this->speedX = 0.f;
		if(player == true)
			this->setCurrentAnimation(5);

	}
	else if( key == 's') // Down (walk) = 7; -Y
	{
		this->speedY = -move;
		this->speedX = 0.f;
		if(player == true)
			this->setCurrentAnimation(7);
	}
	else if( key == 'a') // Left (walk) = 6; -X
	{
		this->speedY = 0.f;
		this->speedX = -move;
		if(player == true)
			this->setCurrentAnimation(6);
	}
	else if( key == 'd') // right (walk) = 4; +X
	{
		this->speedY = 0.f;
		this->speedX = move;
		if(player == true)
			this->setCurrentAnimation(4);
	}
	else // Character going nowhere
	{
		this->speedY = 0.f;
		this->speedX = 0.f;
	}

	}
	
	

void Objects::movementStop(unsigned char key) //Keyboard Up
	{
				switch(key)
	{
	case 'w': //Up (stationary) = 1; Y
		this->speedY=0.f;
		this->speedX=0.f;
		if(player == true)
			this->setCurrentAnimation(1);
		break;
	case 's': // Down (stationary) = 3; Y
		this->speedY=0.f;
		this->speedX=0.f;
		if(player == true)
			this->setCurrentAnimation(3);
		break;
	case 'a': // Left (stationary) = 2; X
		this->speedY=0.f;
		this->speedX=0.f;
		if(player == true)
			this->setCurrentAnimation(2);
		break;
	case 'd': // right (stationary) = 0; X
		this->speedY=0.f;
		this->speedX=0.f;
		if(player == true)
			this->setCurrentAnimation(0);
		break;
		}
	}


void Objects::movement()
	{
	this->positionX = positionX + speedX;
	this->positionY = positionY + speedY;

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


