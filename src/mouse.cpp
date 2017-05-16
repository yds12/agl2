#include "agl/mouse.h"

AGL::Mouse::Mouse()
{
	position = new IntVector2;
	heldDelay = MOUSE_HELD_DELAY;
	doubleClickDelay = DOUBLECLICK_DELAY;
	leftPressed = false;
	rightPressed = false;
	leftPrevPressed = false;
	rightPrevPressed = false;
	leftDoubleChecking = false;
	rightDoubleChecking = false;
	leftHeldTimer = 0;
	rightHeldTimer = 0;
	leftDoubleTimer = 0;
	rightDoubleTimer = 0;
}

AGL::Mouse::Mouse(Uint16 _heldDelay, Uint16 _doubleClickDelay)
{
	position = new IntVector2;
	heldDelay = _heldDelay;
	doubleClickDelay = _doubleClickDelay;
	leftPressed = false;
	rightPressed = false;
	leftPrevPressed = false;
	rightPrevPressed = false;
	leftDoubleChecking = false;
	rightDoubleChecking = false;
	leftHeldTimer = 0;
	rightHeldTimer = 0;
	leftDoubleTimer = 0;
	rightDoubleTimer = 0;
}

bool AGL::Mouse::isLeftButtonPressed()
{
	return leftPressed && !leftPrevPressed;
}

bool AGL::Mouse::isRightButtonPressed()
{
	return rightPressed && !rightPrevPressed;
}

bool AGL::Mouse::isLeftButtonDoubleClicked()
{
	return leftDoubleTimer == -1;
}

bool AGL::Mouse::isRightButtonDoubleClicked()
{
	return rightDoubleTimer == -1;
}

bool AGL::Mouse::isLeftButtonHeld()
{
	return leftHeldTimer == heldDelay;
}

bool AGL::Mouse::isRightButtonHeld()
{
	return rightHeldTimer == heldDelay;
}

bool AGL::Mouse::isLeftButtonReleased()
{
	return !leftPressed && leftPrevPressed;
}

bool AGL::Mouse::isRightButtonReleased()
{
	return !rightPressed && rightPrevPressed;
}

bool AGL::Mouse::isLeftButtonInactive()
{
	return !leftPressed && !leftPrevPressed;
}

bool AGL::Mouse::isRightButtonInactive()
{
	return !rightPressed && !rightPrevPressed;
}

bool AGL::Mouse::isLeftButtonDown()
{
	return leftPressed;
}

bool AGL::Mouse::isRightButtonDown()
{
	return rightPressed;
}

bool AGL::Mouse::isOnlyLeftButtonDown()
{
	return leftPressed && !rightPressed;
}

bool AGL::Mouse::isOnlyRightButtonDown()
{
	return rightPressed && !leftPressed;
}

void AGL::Mouse::update()
{
	int mX, mY;
	Uint8 mouseState = SDL_GetMouseState(&mX, &mY);

	bool mL = false, mR = false;

	if(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) mL = true;
	if(mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) mR = true;

	position->x = mX;
	position->y = mY;

	leftPrevPressed = leftPressed;
	if (leftDoubleChecking)
	{
	    leftDoubleTimer++;
	    if (leftDoubleTimer > doubleClickDelay)
	    {
	        leftDoubleTimer = 0;
	        leftDoubleChecking = false;
	    }
	}
	if (mL)
	{
	    if (leftDoubleChecking)
	    {
	        leftDoubleTimer = -1;
	        leftDoubleChecking = false;
	    }
	    else if (leftDoubleTimer == -1) leftDoubleTimer = -2;
	    if (leftPrevPressed)
	        if (leftHeldTimer < heldDelay) leftHeldTimer++;
	    leftPressed = true;
	}
	else
	{
	    if (leftHeldTimer > 0) leftHeldTimer = 0;
	    if (leftPrevPressed)
	    {
	        if (leftDoubleTimer == -2) leftDoubleChecking = false;
	        else leftDoubleChecking = true;
	        leftDoubleTimer = 0;
	    }
	    leftPressed = false;
	}
	rightPrevPressed = rightPressed;
	if (rightDoubleChecking)
	{
	    rightDoubleTimer++;
	    if (rightDoubleTimer > doubleClickDelay)
	    {
	        rightDoubleTimer = 0;
	        rightDoubleChecking = false;
	    }
	}
	if (mR)
	{
	    if (rightDoubleChecking)
	    {
	        rightDoubleTimer = -1;
	        rightDoubleChecking = false;
	    }
	    else if (rightDoubleTimer == -1) rightDoubleTimer = -2;
	    if (rightPrevPressed)
	        if (rightHeldTimer < heldDelay) rightHeldTimer++;
	    rightPressed = true;
	}
	else
	{
	    if (rightHeldTimer > 0) rightHeldTimer = 0;
	    if (rightPrevPressed)
	    {
	        if (rightDoubleTimer == -2) rightDoubleChecking = false;
	        else rightDoubleChecking = true;
	        rightDoubleTimer = 0;
	    }
	    rightPressed = false;
	}
}

bool AGL::Mouse::isCursorOver(Rectangle area)
{
	if (position->x >= area.x &&
	    position->y >= area.y &&
	    position->x < area.x + area.width &&
	    position->y < area.y + area.height)
	    return true;
	return false;
}

void AGL::Mouse::setPosition(int x, int y)
{
	SDL_WarpMouse(x, y);
}

void AGL::Mouse::setPosition(IntVector2& position)
{
	SDL_WarpMouse(position.x, position.y);
}

