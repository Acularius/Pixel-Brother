#ifndef KEYBINDING_H
#define KEYBINDING_H

class Keybinding
{
public:
	char upkey;
	char leftkey;
	char downkey;
	char rightkey;
	char keys;


private:
	Keybinding(char,char,char,char);
	int optionnum;

};


#endif