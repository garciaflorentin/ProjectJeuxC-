#include "Player.hpp"

Player::Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject,initPos) {
	std::cout<<"player_constructeur"<< std::endl;
	speed = 3;
	damageAttack = 3;
	//_sword = new Sword();

}

void Player::openChest(Chest* chest) {
	std::cout<<"openChest"<<std::endl;
	if (!chest->isOpen()) {
		std::cout<<"coffrePasOuvert"<<std::endl;
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


