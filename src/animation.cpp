#include "agl/animation.h"

AGL::Animation::Animation(Image* _spritesheet, Drawer* _drawer, short columns, short lines)
{
	finished = false;
	spritesheet = _spritesheet;
	drawer = _drawer;
	index = 0;
	spriteCount = columns * lines;
	updateCounter = 0;
	indexIndex = 0;
	spriteWidth = spritesheet->size->x / columns;
	spriteHeight = spritesheet->size->y / lines;
	timer = 0;

	sprites = new Rectangle[spriteCount];
	for (short j = 0; j < lines; j++)
	{
		for (short i = 0; i < columns; i++)
		{
			Rectangle r;
			r.x = i * spriteWidth;
			r.y = j * spriteHeight;
			r.width = spriteWidth;
			r.height = spriteHeight;
			sprites[j * columns + i] = r;
		}
	}
}

void AGL::Animation::update(short imageDuration)
{
	updateCounter++;
    if (updateCounter == imageDuration)
    {
        if (index == spriteCount - 1) 
        {
        	index = 0;
        	finished = true;
        }
        else index++;
        updateCounter = 0;
    }
}

void AGL::Animation::update(short indices[], short size, short imageDuration)
{
	updateCounter++;
    if (updateCounter == imageDuration)
    {
        if (indexIndex == size - 1) 
        {
        	indexIndex = 0;
        	finished = true;
        }
        else indexIndex++;
        index = indices[indexIndex];
        updateCounter = 0;
    }
}

void AGL::Animation::update(float imageDuration, Game* game)
{
	timer += game->getUpdateTime();
    if (timer >= imageDuration)
    {
        if (index == spriteCount - 1)
        {
        	index = 0;
        	finished = true;
        }
        else index++;
        timer = 0;
    }
}

void AGL::Animation::update(short indices[], short size, float imageDuration, Game* game)
{
	timer += game->getUpdateTime();
    if (timer >= imageDuration)
    {
        if (indexIndex == size - 1)
        {
        	indexIndex = 0;
        	finished = true;
        }
        else indexIndex++;
        index = indices[indexIndex];
        timer = 0;
    }
}

void AGL::Animation::reset()
{
	index = 0;
    indexIndex = 0;
    updateCounter = 0;
    timer = 0;
    finished = false;
}

void AGL::Animation::draw(IntVector2 &position)
{
	drawer->draw(spritesheet, sprites[index], position);
}

AGL::Rectangle AGL::Animation::getSpriteRectangle(short _index)
{
	return sprites[_index];
}

AGL::Rectangle AGL::Animation::getCurrentSpriteRectangle()
{
	return sprites[index];
}
