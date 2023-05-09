#include "Character.hpp"

Character::Character(): Object(nameObject, initPos) {
	anim.x = 1;
	anim.y = Down;
	life = new Heart();
	_isAlive = true;
}

Character::~Character() {
	delete life;
}

void Character::takeDamage(int NOQ) {
	if (NOQ < 0) {
		return;
	}
	else if (NOQ >= 12) {
		_isAlive = false;
	}
	else {
		for (int i = 0; i < NOQ; i++) {
			life->removeLife();
		}
	}
}