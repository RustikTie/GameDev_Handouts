#ifndef __TEXT_H__
#define __TEXT_H__

#include "Element.h"
#include "j1Fonts.h"

class Text : public Element
{
public:
	Text();
	~Text();
private:

	_TTF_Font* letter = nullptr;
	p2SString text;

};

#endif // !__TEXT_H__
