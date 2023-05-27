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
    switch(direction){
        case 0:
        this->getSprite()->move(0,-10);
        break;
        case 1:
        this->getSprite()->move(-10,0);
        break;
        case 2:
        this->getSprite()->move(0,10);
        break;
        case 3:
        this->getSprite()->move(10,0);
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

   if(typeid(*o) == typeid(Monster)){
        std::cout<<"ProjectcollideAMonster"<<std::endl;
        Monster* target=dynamic_cast<Monster*>(o);
        target->takeDamage(12);
    }

    distance=0;
    _isShot=false;

 }




 


void Projectile::arrowOutOfBounds(){
    //cout << "Projectile distance: " << distance << endl;

    if((isShot()) && (distance <= 96)) {
            //cout << "shooting projectile" << endl;
			goTo();
			incrementeDistance();

	} else if ( (isShot()) && (distance > 96)) {
			std:cout<<"destruction projectile"<<std::endl;
			setDistance(0);
		    setIsShot(false);
    }
    //cout << "exiting arrowOutOfBounds" << endl;
}
