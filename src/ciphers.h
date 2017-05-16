#ifndef _AGL_CIPHERS_H
#define _AGL_CIPHERS_H

namespace AGL
{
	/// Class Ciphers
	class Ciphers
	{
		private:
		public:
			/// Revert the char*
			/// 
			/// @param data data to revert
			/// @param length length of the data to revert
			void revert(char* data, int length);
	};
}

#endif

