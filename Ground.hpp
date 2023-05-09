#ifndef _GROUND_H_
#define _GROUND_H_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "Tile.hpp"
#include "TypeGround.hpp"

class Ground: public Tile {

	protected:



public:

	Ground(const char* nameObject, sf::Vector2f initPos, TypeGround _typeGround) : Tile(nameObject,initPos) {

		passable = true;
		int t = static_cast<int>(_typeGround);
		_sprite->setTextureRect(sf::IntRect(t * 64+ 3, t * 96+ 3, 64, 64));

	}


};
#endif