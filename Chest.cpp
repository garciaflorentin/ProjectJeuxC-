#include "Chest.hpp"

Chest::Chest(): _isOpen(false) {
	CHEST_SIZE = 48;
	_gain = new Gain();
	_sprite = new sf::Sprite();
	_sprite->setTexture(*TexturesLib::assignTexture("chest.png"));
	chestAnim.x = 1;
	chestAnim.y = 0;
	_sprite->setTextureRect(sf::IntRect(chestAnim.x * CHEST_SIZE , chestAnim.y* CHEST_SIZE , CHEST_SIZE, CHEST_SIZE));
}
Chest::~Chest() {
	delete _gain;
}



