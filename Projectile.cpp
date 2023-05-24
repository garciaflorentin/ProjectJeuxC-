#include "Projectile.hpp"


Projectile::Projectile(const char* nameObject, sf::Vector2f initPos,Player* player) : Object(nameObject,initPos){
    this->_player = player;
    _isShot= false;
    distance= 0;
    this->getSprite()->scale(0.25,0.25);

    //initProjectile();
}

Projectile::Projectile(const Projectile& other) : Object(other)
{
    _player = other._player;
    _isShot = other._isShot;
    distance= 0;
    this->getSprite()->scale(0.25,0.25);

}

Projectile& Projectile::operator=(const Projectile& other)
{
    if (this != &other) {
        Object::operator=(other);
        _player = other._player;
        _isShot = other._isShot;
        distance= 0;
        this->getSprite()->scale(0.25,0.25);

    }
    return *this;
}


void Projectile::goTo(){
    float vitesse= _player->getSpeed()*4;
    switch(direction){
        case 0:
        this->getSprite()->move(0,-vitesse);
        break;
        case 1:
        this->getSprite()->move(-vitesse,0);
        break;
        case 2:
        this->getSprite()->move(0,vitesse);
        break;
        case 3:
        this->getSprite()->move(vitesse,0);
        break;

    }
}

void Projectile::initProjectile(){
    std::cout<<"initprojectile"<<std::endl;
    _sprite->setTextureRect(sf::IntRect(direction*256,0,256,256));
    _sprite->setPosition(_player->getPosition().x,_player->getPosition().y);
}


 void Projectile::collide(Object* o){
    std::cout<<"ProjectileCollideObject"<<std::endl;

    distance=0;
    _isShot=false;

 }




 


void Projectile::arrowOutOfBounds(){

    if(isShot() && distance<= 96){
			goTo();
			incrementeDistance();

	}else if( isShot() && distance > 96){
			std:cout<<"destruction projectile"<<std::endl;
			setDistance(0);
		    setIsShot(false);

		}

}
