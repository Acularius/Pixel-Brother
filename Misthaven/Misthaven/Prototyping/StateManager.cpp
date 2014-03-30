//###########################################################################################
//
//									   STATE MANAGER.cpp
//																			|Aaron Alphonso|
//###########################################################################################

		#include "Game.h"

//-------------------------------------------------------------------------------------------
// This "StateManger.cpp" is purely a defination file for state related Game functions.
// The functions here are to aid in state transition (Of GameState.h/GameState.cpp) Objects
// by accessing and modifying the boolean "active" toggle variable of the game state.
//-------------------------------------------------------------------------------------------


//===========================================================================================
//						   STATEMANAGER ----- STATE RESET
//===========================================================================================

	void Game::StateReset()
	{

		std::vector<GameState*>::iterator it;
		for (it = states.begin(); it != states.end(); it++)
		{
			if (*it)
			{  
				  GameState* s = (*it);

				  s->active=false;	// Setting all values to false.

				  std::cout<<"\n Reseting states...";

	}}}

//===========================================================================================
//						   STATEMANAGER ----- STATE CONTROL
//===========================================================================================

	void Game::StateControl (GameState* g, bool a, int num)
	{  
		std::vector<GameState*>::iterator it;
		for (it = states.begin(); it != states.end(); it++)
		{ 
			if (*it)
			{	  
				  GameState* s = (*it);
				  if(s->StateNum==num)
				  { 
					  s->active = a;    // Setting value to 'a' (true/false).

					  s->ResetMap();	// Resetting the sprite values,
									    // spawn points, positions etc.
					  std::cout<<"\n Changing value to true, Reseting Map...";
				  }
	}}}

//===========================================================================================
//						   STATEMANAGER ----- SWITCH STATE TO
//===========================================================================================

	void Game::SwitchStateTo (GameState* g, int num)
	{
		/*Just calling functions*/
		StateReset();
		StateControl(g,true,num);
		std::cout<<"\n Switching State...";
	}
//																			|Aaron Alphonso|
//###########################################################################################