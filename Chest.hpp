#ifndef CHEST_HPP
#define CHEST_HPP


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"
#include "Gain.hpp"
#include "TexturesLib.hpp"

class Chest {

private:
    
    int CHEST_SIZE;
    sf::Sprite* _sprite;
    bool _isOpen;
    Gain* _gain;
    sf::Vector2i chestAnim;

public:

    Chest();
    ~Chest();
  
int open(){
	chestAnim.y = 3;
	_sprite->setTextureRect(sf::IntRect(chestAnim.x * CHEST_SIZE , chestAnim.y * CHEST_SIZE, CHEST_SIZE, CHEST_SIZE));
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
    
};
#endif