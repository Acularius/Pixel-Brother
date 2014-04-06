#include "Objects.h"




NPC::NPC(std::string filename, int posX, int posY, int width, int height)
	//:Characters(filename, width, height)
{
	this->setNumberOfAnimations(1);
	this->addSpriteAnimFrame(1,posX,posY);
	this->setPosition(posX,posY);
	this->setCurrentAnimation(2);
	this->setLayerID(11);
	this->stationary=true; 
	this->collidable=true;

	// Hitbox for NPCs
	ObjectHitbox = new Hitbox(0,0, positionX,positionY); 

}

