#include "Sprite.h"
#include "Hitbox.h"
#include "AudioLib.h"

class Objects : public Sprite
{
public:
	Objects(){}; //Default Constructor
	Objects(std::string filename, int width, int height);
	~Objects(void);

	bool AI; // AI call.
	bool stationary; // In reference to HUD. Static objects that NEVER move.
	bool player; // Animation reference. Stationary. Everything moves in respect to the player.
	bool collidable; // Does it collide?
	bool ghost;
	bool award;

	bool inMotion; // In motion in relation to the player
	float inMotionSpeed; // The speed that everyone moves in relation to the player
	float respectiveSpeed; //The speed an object moves whether or not the player is moving or not. Max Speed.

	int tickFrame;


	virtual void update();

	//Combat
	bool immortal; // Does it take damage?
	int hP; //Hit Points
	int dam; //Damage
	bool coolDown;
	int coolDTicking;
	int attackTicking;

	bool bOpponent;
	bool bInitiator;
	bool separComSys;

	void coolDownfunc(); // No attack spam
	void attackBreakUp(); // So one can't hold down the attack key - Up
	void attackBreakDown(); // So one can't hold down the attack key - Down
	void attackUpdate();


	int direction;
	//Interact Box
	bool attack;
	bool attackanim;
	bool talk;
	bool interboxactive;

	//Score
	int scoreStorage;

	//Movement
	float inMotionSpeedX; // Object's move speed in pixels. X (left or right) - When the player moves - X Plane
	float inMotionSpeedY; // Object's move speed in pixels. Y (up or down) - When the player moves - Y plane
	float respectiveSpeedX; // Object's respective move speed regardless of player's speed. - X plane
	float respectiveSpeedY; // Object's respective move speed regardless of player's speed - Y plane

	void movementGo(unsigned char key); //Keyboard down - Activates movement in respect to the player 
	void movementStop(unsigned char key); //Keyboard Up - De-activates movement in respect to the player

	/* Creation of a hitbox */
	Hitbox *ObjectHitbox;
	InteractBox *ObjectActBox;

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
	int tickHPRegen;


	Hitbox *ObjectHitbox;
	
	void playerUpdate();
	void healthRegen();

};

/* Backgrounds */

class Background : public Objects
{
public:
	Background::Background(std::string filename, int width, int height);
	~Background(void);
};

class Ghost : public Characters
{
public:
	Ghost::Ghost (std::string filename, int width, int height);
	~Ghost(void);
	bool engage;
	float playPosX, playPosY;


	void ghUpdate();

	void getPlayerPos(float inPlayerPosX, float inPlayerPosY);
	void movementGhost(float inPlayerPosX, float inPlayerPosY);
	void ghostRespawn();

	void closeToAttack();
	void attackZePlayer();
	void aboutFace();

};

class Seagull: public Characters
{
public:
	Seagull::Seagull (std::string filename, int width, int height);
	~Seagull(void);
	bool engage;
	float playPosX, playPosY;


	void sgUpdate();

	void getPlayerPos(float inPlayerPosX, float inPlayerPosY);
	void movementSeagull(float inPlayerPosX, float inPlayerPosY);
	void seagullRespawn();

	void closeToAttack();
	void attackZePlayer();
	void aboutFace();

};



class Transition : public Objects 
{
public:
	~Transition(void);
	Transition(std::string filename, int width, int height);

	bool transition;
	int toLevel;

};


