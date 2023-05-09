#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
//class
#include "TexturesLib.hpp"

class Gain{

private:


    int GAIN_SIZE;
    sf::Sprite* _sprite;
    sf::Texture* _texture;
    int _gain;
   
public:

    Gain();
    ~Gain();
    
    const int getGain() const{

        return _gain;
    }

    sf::Sprite* getSpriteGain() {
        return _sprite;
    }

};

#endif