#ifndef _GROUND_H_
#define _GROUND_H_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "Tile.hpp"

class Ground: public Tile {

public:

	Ground() : Tile() {

		passable = true;

	}
};
#endif