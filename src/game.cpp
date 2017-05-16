#include <iostream>

#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "agl/game.h"

using namespace std;

void AGL::Game::setQuit(bool mustQuit)
{
	quit = mustQuit;
}

// ####### Constructors
AGL::Game::Game()
{
	basicInitialize(AGL_WINDOW_TITLE);
}

AGL::Game::Game(const char* windowTitle)
{
	basicInitialize(windowTitle);
}

void AGL::Game::basicInitialize(const char* windowTitle)
{
	if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		cout << "Erro ao inicializar SDL: " << SDL_GetError() << endl;
		exit(1);
	}
	
	cycleSize = 60;
	gameCounter = 0;
	cumulativeCycleTime = 0;
	quit = false;	
	timer = new AGL::Timer;
	timer->start();
	gameTimer = new AGL::Timer;
	gameTimer->start();

	Mix_OpenAudio(AGL_SOUND_FREQUENCY, MIX_DEFAULT_FORMAT, AGL_SOUND_MODE, AGL_SOUND_BUFFER);
	Mix_AllocateChannels(AGL_SOUND_CHANNELS);
	AGL::Sound::initialize();
	TTF_Init();
	setWindowTitle(windowTitle);
}

// ####### Methods
void AGL::Game::end()
{
	Mix_CloseAudio();
   SDL_Quit();
}

void AGL::Game::update()
{
	updateGameTime();

	SDL_Event event;
	while(SDL_PollEvent(&event))
		if(event.type == SDL_QUIT)	quit = true;
}

void AGL::Game::update(Keyboard* keyboard)
{
	updateGameTime();

	SDL_Event event;
	while(SDL_PollEvent(&event))
		if(event.type == SDL_QUIT)	quit = true;

	if(keyboard != NULL && keyboard->numberOfKeys > 0) keyboard->update();
}

void AGL::Game::update(Mouse* mouse)
{
	updateGameTime();

	SDL_Event event;
	while(SDL_PollEvent(&event))
		if(event.type == SDL_QUIT)	quit = true;

	if(mouse != NULL) mouse->update();
}

void AGL::Game::update(Keyboard* keyboard, Mouse* mouse)
{
	updateGameTime();

	SDL_Event event;
	while(SDL_PollEvent(&event))
		if(event.type == SDL_QUIT)	quit = true;

	if(keyboard != NULL && keyboard->numberOfKeys > 0) keyboard->update();
	if(mouse != NULL) mouse->update();
}

void AGL::Game::update(Keyboard* keyboard, Mouse* mouse, bool updateJoysticks)
{
	updateGameTime();

	SDL_Event event;
	while(SDL_PollEvent(&event))
		if(event.type == SDL_QUIT)	quit = true;

	if(keyboard != NULL && keyboard->numberOfKeys > 0) keyboard->update();
	if(mouse != NULL) mouse->update();
	if(updateJoysticks) AGL::Joystick::update();
}

void AGL::Game::updateGameTime()
{
	updateTime = timer->stop();
	cumulativeCycleTime += updateTime;

	if(gameCounter >= cycleSize) 
	{
		cycleTime = cumulativeCycleTime;
		cumulativeCycleTime = 0;
		gameCounter = 0;
	}	
	else gameCounter++;
	
	timer->start();
}

float AGL::Game::getUpdateTime()
{
	return updateTime;
}

void AGL::Game::runFixedFps(void (*updateMethod)(), void (*drawMethod)(), unsigned short fps)
{
	Timer fpsTimer;
	int threshold = 1000 / fps;
	int frames = 0;		
			
	while(!quit)
	{
		fpsTimer.start();
		(*updateMethod)();
		(*drawMethod)();
		int milli = fpsTimer.stopMs();
		
		if(milli < threshold) SDL_Delay(threshold - milli);
		frames++;
	}
}

float AGL::Game::getFps(float updatesPerDraw)
{
	return cycleSize / (cycleTime * updatesPerDraw);
}

void AGL::Game::wait(int milliseconds)
{
	SDL_Delay(milliseconds);
}

void AGL::Game::setWindowTitle(const char* title)
{
	SDL_WM_SetCaption(title, title);
}

void AGL::Game::showMouse(bool show)
{
	if(show) SDL_ShowCursor(SDL_ENABLE);
	else SDL_ShowCursor(SDL_DISABLE);
}
