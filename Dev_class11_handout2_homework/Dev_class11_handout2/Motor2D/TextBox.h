#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Element.h"
#include "j1Fonts.h"


class TextBox : public Element
{
public:
	TextBox();
	~TextBox();

	void InsertLetter(char letter, p2SString* text);
	void DeleteLetter(p2SString* text);
	void OnClick();

private: 
	bool isClicked = false;
	_TTF_Font* letters = nullptr;
	p2SString text;
};

#endif