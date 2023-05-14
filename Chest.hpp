#ifndef CHEST_HPP
#define CHEST_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Gain.hpp"
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Character.hpp"

class Player;

class Chest : public Tile{

private:
    
    int CHEST_SIZE = 37;
    bool _isOpen;
    Gain* _gain;
    sf::Vector2i chestAnim;

public:

Chest(const char* nameObject, sf::Vector2f initPos) : Tile(nameObject,initPos),  _isOpen(false) {
	chestAnim.x = 0;
	chestAnim.y = 1;
	_sprite->setTextureRect(sf::IntRect(chestAnim.x * CHEST_SIZE , chestAnim.y* CHEST_SIZE , CHEST_SIZE, CHEST_SIZE));
}
~Chest() {
	delete _gain;
}
  
int open(){
	chestAnim.x = 1;
	_sprite->setTextureRect(sf::IntRect(chestAnim.x * CHEST_SIZE , chestAnim.y * CHEST_SIZE, CHEST_SIZE, CHEST_SIZE));
    _isOpen=true;
	return _gain->getGain();
}

    sf::Sprite* getSpriteChest() {
        return _sprite;
    }

    sf::Vector2f getPosition() {
        return _sprite->getPosition();
    }

    bool isOpen() {
        return _isOpen;
    }
    
    void collide(Player* p);
    void collide(Object* o){}

    
    const int getBlockSize(){
		return CHEST_SIZE;
	}
};
#endif