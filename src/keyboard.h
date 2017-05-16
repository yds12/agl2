#ifndef _AGL_KEYBOARD_H
#define _AGL_KEYBOARD_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "agl/support.h"

#define KEYBOARD_HELD_DELAY 35

namespace AGL
{
	//	Arrows		
	const Uint16	KEY_UP	=	SDLK_UP;
	const Uint16	KEY_RIGHT	=	SDLK_RIGHT;
	const Uint16	KEY_DOWN	=	SDLK_DOWN;
	const Uint16	KEY_LEFT	=	SDLK_LEFT;
			
	//	Special keys		
	const Uint16	KEY_ESC	=	SDLK_ESCAPE;
	const Uint16	KEY_SPACE	=	SDLK_SPACE;
	const Uint16	KEY_ENTER	=	SDLK_RETURN;
	const Uint16	KEY_DELETE	=	SDLK_DELETE;
	const Uint16	KEY_BACKSPACE	=	SDLK_BACKSPACE;
	const Uint16	KEY_TAB	=	SDLK_TAB;
	const Uint16	KEY_PAUSE	=	SDLK_PAUSE;
	const Uint16	KEY_INSERT	=	SDLK_INSERT;
	const Uint16	KEY_HOME	=	SDLK_HOME;
	const Uint16	KEY_END	=	SDLK_END;
	const Uint16	KEY_PAGEUP	=	SDLK_PAGEUP;
	const Uint16	KEY_PAGEDOWN	=	SDLK_PAGEDOWN;
			
	//	Letters		
	const Uint16	KEY_A	=	SDLK_a;
	const Uint16	KEY_B	=	SDLK_b;
	const Uint16	KEY_C	=	SDLK_c;
	const Uint16	KEY_D	=	SDLK_d;
	const Uint16	KEY_E	=	SDLK_e;
	const Uint16	KEY_F	=	SDLK_f;
	const Uint16	KEY_G	=	SDLK_g;
	const Uint16	KEY_H	=	SDLK_h;
	const Uint16	KEY_I	=	SDLK_i;
	const Uint16	KEY_J	=	SDLK_j;
	const Uint16	KEY_K	=	SDLK_k;
	const Uint16	KEY_L	=	SDLK_l;
	const Uint16	KEY_M	=	SDLK_m;
	const Uint16	KEY_N	=	SDLK_n;
	const Uint16	KEY_O	=	SDLK_o;
	const Uint16	KEY_P	=	SDLK_p;
	const Uint16	KEY_Q	=	SDLK_q;
	const Uint16	KEY_R	=	SDLK_r;
	const Uint16	KEY_S	=	SDLK_s;
	const Uint16	KEY_T	=	SDLK_t;
	const Uint16	KEY_U	=	SDLK_u;
	const Uint16	KEY_V	=	SDLK_v;
	const Uint16	KEY_W	=	SDLK_w;
	const Uint16	KEY_X	=	SDLK_x;
	const Uint16	KEY_Y	=	SDLK_y;
	const Uint16	KEY_Z	=	SDLK_z;
			
	//	Numbers		
	const Uint16	KEY_0	=	SDLK_0;
	const Uint16	KEY_1	=	SDLK_1;
	const Uint16	KEY_2	=	SDLK_2;
	const Uint16	KEY_3	=	SDLK_3;
	const Uint16	KEY_4	=	SDLK_4;
	const Uint16	KEY_5	=	SDLK_5;
	const Uint16	KEY_6	=	SDLK_6;
	const Uint16	KEY_7	=	SDLK_7;
	const Uint16	KEY_8	=	SDLK_8;
	const Uint16	KEY_9	=	SDLK_9;
			
	//	F		
	const Uint16	KEY_F1	=	SDLK_F1;
	const Uint16	KEY_F2	=	SDLK_F2;
	const Uint16	KEY_F3	=	SDLK_F3;
	const Uint16	KEY_F4	=	SDLK_F4;
	const Uint16	KEY_F5	=	SDLK_F5;
	const Uint16	KEY_F6	=	SDLK_F6;
	const Uint16	KEY_F7	=	SDLK_F7;
	const Uint16	KEY_F8	=	SDLK_F8;
	const Uint16	KEY_F9	=	SDLK_F9;
	const Uint16	KEY_F10	=	SDLK_F10;
	const Uint16	KEY_F11	=	SDLK_F11;
	const Uint16	KEY_F12	=	SDLK_F12;
	const Uint16	KEY_F13	=	SDLK_F13;
	const Uint16	KEY_F14	=	SDLK_F14;
	const Uint16	KEY_F15	=	SDLK_F15;
			
