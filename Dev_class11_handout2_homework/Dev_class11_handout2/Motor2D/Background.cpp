#include "Background.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Gui.h"


Background::Background(int x, int y, ElementType type, SDL_Rect rec, SDL_Texture* tex) : Element(x,y,type)
{
	this->rec = rec;
	this->tex = tex;
}


Background::~Background()
{
}

void Background::Draw()
{

	App->render->Blit(App->gui->GetBackground(), pos.x, pos.y, &rec);

}
