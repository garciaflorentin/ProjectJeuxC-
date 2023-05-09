#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"
#include "Tile.hpp"

class Wall: public Tile {

public:

	Wall() : Tile() {

		passable = false;
	}

};
#endif