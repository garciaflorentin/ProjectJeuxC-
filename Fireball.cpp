#include "Fireball.hpp"


Fireball::Fireball(string nameObject, sf::Vector2f initPos, Character& player, float angle, int dmg) : 
Projectile(nameObject, initPos), _target(player) {
        _isShot = false;
        _distance = 0;

        this->setPosition(initPos);

        _dmg = dmg;

        this->computeTrajectory(angle);
}


Fireball& Fireball::operator=(const Fireball& other) {
    Projectile::operator=(other);

    _initPos = other._initPos;
    _dirVect = other._dirVect;

    _dmg = other._dmg;

    _target = other._target;

    return *this;
}


void Fireball::computeTrajectory(float angle) {
    sf::Vector2f targetPos = _target.getPosition();
    
    float distX = targetPos.x - this->getPosition().x;
    float distY = targetPos.y - this->getPosition().y;

    distX += distX * (1-cos(angle));
    distY += distY * (sin(angle));

    _dirVect.x = -distX / (distX+distY) * PROJECTILE_SPEED;
    _dirVect.y = -distY / (distX+distY) * PROJECTILE_SPEED;
}


void Fireball::initProjectile(){
    if (_dirVect.x != 0)    _sprite.rotate(-atan(_dirVect.y/_dirVect.x));
    else                    _sprite.rotate(90);
}


void Fireball::goTo(){
    this->getSprite().move(_dirVect);
}


void Fireball::collide(Object& o){
   if(o.getName()=="player1.png" || o.getName()=="player2.png"){
        Player& target=dynamic_cast<Player&>(o);
        target.takeDamage(2);
    }

    _distance=0;
    _isShot=false;
 }