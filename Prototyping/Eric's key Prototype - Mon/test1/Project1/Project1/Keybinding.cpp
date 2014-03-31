#include<iostream>
#include<fstream>
#include <string>
#include"Keybinding.h"

using namespace std;
using std::cout;


Keybinding::Keybinding()
{
	
		//default keysetting
	// note: must make code used only when
	ofstream ifile("keybind.txt");
	if(!ifile.is_open())
	{
		//set default
		upKey=119; //up
		leftKey=97; //left
		downKey=115; //down
		rightKey=100; //right
		interactKey=101; //interact
		actionKey=102; //action space = 32, f = 102 for place holder
		//write code
		ifile.open("keybind.txt");
		ifile<<"Up key = " << upKey <<".\n"<<endl;
		ifile<<"Left key = " << leftKey <<".\n"<<endl;
		ifile<<"Down key = " << downKey <<".\n"<<endl;
		ifile<<"Right key = " << rightKey <<".\n"<<endl;
		ifile<<"Interact key = " << interactKey <<".\n"<<endl;
		ifile<<"Action key = " << actionKey <<".\n"<<endl;
		ifile.close();
	}
		
}

Keybinding::~Keybinding(void)
{
	/* Default Deconstructor */
}

void Keybinding::keybindFunc()
{
	//read file
	string line;
	ifstream Keybindfile;
	Keybindfile.open("keybind.txt");
	if (Keybindfile.is_open())
	{
		while (getline(Keybindfile,line))
		{
			cout << line << '\n';
		}
	Keybindfile.close();
	}
	else cout << "Unable to open file"<<endl;
	//replace lines in file
	ofstream Keyeditor;
	Keyeditor.open("keybind.txt");

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
	cout<<"8.save setting"<<endl;
	cin >> optionnum;
	
	//pressing num to change keys
	switch(optionnum)
	{
	case 1:
		cout<<"Set key for up"<<endl;
		cin>>upKey;
		cout<<"Upkey is now: "<< upKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"Up key = " << upKey <<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 2:
		cout<<"Set key for left"<<endl;
		cin>>leftKey;
		cout<<"Leftkey is now: "<< leftKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"left key = " <<leftKey<<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 3:
		cout<<"Set key for down"<<endl;
		cin>>downKey;
		cout<<"Downkey is now: "<< downKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"down key = " <<downKey<<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 4:
		cout<<"Set key for right"<<endl;
		cin>>rightKey;
		cout<<"Rightkey is now: "<< rightKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"right key = " <<rightKey<<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 5:
		cout<<"Set key for interaction"<<endl;
		cin>>interactKey;
		cout<<"interactkey is now: "<< interactKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"interact key = " <<interactKey<<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 6:
		cout<<"Set key for action"<<endl;
		cin>>actionKey;
		cout<<"actionkey is now: "<< actionKey<<endl;
		/*Keyeditor.open("keybind.txt");
		Keyeditor<<"action key = " <<actionKey<<".\n"<<endl;
		Keyeditor.close();*/
		break;
	case 7:
		cout<<"Keys stay the same"<<endl;
		upKey=119; //up
		leftKey=97; //left
		downKey=115; //down
		rightKey=100; //right
		interactKey=101; //interact
		actionKey=32; //action
		break;
	case 8:
		Keyeditor.open("keybind.txt");	
		Keyeditor<<"Up key = " << upKey <<".\n"<<endl;
		Keyeditor<<"left key = " <<leftKey<<".\n"<<endl;
		Keyeditor<<"down key = " <<downKey<<".\n"<<endl;
		Keyeditor<<"right key = " <<rightKey<<".\n"<<endl;
		Keyeditor<<"interact key = " <<interactKey<<".\n"<<endl;
		Keyeditor<<"action key = " <<actionKey<<".\n"<<endl;
		Keyeditor.close();
		break;
	}
}