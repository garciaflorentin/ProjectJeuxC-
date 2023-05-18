#include "Player.hpp"

Player::Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject,initPos) {
	speed = 3;
	damageAttack = 3;
	initWeapon();
	projectile = new Projectile("arrow.png",initPos,this);
	orientation= Down;
}

Player::~Player() {
		delete SwordAttack;
		delete bowAttack;
		delete wandAttack;
		//delete projectile;
	};

void Player::openChest(Chest* chest) {


	if (!chest->isOpen()) {
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

bool Player::WeaponIsUsed(){
		return ( bowAnim!=0 || swordAnim!=0 || wandAnim!=0);
	}

void Player::useSword(){
	if(swordAnim>=1){

		if(swordAnim==10){
			SwordAttack->stop();
			SwordAttack->play();
			_sprite->setTextureRect(sf::IntRect(6*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
			swordAnim=0;
		}else if(swordAnim<10){swordAnim++;}

	}else if(swordAnim==0){
	_sprite->setTextureRect(sf::IntRect(5*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
	swordAnim++;
	}


}


void Player::useBow(){
	if(bowAnim>=1){

		if(bowAnim==20 && !projectile->isShooted()){
			bowAttack->stop();
			bowAttack->play();
			projectile->setDirection(orientation);
			projectile->setIsShooted(true);
			projectile->initProjectile();
			_sprite->setTextureRect(sf::IntRect(9*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
			bowAnim=0;
		}else if(bowAnim<20){bowAnim++;}

	}else if(bowAnim==0){
		_sprite->setTextureRect(sf::IntRect(8*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
		bowAnim++;
	}


}


void Player::useWand(){
	if(wandAnim>=1){

		if(wandAnim==10){
				wandAttack->stop();
			wandAttack->play();
			_sprite->setTextureRect(sf::IntRect(14*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
			wandAnim=0;
		}else if(wandAnim<10){wandAnim++;}

	}else if(wandAnim==0){
	_sprite->setTextureRect(sf::IntRect(13*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
	wandAnim++;
	}


}

void Player::initWeapon(){
	swordAnim= 0;
	bowAnim=0;
	wandAnim=0;
	SwordAttack=new sf::Music;
	 if (!SwordAttack->openFromFile("attackSimple.wav"))
    {
        std::cout<<"erreur de chargement de SwordAttack"<<std::endl;
    }
	bowAttack = new sf::Music;
	if (!bowAttack->openFromFile("Retro Weapon Arrow 02.wav"))
    {
        std::cout<<"erreur de chargement de bowAttack"<<std::endl;
    }
	wandAttack = new sf::Music;
	if (!wandAttack->openFromFile("Retro Weapon Electric 05.wav"))
    {
        std::cout<<"erreur de chargement de wandAttack"<<std::endl;
    }
}


void Player::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}


