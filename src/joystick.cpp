#include "agl/joystick.h"

/// Counts the number of installed joysticks
///
/// @return number of installed joysticks
int AGL::Joystick::countJoysticks()
{
	return SDL_NumJoysticks();
}

/// Gets the name of a installed joystick
///
/// @param index index of the installed joystick
/// @return name of the joystick
string AGL::Joystick::getJoystickName(int index)
{
	return SDL_JoystickName(index);
}

/// Verifies whether a joystick is opened
///
/// @param index index of the installed joystick
/// @return whether the joystick is opened
bool AGL::Joystick::isOpened(int index)
{
	return SDL_JoystickOpened(index);
}

/// Updates the joysticks
///
/// This method must be called in every game update
void AGL::Joystick::update()
{
	SDL_JoystickUpdate();
}

/// Constructor
///
/// @param index index of the joystick
AGL::Joystick::Joystick(int index)
{
	sdlJoy = SDL_JoystickOpen(index);
}

/// Destructor
AGL::Joystick::~Joystick()
{
	SDL_JoystickClose(sdlJoy);
}

/// Gets the index of the joystick among the installed joysticks
///
/// @return index of the joystick
int AGL::Joystick::getIndex()
{
	return SDL_JoystickIndex(sdlJoy);
}

/// Gets the name of the joystick
///
/// @return name of the joystick
string AGL::Joystick::getName()
{
	return AGL::Joystick::getJoystickName(getIndex());
}

/// Gets the number of axes this joystick has
///
/// Usualy the directional button is made by 2 axes, X axis and y axis
///
/// @return number of axes
int AGL::Joystick::countAxes()
{
	return SDL_JoystickNumAxes(sdlJoy);
}

/// Gets the number of buttons this joystick has
///
/// Buttons are the common buttons, which has 2 states: pressed and released
///
/// @return number of buttons
int AGL::Joystick::countButtons()
{
	return SDL_JoystickNumButtons(sdlJoy);
}

/// Gets the number of balls this joystick has
///
/// Balls or track-balls has 2 values associated: x shift and y shift
///
/// @return number of balls
int AGL::Joystick::countBalls()
{
	return SDL_JoystickNumBalls(sdlJoy);
}

/// Gets the number of hats this joystick has
///
/// Hats or Point-of-Views (POV) can be in 9 states: centered, up, down, left, right and the diagonals
///
/// @return number of hats
int AGL::Joystick::countHats()
{
	return SDL_JoystickNumHats(sdlJoy);
}

/// Gets the state of a button
///
/// @param index index of the button (0 is the first button of the joystick, 1 the next, and so on...)
/// @return true if the button is pressed, false otherwise
bool AGL::Joystick::getButtonState(int index)
{
	return SDL_JoystickGetButton(sdlJoy, index);
}

/// Gets the state of an axis
///
/// @param index index of the axis (0 is the first axis of the joystick, 1 the next, and so on...). Usualy the directional button has
/// the axis 0 as the X axis, and 1 as the Y axis
/// @return a value between -32768 and 32768
Sint16 AGL::Joystick::getAxisState(int index)
{
	return SDL_JoystickGetAxis(sdlJoy, index);
}

/// Gets the state of a hat
///
/// @param index index of the hat (0 is the first hat of the joystick, 1 the next, and so on...)
/// @return one of the following states: AGL_POSITION_UP, AGL_POSITION_DOWN, AGL_POSITION_LEFT, AGL_POSITION_RIGHT,
/// AGL_POSITION_CENTER, AGL_POSITION_TOPLEFT, AGL_POSITION_TOPRIGHT, AGL_POSITION_DOWNLEFT, AGL_POSITION_DOWNRIGHT.
/// Those states represents the possible positions for the hat, the four directions, diagonals and centered.
Uint8 AGL::Joystick::getHatState(int index)
{
	return SDL_JoystickGetHat(sdlJoy, index);
}

/// Gets the state of a ball
///
/// @param index index of the ball (0 is the first hat of the joystick, 1 the next, and so on...)
/// @param xShift relative movement of the ball in the X axis
/// @param yShift relative movement of the ball in the Y axis
void AGL::Joystick::getBallState(int index, int* xShift, int* yShift)
{
	SDL_JoystickGetBall(sdlJoy, index, xShift, yShift);
}
