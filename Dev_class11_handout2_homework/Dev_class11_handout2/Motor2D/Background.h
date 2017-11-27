#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "Element.h"

struct Animation;

class Background : public Element
{
public:
	Background();
	~Background();

public:
	bool isAnimated = false;
	Animation* animation = nullptr;
};

#endif // !__BACKGROUND_H__
