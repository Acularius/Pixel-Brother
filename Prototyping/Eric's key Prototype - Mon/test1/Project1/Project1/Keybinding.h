#ifndef KEYBINDING_H
#define KEYBINDING_H

class Keybinding
{
public:
	Keybinding();
	~Keybinding(void);

	char upKey;
	char leftKey;
	char downKey;
	char rightKey;
	char interactKey;
	char actionKey;

	void keybindFunc();


};


#endif