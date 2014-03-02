#include <iostream>

using namespace std;

void control1()
{
	cout << "wasd";
}
void control2()
{
	cout << "okl;";
}
void control3()
{
	cout << "arrows";
}

int main()
{
	int input;

	cout<<"1.wasd";
	cout<<"2.okl;";
	cout<<"3.ARROWS";

	cout<<"Select: ";
	cin>> input;
	switch