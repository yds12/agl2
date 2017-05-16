#include <stdlib.h>
#include "agl/game.h"
#include "agl/drawer.h"

// ------------ Includes here ---------------
#include <iostream>
#include "agl/filemanipulator.h"
#include "agl/ciphers.h"
#include "agl/sound.h"
#include "agl/music.h"
#include "agl/joystick.h"
#include "agl/vector2.h"
#include "agl/intvector2.h"
#include "agl/gameobject.h"
#include "agl/support.h"
#include "agl/color.h"
#include "agl/graphics/graphics.h"
// ------------------------------------------

// ------------ Defines here ----------------
// ------------------------------------------

//const string contentPath = "/home/USER/tests/agl/";
const string fontPath = "/usr/share/fonts/truetype/freefont/FreeMono.ttf";
const string contentPath = "/home/yuri/test/agl/";

/* class StupidObject : public AGL::GameObject
{
	public:
		int nome;

		StupidObject(int _nome, AGLTexture* _texture, AGL::Drawer* _drawer) : AGL::GameObject(_texture, _drawer)
		{
			AGL::Point zero;
			zero.x = 0;
			zero.y = 0;
			imageGap = zero;
			imageSize.x = _texture->w;
			imageSize.y = _texture->h;
			position = AGL::Vector2::zero();
			texture = _texture;
			nome = _nome;
			drawer = _drawer;
		}
}; */

AGL::Game* game = NULL;
AGL::Drawer* drawer = NULL;

// ------------ Declare variables here ------
AGL::Image* imagem = NULL;
AGL::IntVector2* position;
AGL::Keyboard* kb = NULL;
AGL::Mouse* ms = NULL;
AGL::Font* font = NULL;
AGL::Sound* sound = NULL, *sound2 = NULL, *sound3 = NULL;
AGL::Music* music = NULL;
AGL::Joystick* joy = NULL;
AGL::GameObject* go = NULL;
AGL::Timer* timer;
// ------------------------------------------

void initialize()
{
	AGL::FileManipulator fr(AGL::Format::stringToChar(&(contentPath + "bat.png")));
	int frs = 0;
	char* data = fr.readAll(frs);

	cout << data << endl;
	
	AGL::Ciphers ciph;
	ciph.revert(data, frs);
	cout << data << endl;
	
	AGL::FileManipulator fw(AGL::Format::stringToChar(&(contentPath + "new.png")));
	fw.writeAll(data, frs);

	// ------------ Initialize variables here ---
	
	game = new AGL::Game;
	game->setWindowTitle("teste");
	drawer = new AGL::Drawer;
	game->showMouse(true);
	kb = new AGL::Keyboard(false, false, true, true, false, false);
	ms = new AGL::Mouse;
	
	position = new AGL::IntVector2(10, 10);

        return;
	
	//font = new AGL::Font(AGL::Format::stringToChar(&(fontPath + "")), 60);
	sound = new AGL::Sound(AGL_AGR, AGL::Format::stringToChar(&(contentPath + "blink.agr")));
	sound2 = new AGL::Sound(AGL_AGR, AGL::Format::stringToChar(&(contentPath + "bomb.agr")));
	sound3 = new AGL::Sound(AGL_AGR, AGL::Format::stringToChar(&(contentPath + "buttonClick.agr")));
	//music = new AGL::Music("/home/USER/tests/agl/distress.mp3");
	
	int jnum = AGL::Joystick::countJoysticks();
	cout << "Number of joysticks connected: " << jnum << endl << endl;

	for(int i = 0; i < jnum; i++)
	{
		cout << "Joystick " << i << endl;
		cout << "tipo: " << AGL::Joystick::getJoystickName(i) << endl;
		cout << "inicializado? (0 não, 1 sim): " << AGL::Joystick::isOpened(i) << endl;

		joy = new AGL::Joystick(i);
		cout << "índice: " << joy->getIndex() << endl;
		cout << "nome: " << joy->getName() << endl;
		cout << "num. de eixos: " << joy->countAxes() << endl;
		cout << "num. de botões: " << joy->countButtons() << endl;
		cout << "num. de hats: " << joy->countHats() << endl;
		cout << "num. de bolas: " << joy->countBalls() << endl;

		//delete(joy);
		cout << endl;
	}
	// ------------------------------------------
}

