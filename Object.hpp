#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"

using namespace std;

class Object {

private:
    sf::Texture* _texture;
    sf::Sprite* _sprite;
    const char* name;
    const sf::Vector2f objectDim = { 48,48 };
    bool use;
    sf::Vector2f position;

    bool loadTexture(const char* spriteName);//focntion finalement inutile , je vais la virrer 
    

public:

    // attributs de classe , commun à tout les objets.
    static TexturesLib _texturesLib;

    //constructeurs
    Object();
    Object(const char* nameObject, sf::Vector2f initPos);

    //chargement textures sur le sprites
    const int loadSprite(const char* nameSprite, sf::Vector2f initPos);

    //getteur de use
    const bool isUse() const{
        return use;
    }

    //setteur
    void setPosition(sf::Vector2f& newPos);

    sf::Sprite* getSprite(){
        return _sprite;
    }

    void setSprite(sf::Sprite& sprite) {
        _sprite = &sprite;
    }

       

};

#endif