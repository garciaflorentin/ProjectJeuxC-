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

	const int getBlockSize(){
		return TILE_SIZE;
	}

	void collide(Object* o){}


	Ground(const char* nameObject, sf::Vector2f initPos, TypeGround _typeGround) : Tile(nameObject,initPos) {

		TILE_SIZE=48;
		
		int t = static_cast<int>(_typeGround);
		if(t<9){
		_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 14 * 48+ 6, 48, 48));
		}
		else{
			switch(t){
				case 9:
				_sprite->setTextureRect(sf::IntRect( 698, 1181, 48, 48));
				break;
			}
		}

	}




};
#endif