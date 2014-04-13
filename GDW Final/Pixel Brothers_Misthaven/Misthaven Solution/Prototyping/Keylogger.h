#include <iostream>

class Keylogger
{
public:
	Keylogger(unsigned char inKey, int inKeyID);
	~Keylogger(void);

	unsigned char keyDown;
	int keyID;

};

