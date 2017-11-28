#include "Background.h"



Background::Background(int x, int y, ElementType type, SDL_Rect rec) : Element(x,y,type)
{
	this->rec = rec;
}


Background::~Background()
{
}

void Background::Draw()
{


}
