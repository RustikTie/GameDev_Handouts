#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "j1Fonts.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes
class Element;
struct SDL_Texture;

enum ElementType
{
	FONT,
	IMAGE,
	BUTTON,
	TEXT_BOX,
	BACKGROUND,
	NO_TYPE,
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
	Element* CreateImage(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex);
	Element* CreateText(int x, int y, ElementType type, const char* text);
	Element* CreateBackground(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex);
	Element* CreateButton(int x, int y, ElementType type, SDL_Rect rec, const char* text, SDL_Texture* tex, _TTF_Font* font);

	void DeleteElement(Element* elem);
	void BlitElements(Element* elem);

	SDL_Texture* GetAtlas() const;
	SDL_Texture* GetBackground() const;
	SDL_Texture* WoWLogo = nullptr;
	_TTF_Font* firstFont = nullptr;
	SDL_Texture* RedButton = nullptr;

private:

	SDL_Texture* atlas = nullptr; 
	SDL_Texture* background = nullptr;
	SDL_Texture* BlizzLogo = nullptr;
	p2SString atlas_file_name;
	p2List<Element*> elements;


};

#endif // __j1GUI_H__