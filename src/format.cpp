#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "agl/format.h"

// Converte um char* para float
float AGL::Format::charToFloat(const char* str)
{
	float f;   
   stringstream ss;
   ss << str;
   ss >> f;

   return f;
}

// Converte um char* para float
float AGL::Format::charToFloat(char* str)
{
	float f;   
   stringstream ss;
   ss << str;
   ss >> f;

   return f;
}

// Converte string para float
float AGL::Format::stringToFloat(string str)
{
   float f;   
   stringstream ss;
   ss << str;
   ss >> f;

   return f;
}

// Converte string para char*
char* AGL::Format::stringToChar(string* str)
{
	char* c = new char[str->size() + 1];
   std::strcpy (c, str->c_str());
   
	return c;
}

// Converte char* para string
string AGL::Format::charToString(const char* str)
{   
   stringstream ss;
   ss << str;

   return ss.str();
}

// Converte char* para string
string AGL::Format::charToString(char* str)
{   
   stringstream ss;
   ss << str;

   return ss.str();
}

// Converte int para string
string AGL::Format::intToString(int val)
{
   stringstream ss;
   ss << val;
   return ss.str();
}

// Converte string para int
int AGL::Format::stringToInt(string val)
{
   return atoi(val.c_str());
}

// Formata [uma string representando] um número decimal com o número de casas inteiras e decimais desejado, e sinal
string AGL::Format::formatDecimal(string val, int integerDigits, int decimalDigits)
{
   string sign;

	// Verifica qual o sinal do número
   if(val.find_first_of("+-") != string::npos)
   {
      sign = val.substr(0, 1);
      val = val.substr(1, val.length() - 1);
   }
   else
      sign = "+";

   int index = (int) val.find_first_of(".");
   
	// separa a string em inteiros e decimais
   string s1 = val.substr(0, index);
   string s2 = val.substr(index + 1, val.length() - (index + 1));

	// preenche a string da parte inteira com zeros caso seja menor que o tamanho desejado
   while((int)s1.length() < integerDigits)
      s1.insert(0, "0");

	// corta ou preenche com zeros a direita a parte decimal, dependendo do tamanho
   if((int)s2.length() > decimalDigits)
      s2 = s2.substr(0, decimalDigits);
   else while((int)s2.length() < decimalDigits)
      s2.append("0");

	// retorna tudo formatado
   return sign + s1 + "." + s2;
}

// Formata um número inteiro com o número de casas desejado
string AGL::Format::formatInt(int val, int digits)
{
   string val2 = intToString(val);   

	// preenche com zeros
   while((int)val2.length() < digits)
      val2.insert(0, "0");

   return val2;
}

// Formata [uma string representando] um número inteiro com o número de casas desejado
string AGL::Format::formatInt(string val, int digits)
{
	// preenche com zeros
   while((int)val.length() < digits)
      val.insert(0, "0");

   return val;
}

// Extrai a extensão do arquivo
string AGL::Format::findFileExtension(string file)
{
	size_t index = file.find_last_of(".");

	// extensão é tudo que vem após o último "."
   if(index != string::npos && index != file.length() - 1)
		return file.substr(index + 1);
	else
		return "";
}

// Remove a extensão do arquivo
string AGL::Format::removeFileExtension(string file)
{
	// encontra o último ponto
	size_t index = file.find_last_of(".");

	// remove o ponto e tudo que vem depois
   if(index != string::npos)
		return file.substr(0, index);
	else
		return file;
}

// Compara duas strings
bool AGL::Format::compareStrings(string a, string b)
{
	return a.compare(b) == 0;
}

// Compara um char* com uma string
bool AGL::Format::compareCharString(const char* a, string b)
{
	return string(a).compare(b) == 0;
}

// Compara um char* com uma string
bool AGL::Format::compareCharString(char* a, string b)
{
	return string(a).compare(b) == 0;
}

// Compara dois char*
bool AGL::Format::compareChars(const char* a, const char* b)
{
	return string(a).compare(string(b)) == 0;
}

// Compara dois char*
bool AGL::Format::compareChars(char* a, char* b)
{
	return string(a).compare(string(b)) == 0;
}

