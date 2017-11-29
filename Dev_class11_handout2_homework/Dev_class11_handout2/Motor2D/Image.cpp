#include "Image.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Gui.h"


Image::Image(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex) : Element(x, y,type)
{
	this->rec = rec;
	this->tex = tex;
}


Image::~Image()
{
}

void Image::Draw()
{
	App->render->Blit(tex, pos.x, pos.y, &rec);

}
