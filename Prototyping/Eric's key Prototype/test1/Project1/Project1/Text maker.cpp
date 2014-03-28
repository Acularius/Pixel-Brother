#include <iostream>
#include <fstream>
#include <string>
#include "Keybinding.h"


using namespace std;

void Keybinding::keyfile(int sol)
{
	if(sol==0)
	{
	ofstream Keybindfile;
	Keybindfile.open("keybind.txt");
	if (Keybindfile.is_open())
	{
	Keybindfile<<"Up key = " << upKey <<".\n"<<endl;
	Keybindfile<<"left key = " <<leftKey<<".\n"<<endl;
	Keybindfile<<"down key = " <<downKey<<".\n"<<endl;
	Keybindfile<<"right key = " <<rightKey<<".\n"<<endl;
	Keybindfile<<"interact key = " <<interactKey<<".\n"<<endl;
	Keybindfile<<"action key = " <<actionKey<<"space"<<".\n"<<endl;
	Keybindfile.close();
	}
	else cout << "Unable to open file"<<endl;
	}
}