	//	Numbers from Keypad
	const Uint16	KEY_KP0	=	SDLK_KP0;
	const Uint16	KEY_KP1	=	SDLK_KP1;
	const Uint16	KEY_KP2	=	SDLK_KP2;
	const Uint16	KEY_KP3	=	SDLK_KP3;
	const Uint16	KEY_KP4	=	SDLK_KP4;
	const Uint16	KEY_KP5	=	SDLK_KP5;
	const Uint16	KEY_KP6	=	SDLK_KP6;
	const Uint16	KEY_KP7	=	SDLK_KP7;
	const Uint16	KEY_KP8	=	SDLK_KP8;
	const Uint16	KEY_KP9	=	SDLK_KP9;
			
	//	Keypad (others)
	const Uint16	KEY_KPPERIOD	=	SDLK_KP_PERIOD;
	const Uint16	KEY_KPDIVIDE	=	SDLK_KP_DIVIDE;
	const Uint16	KEY_KPMULTIPLY	=	SDLK_KP_MULTIPLY;
	const Uint16	KEY_KPMINUS	=	SDLK_KP_MINUS;
	const Uint16	KEY_KPPLUS	=	SDLK_KP_PLUS;
	const Uint16	KEY_KPENTER	=	SDLK_KP_ENTER;
	const Uint16	KEY_KPEQUALS	=	SDLK_KP_EQUALS;
			
	//	Modifiers		
	//const Uint16	KEY_CONTROL	=	KMOD_CTRL;
	//const Uint16	KEY_SHIFT	=	KMOD_SHIFT;
	//const Uint16	KEY_ALT	=	KMOD_ALT;
	//const Uint16	KEY_NOMODIFIER	=	KMOD_NONE;
	const Uint16	KEY_NUMLOCK	=	SDLK_NUMLOCK;
	const Uint16	KEY_CAPSLOCK	=	SDLK_CAPSLOCK;
	const Uint16	KEY_SCROLLOCK	=	SDLK_SCROLLOCK;
	const Uint16	KEY_LEFTCONTROL	=	SDLK_LCTRL;
	const Uint16	KEY_RIGHTCONTROL	=	SDLK_RCTRL;
	const Uint16	KEY_RIGHTSHIFT	=	SDLK_RSHIFT;
	const Uint16	KEY_LEFTSHIFT	=	SDLK_LSHIFT;
	const Uint16	KEY_RIGHTALT	=	SDLK_RALT;
	const Uint16	KEY_LEFTALT	=	SDLK_LALT;
			
	//	Special characters
	const Uint16	KEY_EXCLAMATION	=	SDLK_EXCLAIM;
	const Uint16	KEY_QUOTE	=	SDLK_QUOTE;
	const Uint16	KEY_DOUBLEQUOTE	=	SDLK_QUOTEDBL;
	const Uint16	KEY_HASH	=	SDLK_HASH;
	const Uint16	KEY_DOLLAR	=	SDLK_DOLLAR;
	const Uint16	KEY_AMPERSAND	=	SDLK_AMPERSAND;
	const Uint16	KEY_LEFTPARENTHESIS	=	SDLK_LEFTPAREN;
	const Uint16	KEY_RIGHTPARENTHESIS	=	SDLK_RIGHTPAREN;
	const Uint16	KEY_ASTERISK	=	SDLK_ASTERISK;
	const Uint16	KEY_PLUS	=	SDLK_PLUS;
	const Uint16	KEY_COMMA	=	SDLK_COMMA;
	const Uint16	KEY_MINUS	=	SDLK_MINUS;
	const Uint16	KEY_PERIOD	=	SDLK_PERIOD;
	const Uint16	KEY_SLASH	=	SDLK_SLASH;
	const Uint16	KEY_ARROBA	=	SDLK_AT;
	const Uint16	KEY_COLON	=	SDLK_COLON;
	const Uint16	KEY_SEMICOLON	=	SDLK_SEMICOLON;
	const Uint16	KEY_LESS	=	SDLK_LESS;
	const Uint16	KEY_EQUALS	=	SDLK_EQUALS;
	const Uint16	KEY_GREATER	=	SDLK_GREATER;
	const Uint16	KEY_QUESTION	=	SDLK_QUESTION;
	const Uint16	KEY_LEFTBRACKET	=	SDLK_LEFTBRACKET;
	const Uint16	KEY_RIGHTBRACKET	=	SDLK_RIGHTBRACKET;
	const Uint16	KEY_BACKSLASH	=	SDLK_BACKSLASH;
	const Uint16	KEY_CIRCUMFLEX	=	SDLK_CARET;
	const Uint16	KEY_UNDERLINE	=	SDLK_UNDERSCORE;
	const Uint16	KEY_BACKQUOTE	=	SDLK_BACKQUOTE;
			
