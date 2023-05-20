#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include "TexturesLib.hpp"
//#include "GameGestion.hpp"

using namespace std;

class Object {

protected:
    sf::Texture* _texture;
    sf::Sprite* _sprite;
    //const char* name;
    string name;
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

    virtual const int getBlockSize() =0;

    //getteur de use
    const bool isUse() const {
        return _isUse;
    }

    //setteur
    void setPosition(sf::Vector2f& newPos);
    void setPositionInBox(sf::Vector2f& newPos);

    sf::Sprite* getSprite(){
        return _sprite;
    }

    sf::Vector2f getPosition() const {
        return _sprite->getPosition();
    }

    void setSprite(sf::Sprite& sprite) {
        _sprite = &sprite;
    }

    string getName() const { return name; };

    virtual void update(Object& player) {};

    //virtual void virtual_temporal_method_do_not_touch();

    //collide
	
    virtual void collide(Object* o)=0;
    /*{
        std::cout<<"collideObject"<<std::endl;
    }*/

    virtual int getSerial() { return 0; };
};

#endif