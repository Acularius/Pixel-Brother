#include "Objects.h"
/*	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	*/



MainCharacter::MainCharacter(std::string filename, int width, int height)
	:Characters(filename, width, height)
{
	this->setNumberOfAnimations(8);
	this->addSpriteAnimFrame(0,0,96); // 0 face right
	this->addSpriteAnimFrame(1,0,48); // 1 face up
	this->addSpriteAnimFrame(2,0,144); // 2 face left 
	this->addSpriteAnimFrame(3,0,0); // 3 face down 
	this->addSpriteAnimRow(4, 28,96, 28,0, 4); // 4 walk right
	this->addSpriteAnimRow(5, 28,48, 28,0, 4); // 5 walk up
	this->addSpriteAnimRow(6, 28,144, 28,0, 4); // 6 walk left 
	this->addSpriteAnimRow(7, 28,0, 28,0, 4); // 7 walk down
	this->setPosition(232,156);
	this->setCurrentAnimation(3);
	this->direction = 3; // Facing down

	this->centerX = width/2;
	this->centerY = height/2;

	this->setLayerID(11);
	this-> speedX = 0; // Character starts NOT moving
	this-> speedY = 0;
	this-> human = true;
	this-> player = true;
	this-> stationary = false;
	

}

MainCharacter::~MainCharacter(void)
{
	/* Deconstructor */
}



