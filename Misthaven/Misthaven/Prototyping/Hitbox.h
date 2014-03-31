


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

