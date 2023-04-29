#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TexturesLib.hpp"

using namespace std;

class Object {

private:

    sf::Sprite _sprite;
    sf::Texture _texture;
    const char* name;
    const sf::Vector2f objectDim = { 48,48 };
    bool use;

    bool loadTexture(const char* spriteName);//focntion finalement inutile , je vais la virrer 
    

public:

    // attributs de classe , commun à tout les objets.
    static TexturesLib _texturesLib;

    //constructeurs
    Object();
    Object(const char* nameObject);

    //chargement textures sur le sprites
    bool loadSprite(const char* nameSprite, sf::Vector2f initPos);

    //getteur de use
    const bool isUse() const{
        return use;
    }

    //setteur
    void setPosition(sf::Vector2f& newPos);

    sf::Sprite& getSprite(){
        return _sprite;
    }
       

};

#endif