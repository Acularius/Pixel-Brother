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

	switch(optionnum)
	{
	case 1:
		cout<<"Set key for up"<<endl;
		cin>>upkey;
		cout<<"Upkey is now: "<< upkey<<endl;
		break;
	case 2:
		cout<<"Set key for left"<<endl;
		cin>>leftkey;
		cout<<"Leftkey is now: "<< leftkey<<endl;

		break;
	case 3:
		cout<<"Set key for down"<<endl;
		cin>>downkey;
		cout<<"Downkey is now: "<< downkey<<endl;
		break;
	case 4:
		cout<<"Set key for right"<<endl;
		cin>>rightkey;
		cout<<"Rightkey is now: "<< rightkey<<endl;
		break;
	case 5:
		cout<<"Keys stay the same"<<endl;
		break;


}

