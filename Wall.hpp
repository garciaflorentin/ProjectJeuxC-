#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "TypeWall.hpp"

class Wall: public Tile {

public:

	const int getBlockSize(){
		return TILE_SIZE;
	}

	Wall(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Tile(nameObject,initPos) {
		std::cout<<"Ground_Constructor"<<std::endl;

		TILE_SIZE=64;
		passable = true;
		int t = static_cast<int>(_typeWall);
		_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));

	}
};
#endif