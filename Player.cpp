#include "Player.hpp"


int Player::_keys = 0;


Player::Player(string nameObject, sf::Vector2f initPos, string nameProjectile): 
Character(nameObject,initPos), _projectile(*(new Arrow(nameProjectile,initPos,*this))) {
	_speed = 10;
	_hitAnim = 0;
	_damageAttack = 3;
	_isInTheCave = false;
	_canOpenChest = true;

	_isAlive = true;

	initWeapon();

	// if(getName()=="PlayerTextures/player2.png")
	//     _projectile = Arrow("OtherTextures/fate.png",initPos,*this);
	
	_orientation = Down;

	_life.setBelongTo(getName());
	_life.initPlayerLife();

	cout << "loading sounds..." << endl;
	_takeDamageMusic = SoundsLib::assignSound("Sounds/hurt_knight.wav");
	_footStepSound = SoundsLib::assignSound("Sounds/Steps_wood-015.ogg");	
}


Player& Player::operator=(const Player& other) {
    Character::operator=(other);

    _isInTheCave = other._isInTheCave;

    _projectile = other._projectile;

    _hitAnim = other._hitAnim;

    initWeapon();

	return *this;
}


Player::~Player() {
    _bowAttack->stop();
    _wandAttack->stop();
};


void Player::takeDamage(int NOQ) {
	cout << "Entering takeDamage()" << endl;

	if (_takeDamageMusic == nullptr)
		cout << "no _takeDamageMusic" << endl;
		
	_takeDamageMusic->setVolume(75);

	cout << "Playing sounds..." << endl;

	_takeDamageMusic->stop();
	_takeDamageMusic->play();

	cout << "Removing heart quarters..." << endl;

	if(0 < NOQ <= _life.getNumberOfQuarter())
		for (int i = 0; i < NOQ; i++)
			_life.removeLife();
		
	cout << "Checking if dead..." << endl;

	if(_life.getNumberOfQuarter() <= 0)
		_isAlive=false;

	cout << "Exiting takeDamage()" << endl;
}


void Player::openChest(Chest& chest) {
	if (!chest.isOpen()) {
		int prise = chest.open();

		for (int i = 0; i < prise; i++) {
			_life.addLife();
		}
	}
}


void Player::makeDamage(Character& target){
	target.takeDamage(_damageAttack);
}


void Player::attack(Character& target){
	makeDamage(target);
}


bool Player::WeaponIsUsed(){
	return ( _bowAnim!=0 || _wandAnim!=0);
}


void Player::useBow(){
	if (_bowAnim>=1) {
		if(_bowAnim==3 && !_projectile.isShot()){
			_bowAttack->setVolume(30);
			_bowAttack->stop();
			_bowAttack->play();
			_projectile.setDirection(_orientation);
			_projectile.setIsShot(true);
			_projectile.initProjectile();
			_sprite.setTextureRect(sf::IntRect(9*_object_size, _anim.y*_object_size, _object_size, _object_size));
			_bowAnim=0;
		} else if (_bowAnim<3) { _bowAnim++; }
	} else if(_bowAnim==0){
		_sprite.setTextureRect(sf::IntRect(8*_object_size, _anim.y*_object_size, _object_size, _object_size));
		_bowAnim++;
	}
}


void Player::useWand(){
	if(_wandAnim>=1){
		if(_wandAnim==3 && !_projectile.isShot()){
			_wandAttack->setVolume(30);
			_wandAttack->stop();
			_wandAttack->play();
			_projectile.setDirection(_orientation);
			_projectile.setIsShot(true);
			_projectile.initProjectile();
			_sprite.setTextureRect(sf::IntRect(14*_object_size, _anim.y*_object_size, _object_size, _object_size));
			_wandAnim=0;
		} else if (_wandAnim<3) { _wandAnim++; }
	}else if (_wandAnim==0) {
        _sprite.setTextureRect(sf::IntRect(13*_object_size, _anim.y*_object_size, _object_size, _object_size));
        _wandAnim++;
	}
}


void Player::initWeapon(){
	_swordAnim = 0;
	_bowAnim = 0;
	_wandAnim = 0;

	_bowAttack = SoundsLib::assignSound("Sounds/Retro Weapon Arrow 02.wav");
	_wandAttack = SoundsLib::assignSound("Sounds/Retro Weapon Electric 05.wav");
}


void Player::collide(Object& o) {
	cout << "Player collide" << endl;
}


void Player::targetInRange(std::vector<Monster*>& targetList,std::vector<int> indiceToKill){
	float _x1=getPosition().x;
	float _y1=getPosition().y;

	for(int i=0;i<targetList.size();i++){
		float _x2 = targetList[i]->getPosition().x;
		float _y2 = targetList[i]->getPosition().y;
		float distance = sqrt(pow(_x2 - _x1, 2) + pow(_y2 - _y1, 2));

		if(distance<96){
			indiceToKill.push_back(i);
		}		
	}
}


void Player::isInTheCave(bool state){
		_isInTheCave=state;
	}

bool Player::getIsInTheCave(){
	return _isInTheCave;
}

bool Player::bowIsUsed(){
	return _bowAnim!=0;
}
bool Player::wandIsUsed(){
	return _wandAnim!=0;
}
	
Projectile* Player::getProjectile(){
	return &_projectile;
}



sf::Sprite& Player::deadGestion(){
    _sprite.setTextureRect(sf::IntRect(704,64,32,32));
    _sprite.setPosition(getPosition().x,getPosition().y);
    return _sprite;
}


int Player::getHitAnim(){
	return _hitAnim;
}

void Player::incrHitAnim(){
	_hitAnim++;
}

void Player::setHitAnim(int nbAnim){
	_hitAnim=nbAnim;
}