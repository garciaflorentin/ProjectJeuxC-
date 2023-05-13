#include "Player.hpp"


void Player::openChest(Chest* chest) {
	if (!chest->isOpen()) {
		int gain= chest->open();
		for (int i = 0; i < gain; i++) {
			life->addLife();
		}
	}
}

void Player::setDamage(Character* target){
	target->takeDamage(damageAttack);

}

void Player::attack(Character* target){
	setDamage(target);
}

void Player::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}


