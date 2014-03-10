#include <iostream>
using namespace std;

int main()
{

	char upkey;
	char leftkey;
	char downkey;
	char rightkey;
	
	char keys;
	cin >> keys;
	

	if(keys=='o')
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
	else
	{
		upkey=119;
		leftkey=97;
		downkey=115;
		rightkey=100;
	}



	if(keys==upkey)
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
	}

	return 0;
}