void loadContent()
{
return;
	//cout << "load" << endl;
	// ------------ Load content here -----------
	//const char* filepath = "/home/USER/test/new.agr";
	//AGL::Format::stringToChar(&(contentPath + "new.agr"))
	imagem = new AGL::Image(AGL_AGR, AGL::Format::stringToChar(&(contentPath + "new.agr")));
	// ------------------------------------------
	//cout << "load end" << endl;
}

void update()
{
	//cout << "update" << endl;
	game->update(kb, ms, false);
	// ------------ Update the game here --------
	//if(kb->isKeyPressed(kb->getIndex(AGL::KEY_UP))) position->y -= 30;
	if(kb->isKeyPressed(kb->getIndex(AGL::KEY_DOWN))) position->y += 30;
	if(kb->isKeyPressed(kb->getIndex(AGL::KEY_LEFT))) position->x -= 30;
	if(kb->isKeyPressed(kb->getIndex(AGL::KEY_RIGHT))) position->x += 30;
	if(kb->isKeyPressed(kb->getIndex(AGL::KEY_UP))) 
	{
		cout << "uopaaaaa" << endl;
		
		AGL::SoundInstance* si = new AGL::SoundInstance(sound);
		AGL::SoundInstance* si2 = new AGL::SoundInstance(sound);
		AGL::SoundInstance* si3 = new AGL::SoundInstance(sound);
		
		si->play();
		si2->play();
		si3->play();
		
		si->stop();
		si2->stop();
		//si3->stop();
		
		cout << si3->activeChannel << endl;
		
		position->y--;
	}
	if(kb->isKeyHeld(kb->getIndex(AGL::KEY_DOWN))) position->y++;
	//if(kb->isKeyHeld(kb->getIndex(AGL::KEY_LEFT))) music->pause(); //position.x--;
	//if(kb->isKeyHeld(kb->getIndex(AGL::KEY_RIGHT))) music->unpause(); //position.x++;
	if(kb->isKeyDown(kb->getIndex(AGL::KEY_ESC))) game->setQuit(true);
	AGL::IntVector2 v1(800, 600);
	if(kb->isKeyPressed(kb->getIndex(AGL::KEY_SPACE))) drawer->setScreen(v1.x, v1.y, !drawer->fullScreen);
		
	/*if(kb->isKeyPressed(kb->getIndex(AGL::KEY_ENTER)))
	{
		int jnum = AGL::Joystick::countJoysticks();
		cout << "Number of joysticks connected: " << jnum << endl << endl;

		for(int i = 0; i < jnum; i++)
		{
			//cout << "Joystick " << i << endl;
			//cout << "tipo: " << AGL::Joystick::getJoystickName(i) << endl;
			//cout << "inicializado? (0 não, 1 sim): " << AGL::Joystick::isOpened(i) << endl;

			//AGL::Joystick* joy = new AGL::Joystick(i);
			cout << "índice: " << joy->getIndex() << endl;
			cout << "nome: " << joy->getName() << endl;

			int axes, buttons;
			axes = joy->countAxes();
			buttons = joy->countButtons();

			cout << "num. de eixos: " << axes << endl;
			cout << "num. de botões: " << buttons << endl;
			cout << "num. de hats: " << joy->countHats() << endl;
			cout << "num. de bolas: " << joy->countBalls() << endl;

			for(int j = 0; j < axes; j++)
				cout << "estado do eixo " << j << ": " << joy->getAxisState(j) << endl;
			cout << endl;

			for(int j = 0; j < buttons; j++)
				cout << "estado do botão " << j << " (0 solto, 1 pressionado): " << joy->getButtonState(j) << endl;
			cout << endl;

			//delete(joy);
			cout << endl;
		}	
	}*/

	/*if(joy != NULL)
	{
		if(joy->getAxisState(4) < 0) position->y -= 3;
		if(joy->getAxisState(4) > 0) position->y += 3;
		if(joy->getAxisState(3) < 0) position->x -= 3;
		if(joy->getAxisState(3) > 0) position->x += 3;

		if(joy->getButtonState(0)) position->y = 0;
		if(joy->getButtonState(1)) position->y = 300;
		if(joy->getButtonState(2)) position->y = 10;
		if(joy->getButtonState(3)) position->y = 500;
		if(joy->getButtonState(4)) position->y = 30;
		if(joy->getButtonState(5)) position->x = 300;
		if(joy->getButtonState(6)) position->x = 700;
		if(joy->getButtonState(7)) position->x = 1;
		if(joy->getButtonState(8)) position->x = 0;
		if(joy->getButtonState(9)) position->x = 67;
	}*/
	//if(ms->isLeftButtonPressed()) sound->play();
	//if(ms->isRightButtonPressed()) music->playOnce();
	if(ms->isLeftButtonDoubleClicked()) cout << "left button double clicked" << endl;
	if(ms->isRightButtonDoubleClicked()) cout << "right button double clicked" << endl;
	if(ms->isLeftButtonHeld()) cout << "left button held" << endl;
	if(ms->isRightButtonHeld()) cout << "right button held" << endl;
	//if(ms->isLeftButtonReleased()) cout << "left button released" << endl;
	//if(ms->isRightButtonReleased()) cout << "right button released" << endl;
	//if(ms->isLeftButtonInactive()) cout << "left button inactive" << endl;
	//if(ms->isRightButtonInactive()) cout << "right button inactive" << endl;
	//if(ms->isLeftButtonDown()) cout << "left button down" << endl;
	//if(ms->isRightButtonDown()) cout << "right button down" << endl;
	//if(ms->isOnlyLeftButtonDown()) cout << "only left button down" << endl;
	//if(ms->isOnlyRightButtonDown()) cout << "only right button down" << endl;
	//if(ms->isCursorOver({0, 0, 100, 100})) cout << "cursor está sobre área (0, 0) - (100, 100)" << endl;
	
	//cout << "mouse está em " << ms->position.x << "," << ms->position.y << endl;
	//cout << AGL::Music::isPlaying() << endl;
	// ------------------------------------------
	//cout << "update end" << endl;
}

