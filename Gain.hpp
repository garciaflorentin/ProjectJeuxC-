#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

//class
#include "TexturesLib.hpp"
#include "Chest.hpp"
#include "Object.hpp"
class Chest;

class Gain : public Object{

private:

    int GAIN_SIZE = 16;
    int _gain;
   
public:

   
Gain(const char* nameObject, sf::Vector2f initPos) : Object(nameObject,initPos){
	//generation aleatoire du gain
	_gain = rand() % 5;
    _sprite->setScale(0.f,0.f);// rendre le sprite transparent


}

~Gain(){
	delete _sprite;
}

    
int getGain() const{
        std::cout<<"getGain"<<std::endl;
        return _gain;
}

void collide(Object* o){
    std::cout<<"afficheGain"<<std::endl;
    _sprite->setScale(48.f,48.f);
}

const int getBlockSize(){
    return GAIN_SIZE;
}

};

#endif