#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"

class Tile: public Object {

protected:
	bool _passable;
	int TILE_SIZE;
public:
	Tile();
	Tile(const char* nameObject, sf::Vector2f initPos) : Object(nameObject,initPos){
		std::cout<<"Tile_Constructor"<<std::endl;
	}
};
#endif
