#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "Element.h"
#include "Text.h"
#include "Image.h"
#include "Background.h"
#include "Button.h"
#include "TextBox.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");


	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());
	background = App->tex->Load("gui/login_background.png");
	WoWLogo = App->tex->Load("gui/Glues-Logo.png");
	BlizzLogo = App->tex->Load("gui/Glues-BlizzardLogo.png");

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{


	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	p2List_item<Element*>* list;

	for (list = elements.start; list; list = list->next)
	{
		list->data->Draw();
	}

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");
	p2List_item<Element*>* item;
	item = elements.start;
	while (item != NULL)
	{
		RELEASE(item->data);
		item = item->next;
	}

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}
SDL_Texture* j1Gui::GetBackground() const
{
	return background;
}

// class Gui ---------------------------------------------------

Element* j1Gui::CreateImage(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex)
{
	Element* new_element;
	new_element = new Image(x, y, type, rec, tex);

	elements.add(new_element);

	return new_element;
}

Element* j1Gui::CreateText(int x, int y, ElementType type, const char* text)
{
	Element* new_element;
	new_element = new Text(x, y, type, text);

	elements.add(new_element);

	return new_element;
}

Element* j1Gui::CreateBackground(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex)
{
	Element* new_element;
	new_element = new Background(x, y, type, rec, tex);

	elements.add(new_element);

	return new_element;
}
void j1Gui::DeleteElement(Element* elem)
{

}
void j1Gui::BlitElements(Element* elem)
{

}