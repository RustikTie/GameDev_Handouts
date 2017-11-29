#include "Button.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Gui.h"


Button::Button(int x, int y, ElementType type, SDL_Rect rec, const char* text, SDL_Texture* tex): Element(x,y,type)
{
	this->rec = rec;
	this->text = text;
	this->tex = tex;
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

