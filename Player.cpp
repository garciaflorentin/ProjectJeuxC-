#include "Player.hpp"

Player::Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject, initPos) {	//faut la definition precise, un constructeur par defaut a rejouter

	speed = 3;
	damageAttack = 3;
	_sword = new Sword();

}

Player::~Player() {
	delete _sword;
}

void Player::openChest(Chest* chest) {
	if (!chest->isOpen()) {
		int gain= chest->open();	//pas besoin de player pour retourner un int 
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


