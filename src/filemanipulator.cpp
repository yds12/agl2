#include "agl/filemanipulator.h"

using namespace std;

int AGL::FileManipulator::getFileSize(string _file)
{
	ifstream is;
	is.open (AGL::Format::stringToChar(&_file), ios::binary);
	is.seekg (0, ios::end);
	int fileSize = is.tellg();
	is.close();
	return fileSize;
}

bool AGL::FileManipulator::exists(string _file)
{
	struct stat statBuf;
	if (stat(AGL::Format::stringToChar(&_file), &statBuf) < 0) return false;
	return S_ISREG(statBuf.st_mode);
}

// Constructor
AGL::FileManipulator::FileManipulator(string _file)
{
   fileName = _file;
   inputFile = new ifstream();
   outputFile = new ofstream();
}

// Constructor
AGL::FileManipulator::FileManipulator(const char* _file)
{
   fileName = _file;
   inputFile = new ifstream();
   outputFile = new ofstream();
}

// Destructor
AGL::FileManipulator::~FileManipulator()
{
	delete inputFile;
	delete outputFile;
}

// Reads a file until the end
char* AGL::FileManipulator::readAll(int &fileSize)
{
	ifstream is (fileName.c_str(), ios::in | ios::binary | ios::ate);
	char* fileContents;
	
	if(is.is_open())
	{
		fileSize = is.tellg();
		char ch;
		fileContents = new char[fileSize];
		is.seekg(0, ios::beg);

		int loop = 0;
		while(loop < fileSize)
		{
			if(!is.read(&ch, 1)) return fileContents;
			else fileContents[loop] = ch;
			loop++;
		}
	}

	is.close();
	return fileContents;
}

// Reads a file until the end
void AGL::FileManipulator::writeAll(char* fileContent, int fileSize)
{
	FILE* newFile = fopen(fileName.c_str(), "w");
	
	for(int i = 0; i < fileSize; i++) 
		fputc(fileContent[i], newFile);
		
	fclose(newFile);
}

// Abre o arquivo
void AGL::FileManipulator::openReader()
{
   inputFile->open(fileName.c_str(), ifstream::in);
}

// Abre o arquivo
void AGL::FileManipulator::closeReader()
{
   inputFile->close();
}

// Lê e retorna uma linha
string AGL::FileManipulator::readLine()
{
   if (inputFile->is_open()) // verifica se o arquivo está aberto
   {
      if(!inputFile->eof()) // verifica se o arquivo não terminou
      {
         string line;
         getline(*inputFile, line);
         return line;
      }
   }

   return ""; // caso não possa ler retorna uma string vazia
}

// Abre o arquivo para escrita
void AGL::FileManipulator::openWriter()
{
   outputFile->open(fileName.c_str(), ofstream::out);
}

// Fecha o arquivo de escrita
void AGL::FileManipulator::closeWriter()
{
   outputFile->close();
}

// Escreve uma linha
void AGL::FileManipulator::writeLine(string line)
{
   if (outputFile->is_open())
      (*outputFile) << line << endl;
}

// Retorna se o arquivo terminou
bool AGL::FileManipulator::end()
{
   return inputFile->eof();
}

// Retorna se o arquivo está pronto para ser manipulado
bool AGL::FileManipulator::ready()
{
	return (inputFile->is_open() && inputFile->good()) ||
		(outputFile->is_open() && outputFile->good());
}

