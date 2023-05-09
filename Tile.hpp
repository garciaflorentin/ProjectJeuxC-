#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"

class Tile: public Object {

protected:
	bool passable;
public:

	Tile() : Object(){}

};
#endif
