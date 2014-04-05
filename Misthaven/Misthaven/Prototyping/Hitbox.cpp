#include "Hitbox.h"




//Sets up the hitbox in relation to the object it is created for


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

 //=======================================================================
 //=======================================================================

InteractBox::InteractBox()
{
	faceHeight = 33; faceWidth = 30; 
	sideWidth = 33; sideHeight = 35;

	leftCornerX = rightCornerX = bottomCornerY= topCornerY = 0;
	active, attack, talk = false;

}

InteractBox::~InteractBox(void)
{
// Default Deconstructor
}


void InteractBox::InteractBoxActive(bool inputactive, bool intalk, bool inattack, int indirection, float inPosX, float inPosY) // Bottom corner of hitbox
{
	active = inputactive;
	talk = intalk;
	attack = inattack;
	
	if ( active == true)
	{
		switch (indirection)
		{
		case 1: // Facing down, s key. (0,0) = top left of player's bottom left
			{
				leftCornerX = inPosX - 5; topCornerY = inPosY - 3;
				rightCornerX = leftCornerX + faceWidth ; bottomCornerY = topCornerY - faceHeight; 
			};
		case 2: // Facing up, w key. (0,0) = bottom left of player's top left
			{
				leftCornerX = inPosX - 5; bottomCornerY = inPosY -3;
				rightCornerX = leftCornerX + faceWidth; topCornerY = bottomCornerY + faceHeight;

			};
		case 3: // Facing right, d key. (0,0) = bottom right of player's bottom left
			{
				rightCornerX = inPosX +3 ; bottomCornerY  = inPosY -5;
				leftCornerX = rightCornerX - sideWidth; topCornerY = bottomCornerY + sideHeight;
 			};
		case 4: // Facing Left, a key. (0,0) = bottom left of player's bottom left
			{
				leftCornerX = inPosX - 3; bottomCornerY = inPosY -5;
				rightCornerX = leftCornerX + sideWidth; topCornerY = bottomCornerY + sideHeight;

			};
		case 0:{break;} //Nothing happens with the default 0 direction

		}
	} 
	else
	{};

}