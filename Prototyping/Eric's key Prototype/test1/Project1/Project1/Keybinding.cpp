#include<iostream>
#include"Keybinding.h"

using namespace std;
using std::cout;

Keybinding::Keybinding()
{
		//default keysetting
		upKey=119; //up
		leftKey=97; //left
		downKey=115; //down
		rightKey=100; //right
		interactKey=101; //interact
		actionKey=32; //action
}

Keybinding::~Keybinding(void)
{
	/* Default Deconstructor */
}

void Keybinding::keybindFunc()
{
	int optionnum;
	//Keybinding
	cout<<"Which Keybinding do you wish to change? \n";
	cout<<"1.upkey "<<upKey<<endl;
	cout<<"2.leftkey "<<leftKey<<endl;
	cout<<"3.downkey "<<downKey<<endl;
	cout<<"4.rightkey "<<rightKey<<endl;
	cout<<"5.interactkey "<<interactKey<<endl;
	cout<<"6.actionKey "<<actionKey<<endl;
	cout<<"7.set defaults"<<endl;
	cin >> optionnum;

	switch(optionnum)
	{
	case 1:
		cout<<"Set key for up"<<endl;
		cin>>upKey;
		cout<<"Upkey is now: "<< upKey<<endl;
		break;
	case 2:
		cout<<"Set key for left"<<endl;
		cin>>leftKey;
		cout<<"Leftkey is now: "<< leftKey<<endl;

		break;
	case 3:
		cout<<"Set key for down"<<endl;
		cin>>downKey;
		cout<<"Downkey is now: "<< downKey<<endl;
		break;
	case 4:
		cout<<"Set key for right"<<endl;
		cin>>rightKey;
		cout<<"Rightkey is now: "<< rightKey<<endl;
		break;
	case 5:
		cout<<"Set key for interaction"<<endl;
		cin>>interactKey;
		cout<<"interactkey is now: "<< interactKey<<endl;
		break;
	case 6:
		cout<<"Set key for action"<<endl;
		cin>>actionKey;
		cout<<"actionkey is now: "<< actionKey<<endl;
		break;
	case 7:
		cout<<"Keys stay the same"<<endl;
		break;
	}
}

