#include "Projectile.hpp"


Projectile::Projectile(const char* nameObject, sf::Vector2f initPos,Player* player) : Object(nameObject,initPos){
    this->player = player;
    _isShooted= false;
    distance= 0;
    this->getSprite()->scale(0.25,0.25);

    //initProjectile();
}

Projectile::Projectile(const Projectile& other) : Object(other)
{
    player = other.player;
    _isShooted = other._isShooted;
    distance= 0;
    this->getSprite()->scale(0.25,0.25);

}

Projectile& Projectile::operator=(const Projectile& other)
{
    if (this != &other) {
        Object::operator=(other);
        player = other.player;
        _isShooted = other._isShooted;
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
    _sprite->setPosition(player->getPosition().x,player->getPosition().y);
}


 void Projectile::collide(Object* o){
    distance=0;
    _isShooted=false;
    std::cout<<"ProjectcollideAobject"<<std::endl;
 }


void Projectile::arrowOutOfBounds(){
    if(isShooted() && distance<= 96){
			goTo();
			incrementeDistance();

	}else if( isShooted() && distance > 96){
			std:cout<<"destruction projectile"<<std::endl;
			setDistance(0);
		    setIsShooted(false);

		}

}
