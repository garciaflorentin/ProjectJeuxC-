#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

class Gain{

private:

    sf::Sprite* _sprite;
    sf::Texture* _texture;
    const int _gain;
    void setGain();

public:

    Gain();
    ~Gain();
    int getGain();


};

#endif