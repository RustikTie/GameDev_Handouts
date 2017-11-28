#include "Button.h"



Button::Button(int x, int y, ElementType type, SDL_Rect rec, const char* text): Element(x,y,type)
{
	this->rec = rec;
	this->text = text;
}


Button::~Button()
{
	
}

void Button::OnClick()
{

}

void Button::Draw()
{

}

