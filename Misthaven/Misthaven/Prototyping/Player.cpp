#include "Objects.h"




MainCharacter::MainCharacter(std::string filename, int width, int height)
	:Characters(filename, width, height)
{
	this->setNumberOfAnimations(16);
	//this->addSpriteAnimFrame(0,0,120); // 0 face right
	//this->addSpriteAnimFrame(1,0,60); // 1 face up
	//this->addSpriteAnimFrame(2,0,180); // 2 face left 
	//this->addSpriteAnimFrame(3,0,0); // 3 face down 
	//this->addSpriteAnimRow(4, 60,120, 60,0, 4); // 4 walk right
	//this->addSpriteAnimRow(5, 60,60, 60,0, 4); // 5 walk up
	//this->addSpriteAnimRow(6, 60,180, 60,0, 4); // 6 walk left 
	//this->addSpriteAnimRow(7, 60,0, 60,0, 4); // 7 walk down
	this->addSpriteAnimRow(1,0,0,60,0,4);
	this->addSpriteAnimRow(2,0,60,60,0,4);
	this->addSpriteAnimRow(3,0,120,60,0,4);
	this->addSpriteAnimRow(4,0,180,60,0,4);
	this->addSpriteAnimRow(5,0,240,60,0,4);
	this->addSpriteAnimRow(6,0,300,60,0,4);
	this->addSpriteAnimRow(7,0,360,60,0,4);
	this->addSpriteAnimRow(8,0,420,60,0,4);
	this->setPosition(160,95); // 231,130
	this->setCurrentAnimation(1);
	this->direction = 1; // Facing down

	this->setLayerID(11);
	this-> speedX = 0; // Character starts NOT moving
	this-> speedY = 0;
	this-> player = true;
	this-> stationary = false;

	this-> collidable = true;

	Health=10;
	Score=0;

		// Hitbox for objects
	ObjectHitbox = new Hitbox(20,25, positionX+20,positionY+10); 
	

}

MainCharacter::~MainCharacter(void)
{
	/* Deconstructor */
}



