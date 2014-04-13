#include "Keylogger.h"

Keylogger::Keylogger(unsigned char inKey, int inKeyID)
{
	keyDown = inKey;
	keyID = inKeyID;
}

Keylogger::~Keylogger(void)
{
}