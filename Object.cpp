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

Object::Object(const char* nameObject, sf::Vector2f initPos) : use(false) {
    name = nameObject;
    _texturesLib = TexturesLib();
    //on charge la textures sur le sprite
    switch(loadSprite(nameObject, initPos)) {

    case 1: cout << "une erreur c'est produit lors du chargement l'initialisation de l'object " << name << endl; break;
    case 2:
        cout << "Nouvelle texture charg� et "<<name<<" sprite cr�� " << endl; break;
    
    case 3:
        cout << "Texture deja connu. Texture telecharg� et une copie de" << name <<" cr�e" << endl;
    }


}

bool Object::loadSprite(const char* nameSprite, sf::Vector2f initPos) { // return false si la texture � deja etait charg� , recupere la texture et l'assigne au sprite de l'object et return true sinon charge la textures et assigne la texture au sprite de l'object.

    switch(_texturesLib.assignTexture(nameSprite,&_texture))
    {
    case 1: break;
    case 2:
        // si jamais charg�
        _texture.setSmooth(true);
        _sprite.setTexture(_texture);
        setPosition(initPos);
        return true;
        break;
    
    case 3:
        //si deja charg� ( il est dans _textures )
        sf::Texture* texture = _texturesLib.getTextures()[nameSprite];
        _texture.setSmooth(true);
        _sprite.setTexture(*texture);
        return false;
        break;

    }
    
}

void Object::setPosition(sf::Vector2f& newPos){
    _sprite.setPosition(newPos);
    position.x = newPos.x;
    position.y = newPos.y;
    
}

