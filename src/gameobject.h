#ifndef _AGL_GAMEOBJECT_H
#define _AGL_GAMEOBJECT_H

#include "agl/support.h"
#include "agl/vector2.h"
#include "agl/intvector2.h"
#include "agl/game.h"
#include "agl/drawer.h"
#include "agl/image.h"

namespace AGL
{
	/// GameObject class
	class GameObject
	{
		public:
			/// Difference from the object position and the position where it should be drawn
			AGL::IntVector2* imageGap;

			/// Size of the object
			AGL::Vector2* size;

			/// Position of the game object
			AGL::Vector2* position;

			/// Image of the game object
			AGL::Image* image;

			/// Game to which this object belongs
			AGL::Game* game;

			/// Drawer object
			AGL::Drawer* drawer;

			/// Creates a new instance of the GameObject class
			GameObject();

			/// Creates a new instance of the GameObject class
			///
			/// @param _image Image of the GameObject
			GameObject(AGL::Image* _image);

			/// Creates a new instance of the GameObject class
			///
			/// @param _image Image of the GameObject
			/// @param _drawer Drawer object
			GameObject(AGL::Image* _image, AGL::Drawer* _drawer);

			/// Creates a new instance of the GameObject class
			///
			/// @param _position Position of the GameObject
			GameObject(AGL::Vector2 &_position);

			/// Creates a new instance of the GameObject class
			///
			/// @param _image Image of the GameObject
			/// @param _position Position of the GameObject
			GameObject(AGL::Image* _image, AGL::Vector2 &_position);

			/// Creates a new instance of the GameObject class
			///
			/// @param _image Image of the GameObject
			/// @param _position Position of the GameObject
			/// @param _imageGap Difference from the object position and the position where it should be drawn
			GameObject(AGL::Image* _image, AGL::Vector2 &_position, IntVector2 &_imageGap);

			/// Creates a new instance of the GameObject class
			///
			/// @param _drawer Drawer object
			/// @param _image Image of the GameObject
			/// @param _position Position of the GameObject
			GameObject(AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position);

			/// Creates a new instance of the GameObject class
			///
			/// @param _game Game to which this object belongs
			/// @param _drawer Drawer object
			/// @param _image Image of the GameObject
			/// @param _position Position of the GameObject
			GameObject(AGL::Game* _game, AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position);

			/// Creates a new instance of the GameObject class
			///
			/// @param _game Game to which this object belongs
			/// @param _drawer Drawer object
			/// @param _image Image of the GameObject
			/// @param _position Position of the GameObject
			/// @param _imageGap Difference from the object position and the position where it should be drawn
			GameObject(AGL::Game* _game, AGL::Drawer* _drawer, AGL::Image* _image, AGL::Vector2 &_position, 
				AGL::IntVector2 &_imageGap);

			/// Check if this game object collides with another
			///
			/// @param anotherObject another object to check if this object collides with
			/// @return whether this game object collides with the specified game object
			bool collides(AGL::GameObject* anotherObject);

			/// Updates this game object
			virtual void update();

			/// Draws this object. Requires "drawer" attribute not NULL
			virtual void draw();
	};
}

#endif
