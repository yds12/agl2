#ifndef _AGL_ANIMATION_H
#define _AGL_ANIMATION_H

#include "agl/drawer.h"
#include "agl/game.h"
#include "agl/intvector2.h"
#include <vector>

namespace AGL
{
	/// Provides easy control for sprite animation by using a spritesheet
	class Animation
	{
		private:
			Rectangle* sprites;
			short updateCounter, indexIndex, spriteWidth, spriteHeight;
			float timer;

		public:
			/// The spritesheet
			Image* spritesheet;

			/// Object used to draw the images
			Drawer* drawer;

			/// Indicates the amount of sprites in the spritesheet
			short spriteCount;

			/// Indicates the sprite currently being drawn
			short index;

			/// Indicates that the animation has reached the end of the last frame
			bool finished;

			/// Creates a new instance of the Animation class
			///
			/// @param _spritesheet the spritesheet
			/// @param _drawer object used to draw the images
			/// @param columns amount of sprites horizontally
			/// @param lines amount of sprites vertically
			Animation(Image* _spritesheet, Drawer* _drawer, short columns, short lines);

		    /// This should be called at each "update" for the animation to be performed
		    ///
		    /// @param imageDuration number of "updates" between each sprite change
		    void update(short imageDuration);

		    /// This should be called at each "update" for the animation to be performed
		    ///
		    /// @param indices the sequence of sprite indices to be used in the animation
			/// @param size length of the indices array
		    /// @param imageDuration number of "updates" between each sprite change
		    void update(short indices[], short size, short imageDuration);

		    /// This should be called at each "update" for the animation to be performed
		    ///
		    /// @param imageDuration seconds between each sprite change
		    /// @param game used for timing
		    void update(float imageDuration, Game* game);

		    /// This should be called at each "update" for the animation to be performed
		    ///
		    /// @param indices the sequence of sprite indices to be used in the animation
			/// @param size length of the indices array
		    /// @param imageDuration seconds between each sprite change
		    /// @param game used for timing
		    void update(short indices[], short size, float imageDuration, Game* game);

		    /// Resets all variables, i.e., indices and timers, to zero
		    void reset();

		    /// Draws the current sprite in the specified position
		    ///
		    /// @param position position in the screen to draw the sprite
		    void draw(IntVector2 &position);

		    /// Gets the rectangle with position and size of the sprite in the given index of the spritesheet
		    ///
		    /// @param _index index of the sprite in the spritesheet
		    /// @return rectangle with position and size of the sprite
		    Rectangle getSpriteRectangle(short _index);

		    /// Gets the rectangle with position and size of the current sprite
		    ///
		    /// @return rectangle with position and size of the current sprite
		    Rectangle getCurrentSpriteRectangle();
	};
}

#endif

