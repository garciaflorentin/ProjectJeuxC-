#include "Player.hpp"


void Player::openChest(Chest* chest) {
	if (!chest->isOpen()) {
		int gain= chest->open();	//pas besoin de player pour retourner un int 
		for (int i = 0; i < gain; i++) {
			_life->addLife();
		}
	}
}



void Player::setDamage(Character* target){
	target->takeDamage(_damageAttack);

}

void Player::attack(Character* target){
	setDamage(target);
}

void Player::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}