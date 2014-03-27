#pragma once
#include <string>
#include <iostream>

#include "GL/glut.h"

/*
* Timer class
* - Allows us to keep track of the elapsed time (Delta Time)
* in the program. Can be used in things like Physics Calculations
*/

class Timer
{
public:
	Timer(std::string _name)
	{
		previousTime = glutGet(GLUT_ELAPSED_TIME);
		this->tick();
		name = _name;
	}
	~Timer(void);

	// Update the Timer Clock
	float tick()
	{
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		return elapsedTime;
	}

	// Delta time in milliseconds 
	float getElapsedTimeMS()
	{
		return elapsedTime;
	}

	// Delta Time in seconds
	float getElapsedTimeSeconds()
	{
		return (elapsedTime/1000.f);
	}

	float getCurrentTime()
	{
		return currentTime;
	}
	void print()
	{
		std::cout << name << ":" << elapsedTime<<std::endl;
	}

private:
	float currentTime, previousTime, elapsedTime;
	std::string name;
};