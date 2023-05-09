#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"

using namespace std;

class Object {

protected:
    sf::Texture* _texture;
    sf::Sprite* _sprite;
    const char* name;
    int OBJECT_SIZE = 48;
    bool _isUse;

    bool loadTexture(const char* spriteName);//focntion finalement inutile , je vais la virrer 
    

public:

    // attributs de classe , commun � tout les objets.
    static TexturesLib _texturesLib;

    //constructeurs
    Object();
    Object(const char* nameObject, sf::Vector2f initPos);
    //destructeur
    ~Object();

    //chargement textures sur le sprites
    const int loadSprite(const char* nameSprite, sf::Vector2f initPos);

    const int getBlockSize() const {
        return OBJECT_SIZE;
    }

    //getteur de use
    const bool isUse() const {
        return _isUse;
    }

    //setteur
    void setPosition(sf::Vector2f& newPos);

    sf::Sprite* getSprite(){
        return _sprite;
    }

    sf::Vector2f getPosition() {
        return _sprite->getPosition();
    }

    void setSprite(sf::Sprite& sprite) {
        _sprite = &sprite;
    }

       

};

#endif