#include "Player.hpp"

Player::Player(): Character() {

	speed = 3;
	damageAttack = 3;
	_sword = new Sword();

}

Player::~Player() {
	delete _sword;
}

void Player::openChest(Chest* chest) {
	if (!chest->isOpen()) {
		int gain= chest->open(this);
		for (int i = 0; i < gain; i++) {
			life->addLife();
		}
	}
}