#include "Objects.h"
/*	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	*/



MainCharacter::MainCharacter(std::string filename, int width, int height)
	:Characters(filename, width, height)
{
	this->setSpriteFrameSize(width, height);
	this->setNumberOfAnimations(8);
	this->addSpriteAnimFrame(0,0,0); // 0 face right
	this->addSpriteAnimFrame(1,0,64); // 1 face up
	this->addSpriteAnimFrame(2,0,132); // 2 face left (The sprite sheet wasn't made, in an ideal world, y should be 128, 64 intervals)
	this->addSpriteAnimFrame(3,-1,196); // 3 face down (Thee sprite sheet wasn't well made, in an ideal world, x should be 0)
	this->addSpriteAnimRow(4, 32,0, 32,0, 4); // 4 walk right
	this->addSpriteAnimRow(5, 32,64, 32,0, 4); // 5 walk up
	this->addSpriteAnimRow(6, 32,132, 32,0, 4); // 6 walk left 
	this->addSpriteAnimRow(7, 31,196, 32,0, 4); // 7 walk down
	this->setPosition(200,200);
	this->setCurrentAnimation(3);

	this->setLayerID(5);

}

MainCharacter::~MainCharacter(void)
{
	/* Deconstructor */
}

void MainCharacter::update()
{
	glutKeyboardFunc;
	glutKeyboardUpFunc;
	this->nextFrame();
}


void MainCharacter::movementGo(unsigned char key)
{
	switch(key)
	{
	case 'w': //Up (walk) = 5
		this->setCurrentAnimation(5);
		this->positionY = positionY + 5.f;
		if(positionY > 432) positionY = 431;
		break;
	case 's': // Down (walk) = 7
		this->setCurrentAnimation(7);
		this->positionY = positionY + -5.f;
		if(positionY < 0) positionY = 1;
		break;
	case 'a': // Left (walk) = 6
		this->setCurrentAnimation(6);
		this->positionX = positionX + -5.f;
		if(positionX < 0) positionX = 1;
		break;
	case 'd': // right (walk) = 4
		this->setCurrentAnimation(4);
		this->positionX = positionX + 5.f;
		if(positionX > 800) positionX = 799;
		break;
	}
}

void MainCharacter::movementStop(unsigned char key)
{
		switch(key)
	{
	case 'w': //Up (stationary) = 1
		this->setCurrentAnimation(1);
		break;
	case 's': // Down (stationary) = 3
		this->setCurrentAnimation(3);
		break;
	case 'a': // Left (stationary) = 2
		this->setCurrentAnimation(2);
		break;
	case 'd': // right (stationary) = 0
		this->setCurrentAnimation(0);
		break;
		}
}	
