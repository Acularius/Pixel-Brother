#include "Keybinding.h"
#include <iostream>



int main()
{
	Keybinding Keybind;
	bool loop = true;

	while (loop == true)
	{
		char yesno;
		Keybind.keybindFunc();
		std::cout << "Continue? (y/n)?" << std::endl;
		std::cin >> yesno;
		if (yesno == 'n')
		{
			loop = false;
			void exit(int status);
		
		} else {
			loop = true;
		}
	}
	system("pause");
	return 0;

};