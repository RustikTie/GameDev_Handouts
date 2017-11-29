#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "Element.h"

class Image : public Element
{
public:
	Image(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex);
	~Image();
	void Draw();

private:
	SDL_Rect rec;
	SDL_Texture* tex;

};

#endif // !__IMAGE_H__
