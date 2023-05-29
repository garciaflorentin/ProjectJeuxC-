#include "Fate.hpp"

void Fate::initProjectile(){
    std::cout<<"initFate"<<std::endl;
    _sprite->setTextureRect(sf::IntRect(9,40,13,13));
    _sprite->setPosition(_player->getPosition().x,_player->getPosition().y);
    goTo();
	incrementeDistance();
}

Fate::Fate(const char* nameObject, sf::Vector2f initPos,Player* player): Projectile(nameObject, initPos, player){

            this->getSprite()->scale(4,4);

     }

Fate:: ~Fate(){}
