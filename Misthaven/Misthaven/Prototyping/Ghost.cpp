#include "Objects.h"
#include <cmath>

Ghost::Ghost (std::string filename, int width, int height)
		:Characters(filename, width, height)
{
	this-> setNumberOfAnimations(1);
	this-> addSpriteAnimRow(0, 0,0, 40,0,2);
	this-> setCurrentAnimation(0);
	this-> direction=0;
	this-> ghost=true;
	this-> immortal = false;
	playPosX = playPosY = 0;

	this-> respectiveSpeed = 5;

	this-> setLayerID(6);

	//Combat info
	hP = 5;
	dam = 1;
	engage = false;
	separComSys = true;


}

Ghost::~Ghost(void)
{
	/* Default Deconstructor */
}

void Ghost::getPlayerPos(float inPlayerPosX, float inPlayerPosY)
{
	playPosX = inPlayerPosX;
	playPosY = inPlayerPosY;
}


void Ghost::movementGhost(float inPlayerPosX, float inPlayerPosY)
{
	float playerPosX, playerPosY, move, ghostPosX, ghostPosY, offset, stop;
	bool choice;
	choice = rand() %2; // Either 0 or 1
	offset = rand() % 11;
	move = (this->respectiveSpeed);
	stop = 0;
	playerPosX = inPlayerPosX - offset; playerPosY = inPlayerPosY - offset;
	ghostPosX = (this->positionX); ghostPosY = (this->positionY);

	
	switch (choice)
	{
	case true:{
		// Dealing with the x-coords
				if (ghostPosX < playerPosX)
				{
					(this->respectiveSpeedY) = stop;
					(this->respectiveSpeedX) = move;
				};
				if (ghostPosX > playerPosX)
				{
					(this->respectiveSpeedY) = stop;
					(this->respectiveSpeedX) = -move;
				};
				if (ghostPosX >= (playerPosX) && ghostPosX <= (playerPosX + 15) )
				{
					(this->respectiveSpeedX) = stop;
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
					}
				};
			  }
			  break;
	case false:
		{
			// Dealing with the y-coords
			if (ghostPosY < playerPosY)
				{
					(this->respectiveSpeedX) = stop;
					(this->respectiveSpeedY) = move;
				};
				if (ghostPosY > playerPosY)
				{
					(this->respectiveSpeedX) = stop;
					(this->respectiveSpeedY) = -move;
				};
				if (ghostPosY >= (playerPosY) && ghostPosY <= (playerPosY + 15) )
				{
					(this->respectiveSpeedY) = stop;
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
					}
				};
		}
		break;

	}

}

void Ghost::ghostRespawn()
{
	if (hP <= 0 || coolDown == true)
	{
		hP = 5;
			int randspot = rand() % 3;
			switch(randspot)
			{
				case 0: { 
					setPosition(0,2000);
					break;
				  }
					case 1: { 
					setPosition(0,-2000);
					break;
				  }
					case 2: { 
					setPosition(2500,0);
					break;
				  }
					case 3: { 
					setPosition(-2500,2000);
					break;
				  }
			}
	}
	else
	{
	}
}

void Ghost::closeToAttack()
{
	if ( (std::abs(positionX-playPosX) <= 20) && (std::abs(positionY-playPosY) <=30 ) )
	{
		engage = true;
	}
	else
	{
		engage = false;
	}
	
}

void Ghost::attackZePlayer()
{
	if (engage == true  && coolDown == false && attackTicking < 30)
	{
		attackTicking++;
		interboxactive = true;
		std::cout<< "+";
	}
	else if (engage == true  && coolDown == false && attackTicking >= 30)
	{
		attack = true;
		coolDown = true;
		interboxactive = true;
		std::cout << "Fire!" << std::endl;
	}
	else
	{
		interboxactive = false;
		attackTicking = 0;
		attack = false;
	}
}

void Ghost::aboutFace()
{
	if (positionY < playPosY && ( positionX-10 < playPosX && positionX+10 > playPosX ) ) // up
	{
		direction = 2;
	}else if(positionY > playPosY && ( positionX-10 < playPosX && positionX+10 > playPosX )) // down
	{
		direction = 1;
	} else if (positionX < playPosX && ( positionY-10 < playPosY && positionY+30 > playPosY ) ) //right
	{
		direction = 3;
	}else if(positionX > playPosX && ( positionY-10 < playPosY && positionY+30 > playPosY )) //left
	{
		direction = 4;
	}
	else
	{
		direction = 0;
	}

}

void Ghost::ghUpdate()
{
	ghostRespawn();
	closeToAttack();
	
	aboutFace();
	movementGhost(playPosX, playPosY);

	attackZePlayer();
}