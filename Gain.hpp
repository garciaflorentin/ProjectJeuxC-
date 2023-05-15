#ifndef GAIN_HPP
#define GAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    sf::Music* musicGain;
    sf::Music* musicNoGain;

    int GAIN_SIZE = 16;
    int _gain;
    bool gainReaped =false;
   
public:

   
Gain(const char* nameObject, sf::Vector2f initPos) : Object(nameObject,initPos){
	//generation aleatoire du gain
	_gain = rand() % 5;
    _sprite->setScale(0.f,0.f);// rendre le sprite transparent
    musicGain= new sf::Music;
    if (!musicGain->openFromFile("/home/garcia/Bureau/ProjetC++  (travail)/ProjectJeuxC-/FreeSFX/GameSFX/PickUp/musicGain.wav"))
    {
        std::cout<<"erreur de chargement de musicGain"<<std::endl;
    }
    musicNoGain= new sf::Music;
    if (!musicNoGain->openFromFile("/home/garcia/Bureau/ProjetC++  (travail)/ProjectJeuxC-/FreeSFX/GameSFX/Wrong/musicNoGain.wav"))
    {
        std::cout<<"erreur de chargement de musicNoGainOk"<<std::endl;
    }



}

~Gain(){
	delete _sprite;
    delete musicGain;
    delete musicNoGain;
}

    
int getGain() const{
        std::cout<<"getGain"<<std::endl;
        return _gain;
}

void collide(Object* o){
    std::cout<<"afficheGain"<<std::endl;
    _sprite->setScale(48.f,48.f);
    if(!gainReaped){
        gainReaped=true;
    if(_gain>0){
        musicGain->play();
    }else{
        musicNoGain->play();
    }
    }
}

const int getBlockSize(){
    return GAIN_SIZE;
}

};

#endif