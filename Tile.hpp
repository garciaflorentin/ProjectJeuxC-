#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Object.hpp"

class Tile: public Object {

protected:
	
	int TILE_SIZE = 48;
public:


	Tile(const char* nameObject, sf::Vector2f initPos) : Object(nameObject,initPos){
		std::cout<<"Tile_Constructor"<<std::endl;
		
	}

};
#endif
