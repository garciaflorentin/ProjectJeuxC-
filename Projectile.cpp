#include "Projectile.hpp"


Projectile::Projectile(string nameObject, sf::Vector2f initPos) : 
Object(nameObject,initPos) {
    _isShot = false;
    _distance= 0;

    //this->getSprite().scale(0.75,0.75);
}


Projectile::Projectile(const Projectile& other) : Object(other) {
    _isShot = other._isShot;
    _distance = 0;
    //this->getSprite().scale(1,1);

}


Projectile& Projectile::operator=(const Projectile& other) {
    if (this != &other) {
        Object::operator=(other);

        _isShot = other._isShot;
        _distance = 0;

        //this->getSprite().scale(1,1);
    }
    
    return *this;
}


void Projectile::collide(Object& o){
    _distance=0;
    _isShot=false;
 }


 void Projectile::arrowOutOfBounds(){
    if(isShot() && _distance<= 96) {
        goTo();
        incrementeDistance();
	} else if ( isShot() && _distance > 96) {
        setDistance(0);
        setIsShot(false);
    }
}