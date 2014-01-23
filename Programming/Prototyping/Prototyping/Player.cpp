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
	this->addSpriteAnimRow(4, 0,0, 32,0, 4); // 4 walk right
	this->addSpriteAnimRow(5, 32,64, 32,0, 4); // 5 walk up
	this->addSpriteAnimRow(6, 0,132, 32,0, 4); // 6 walk left 
	this->addSpriteAnimRow(7, 31,196, 32,0, 4); // 7 walk down
	this->setPosition(0,0);
	this->setCurrentAnimation(3);

	this->setLayerID(11);
	speedX = 0; // Character starts NOT moving
	speedY = 0;
}

MainCharacter::~MainCharacter(void)
{
	/* Deconstructor */
}

void MainCharacter::update()
{

	this->nextFrame();
}


void MainCharacter::movementGo(unsigned char key)
{
	float move = 5;
	if (key == 'w')//Up (walk) = 5; +Y
	{
		this->setCurrentAnimation(5); 
		this->speedY = move;
		this->speedX = 0.f;
	}
	else if( key == 's') // Down (walk) = 7; -Y
	{
		this->setCurrentAnimation(7); 
		this->speedY = -move;
		this->speedX = 0.f;
	}
	else if( key == 'a') // Left (walk) = 6; -X
	{
		this->setCurrentAnimation(6);
		this->speedY = 0.f;
		this->speedX = -move;
	}
	else if( key == 'd') // right (walk) = 4; +X
	{
		this->setCurrentAnimation(4);
		this->speedY = 0.f;
		this->speedX = move;
	}
	else // Character going nowhere
	{
		this->speedY = 0.f;
		this->speedX = 0.f;
	}
}
	
	//Works
/*{
	float move = 5;
	switch(key)
	{
	case 'w': //Up (walk) = 5; +Y
		this->setCurrentAnimation(5);
		this->speedY = move;
		this->speedX =0.f;
		if(positionY > 432) positionY = 431;
		break;
	case 's': // Down (walk) = 7; -Y
		this->setCurrentAnimation(7);
		this->speedY = -move;
		this->speedX = 0.f;
		if(positionY < 0) positionY = 1;
		break;
	case 'a': // Left (walk) = 6; -X
		this->setCurrentAnimation(6);
		this->speedY = 0.f;
		this->speedX = -move;
		if(positionX < 0) positionX = 1;
		break;
	case 'd': // right (walk) = 4; +X
		this->setCurrentAnimation(4);
		this->speedY = 0.f;
		this->speedX = move;
		if(positionX > 800) positionX = 799;
		break;
	}
}*/


void MainCharacter::movementStop(unsigned char key)
{
	
		switch(key)
	{
	case 'w': //Up (stationary) = 1; Y
		this->setCurrentAnimation(1);
		this->speedY=0.f;
		this->speedX=0.f;
		break;
	case 's': // Down (stationary) = 3; Y
		this->setCurrentAnimation(3);
		this->speedY=0.f;
		this->speedX=0.f;
		break;
	case 'a': // Left (stationary) = 2; X
		this->setCurrentAnimation(2);
		this->speedY=0.f;
		this->speedX=0.f;
		break;
	case 'd': // right (stationary) = 0; X
		this->setCurrentAnimation(0);
		this->speedY=0.f;
		this->speedX=0.f;
		break;
		}
}	

void MainCharacter::movement()
{
	this->positionX = positionX + speedX;
		if(positionX < 0) this->positionX = 1;
		if(positionX > 800) this->positionX = 799;
	
	this->positionY = positionY + speedY;
		if(positionY > 432) this->positionY = 431; //Collision system later, simple boundary
		if(positionY < 0) this->positionY = 1; //Collision system later, simple boundary
}