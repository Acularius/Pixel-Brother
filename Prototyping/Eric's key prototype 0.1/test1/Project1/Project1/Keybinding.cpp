#include<iostream>
#include"Keybinding.h"

using namespace std;
using std::cout;

void keybinding(char upkey, char leftkey, char downkey, char rightkey, int optionnum)
{

	//default keysetting
		upkey=119;
		leftkey=97;
		downkey=115;
		rightkey=100;

	
	//Keybinding
	cout<<"Which Keybinding do you wish to change? \n";
	cout<<"1.upkey "<<upkey<<endl;
	cout<<"2.leftkey "<<leftkey<<endl;
	cout<<"3.downkey "<<downkey<<endl;
	cout<<"4.rightkey "<<rightkey<<endl;
	cout<<"5.set defaults"<<endl;
	cin >> optionnum; 

}

