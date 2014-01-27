#include "Sprite.h"

class Objects : public Sprite
{
public:
	Objects(std::string filename, int width, int height);
	~Objects(void);

	bool human;
	virtual void update();
};


/* Character Classes */
class Characters : public Objects
{
public:
	Characters::Characters(std::string filename, int width, int height);
	~Characters(void);

	virtual void update();

};

class MainCharacter : public Characters
{
public:
	MainCharacter::MainCharacter(std::string filename, int width, int height);
	~MainCharacter(void);

	float speedX; // Character's move speed in pixels. X (left or right)
	float speedY; // Character's move speed in pixels. Y (up or down)

	virtual void update();
	void movementGo(unsigned char key); //Keyboard down
	void movementStop(unsigned char key); //Keyboard Up
	void movement();
	

};