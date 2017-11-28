#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Element.h"
#include "j1Fonts.h"


class TextBox : public Element
{
public:
	TextBox(int x, int y, ElementType type, SDL_Rect rec, const char* text);
	~TextBox();

	void InsertLetter(char letter, p2SString* text);
	void DeleteLetter(p2SString* text);
	void OnClick();
	void Draw();

private: 
	bool isClicked = false;
	SDL_Rect rec;
	const char* text;
};

#endif