//###########################################################################################
//
//									TRANSITIONOBJECT.cpp
//																					|Donald|
//###########################################################################################

		#include "Objects.h"	

//-------------------------------------------------------------------------------------------
//  
//-------------------------------------------------------------------------------------------

		Transition::~Transition(void){};

		Transition::Transition(std::string filename, int width, int height)
		:Objects(filename, width, height)
		{
		this-> AI = false;
		this-> stationary = false;
		this-> player = false;
		this-> collidable = false;
		this-> transition = true;

		this-> inMotion = false;
		this-> inMotionSpeed = 10.f;
		this-> respectiveSpeed = 0.f;

		this-> setPosition(0,0);
		this-> toLevel = 0;
			//Movement - Object starts NOT moving
		inMotionSpeedX = 0; 
		inMotionSpeedY = 0;
		respectiveSpeedX = 0;
		respectiveSpeedY = 0;

		ObjectHitbox = new Hitbox(width,height, positionX,positionY);
		}
//																					|Donald|
//###########################################################################################