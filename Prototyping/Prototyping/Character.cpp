#include "Character.h"

Character::Character(std::string filename, int width, int height)
	: Sprite(filename)
{
	/*I assume the filename is loaded through the parent class constructor above, Sprite*/
	/* It is assumed I should have the texture associated with this character, Player or NPC*/
	human = true;
	this->setNumberOfAnimations(1);
	this->addSpriteAnimFrame(0,0,0);
	this->setSpriteFrameSize(width, height);
	this->setPosition(200,200);
	this->setCurrentAnimation(0);

}

void Character::update()
{
/*Nothing as of yet, will contain controls*/
}