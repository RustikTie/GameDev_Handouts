#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "j1Gui.h"
#include "p2Point.h"

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
