#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "Element.h"

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

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	for (int i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (elements[i]->type == ElementType::IMAGE)
		{
			App->render->Blit(atlas, elements[i]->rect.x, elements[0]->rect.y, &elements[0]->rect, NULL);
		}
	}
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
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
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

Element* j1Gui::CreateElement(ElementType type, int x, int y, int height, int width)
{
	Element* new_element = new Element;
	new_element[0].type = type;
	new_element[0].rect.x = x;
	new_element[0].rect.y = y;
	new_element[0].rect.w = width;
	new_element[0].rect.h = height;

	elements.add(new_element);

	return new_element;
}
void j1Gui::DeleteElement(Element* elem)
{

}
void j1Gui::BlitElements(Element* elem)
{

}