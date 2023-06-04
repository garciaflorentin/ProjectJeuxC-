#include "Character.hpp"


Character::Character(string nameObject, sf::Vector2f initPos): 
Object(nameObject, initPos), _life(*(new Heart(nameObject))) {
	//_life.setBelongTo(nameObject);

	_anim.x = 1;
	_anim.y = 0;
	_object_size = 32;
	//_keys = 0;

	_isAlive = true;

	_damageAttack = DEFAULT_DMG;
	_speed = DEFAULT_SPEED;

	_orientation = 0;

	_clock = sf::Clock();
}


Character& Character::operator=(const Character& other) {
    Object::operator=(other);

    _damageAttack = other._damageAttack;
    _speed = other._speed;

    _isAlive = true;

    _object_size = other._object_size;
    _orientation = other._orientation;

    //_keys = 0;
    _killedallMobs = { false, false, false, false };

	_footStepSound = other._footStepSound;
	_takeDamageMusic = other._takeDamageMusic; 

	_clock = sf::Clock();

    _anim = other._anim;
    _life = other._life;

	_canOpenChest = other._canOpenChest;

	return *this;
}


Character::~Character() {
    _footStepSound->stop();
    _takeDamageMusic->stop();
}


void Character::takeDamage(int NOQ) {
	if (_takeDamageMusic == nullptr)
		cout << "no _takeDamageMusic" << endl;
		
	_takeDamageMusic->setVolume(75);
	_takeDamageMusic->stop();
	_takeDamageMusic->play();

	if(0<NOQ <= _life.getNumberOfQuarter()){
	for (int i = 0; i < NOQ; i++)
		_life.removeLife();
	}

	if(_life.getNumberOfQuarter() <= 0)
		_isAlive=false;
}


void Character::setUpCharacter(){
	_anim.x = 1;
	_anim.y = 0;
	_sprite.setTextureRect(sf::IntRect(_anim.x * _object_size , _anim.y * _object_size , _object_size, _object_size));
	_sprite.scale(1.5,1.5);
}


const int Character::getBlockSize() const {
	return _object_size;
}


void Character::setAnim(int x ,int y){
	_anim.x = x;
	_anim.y = y;
}


void Character::updateSprite() {
	if(_anim.x*_object_size >= _object_size*4)  _anim.x=1;
	_sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}


void Character::move(sf::Vector2f deplacement){
	_sprite.move(deplacement.x,deplacement.y);
}


void Character::updateKilledallMobs(std::vector<bool>& _killedallMobs){
	_killedallMobs=_killedallMobs;
}

std::vector<bool>& Character::getKilledallMobs(){
	return _killedallMobs;
}

const float Character::getSpeed() const {
	return _speed;
}

void Character::setSpeed(double speed){
	_speed = speed;
}

const int Character::getOrientation() const{
	return _orientation;
}

void Character::setOrientation(int orientation){
	_orientation = orientation;
}

const bool Character::isAlive() const{
	return _isAlive;
}

sf::Vector2i& Character::getAnim() {
	return _anim;
}

Heart& Character::getlife() const {
	return _life;
}

const bool Character::canOpenChest() const { return _canOpenChest; };

// const int Character::getKey() const {
// 	return _keys;
// }

// void Character::addKey(){
// 	if(_keys<4)	_keys++;
// }

// void Character::setKey(int nbKey){
// 	_keys = nbKey;
// }