#include "agl/ciphers.h"
#include <stdio.h>
void AGL::Ciphers::revert(char* data, int length)
{
	for(int i = 0; i < length / 2; i++)
	{
		char temp = data[i];
		data[i] = data[length - 1 - i];
		data[length - 1 - i] = temp;
	}
}

