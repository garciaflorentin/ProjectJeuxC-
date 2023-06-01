#include "Arrow.hpp"


Arrow::Arrow(string nameObject, sf::Vector2f initPos, Character& player) : 
Projectile(nameObject,initPos), _player(player) {};


void Arrow::goTo(){
    switch(_direction){
        case 0:
            this->getSprite().move(0,-PROJECTILE_SPEED);
            break;
        case 1:
            this->getSprite().move(-PROJECTILE_SPEED,0);
            break;
        case 2:
            this->getSprite().move(0,PROJECTILE_SPEED);
            break;
        case 3:
            this->getSprite().move(PROJECTILE_SPEED,0);
            break;
    }
}


void Arrow::initProjectile(){
    if (getName()=="arrow.png") {
        _sprite.setTextureRect(sf::IntRect(_direction*256,0,256,256));
        _sprite.setPosition(_player.getPosition().x, _player.getPosition().y);
        goTo();
        incrementeDistance();
    } else {
        _sprite.setTextureRect(sf::IntRect(9,40,13,13));
        _sprite.setPosition(_player.getPosition().x + _player.getSprite().getGlobalBounds().width/2, _player.getPosition().y + _player.getSprite().getGlobalBounds().height/2);
        goTo();
        incrementeDistance();
    }
}


Arrow::Arrow(const Arrow& other) : Projectile(other), _player(other._player) {
    _isShot = other._isShot;
    _distance= 0;
    this->getSprite().scale(0.25,0.25);
}


Arrow& Arrow::operator=(const Arrow& other){
    if (this != &other) {
        Projectile::operator=(other);

        _player = other._player;
        _isShot = other._isShot;
        _distance = 0;
        this->getSprite().scale(0.25,0.25);
    }

    return *this;
}