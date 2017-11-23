#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Element.h"
#include "j1Fonts.h"
#include "p2SString.h"

class Button : public Element
{
public:
	Button();
	~Button();

	void OnClick();

private: 
	bool isClicked = false;
	_TTF_Font* font = nullptr;
	p2SString text;
	
};

#endif // !__BUTTON_H__
