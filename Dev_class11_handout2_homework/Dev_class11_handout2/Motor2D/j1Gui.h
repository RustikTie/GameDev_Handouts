#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "Element.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

enum ElementType
{
	FONT,
	IMAGE,
	BUTTON,
	TEXT_BOX,
	BACKGROUND,
};
// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	void CreateElement(ElementType type, int x, int y, int height, int width);
	void DeleteElement(Element* elem);
	void BlitElements(Element* elem);
	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2List<Element*> elements;


};

#endif // __j1GUI_H__