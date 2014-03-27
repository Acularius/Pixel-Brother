#ifndef KEYBINDING_H
#define KEYBINDING_H

class Keybinding
{
public:
	char upkey;
	char leftKey;
	char downKey;
	char rightKey;
	char interactKey;
	char actionKey;
	char keys;


private:
	Keybinding(char,char,char,char,char,char,char);
	int optionnum;

};


#endif