#include "RangedMonster.hpp"


void RangedMonster::attack(Character& target) {
    _crySound->setVolume(50);
    _crySound->stop();
    _crySound->play();

    _fireball = Fireball("fireball.png", this->getPosition(), target);
    _fireball.initProjectile();
    _fireball.setIsShot(true);
}


void RangedMonster::updateSprite(){
    if(_anim.x*_object_size >= _object_size*9)  _anim.x=9;
    _sprite.setTextureRect(sf::IntRect(_anim.x*_object_size, _anim.y*_object_size, _object_size, _object_size));
}