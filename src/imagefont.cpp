#include <string>
#include <vector>
#include <algorithm>

#include "agl/imagefont.h"

using namespace std;

short AGL::ImageFont::getCharIndex(char ch)
{
	for(int i = 0; i < chars.length(); i++)
		if(chars[i] == ch)
			return i;

	return -1;
}

short AGL::ImageFont::getCharIndex(wchar_t ch)
{
	for(int i = 0; i < wchars.length(); i++)
		if(wchars[i] == ch)
			return i;

	return -1;
}

void AGL::ImageFont::blitChar(Image* image, short x, short y, AGL::Rectangle rect)
{
	for(int i = 0; i < rect.width; i++)
		for(int j = 0; j < rect.height; j++)
		{
			Uint8 r, g, b, a;
			spriteSheet->getPixel(rect.x + i, rect.y + j, &r, &g, &b, &a);
			image->setPixel(x + i, y + j, r, g, b, a);
		}
}

AGL::ImageFont::~ImageFont()
{
	delete rects;
}

void AGL::ImageFont::basicInitialize(AGL::Image* _spriteSheet, short lines, string _chars)
{
	lineSpacing = 1;
	ssLines = lines;
	charSpacing = 1;
	blankSpaceWidth = 5;
	spriteSheet = _spriteSheet;
	chars = _chars;

	charHeight = (spriteSheet->size->y - ssLines) / ssLines;

	rects = new Rectangle[chars.length()];
	short rectCount = 0;

	for(int i = 0; i < ssLines; i++)
	{
		short lastJ = 0;
		for(int j = 0; j < spriteSheet->size->x; j++)
		{
			Uint8 r, g, b, a;
			spriteSheet->getPixel(j, i * (charHeight + 1), &r, &g, &b, &a);

			if(r == 0 && g == 0 && b == 0 && a == 255)
			{
				rects[rectCount] = { lastJ, i * (charHeight + 1) + 1, j - lastJ + 1, charHeight};
				rectCount++;
				lastJ = j + 1;
			}
		}
	}
}

void AGL::ImageFont::basicInitialize(AGL::Image* _spriteSheet, short lines, wstring _chars)
{
	lineSpacing = 1;
	ssLines = lines;
	charSpacing = 1;
	blankSpaceWidth = 5;
	spriteSheet = _spriteSheet;
	wchars = _chars;

	charHeight = (spriteSheet->size->y - ssLines) / ssLines;

	rects = new Rectangle[wchars.length()];
	short rectCount = 0;

	for(int i = 0; i < ssLines; i++)
	{
		short lastJ = 0;
		for(int j = 0; j < spriteSheet->size->x; j++)
		{
			Uint8 r, g, b, a;
			spriteSheet->getPixel(j, i * (charHeight + 1), &r, &g, &b, &a);

			if(r == 0 && g == 0 && b == 0 && a == 255)
			{
				rects[rectCount] = { lastJ, i * (charHeight + 1) + 1, j - lastJ + 1, charHeight};
				rectCount++;
				lastJ = j + 1;
			}
		}
	}
}

AGL::ImageFont::ImageFont(AGL::Image* _spriteSheet, short lines, string _chars)
{
	basicInitialize(_spriteSheet, lines, _chars);
}

AGL::ImageFont::ImageFont(AGL::Image* _spriteSheet, short lines, wstring _chars)
{
	basicInitialize(_spriteSheet, lines, _chars);
}

