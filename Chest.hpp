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
class Gain;
class Player;

class Chest : public Tile{

private:
    
    int CHEST_SIZE = 35;
    bool _isOpen;
    Gain* _gain;
    sf::Vector2i* chestAnim;

public:

Chest(const char* nameObject, sf::Vector2f initPos) : Tile(nameObject,initPos),  _isOpen(false) {
    chestAnim = new sf::Vector2i();
    _gain=new Gain("gain.png",{getPosition().x+48,getPosition().y+48});
	chestAnim->x = 0;
	chestAnim->y = 1;
	_sprite->setTextureRect(sf::IntRect(chestAnim->x * CHEST_SIZE , chestAnim->y* CHEST_SIZE , CHEST_SIZE, CHEST_SIZE));
}
~Chest() {
	delete _gain;
    delete chestAnim; 
}
  
int open();


sf::Sprite* getSpriteChest() {
        return _sprite;
}

sf::Vector2f getPosition() {
        return _sprite->getPosition();
}

    bool isOpen() {
        return _isOpen;
    }
    
    void collide(Object* o);
    
    const int getBlockSize(){
		return CHEST_SIZE;
	}

    Gain* getGain(){
        return _gain;
    }
};
#endif