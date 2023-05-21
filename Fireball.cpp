#include "Fireball.hpp"


Fireball::Fireball(const char* nameObject, sf::Vector2f initPos, Character* player, int dmg) {
    _player = dynamic_cast<Player*>(player);
    _isShot = false;
    distance = 0;

    _initPos = initPos;

    _dmg = dmg;

    this->computeTrajectory();

    initProjectile();

    // while (!_isShot) {
    //     goTo;
    // }
}

void Fireball::computeTrajectory() {
    sf::Vector2f targetPos = _player->getPosition();

    float distX = targetPos.x - this->getPosition().x;
    float distY = targetPos.y - this->getPosition().y;

    _dirVect.x = distX / PROJECTILE_SPEED;
    _dirVect.y = distY / PROJECTILE_SPEED;
}

void Fireball::initProjectile(){
    std::cout<<"init fireball"<<std::endl;
    _sprite->setTextureRect(sf::IntRect(0,0,256,256));
    if (_dirVect.x != 0)    _sprite->rotate(atan(_dirVect.y/_dirVect.x));
    else                    _sprite->rotate(90);

    _sprite->setPosition(_initPos.x,_initPos.y);
}

void Fireball::goTo(){
    this->getSprite()->move(_dirVect);
}

void Fireball::collide(Object* o){
    std::cout<<"Fireball CollideObject"<<std::endl;

   if(typeid(*o) == typeid(Player)){
        std::cout<<"Fireball collide Player"<<std::endl;
        Monster* target=dynamic_cast<Monster*>(o);
        target->takeDamage(12);
    }

    distance=0;
    _isShot=true;
 }