AGL::ImageFont::ImageFont(AGL::Image* _spriteSheet, short lines)
{
	basicInitialize(_spriteSheet, lines,
		L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzÁÉÍÓÚÀÈÃÕÂÊÔÜÇáéíóúàèãõâêôüç0123456789.,;:!?¡¿+-*/=<>\\@#$%&()[]{}_'\"");
}

void AGL::ImageFont::setOptions(short charSpacing, short lineSpacing, short blankWidth)
{
	this->charSpacing = charSpacing;
	this->lineSpacing = lineSpacing;
	this->blankSpaceWidth = blankWidth;
}

short AGL::ImageFont::getCharWidth(char ch)
{
	if (ch == ' ') return blankSpaceWidth;
	return rects[getCharIndex(ch)].width;
}

short AGL::ImageFont::getCharWidth(wchar_t ch)
{
	if (ch == L' ') return blankSpaceWidth;
	return rects[getCharIndex(ch)].width;
}

AGL::Image* AGL::ImageFont::writeLine(string text)
{
	short width = (text.length() - 1) * charSpacing;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') width += blankSpaceWidth;
		else width += rects[getCharIndex(text[i])].width;
	}

	Image* image = new Image(width, charHeight);

	short curX = 0;
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(text[i]);
			blitChar(image, curX, 0, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeLine(wstring text)
{
	short width = (text.length() - 1) * charSpacing;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') width += blankSpaceWidth;
		else width += rects[getCharIndex(text[i])].width;
	}

	Image* image = new Image(width, charHeight);

	short curX = 0;
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(text[i]);
			blitChar(image, curX, 0, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeCenteredLine(string text, short width)
{
	short textWidth = (text.length() - 1) * charSpacing;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') textWidth += blankSpaceWidth;
		else textWidth += rects[getCharIndex(text[i])].width;
	}

	Image* image = new Image(width, charHeight);

	short curX = (width - textWidth) / 2;
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(text[i]);
			blitChar(image, curX, 0, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeCenteredLine(wstring text, short width)
{
	short textWidth = (text.length() - 1) * charSpacing;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') textWidth += blankSpaceWidth;
		else textWidth += rects[getCharIndex(text[i])].width;
	}

	Image* image = new Image(width, charHeight);

	short curX = (width - textWidth) / 2;
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ') curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(text[i]);
			blitChar(image, curX, 0, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeBreaking(string text, short width)
{
	text += ' ';

	short lastSpace = 0;
	string allText = "";
	string lastWord = "";
	short wordLength = 0;
	short lineLength = 0;
	short textLines = 1;
	short maxLine = width;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == '\n')
		{
			lineLength += wordLength;
			if(lineLength > maxLine) maxLine = lineLength;

			if(lineLength > width)
			{
				lineLength = wordLength;
				allText += '\n';
				textLines++;
			}

			wordLength = 0;
			allText += lastWord + '\n';
			lastWord = "";
			lineLength = 0;
			textLines++;
		}
		else if(text[i] == ' ')
		{
			lineLength += wordLength;

			if(lineLength > width)
			{
				if(lineLength > maxLine) maxLine = lineLength;

				lineLength = wordLength;
				allText += '\n';
				textLines++;
			}

			lineLength += blankSpaceWidth;
			wordLength = 0;
			allText += lastWord + ' ';
			lastWord = "";
		}
		else
		{
			lastWord += text[i];
			wordLength += rects[getCharIndex(text[i])].width + charSpacing;
		}
	}

	Image* image = new Image(maxLine, charHeight * textLines + lineSpacing * (textLines - 1));

	short curX = 0;
	short curY = 0;

	for(int i = 0; i < allText.length(); i++)
	{
		if(allText[i] == '\n')
		{
			curX = 0;
			curY += charHeight + lineSpacing;
		}
		else if(allText[i] == ' ')	curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(allText[i]);
			blitChar(image, curX, curY, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeBreaking(wstring text, short width)
{
	text += L' ';

	short lastSpace = 0;
	wstring allText = L"";
	wstring lastWord = L"";
	short wordLength = 0;
	short lineLength = 0;
	short textLines = 1;
	short maxLine = width;

	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] == L'\n')
		{
			lineLength += wordLength;
			if(lineLength > maxLine) maxLine = lineLength;

			if(lineLength > width)
			{
				lineLength = wordLength;
				allText += L'\n';
				textLines++;
			}

			wordLength = 0;
			allText += lastWord + L'\n';
			lastWord = L"";
			lineLength = 0;
			textLines++;
		}
		else if(text[i] == L' ')
		{
			lineLength += wordLength;

			if(lineLength > width)
			{
				if(lineLength > maxLine) maxLine = lineLength;

				lineLength = wordLength;
				allText += L'\n';
				textLines++;
			}

			lineLength += blankSpaceWidth;
			wordLength = 0;
			allText += lastWord + L' ';
			lastWord = L"";
		}
		else
		{
			lastWord += text[i];
			wordLength += rects[getCharIndex(text[i])].width + charSpacing;
		}
	}

	Image* image = new Image(maxLine, charHeight * textLines + lineSpacing * (textLines - 1));

	short curX = 0;
	short curY = 0;

	for(int i = 0; i < allText.length(); i++)
	{
		if(allText[i] == L'\n')
		{
			curX = 0;
			curY += charHeight + lineSpacing;
		}
		else if(allText[i] == L' ')	curX += blankSpaceWidth + charSpacing;
		else
		{
			short index = getCharIndex(allText[i]);
			blitChar(image, curX, curY, rects[index]);
			curX += rects[index].width + charSpacing;
		}
	}

	return image;
}

AGL::Image* AGL::ImageFont::writeJustified(string text, short width)
{
	vector< vector<short>* > lines;
	lines.push_back(new vector<short>);
	vector<short> paragraphEndLines;
	int lineIndex = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '\n')
		{
			paragraphEndLines.push_back(lineIndex);
			lineIndex++;
			lines.push_back(new vector<short>);
		}
		else if (text[i] == ' ')
		{
			short w = 0;
			for (int j = i - lines[lineIndex]->size(); j < text.length(); j++)
			{
				if ((text[j] == ' ' && j > i) || text[j] == '\n') break;
				w += text[j] == ' ' ? blankSpaceWidth : rects[getCharIndex(text[j])].width + charSpacing;
			}
			w -= charSpacing;
			if (w > width)
			{
				lineIndex++;
				lines.push_back(new vector<short>);
			}
			else lines[lineIndex]->push_back(-1);
		}
		else lines[lineIndex]->push_back(getCharIndex(text[i]));
	}
	
	Image* image = new Image(width, charHeight * lines.size() + lineSpacing * (lines.size() - 1));
	for (int i = 0; i < lines.size(); i++)
	{
		int currentX = 0;
		if (i == lines.size() - 1 || find(paragraphEndLines.begin(), paragraphEndLines.end(), i) != paragraphEndLines.end())
		{
			for (int j = 0; j < lines[i]->size(); j++)
			{
				if ((*(lines[i]))[j] == -1)
					currentX += blankSpaceWidth + charSpacing;
				else
				{
					blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
					currentX += rects[(*(lines[i]))[j]].width + charSpacing;
				}
			}
		}
		else
		{
			short spaceCount = 0;
			for (int j = 0; j < lines[i]->size(); j++)
				if ((*(lines[i]))[j] == -1) spaceCount++;
			int *spaces, len;
			if (spaceCount > 0) spaces = new int[len = spaceCount];
			else spaces = new int[len = lines[i]->size() - 1];
			for (int j = 0; j < len; j++) spaces[j] = 0;
			short w = 0;
			for (int j = 0; j < lines[i]->size(); j++)
			{
				if ((*(lines[i]))[j] == -1) w += blankSpaceWidth + charSpacing;
				else w += rects[(*(lines[i]))[j]].width + charSpacing;
			}
			w -= charSpacing;
			short spaceIndex = 0;
			for (short spacesToDistribute = width - w; spacesToDistribute > 0; spacesToDistribute--)
			{
				spaces[spaceIndex]++;
				if (spaceIndex == len - 1) spaceIndex = 0;
				else spaceIndex++;
			}
			spaceIndex = 0;
			if (spaceCount > 0)
			{
				for (int j = 0; j < lines[i]->size(); j++)
				{
					if ((*(lines[i]))[j] == -1)
					{
						currentX += blankSpaceWidth + charSpacing + spaces[spaceIndex];
						spaceIndex++;
					}
					else
					{
						blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
						if (j < lines[i]->size() - 1) currentX += rects[(*(lines[i]))[j]].width + charSpacing;
					}
				}
			}
			else
			{
				for (int j = 0; j < lines[i]->size(); j++)
				{
					blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
					if (j < lines[i]->size() - 1) currentX += rects[(*(lines[i]))[j]].width + charSpacing + spaces[spaceIndex];
					spaceIndex++;
				}
			}
			delete spaces;
		}
	}
	
	for (int i = 0; i < lines.size(); i++)
		delete lines[i];

	return image;
}

AGL::Image* AGL::ImageFont::writeJustified(wstring text, short width)
{
	vector< vector<short>* > lines;
	lines.push_back(new vector<short>);
	vector<short> paragraphEndLines;
	int lineIndex = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == L'\n')
		{
			paragraphEndLines.push_back(lineIndex);
			lineIndex++;
			lines.push_back(new vector<short>);
		}
		else if (text[i] == L' ')
		{
			short w = 0;
			for (int j = i - lines[lineIndex]->size(); j < text.length(); j++)
			{
				if ((text[j] == L' ' && j > i) || text[j] == L'\n') break;
				w += text[j] == L' ' ? blankSpaceWidth : rects[getCharIndex(text[j])].width + charSpacing;
			}
			w -= charSpacing;
			if (w > width)
			{
				lineIndex++;
				lines.push_back(new vector<short>);
			}
			else lines[lineIndex]->push_back(-1);
		}
		else lines[lineIndex]->push_back(getCharIndex(text[i]));
	}
	
	Image* image = new Image(width, charHeight * lines.size() + lineSpacing * (lines.size() - 1));
	for (int i = 0; i < lines.size(); i++)
	{
		int currentX = 0;
		if (i == lines.size() - 1 || find(paragraphEndLines.begin(), paragraphEndLines.end(), i) != paragraphEndLines.end())
		{
			for (int j = 0; j < lines[i]->size(); j++)
			{
				if ((*(lines[i]))[j] == -1)
					currentX += blankSpaceWidth + charSpacing;
				else
				{
					blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
					currentX += rects[(*(lines[i]))[j]].width + charSpacing;
				}
			}
		}
		else
		{
			short spaceCount = 0;
			for (int j = 0; j < lines[i]->size(); j++)
				if ((*(lines[i]))[j] == -1) spaceCount++;
			int *spaces, len;
			if (spaceCount > 0) spaces = new int[len = spaceCount];
			else spaces = new int[len = lines[i]->size() - 1];
			for (int j = 0; j < len; j++) spaces[j] = 0;
			short w = 0;
			for (int j = 0; j < lines[i]->size(); j++)
			{
				if ((*(lines[i]))[j] == -1) w += blankSpaceWidth + charSpacing;
				else w += rects[(*(lines[i]))[j]].width + charSpacing;
			}
			w -= charSpacing;
			short spaceIndex = 0;
			for (short spacesToDistribute = width - w; spacesToDistribute > 0; spacesToDistribute--)
			{
				spaces[spaceIndex]++;
				if (spaceIndex == len - 1) spaceIndex = 0;
				else spaceIndex++;
			}
			spaceIndex = 0;
			if (spaceCount > 0)
			{
				for (int j = 0; j < lines[i]->size(); j++)
				{
					if ((*(lines[i]))[j] == -1)
					{
						currentX += blankSpaceWidth + charSpacing + spaces[spaceIndex];
						spaceIndex++;
					}
					else
					{
						blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
						if (j < lines[i]->size() - 1) currentX += rects[(*(lines[i]))[j]].width + charSpacing;
					}
				}
			}
			else
			{
				for (int j = 0; j < lines[i]->size(); j++)
				{
					blitChar(image, currentX, i * (charHeight + lineSpacing), rects[(*(lines[i]))[j]]);
					if (j < lines[i]->size() - 1) currentX += rects[(*(lines[i]))[j]].width + charSpacing + spaces[spaceIndex];
					spaceIndex++;
				}
			}
			delete spaces;
		}
	}
	
	for (int i = 0; i < lines.size(); i++)
		delete lines[i];

	return image;
}
