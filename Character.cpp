#include "Character.hpp"


Character::Character(const char* nameObject, sf::Vector2f initPos): Object(nameObject, initPos) {
	anim = new sf::Vector2i; // probleme du segmentation fault
	anim->x = 1;
	anim->y = 0;
	//_sprite->setTextureRect(sf::IntRect(anim->x * OBJECT_SIZE , anim->y * OBJECT_SIZE , OBJECT_SIZE, OBJECT_SIZE));
	//_sprite->scale(1.5,1.5);

	life = new Heart();

	_isAlive = true;
}

Character::~Character() {
	delete[] life;
}

void Character::takeDamage(int NOQ) {
	cout << "Starting takeDamage()" << endl;
	if (NOQ < 0) {
		return;
	}
	else if (NOQ >= 12) {
		_isAlive = false;
	}
	else {
		for (int i = 0; i < NOQ; i++) {
			cout << "calling removeLife()" << endl;
			life->removeLife();
		}
	}
}

void Character::setUpCharacter(){
anim->x = 1;
	anim->y = 0;
	_sprite->setTextureRect(sf::IntRect(anim->x * OBJECT_SIZE , anim->y * OBJECT_SIZE , OBJECT_SIZE, OBJECT_SIZE));
	_sprite->scale(1.5,1.5);

}

const int Character::getBlockSize(){
	return OBJECT_SIZE;
}

void Character::setAnim(int x ,int y){
	anim->x = x;
	anim->y = y;
}

void Character::updateSprite(){
	if(anim->x*OBJECT_SIZE >= OBJECT_SIZE*4){anim->x=1;}
	_sprite->setTextureRect(sf::IntRect(anim->x*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));

}

void Character::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}

