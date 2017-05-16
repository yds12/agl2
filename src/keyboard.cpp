#include "SDL/SDL.h"

#include "agl/support.h"
#include "agl/keyboard.h"

AGL::Keyboard::Keyboard(Uint16* _functionalKeys, Uint16 _numberOfKeys)
{
	basicInitialize(_functionalKeys, _numberOfKeys, KEYBOARD_HELD_DELAY);
}

AGL::Keyboard::Keyboard(Uint16* _functionalKeys, Uint16 _numberOfKeys, Uint16 _heldDelay)
{
	basicInitialize(_functionalKeys, _numberOfKeys, _heldDelay);
}

AGL::Keyboard::Keyboard(bool useLetters, bool useNumbers, bool useArrows, bool useSpecials, bool useF, bool useOthers)
{
	Uint16 _numberOfKeys = 0;

	if(useLetters) _numberOfKeys += 26;
	if(useNumbers) _numberOfKeys += 10;
	if(useArrows) _numberOfKeys += 4;
	if(useSpecials) _numberOfKeys += 3;
	if(useF) _numberOfKeys += 12;
	if(useOthers) _numberOfKeys += 9;

	Uint16* _functionalKeys = new Uint16[_numberOfKeys];

	unsigned short baseIndex = 0;

	if(useLetters)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_A;
		_functionalKeys[baseIndex + 1] = AGL::KEY_B;
		_functionalKeys[baseIndex + 2] = AGL::KEY_C;
		_functionalKeys[baseIndex + 3] = AGL::KEY_D;
		_functionalKeys[baseIndex + 4] = AGL::KEY_E;
		_functionalKeys[baseIndex + 5] = AGL::KEY_F;
		_functionalKeys[baseIndex + 6] = AGL::KEY_G;
		_functionalKeys[baseIndex + 7] = AGL::KEY_H;
		_functionalKeys[baseIndex + 8] = AGL::KEY_I;
		_functionalKeys[baseIndex + 9] = AGL::KEY_J;
		_functionalKeys[baseIndex + 10] = AGL::KEY_K;
		_functionalKeys[baseIndex + 11] = AGL::KEY_L;
		_functionalKeys[baseIndex + 12] = AGL::KEY_M;
		_functionalKeys[baseIndex + 13] = AGL::KEY_N;
		_functionalKeys[baseIndex + 14] = AGL::KEY_O;
		_functionalKeys[baseIndex + 15] = AGL::KEY_P;
		_functionalKeys[baseIndex + 16] = AGL::KEY_Q;
		_functionalKeys[baseIndex + 17] = AGL::KEY_R;
		_functionalKeys[baseIndex + 18] = AGL::KEY_S;
		_functionalKeys[baseIndex + 19] = AGL::KEY_T;
		_functionalKeys[baseIndex + 20] = AGL::KEY_U;
		_functionalKeys[baseIndex + 21] = AGL::KEY_V;
		_functionalKeys[baseIndex + 22] = AGL::KEY_W;
		_functionalKeys[baseIndex + 23] = AGL::KEY_X;
		_functionalKeys[baseIndex + 24] = AGL::KEY_Y;
		_functionalKeys[baseIndex + 25] = AGL::KEY_Z;
		baseIndex += 26;
	}

	if(useNumbers)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_0;
		_functionalKeys[baseIndex + 1] = AGL::KEY_1;
		_functionalKeys[baseIndex + 2] = AGL::KEY_2;
		_functionalKeys[baseIndex + 3] = AGL::KEY_3;
		_functionalKeys[baseIndex + 4] = AGL::KEY_4;
		_functionalKeys[baseIndex + 5] = AGL::KEY_5;
		_functionalKeys[baseIndex + 6] = AGL::KEY_6;
		_functionalKeys[baseIndex + 7] = AGL::KEY_7;
		_functionalKeys[baseIndex + 8] = AGL::KEY_8;
		_functionalKeys[baseIndex + 9] = AGL::KEY_9;
		baseIndex += 10;
	}

	if(useArrows)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_UP;
		_functionalKeys[baseIndex + 1] = AGL::KEY_DOWN;
		_functionalKeys[baseIndex + 2] = AGL::KEY_LEFT;
		_functionalKeys[baseIndex + 3] = AGL::KEY_RIGHT;
		baseIndex += 4;
	}

	if(useSpecials)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_ESC;
		_functionalKeys[baseIndex + 1] = AGL::KEY_ENTER;
		_functionalKeys[baseIndex + 2] = AGL::KEY_SPACE;
		baseIndex += 3;
	}

	if(useF)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_F1;
		_functionalKeys[baseIndex + 1] = AGL::KEY_F2;
		_functionalKeys[baseIndex + 2] = AGL::KEY_F3;
		_functionalKeys[baseIndex + 3] = AGL::KEY_F4;
		_functionalKeys[baseIndex + 4] = AGL::KEY_F5;
		_functionalKeys[baseIndex + 5] = AGL::KEY_F6;
		_functionalKeys[baseIndex + 6] = AGL::KEY_F7;
		_functionalKeys[baseIndex + 7] = AGL::KEY_F8;
		_functionalKeys[baseIndex + 8] = AGL::KEY_F9;
		_functionalKeys[baseIndex + 9] = AGL::KEY_F10;
		_functionalKeys[baseIndex + 10] = AGL::KEY_F11;
		_functionalKeys[baseIndex + 11] = AGL::KEY_F12;
		baseIndex += 12;
	}

	if(useOthers)
	{
		_functionalKeys[baseIndex + 0] = AGL::KEY_LEFTSHIFT;
		_functionalKeys[baseIndex + 1] = AGL::KEY_RIGHTSHIFT;
		_functionalKeys[baseIndex + 2] = AGL::KEY_LEFTCONTROL;
		_functionalKeys[baseIndex + 3] = AGL::KEY_RIGHTCONTROL;
		_functionalKeys[baseIndex + 4] = AGL::KEY_LEFTALT;
		_functionalKeys[baseIndex + 5] = AGL::KEY_RIGHTALT;
		_functionalKeys[baseIndex + 6] = AGL::KEY_BACKSPACE;
		_functionalKeys[baseIndex + 7] = AGL::KEY_CAPSLOCK;
		_functionalKeys[baseIndex + 8] = AGL::KEY_DELETE;
		baseIndex += 9;
	}

	basicInitialize(_functionalKeys, _numberOfKeys, KEYBOARD_HELD_DELAY);
}

