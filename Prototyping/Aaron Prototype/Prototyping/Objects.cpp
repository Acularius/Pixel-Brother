#include "Objects.h"


Objects::Objects(std::string filename, int width, int height)
	: Sprite(filename)
{
	/*I assume the filename is loaded through the parent class constructor above, Sprite*/
	/* It is assumed I should have the texture associated with this character, Player or NPC*/
}
Objects::~Objects()
{
	/* Deconstructor */
}
void Objects::update()
{
/*Nothing as of yet*/
}


/* Creation of Characters
* It will be derived into the Player (human) class, NPC's and enemies
*/
Characters::Characters(std::string filename, int width, int height)
	:Objects(filename, width, height)
{

}

Characters::~Characters(void)
{
	/* Deconstructor */
}

void Characters::update()
{
	/*Nothing as of yet*/
}
