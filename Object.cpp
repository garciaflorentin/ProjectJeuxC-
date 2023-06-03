#include "Object.hpp"


Object::Object(string nameObject, sf::Vector2f initPos) : 
_name(nameObject), _texture(TexturesLib::assignTexture(nameObject)), _sprite(*(new sf::Sprite(_texture))) {
    _name = nameObject;

    _texture.setSmooth(true);
    //_sprite = sf::Sprite(_texture);
    setPositionInBox(initPos);
}


Object& Object::operator=(const Object& other) {
    _texture = other._texture;
    _sprite = other._sprite;
    _name = other._name;

    return *this;
}


void Object::loadSprite(string nameSprite, sf::Vector2f initPos) { // return false si la texture � deja etait charg� , recupere la texture et l'assigne au sprite de l'object et return true sinon charge la textures et assigne la texture au sprite de l'object.
    _texture = TexturesLib::assignTexture(nameSprite);

    _texture.setSmooth(true);
    _sprite.setTexture(_texture);
    setPositionInBox(initPos);
}


sf::Sprite& Object::getSprite(){
    return _sprite;
}

const sf::Vector2f Object::getPosition() const {
    return _sprite.getPosition();
}

void Object::setSprite(sf::Sprite& sprite) {
    _sprite = sprite;
}

const string Object::getName() const { return _name; };

const int Object::getSerial() const { return 0; };


void Object::setPosition(sf::Vector2f& newPos){
    _sprite.setPosition(newPos);
}

void Object::setPositionInBox(sf::Vector2f& newPos){
    _sprite.setPosition({newPos.x*48,newPos.y*48});
}