void AGL::Keyboard::basicInitialize(Uint16* _functionalKeys, Uint16 _numberOfKeys, Uint16 _heldDelay)
{
	numberOfKeys = _numberOfKeys;
   keys = _functionalKeys;
   heldDelay = _heldDelay;
   heldRepeat = heldDelay / 4;
   currentlyPressed = new bool[numberOfKeys];
   previouslyPressed = new bool[numberOfKeys];
   heldTimer = new Uint16[numberOfKeys];

	// Creates the index
	int keyCount = 0;
	SDL_GetKeyState(&keyCount);
	keyIndex = new Uint16[keyCount];

   for (int i = 0; i < numberOfKeys; i++)
   {
       currentlyPressed[i] = false;
       previouslyPressed[i] = false;
       heldTimer[i] = 0;

		// Populate the index
		keyIndex[keys[i]] = i;
   }
}

void AGL::Keyboard::update()
{
	Uint8* _keyboardState = SDL_GetKeyState(NULL);

	for (int i = 0; i < numberOfKeys; i++)
   {
		previouslyPressed[i] = currentlyPressed[i];
		if (_keyboardState[keys[i]])
		{
			if (previouslyPressed[i])
			{ 
				if(heldTimer[i] == heldDelay) heldTimer[i] -= heldRepeat;
				heldTimer[i]++;				
			}
			
			currentlyPressed[i] = true;
		}
		else
		{
			heldTimer[i] = 0;
			currentlyPressed[i] = false;
		}
   }
}

bool AGL::Keyboard::isKeyPressed(Uint16 key)
{
   return currentlyPressed[key] && !previouslyPressed[key];
}

bool AGL::Keyboard::isKeyHeld(Uint16 key)
{
   return heldTimer[key] == heldDelay;
}

bool AGL::Keyboard::isKeyReleased(Uint16 key)
{
   return !currentlyPressed[key] && previouslyPressed[key];
}

bool AGL::Keyboard::isKeyInactive(Uint16 key)
{
   return !currentlyPressed[key] && !previouslyPressed[key];
}

bool AGL::Keyboard::isKeyDown(Uint16 key)
{
   return currentlyPressed[key];
}

bool AGL::Keyboard::isOnlyKeyDown(Uint16 key)
{
	if (isKeyDown(key))
	{
		for (int i = 0; i < numberOfKeys; i++)
			if (i != key && isKeyDown(i))
				return false;

		return true;
	}

	return false;
}

Uint16 AGL::Keyboard::getIndex(Uint16 key)
{
	return keyIndex[key];
}
