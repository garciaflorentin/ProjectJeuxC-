#include "Player.hpp"

Player::Player(const char* nameObject, sf::Vector2f initPos): Character(nameObject,initPos) {
	std::cout<<"player_constructeur"<< std::endl;
	speed = 3;
	damageAttack = 3;

	//_canOpenChest = true;
	//attackSimple=new sf::Music;
	/*/ if (!attackSimple->openFromFile("/home/garcia/Bureau/ProjetC++  (travail)/ProjectJeuxC-/bruit/attackSimple.wav"))
    {
        std::cout<<"erreur de chargement de attackSimple"<<std::endl;
    }*/
}

Player::~Player() {}

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

void Player::useSword(){
	_sprite->setTextureRect(sf::IntRect(6*OBJECT_SIZE, anim->y*OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
	//attackSimple->stop();
	//attackSimple->play();

}

void Player::move(sf::Vector2i deplacement){
	_sprite->move(deplacement.x,deplacement.y);

}


