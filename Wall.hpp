#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "TypeWall.hpp"


class Wall: public Tile {

private:

//sf::Music* collideMusic;

public:


	const int getBlockSize(){
		return TILE_SIZE;
	}

	void collide(Object* o){
		//std::cout<<"wall"<<std::endl;
		//collideMusic->stop();
		//collideMusic->play();
	}

	~Wall(){
		//delete collideMusic;
	}

	Wall(const char* nameObject, sf::Vector2f initPos, TypeWall _typeWall) : Tile(nameObject,initPos) {

	//collideMusic=new sf::Music;

	/*if (!collideMusic->openFromFile("musicCollideWall.wav"))
    {
        std::cout<<"erreur de chargement de collideMusic"<<std::endl;
    }*/
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
			case 2:
			_sprite->setTextureRect(sf::IntRect( 338, 1882, 48, 48));
			break;
			case 3:
			_sprite->setTextureRect(sf::IntRect(  2, 50, 96, 96));
			break;
			case 4:
			_sprite->setTextureRect(sf::IntRect( 386, 1594, 48, 96));
			break;
			case 5:
			_sprite->setTextureRect(sf::IntRect( 338, 1930, 48, 48));
			break;
			case 6:
			_sprite->setTextureRect(sf::IntRect( 626, 1498, 48, 96));
			break;
			case 7:
			_sprite->setTextureRect(sf::IntRect( 772, 1498, 48, 48));
			break;
			case 8:
			_sprite->setTextureRect(sf::IntRect(772, 1450, 48, 48));
			break;
			case 9:
			_sprite->setTextureRect(sf::IntRect( 2, 1434, 48, 48));
			break;
			case 10:
			_sprite->setTextureRect(sf::IntRect( 578, 1354, 48, 48));
			break;
			case 11:
			_sprite->setTextureRect(sf::IntRect( 576, 1594, 48, 96));
			break;
			case 12:
			_sprite->setTextureRect(sf::IntRect(  2, 482, 96, 96));
			break;
			case 13:
			_sprite->setTextureRect(sf::IntRect( 242, 1786, 48, 48));
			break;
			case 14:
			_sprite->setTextureRect(sf::IntRect( 146, 1786, 48, 48));
			break;
			case 15:
			_sprite->setTextureRect(sf::IntRect( 772, 1834, 48, 96));
			break;
			case 16:
			_sprite->setTextureRect(sf::IntRect( 51, 1786, 48, 48));
			break;
			
		}

	}
};
#endif