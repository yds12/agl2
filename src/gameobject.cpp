#include "agl/gameobject.h"
#include "agl/vector2.h"

AGL::GameObject::GameObject() 
{
	imageGap = new AGL::IntVector2(0, 0);
	size = new AGL::Vector2(0, 0);
	position = new AGL::Vector2(0, 0);
	image = NULL;
}

AGL::GameObject::GameObject(AGL::Image* _image)
{
	imageGap = new AGL::IntVector2(0, 0);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new AGL::Vector2(0, 0);
	image = _image;
}

AGL::GameObject::GameObject(AGL::Image* _image, AGL::Drawer* _drawer)
{
	imageGap = new AGL::IntVector2(0, 0);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new AGL::Vector2(0, 0);
	image = _image;
	drawer = _drawer;
}

AGL::GameObject::GameObject(AGL::Vector2 &_position)
{
	position = new Vector2(_position);
	size = new AGL::Vector2(0, 0);
	imageGap = new AGL::IntVector2(0, 0);
	image = NULL;
}

AGL::GameObject::GameObject(AGL::Image* _image, AGL::Vector2 &_position)
{
	imageGap = new AGL::IntVector2(0, 0);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new Vector2(_position);
	image = _image;
}

AGL::GameObject::GameObject(AGL::Image* _image, AGL::Vector2 &_position, AGL::IntVector2 &_imageGap)
{
	imageGap = new IntVector2(_imageGap);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new Vector2(_position);
	image = _image;
}

AGL::GameObject::GameObject(AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position)
{
	drawer = _drawer;
	imageGap = new AGL::IntVector2(0, 0);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new Vector2(_position);
	image = _image;
}

AGL::GameObject::GameObject(AGL::Game* _game, AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position)
{
	game = _game;
	drawer = _drawer;
	imageGap = new AGL::IntVector2(0, 0);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new Vector2(_position);
	image = _image;
}

AGL::GameObject::GameObject(AGL::Game* _game, AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position,
	AGL::IntVector2 &_imageGap)
{
	game = _game;
	drawer = _drawer;
	imageGap = new IntVector2(_imageGap);
	if (_image != NULL) size = new AGL::Vector2(_image->size->x, _image->size->y);
	else size = new AGL::Vector2(0, 0);
	position = new Vector2(_position);
	image = _image;
}

bool AGL::GameObject::collides(AGL::GameObject* anotherObject)
{
	if(position->x + size->x > anotherObject->position->x 
		&& anotherObject->position->x + anotherObject->size->x > position->x
		&& position->y + size->y > anotherObject->position->y 
		&& anotherObject->position->y + anotherObject->size->y > position->y)
		return true;

	return false;
}

void AGL::GameObject::update()
{
	
}

void AGL::GameObject::draw()
{
	Vector2 igv(*imageGap);
	IntVector2 pos = (*position + igv).toIntVector2();
	drawer->draw(image, pos);
}
