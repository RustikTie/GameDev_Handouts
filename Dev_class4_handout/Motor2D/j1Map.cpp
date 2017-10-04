#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());
	
	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		fill_map(map_file);
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

void j1Map::fill_map(pugi::xml_document &_map_file){

	pugi::xml_node file = _map_file.first_child();

	map.map_version = file.child("map").attribute("version").as_double();
	
	if (file.child("map").attribute("orientation").as_string() == "orthogonal") 
		map._orientation = orthogonal;
	
	if (file.child("map").attribute("orientation").as_string() == "isometric") 
		map._orientation = isometric;
	
	if (file.child("map").attribute("orientation").as_string() == "staggered") 
		map._orientation = staggered;
	
	if (file.child("map").attribute("orientation").as_string() == "hexagonal") 
		map._orientation = hexagonal;
	
	if (file.child("map").attribute("renderorder").as_string() == "right_down") 
		map._renderorder = right_down;
	
	if (file.child("map").attribute("renderorder").as_string() == "right_up")
		map._renderorder = right_up;

	if (file.child("map").attribute("renderorder").as_string() == "left_down")
		map._renderorder = left_down;

	if (file.child("map").attribute("renderorder").as_string() == "left_up")
		map._renderorder = left_up;

	map.width = file.child("map").attribute("width").as_uint();
	map.height = file.child("map").attribute("height").as_uint();
	map.tilewidth = file.child("map").attribute("tilewidth").as_uint();
	map.tileheight = file.child("map").attribute("tileheight").as_uint();
	map.nextobjectid = file.child("map").attribute("nextobjectid").as_int();

}

