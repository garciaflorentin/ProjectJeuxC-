#include "Object.hpp"

// d�finition de l'attribut de classe texturesLib, commun � tout les objects.
TexturesLib Object ::_texturesLib;


bool Object:: loadTexture(const char* spriteName) {// inutile surrement
    if (!_texture.loadFromFile(spriteName)) {

        std::cout << "error image " << spriteName << std::endl;
        return false;

    }
}

// constructeurs

Object::Object() : use(false) {
    name = nullptr;
    _texturesLib = TexturesLib();
}

Object::Object(const char* nameObject) : use(false) {
    name = nameObject;
    sf::Vector2f v = { 0, 0 };
    _texturesLib = TexturesLib();
    //on charge la textures sur le sprite
    if (loadSprite(nameObject, v) != false) {
        cout << "Texture charg� et Sprite cr�e " << endl;
    }
    else {
        cout << "une erreur c'est produit lors du chargement l'initialisation de l'object " << name << endl;
    }


}

bool Object::loadSprite(const char* nameSprite, sf::Vector2f initPos) { // return false si la texture � deja etait charg� , recupere la texture et l'assigne au sprite de l'object et return true sinon charge la textures et assigne la texture au sprite de l'object.

    if (_texturesLib.assignTexture(nameSprite,&_texture) != false) {// si jamais charg�
        _sprite.setTexture(_texture);
        _sprite.setPosition(initPos);
        return true;
    }
    else {//si deja charg� ( il est dans _textures )
        sf::Texture* t = _texturesLib._textures[nameSprite];
        _sprite.setTexture(*t);
        _sprite.setPosition(initPos);
        return false;
    }
    
}


void Object::setPosition(sf::Vector2f& newPos){
    _sprite.setPosition(newPos);
}

