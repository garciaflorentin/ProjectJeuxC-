#include "Character.hpp"




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

void Character::setUpCharacter(){
	anim->x=1;
	anim->y=Down;
	_sprite->setTextureRect(sf::IntRect(anim->x * OBJECT_SIZE + 3, anim->y * OBJECT_SIZE + 3, OBJECT_SIZE, OBJECT_SIZE));
		//a modifier playerVector.push_back(player);

}

const int Character::getBlockSize(){
	return OBJECT_SIZE;
}

void Character::setAnim(int x ,int y){
	anim->x = x;
	anim->y = y;
}

void Character::updateSprite(){
	if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*3){anim->x=0;}
	_sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE + 3, anim->y*OBJECT_SIZE + 3, OBJECT_SIZE, OBJECT_SIZE));
}
