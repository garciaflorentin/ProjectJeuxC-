#include "Character.hpp"


Character::Character(const char* nameObject, sf::Vector2f initPos): Object(nameObject, initPos) {
	anim = new sf::Vector2i; // probleme du segmentation fault
	anim->x = 1;
	anim->y = 0;
	OBJECT_SIZE= 32;
	key=0;
	//_sprite->setTextureRect(sf::IntRect(anim->x * OBJECT_SIZE , anim->y * OBJECT_SIZE , OBJECT_SIZE, OBJECT_SIZE));
	//_sprite->scale(1.5,1.5);

	life = new Heart();

	_isAlive = true;
	

}

Character::~Character() {
	footStepSound.stop();
	takeDamageMusic.stop();
	delete life;
	delete anim;
}

void Character::takeDamage(int NOQ) {
	std::cout<<"Character::takeDamage"<<std::endl;
	//takeDamageMusic->setVolume(75);
	//takeDamageMusic->stop();
	//takeDamageMusic->play();
	if(0<NOQ<=life->getNumberOfQuarter()){
	for (int i = 0; i < NOQ; i++) {
			life->removeLife();
		}
	}
	if(life->getNumberOfQuarter()<=0){
		_isAlive=false;
	}
	cout << "Exiting takeDamage()" << endl;
	
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

void Character::move(sf::Vector2f deplacement){
	_sprite->move(deplacement.x,deplacement.y);
	/*int x = static_cast<int>(getPosition().x);
	int y = static_cast<int>(getPosition().y);

	if (x%6==0 || y%7==0)
                {
                   footStepSound->setVolume(40);
				   footStepSound->stop();
	            	footStepSound->play();
                }*/
}



void Character::updateKilledallMobs(std::vector<bool>& _killedallMobs){
		killedallMobs=_killedallMobs;
	}

std::vector<bool>& Character::getKilledallMobs(){
		return killedallMobs;
	}

double Character::getSpeed(){
		return speed;
	}

void Character::setSpeed(double _speed){
		speed=_speed;
	}

int Character::getOrientation(){
		return orientation;
	}

	void Character::setOrientation(int _orientation){
		orientation=_orientation;
	}

	const bool Character::isAlive() const{
		return _isAlive;
	}

		sf::Vector2i* Character::getAnim(){
		return anim;
	}

	Heart* Character::getlife() const {
		return life;
	}

	bool Character::canOpenChest() const { return _canOpenChest; };

	int Character::getKey(){
		return key;
	}

	void Character::addKey(){
		if(key<4){
			key++;
		}
	}

    void Character::setKey(int nbKey){
		key=nbKey;
	}
