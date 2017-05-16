#ifndef _AGL_FORMAT_H
#define _AGL_FORMAT_H

#include <string>

using namespace std;

namespace AGL
{
	/// Auxiliar class to format data
	///
	/// Provides static methods to format numbers and strings
	class Format
	{
		private:
		public:
			/// Converts string to float
			///
			/// @param str string to be converted to float
			/// @return a float with the value that was contained in the string
			static char* stringToChar(string* str);

			/// Converts const char* to string
			///
			/// @param str string to be converted into float
			/// @return a float with the value contained in the string
			static string charToString(const char* str);

			/// Converts char* to string
			///
			/// @param str string to be converted into float
			/// @return a float with the value contained in the string
			static string charToString(char* str);

			/// Converts string to float
			///
			/// @param str string to be converted into float
			/// @return float with the value contained in the string
			static float stringToFloat(string str);

			/// Converts const char* to float
			///
			/// @param str char* to be converted into float
			/// @return float with the value contained in the string
			static float charToFloat(const char* str);

			/// Converts char* to float
			///
			/// @param str char* to be converted into float
			/// @return float with the value contained in the string
			static float charToFloat(char* str);

			/// Converts int to string
			///
			/// @param val integer to be converted into string
			/// @return string with the value contained in the integer
			static string intToString(int val);

			/// Converts string to int
			///
			/// @param val string to be converted into integer
			/// @return integer with the value contained in the string
			static int stringToInt(string val);

			/// Formats [a string representing] a decimal number with the number of decimal and integer places specified
			///
			/// @param val string with a decimal value
			/// @param integerDigits number of integer digits
			/// @param decimalDigits number of decimal digits
			/// @return formated string representing a decimal
			static string formatDecimal(string val, int integerDigits, int decimalDigits);

			/// Formats an integer with the desired number of digits
			///
			/// @param val integer
			/// @param digits desired number of digits (fill the rest with zeroes)
			/// @return formated string representing an integer
			static string formatInt(int val, int digits);

			/// Formats [a string representing] an integer number with the number of digits specified
			///
			/// @param val string representing an integer
			/// @param digits desired number of digits (fill the rest with zeroes)
			/// @return formated string representing an integer
			static string formatInt(string val, int digits);

			/// Extracts the file extension
			///
			/// @param file file name
			/// @return file extension
			static string findFileExtension(string file);

			/// Removes the file extension
			///
			/// @param file file name
			/// @return file name without extension
			static string removeFileExtension(string file);

			/// Compares two strings
			///
			/// @param a a string
			/// @param b another string
			/// @return bool indicating whether both strings have equal content
			static bool compareStrings(string a, string b);

			/// Compares a const char* with a string
			///
			/// @param a a const char*
			/// @param b a string
			/// @return bool indicating whether both strings have equal content
			static bool compareCharString(const char* a, string b);

			/// Compares a char* with a string
			///
			/// @param a a char*
			/// @param b a string
			/// @return bool indicating whether both strings have equal content
			static bool compareCharString(char* a, string b);

			/// Compares two const char*
			///
			/// @param a a const char*
			/// @param b another const char*
			/// @return bool indicating whether both strings have equal content
			static bool compareChars(const char* a, const char* b);

			/// Compares two char*
			///
			/// @param a a char*
			/// @param b another char*
			/// @return bool indicating whether both strings have equal content
			static bool compareChars(char* a, char* b);
	};
}

#endif

