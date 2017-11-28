#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Element.h"
#include "j1Fonts.h"
#include "p2SString.h"

class Button : public Element
{
public:
	Button(int x, int y, ElementType type, SDL_Rect rec, const char* text);
	~Button();

	void OnClick();
	void Draw();

private: 
	
	bool isClicked = false;
	SDL_Rect rec;
	const char* text;
};

#endif // !__BUTTON_H__
