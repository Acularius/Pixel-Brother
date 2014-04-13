#include "Sprite.h"


class Health : public Sprite
{
public:
	Health(std::string filename, int width, int height);
	~Health(void);

	int currentHealth;

	void inputHealth(int inHealth);

};

