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

	void collide(Object* o){
		std::cout<<"collideWall"<<std::endl;

	}



	Wall(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Tile(nameObject,initPos) {
		std::cout<<"Wall_Constructor"<<std::endl;

		TILE_SIZE=48;
		int t = static_cast<int>(_typeWall);
		switch(t){
			case 0:
			std::cout<<"case 0"<<std::endl;
			_sprite->setTextureRect(sf::IntRect( 243, 1880, 48, 96));
			break;
			case 1:
			std::cout<<"case 1"<<std::endl;
			_sprite->setTextureRect(sf::IntRect( 192, 1920, 48, 48));
			break;
			/*case 2:
			_sprite->setTextureRect(sf::IntRect( 192, 1920, 48, 48));
			break;
			case 3:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 4:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 5:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 6:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 7:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 8:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 9:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;
			case 10:
			_sprite->setTextureRect(sf::IntRect( 2*t*48+2+48, 13 * 48+ 6, 48, 48));
			break;*/
		}

	}
};
#endif