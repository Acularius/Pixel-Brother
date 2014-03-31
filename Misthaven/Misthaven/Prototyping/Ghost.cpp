#include "Objects.h"

Ghost::Ghost (std::string filename, int width, int height)
		:Characters(filename, width, height)
{
	this-> setNumberOfAnimations(1);
	this->addSpriteAnimRow(0, 0,0, 40,0,2);
	this-> setCurrentAnimation(0);
	this-> direction=0;
	this-> ghost=true;

	this-> respectiveSpeed = 3;

	this-> setLayerID(6);

}

Ghost::~Ghost(void)
{
	/* Default Deconstructor */
}

void Ghost::movementGhost(float inPlayerPosX, float inPlayerPosY)
{
	float playerPosX, playerPosY, move, ghostPosX, ghostPosY, offset, stop;
	offset = rand() % 11;
	move = (this->respectiveSpeed);
	stop = 0;
	playerPosX = inPlayerPosX - offset; playerPosY = inPlayerPosY - offset;
	ghostPosX = (this->positionX); ghostPosY = (this->positionY);

	// Dealing with the x-coords
	if (ghostPosX < playerPosX)
	{
		(this->respectiveSpeedX) = move;
	};
	if (ghostPosX > playerPosX)
	{
		(this->respectiveSpeedX) = -move;
	};
	if (ghostPosX == playerPosX)
	{
		(this->respectiveSpeedX) = stop;
	};

	// Dealing with the y-coords
	if (ghostPosY < playerPosY)
	{
		(this->respectiveSpeedY) = move;
	};
	if (ghostPosY > playerPosY)
	{
		(this->respectiveSpeedY) = -move;
	};
	if (ghostPosY == playerPosY)
	{
		(this->respectiveSpeedY) = stop;
	};
}