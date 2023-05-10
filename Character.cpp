#include "Character.hpp"

Character::Character(): Object() {	//sans arguments pour l'instant
	anim.x = 1;
	anim.y = Down;
	life = new Heart();
	_isAlive = true;
}

Character::~Character() {
	delete[] life;	//des crochets oublies
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

void Character::moveTo(sf::Vector2f nextPos) {	//redefinition d'une methode virtuelle pure 
	_sprite->setPosition(nextPos);				//a revoir si elle est a declarer dans Objet
}