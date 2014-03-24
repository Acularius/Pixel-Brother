#include <iostream>
using namespace std;

class keybinding
{
public:
	char upkey;
	char leftkey;
	char downkey;
	char rightkey;
	
	char keys;

	private:
		keybinding(char,char,char,char);
		int optionnum;
};


//Unsure if it would affect by the keybinding code below
/*keybinding::keybinding(char upkey, char leftkey, char downkey, char rightkey)
{
		upkey=119;
		leftkey=97;
		downkey=115;
		rightkey=100;
}*/

int main()
{

	char upkey;
	char leftkey;
	char downkey;
	char rightkey;
	
	int optionnum;

	//INITIALIZE: here not later.

		upkey=119;
		leftkey=97;
		downkey=115;
		rightkey=100;

	// Menu so player can choose which key to change.

	cout<<"Which Keybinding do you wish to change? \n";
	cout<<"1.upkey "<<upkey<<endl;
	cout<<"2.leftkey "<<leftkey<<endl;
	cout<<"3.downkey "<<downkey<<endl;
	cout<<"4.rightkey "<<rightkey<<endl;
	cout<<"5.set defaults"<<endl;
	cin >> optionnum; 

	/* based on optionnumber have a list of if statements with seperate individual keybinding. change below code*/
	
	/*if(keys=='o')
	{
		cout<<"Type a key to move up" << endl;
		cin >> upkey;
		cout<<"New key is " << upkey << endl;
		cout<<"Type a key  to move down"<<endl;
		cin >> downkey;
		cout<<"New key is " << downkey << endl;
		cout<<"Type a key to move left" << endl;
		cin >> leftkey;
		cout<<"New key is " << leftkey << endl;
		cout<< "Type a key to move right" << endl;
		cin >> rightkey;
		cout << "New keys is" << rightkey << endl;
		//cout << "The new keys are:" << upkey << " " << downkey << " " << leftkey << " " << rightkey << endl;
	}
	else //do not do this unless player enters option 5. set defaults.
	{
		upkey=119;
		leftkey=97;
		downkey=115;
		rightkey=100;
	}*/


	//the bolow code won't work. you read the keys variable only once, and it was initinalized to 'o' therefore none of it will work.
	//for testing make a do while loop. and "cin>>keys" after every iteration at the begining of the loop. 

	/*if(keys==upkey)
	{
		cout<<"up";
	}

	if(keys==leftkey)
	{
		cout<<"left";
	}
	if(keys==rightkey)
	{
		cout<<"right";
	}

	if(keys==downkey)
	{
		cout<<"down";
	}*/

	return 0;
}