void draw()
{
	//cout << "draw" << endl;
	drawer->clearScreen(AGL_COLOR_WHITE);
	
	AGL::IntVector2 v(*(ms->position));
	//v = ((*(ms->position)) * 2) + v;
	//drawer->draw(imagem, *(ms->position));
	AGL::IntVector2 v1(0,0);
	AGL::IntVector2 v2(0,100);
	//const char *t = "uhsuhsu";
	//drawer->drawText(font, t, v1, AGL_COLOR_BLACK);
	//drawer->drawText(font, "ola", v2, AGL_COLOR_BLACK);
	//drawer->drawText(font, AGL::Format::stringToChar(&strTime), v1, AGL_COLOR_BLACK);
	//drawer->drawText(font, AGL::Format::stringToChar(&strTime2), v2, AGL_COLOR_BLACK);
	//drawer->drawText(font, AGL::Format::stringToChar(&vec.toString()), ms->position, AGL_COLOR_BLACK);
	// ------------------------------------------

	drawer->updateScreen();
	//cout << "draw end" << endl;
}

void unloadContent()
{
	// ------------ Unload objects here ---------
	delete(joy);
	// ------------------------------------------

	game->end();
}

/// Main method, initializes the program
int main(int argc, char *argv[])
{
	initialize();
	loadContent();

	game->runFixedFps(update, draw, 60);
	unloadContent();

	return 0;
}
