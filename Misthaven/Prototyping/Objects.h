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

	int tickFrame; // Affects the rate at which animations cycle through frames.


	virtual void update();

	//Combat
	bool immortal; // Does it take damage?
	int hP; //Hit Points
	int dam; //Damage
	bool coolDown; // Is object on cool down (Attack)
	int coolDTicking; // CoolDown countdown
	int attackTicking; // Time until combat initiates

	bool bOpponent; // Is it the opponent? (Combat System)
	bool bInitiator; // Is it the initiator? (Combat System)
	bool separComSys;

	void coolDownfunc(); // No attack spam
	void attackBreakUp(); // So one can't hold down the attack key - Up
	void attackBreakDown(); // So one can't hold down the attack key - Down
	void attackUpdate(); // The attack for the player


	int direction; // Which way is it facing
	//Interact Box
	bool attack; // Is it initiating combat - activates interact box
	bool attackanim; // Animation for attacking 
	bool talk; // Does it initiate conversation
	bool interboxactive; // Is the interact box active?

	//Score
	int scoreStorage; // Stores the score - FOR PLAYER

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
	int tickHPRegen; // How often does the player regen health
	int GameCheckpoint; //For StoryProgression and filesaving;


	Hitbox *ObjectHitbox;
	
	void playerUpdate(); // Updates Player specific functions
	void healthRegen(); // Health Regeneration function

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
	bool engage; // Player is in Range
	float playPosX, playPosY; // Where the Player's position is.
	int attackCountDown; // CountDown before the attack in attackZePlayer()


	void ghUpdate(); // Updates the Ghost

	void getPlayerPos(float inPlayerPosX, float inPlayerPosY); // Gets the Player's position
	void movementGhost(float inPlayerPosX, float inPlayerPosY); // Using the player's position, heads there.
	void ghostRespawn(); // When the ghost dies or does damage to the player, respawn().

	void closeToAttack(); // If the ghost is close enough to attack, 
	void attackZePlayer(); // Initiates combat
	void aboutFace(); // Faces the player.

};

// Similar to Ghost
class Seagull: public Characters
{
public:
	Seagull::Seagull (std::string filename, int width, int height);
	~Seagull(void);
	float playPosX, playPosY;


	void sgUpdate();

	void getPlayerPos(float inPlayerPosX, float inPlayerPosY);
	void movementSeagull(float inPlayerPosX, float inPlayerPosY);
	void seagullRespawn();


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


