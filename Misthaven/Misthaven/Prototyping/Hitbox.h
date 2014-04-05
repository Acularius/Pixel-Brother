


class Hitbox
{
public:
	Hitbox::Hitbox();
	Hitbox::Hitbox(int inputWidth, int inputHeight, float inputCornerX, float inputCornerY);
	~Hitbox(void);

	int width, height; // width along the x axis, height along the y axis.
	// Always start with the bottom left as that is where openGL measures the origin point from at (0,0) of an image.
	float leftCornerX, rightCornerX, bottomCornerY, topCornerY; //Corners of the hitbox.

	void createHitBox(float startWidth,float startHeight, float initialPositionX,float initialPositionY);
	void updateHitbox(float inputPositionX, float inputPositionY, bool playerCheck);
};


class InteractBox
{
public:
	InteractBox::InteractBox();
	~InteractBox(void);

	bool active, attack, talk;

	int faceWidth, faceHeight; // up or down facing
	int sideWidth,sideHeight; //looking to the sides
	float leftCornerX, rightCornerX, bottomCornerY, topCornerY; //Corners of the hitbox.

	void createInteractBox();
	void InteractBoxActive(bool inputactive, bool intalk, bool inattack, int indirection, float inPosX, float inPosY);

};