#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
enum tile_name {BRICK, COBBLE, DIRT, DESERT};
struct tileset {
	int firstgid;
	tile_name name;
	uint tilewidth;
	uint tileheight;
	uint spacing;
	int margin;
	p2SString image_source;
	uint width;
	uint height;
};


// ----------------------------------------------------

enum orientation {ORTHOGONAL, ISOMETRIC, STAGGERED, HEXAGONAL };
enum renderorder {RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};
// TODO 1: Create a struct needed to hold the information to Map node
struct map_data {
	float map_version;
	orientation _orientation;
	renderorder _renderorder;
	uint width;
	uint height;
	uint tilewidth;
	uint tileheight;
	int nextobjectid;
};


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* file_name	);

private:


public:

	// TODO 1: Add your struct for map info as public for now
	map_data hello;
	tileset tile;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
	void fill_map(pugi::xml_node &node);
};

#endif // __j1MAP_H__