#include "Object.hpp"

// d�finition de l'attribut de classe texturesLib, commun � tout les objects.
TexturesLib Object::_texturesLib;

bool Object::loadTexture(const char* spriteName) {// inutile surrement
    

    if (!_texture->loadFromFile(spriteName)) {

        std::cout << "error image " << spriteName << std::endl;
        return false;

    }
    return true;
}

// constructeurs

Object::Object(){
    _isUse = false;
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();
    name = nullptr;
    //_texturesLib = TexturesLib();
}

Object::Object(const char* nameObject, sf::Vector2f initPos) : _isUse(false){
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();

    //nom
    name = nameObject;
    //_texturesLib = TexturesLib();
    //on charge la textures sur le sprite
    switch(loadSprite(nameObject, initPos)) {

    case 1: cout << "une erreur c'est produit lors du chargement l'initialisation de l'object " << name << endl; break;
    }


}

Object::~Object() {
    delete _texture;
    delete _sprite;
}

const int Object::loadSprite(const char* nameSprite, sf::Vector2f initPos) { // return false si la texture � deja etait charg� , recupere la texture et l'assigne au sprite de l'object et return true sinon charge la textures et assigne la texture au sprite de l'object.
    switch (TexturesLib::assignTexture(nameSprite, _texture))
    {
    case 1: return 1; break;
    case 2:
        // si jamais charg�
        _texture->setSmooth(true);
        _sprite->setTexture(*_texture);
        setPositionInBox(initPos);
        return 2;
        break;
    
    case 3:
        //si deja charg� ( il est dans _textures )
        //sf::Texture* texture = _texturesLib.getTextures()[nameSprite];
        _texture->setSmooth(true);
        _sprite->setTexture(*_texturesLib.getTexture(nameSprite));
        setPositionInBox(initPos);
        return 3;
        break;

    }
    
    return 0;
}



void Object::setPosition(sf::Vector2f& newPos){
    _sprite->setPosition(newPos);
}

void Object::setPositionInBox(sf::Vector2f& newPos){
    _sprite->setPosition({newPos.x*48,newPos.y*48});
}