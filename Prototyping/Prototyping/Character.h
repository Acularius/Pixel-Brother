#include "Sprite.h"

class Character : public Sprite
{
public:
	Character(std::string filename, int width, int height);
	~Character(void);

	bool human;
	virtual void update();
};