#include "Character.hpp"

Character::Character(): Object() {	//sans arguments pour l'instant
	_anim->x = 1;
	_anim->y = Down;
	_life = new Heart();
	_isAlive = true;
}

Character::Character(const char* nameObject, sf::Vector2f initPos): Object(nameObject, initPos) {
		std::cout<<"character_constructeur"<< std::endl;

		_anim = new sf::Vector2i;
cout << "ici" << endl;
		_anim->x = 1;
		
		_anim->y = Down;
		
		_life = new Heart();
		_isAlive = true;
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
			_life->removeLife();
		}
	}
}

void Character::setUpCharacter(){
	_anim->x=1;
	_anim->y=Down;
	_sprite->setTextureRect(sf::IntRect(_anim->x * OBJECT_SIZE + 3, _anim->y * OBJECT_SIZE + 3, OBJECT_SIZE, OBJECT_SIZE));
}


const int Character::getBlockSize(){
	return OBJECT_SIZE;
}

void Character::setAnim(int x ,int y){
	_anim->x = x;
	_anim->y = y;
}

void Character::updateSprite(){
	if(_anim->x*OBJECT_SIZE >= OBJECT_SIZE*3){_anim->x=0;}
	_sprite->setTextureRect(sf::IntRect(_anim->x*OBJECT_SIZE + 3, _anim->y*OBJECT_SIZE + 3, OBJECT_SIZE, OBJECT_SIZE));
}

void Character::move(sf::Vector2f nextPos) {	//redefinition d'une methode virtuelle pure 
	_sprite->setPosition(nextPos);				//a revoir si elle est a declarer dans Objet
}