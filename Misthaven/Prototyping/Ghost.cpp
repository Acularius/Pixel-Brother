//###########################################################################################
//
//										  GHOST.cpp
//																			   |Donald Smith|
//###########################################################################################

			#include "Objects.h"
			#include <cmath>

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	Ghost::Ghost (std::string filename, int width, int height)
			:Characters(filename, width, height)
	{
		this-> setNumberOfAnimations(2);
		this-> addSpriteAnimRow(0, 0,	   0,width,0,16);
		this-> addSpriteAnimRow(1, 0, height,width,0,16);
		this-> setCurrentAnimation(0);
		this-> direction=0;
		this-> ghost=true;
		this->award = true;
		this-> immortal = false;
		playPosX = playPosY = 0;

		this-> respectiveSpeed = 8;

		this-> setLayerID(6);

		//Combat info
		hP = 3;
		dam = 1;
		engage = false;
		separComSys = true;
		attackCountDown = 15;
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	Ghost::~Ghost(void)
	{
		/* Default Deconstructor */
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::getPlayerPos(float inPlayerPosX, float inPlayerPosY)
	{
		playPosX = inPlayerPosX;
		playPosY = inPlayerPosY;
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::movementGhost(float inPlayerPosX, float inPlayerPosY)
	{
		float playerPosX, playerPosY, move, ghostPosX, ghostPosY, offsetX, offsetY, range, stop;
		int choice;
		choice = rand() %2; // Either 0 or 1
		offsetX = 10; // find the player's centre
		offsetY = 10;
		range = 20; // How close to be before Ghost stops
		move = (this->respectiveSpeed);
		stop = 0;
		playerPosX = inPlayerPosX + offsetX; playerPosY = inPlayerPosY + offsetY;
		ghostPosX = (this->positionX); ghostPosY = (this->positionY);

		switch (choice)
		{
		case 0:{
			// Dealing with the x-coords
					if ( std::abs(playerPosX - ghostPosX) > range  && ghostPosX < playerPosX)
					{
						(this->respectiveSpeedY) = stop;
						(this->respectiveSpeedX) = move;
					};
					if ( std::abs(playerPosX - ghostPosX) > range  && ghostPosX > playerPosX)
					{
						(this->respectiveSpeedY) = stop;
						(this->respectiveSpeedX) = -move;
					};
					if ( std::abs(playerPosX - ghostPosX) <= range)
					{
						(this->respectiveSpeedX) = stop;
						// Dealing with the y-coords
						if ( std::abs(playerPosY - ghostPosY) > range  && ghostPosY < playerPosY)
						{
							(this->respectiveSpeedY) = move;
						};
						if ( std::abs(playerPosY - ghostPosY) > range  && ghostPosY > playerPosY)
						{
							(this->respectiveSpeedY) = -move;
						};
						if (std::abs(playerPosY - ghostPosY) <= range)
						{
							(this->respectiveSpeedY) = stop;
						}
					};
				  }
				  break;
		case 1:
			{
				// Dealing with the y-coords
				if (std::abs(playerPosY - ghostPosY) > range  && ghostPosY < playerPosY)
					{
						(this->respectiveSpeedX) = stop;
						(this->respectiveSpeedY) = move;
					};
					if (std::abs(playerPosY - ghostPosY) > range  && ghostPosY > playerPosY)
					{
						(this->respectiveSpeedX) = stop;
						(this->respectiveSpeedY) = -move;
					};
					if (std::abs(playerPosY - ghostPosY) <= range)
					{
						(this->respectiveSpeedY) = stop;
						// Dealing with the x-coords
						if (std::abs(playerPosX - ghostPosX) > range  && ghostPosX < playerPosX)
						{
							(this->respectiveSpeedX) = move;
						};
						if (std::abs(playerPosX - ghostPosX) > range  && ghostPosX > playerPosX)
						{
							(this->respectiveSpeedX) = -move;
						};
						if (std::abs(playerPosX - ghostPosX) <= range)
						{
							(this->respectiveSpeedX) = stop;
						}
					};
			}
			break;

		}

	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::ghostRespawn()
	{
		if (hP <= 0 || coolDown == true)
		{
			hP = 2;
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

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::closeToAttack()
	{
		if ( (std::abs(positionX-playPosX) <= 30) && (std::abs(positionY-playPosY) <=40 ) )
		{
			engage = true;
		}
		else
		{
			engage = false;
		}	
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::attackZePlayer()
	{
		if (engage == true  && coolDown == false && attackTicking < attackCountDown)
		{
			attackTicking++;
			interboxactive = true;
			std::cout<< "+";
		}
		else if (engage == true  && coolDown == false && attackTicking >= attackCountDown)
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

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

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
			this->setCurrentAnimation(0);
		}else if(positionX > playPosX && ( positionY-10 < playPosY && positionY+30 > playPosY )) //left
		{
			direction = 4;
			this->setCurrentAnimation(1);
		}
		else
		{
			direction = 0;
		}

	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Ghost::ghUpdate()
	{
		ghostRespawn();
		closeToAttack();
	
		aboutFace();
		movementGhost(playPosX, playPosY);

		attackZePlayer();
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	Seagull::Seagull (std::string filename, int width, int height)
			:Characters(filename, width, height)
	{
		this-> setNumberOfAnimations(2);
		this-> addSpriteAnimRow(0, 0,	   0,width,0,8);
		this-> addSpriteAnimRow(1, 0, height,width,0,8);
		this-> setCurrentAnimation(0);
		this-> direction=0;
		this-> ghost=true;
		this->award = false;
		this-> immortal = false;
		playPosX = playPosY = 0;

		this-> respectiveSpeed = 5;

		this-> setLayerID(6);

		//Combat info
		hP = 1;
		dam = 0;
		separComSys = true;


	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	Seagull::~Seagull(void)
	{
		/* Default Deconstructor */
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Seagull::getPlayerPos(float inPlayerPosX, float inPlayerPosY)
	{
		playPosX = inPlayerPosX;
		playPosY = inPlayerPosY;
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Seagull::movementSeagull(float inPlayerPosX, float inPlayerPosY)
	{
		float playerPosX, playerPosY, move, ghostPosX, ghostPosY, offset, stop;
		bool choice;
		choice = rand() %2; // Either 0 or 1
		offset = rand() % 11 + 6;
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

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Seagull::seagullRespawn()
	{
		if (hP <= 0 )
		{
			hP = 1;
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



//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Seagull::aboutFace()
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
			this->setCurrentAnimation(0);
		}else if(positionX > playPosX && ( positionY-10 < playPosY && positionY+30 > playPosY )) //left
		{
			direction = 4;
			this->setCurrentAnimation(1);
		}
		else
		{
			direction = 0;
		}
	}

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

	void Seagull::sgUpdate()
	{
		seagullRespawn();

		aboutFace();
		movementSeagull(playPosX, playPosY);
	}

//																			|Donald Smith|
//###########################################################################################