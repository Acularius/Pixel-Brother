#include "Sprite.h"


class Objects : public Sprite
{
public:
	Objects(std::string filename, int width, int height);
	~Objects(void);

	bool human; // True, everything moves to the player's input. False, everything moves in relation to the player.
	bool stationary; // In reference to HUD. Static objects that NEVER move.
	bool player; // Animation reference. 
	virtual void update();


	//Movement
	float speedX; // Object's move speed in pixels. X (left or right)
	float speedY; // Object's move speed in pixels. Y (up or down)

	void movementGo(unsigned char key); //Keyboard down
	void movementStop(unsigned char key); //Keyboard Up
	void movement();

	// Constraints for objects


};


/* Character Classes */
class Characters : public Objects
{
public:
	Characters::Characters(std::string filename, int width, int height);
	~Characters(void);
	int direction; // Will define which direction the character is facing. 0-3 


};

class MainCharacter : public Characters
{
public:
	MainCharacter::MainCharacter(std::string filename, int width, int height);
	~MainCharacter(void);


};

/* Backgrounds */

class Background : public Objects
{
public:
	Background::Background(std::string filename, int width, int height);
	~Background(void);
};