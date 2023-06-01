#include "Door.hpp"


Door::Door(string nameObject, sf::Vector2f initPos, TypeWall _typeWall): 
Wall(nameObject,initPos,_typeWall), _backDoorTexture(TexturesLib::assignTexture(nameObject)), _backDoorSprite(*(new sf::Sprite)) {
    _anim.x=0;
    _anim.y=0;
    _sprite.setTextureRect(sf::IntRect(42,_anim.y*_door_size,156,175));
    _isOpen=false;
    _isOpening=false;
    _resistance=1000000;

    _backDoorSprite.setTexture(_backDoorTexture);
    _backDoorSprite.setTextureRect(sf::IntRect(2159,496,240,240));
    _backDoorSprite.setPosition(initPos);
}



Door::~Door() {}


void Door::animDoor(){
    if (_anim.y==3) {
        _isOpen = true;
        _isOpening = false;
    } else if (_isOpening) {
        _anim.y = _anim.y+1;
        sf::sleep(sf::seconds(0.5));
        _sprite.setTextureRect(sf::IntRect(42,_anim.y*_door_size,156,175));
    }
}


void Door::collide(Object& o){
    if(typeid(o) == typeid(Player)){

        Player& p = dynamic_cast<Player&>(o);

        if(p.getKey()==4){
            if(!_isOpen){
                _isOpening=true;
            } else {
                sf::Vector2f newpos;
                newpos={9984,9984};
                p.isInTheCave(true);
                p.setPosition(newpos);
                
            }
        }
    }
}