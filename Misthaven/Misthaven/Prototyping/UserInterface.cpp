#include "UserInterface.h"

Health::Health(std::string filename, int width, int height)
	: Sprite(filename)
{
	this->currentHealth = 10;
//	setSpriteFrameSize(184, 24);
	this-> setSpriteFrameSize(width, height);
	this-> setNumberOfAnimations(11);
	for(int i=0 ; i<11 ; i++)
		{
			this-> addSpriteAnimRow(i,0,i*24,184,0,1);
		}
	this-> setPosition(8,227);
	this-> setCurrentAnimation(currentHealth);
	this-> setLayerID(12);
	
}

Health::~Health(void)
{
	// Default deconstructor
}

void Health::inputHealth(int inHealth)
{
	currentHealth = inHealth;
	this-> setCurrentAnimation(inHealth);
}
