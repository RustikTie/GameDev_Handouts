#include "Image.h"



Image::Image(int x, int y, ElementType type, SDL_Rect rec) : Element(x, y,type)
{
	this->rec = rec;
}


Image::~Image()
{
}

void Image::Draw()
{

}
