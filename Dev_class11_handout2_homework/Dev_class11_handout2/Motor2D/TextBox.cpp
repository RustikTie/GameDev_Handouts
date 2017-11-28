#include "TextBox.h"



TextBox::TextBox(int x, int y, ElementType type, SDL_Rect rec, const char* text) : Element (x,y,type)
{
	this->rec = rec;
	this->text = text;
}


TextBox::~TextBox()
{
}

void TextBox::InsertLetter(char letter, p2SString* text)
{

}
void TextBox::DeleteLetter(p2SString* text)
{

}

void TextBox::OnClick()
{

}
void TextBox::Draw()
{

}
