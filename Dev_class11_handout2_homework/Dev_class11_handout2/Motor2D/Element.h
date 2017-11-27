#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"
#include "j1Gui.h"



class Element : public j1Gui
{
public:
	Element();
	~Element();
	
public:

	SDL_Rect rect;
	iPoint pos;
	ElementType type;

};

#endif // !__ELEMENT_H__
