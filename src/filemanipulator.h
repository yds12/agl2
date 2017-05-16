#ifndef _AGL_FILEMANIPULATOR_H
#define _AGL_FILEMANIPULATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

#include "agl/format.h"

using namespace std;

namespace AGL
{
	/// Class designed to support file manipulation
	///
	/// Provides methods to open, close, read and write files
	class FileManipulator
	{
		private:
		   /// Name and path of the file
		   string fileName;

		   /// Stream to write
		   ofstream *outputFile;

		   /// Stream to read
		   ifstream *inputFile;

		public:
			/// Gets the file size in Bytes
			///
			/// @param _file file name
			/// @return file size in bytes
			static int getFileSize(string _file);

			/// Checks whether a file exists
			///
			/// @param _file file name
			/// @return true if the file exists, false otherwise
			static bool exists(string _file);

		   /// FileManipulator class constructor
			///
			/// Instantiate an object of this class, already attaching it to a file
			///
			/// @param file file to be read/written
		   FileManipulator(string file);

		   /// FileManipulator class constructor
			///
			/// Instantiate an object of this class, already attaching it to a file
			///
			/// @param file file to be read/written
		   FileManipulator(const char* file);
		   
		   /// Destructor
		   ~FileManipulator();

			/// Reads a file until the end
			///
			/// @param fileSize this variable will store the file size
			/// @return the file in a char*
			char* readAll(int &fileSize);

			/// Reads a file until the end
			///
			/// @param fileContent contents of the file in a char*
			/// @param fileSize size of the file
			void writeAll(char* fileContent, int fileSize);

		   /// Open the file to read
		   void openReader();

		   /// Close the file being read
		   void closeReader();

		   /// Reads and return a line
			///
			/// @return next line of the file
		   string readLine();

		   /// Opens the file to write
		   void openWriter();

		   /// Closes the file being written
		   void closeWriter();

		   /// Writes one line
			///
			/// @param line line content to be written
		   void writeLine(string line);

		   /// Returns whether the file has ended
			///
			/// @return indicates whether the file was completely read
		   bool end();

			/// Returns whether the file is ready to be manipulated
			///
			/// @return indicates whether the file is ready to be manipulated (to be opened and to be read/written) 
			bool ready();
	};
}

#endif