	//	Special 2	
	const Uint16	KEY_LSUPER	=	SDLK_LSUPER;
	const Uint16	KEY_RSUPER	=	SDLK_RSUPER;
	const Uint16	KEY_MODE	=	SDLK_MODE;
	const Uint16	KEY_HELP	=	SDLK_HELP;
	const Uint16	KEY_PRINTSCREEN	=	SDLK_PRINT;
	const Uint16	KEY_SYSRQ	=	SDLK_SYSREQ;
	const Uint16	KEY_BREAK	=	SDLK_BREAK;
	const Uint16	KEY_MENU	=	SDLK_MENU;
	const Uint16	KEY_POWER	=	SDLK_POWER;
	const Uint16	KEY_EURO	=	SDLK_EURO;

	/// Class to manipulate keyboard
	class Keyboard
	{
		private:
			/// An array where the index is the key code and the value is the position on the keys array 
			Uint16* keyIndex;

			void basicInitialize(Uint16* _functionalKeys, Uint16 _numberOfKeys, Uint16 _heldDelay);
			
		public:
			/// Number of keys that will be used in the game
			Uint16 numberOfKeys;

			/// An array containing the code of the keys that will be used
			Uint16* keys;

			/// A boolean array indicating what keys are pressed 
			bool* currentlyPressed;

			/// A boolean array indicating what keys was pressed in the last update 
			bool* previouslyPressed;

			/// An array that counts the time along each key are pressed
			Uint16* heldTimer;

			/// Time to consider that a key is being held
			Uint16 heldDelay;
			
			/// Time to repeat the held state after it started
			Uint16 heldRepeat;

			/// Creates a new instance of the Keyboard class
			/// 
			/// @param _functionalKeys keys that will be used in the game
			/// @param _numberOfKeys number of keys that will be used
			/// @param _heldDelay time to consider that a key is being held (in milliseconds)
			Keyboard(Uint16* _functionalKeys, Uint16 _numberOfKeys, Uint16 _heldDelay);

			/// Creates a new instance of the Keyboard class
			/// 
			/// @param _functionalKeys keys that will be used in the game
			/// @param _numberOfKeys number of keys that will be used
			Keyboard(Uint16* _functionalKeys, Uint16 _numberOfKeys);

			/// Creates a new instance of the Keyboard class
			/// 
			/// @param useLetters whether the letters' keys will be used
			/// @param useNumbers whether the numbers' keys will be used
			/// @param useArrows whether the arrows' keys will be used
			/// @param useSpecials whether the keys ESC, ENTER and SPACE will be used
			/// @param useF whether the F 1 to 12 keys will be used
			/// @param useOthers whether the keys SHIFT (and left/right SHIFT), CONTROL (and left/right CONTROL), ALT (and left/right ALT), 
			/// BACKSPACE, CAPS LOCK and DELETE will be used
			Keyboard(bool useLetters, bool useNumbers, bool useArrows, bool useSpecials, bool useF, bool useOthers);

			/// Updates the input information for the keyboard
			void update();

			/// Verify if a key is pressed at the current update
			/// 
			/// @param key key to verify
			/// @return indicates whether the key is pressed
			bool isKeyPressed(Uint16 key);

			/// Verify if a key is being held at the current update
			/// 
			/// @param key key to verify
			/// @return indicates whether the key is being held
			bool isKeyHeld(Uint16 key);

			/// Verify if a key was released at the current update
			/// 
			/// @param key key to verify
			/// @return indicates whether the key was released
			bool isKeyReleased(Uint16 key);

			/// Returns whether the key is not down and was not released now
			/// 
			/// @param key key to verify
			/// @return indicates whether the key is inactive
			bool isKeyInactive(Uint16 key);

			/// Verify if the is down in the current update
			/// 
			/// @param key key to verify
			/// @return indicates whether the key is down
			bool isKeyDown(Uint16 key);

			/// Verify if the is the only key down in the current update
			/// 
			/// @param key key to verify
			/// @return indicates whether the key is the only key down
			bool isOnlyKeyDown(Uint16 key);

			/// Return the key index
			/// 
			/// @param key key to find the index
			/// @return the index of this key
			Uint16 getIndex(Uint16 key);
	};
}

#endif
