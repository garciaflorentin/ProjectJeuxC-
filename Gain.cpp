#include "Gain.hpp"

Gain::Gain(){
	//generation aleatoire du gain
	GAIN_SIZE = 48;
	srand(time(nullptr));
	_gain = rand() % 5;
	_sprite = new sf::Sprite();
	_sprite->setTexture( *TexturesLib::assignTexture("gain.png") );

}

Gain::~Gain() {
	delete _sprite;
}



