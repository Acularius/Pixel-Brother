#include "Hitbox.h"



/*
Sets up the hitbox in relation to the object it is created for
*/

Hitbox::Hitbox()
{
	
};

Hitbox::Hitbox(int inputWidth, int inputHeight, float inputCornerX, float inputCornerY)
{
	width= inputWidth; height= inputHeight;
	leftCornerX= inputCornerX; bottomCornerY = inputCornerY;

	createHitBox(width,height, leftCornerX,bottomCornerY);
}

Hitbox::~Hitbox(void)
{
	/* Default Deconstructor*/
};

void Hitbox::createHitBox(float startWidth,float startHeight, float initialPositionX,float initialPositionY)
{

	rightCornerX = leftCornerX + width;
	topCornerY = bottomCornerY + height;
}

void Hitbox::updateHitbox(float inputPositionX, float inputPositionY, bool playercheck)
{
	if (playercheck==true) // Due to the sprite sheet, player is offset.
	{
	leftCornerX = inputPositionX +20;
	bottomCornerY = inputPositionY +10 ;
	}
	else{	
	leftCornerX = inputPositionX;
	bottomCornerY = inputPositionY;
	};


	rightCornerX = leftCornerX + width;
	topCornerY = bottomCornerY + height;
};

// =======================================================================
// =======================================================================

