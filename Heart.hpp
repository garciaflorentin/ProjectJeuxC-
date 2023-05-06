#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
//#include "TexturesLib.hpp"

class Heart {
private:

	std::vector<sf::Texture*>* _textures ;
	std::vector<sf::Sprite*>* _sprites;
	std::vector<sf::Sprite*>* life;
	int numberOfQuarter;
	void initlife();
	void changelife(int i);

public:
	//constructeur et destructeur
	Heart();
	~Heart();

	
	void removeLife();
	void addLife();

	const int getNOQ() const{
		return numberOfQuarter;
	}

	sf::Sprite getHeart(int NOQ) const {

		return *(*_sprites)[NOQ];

	}

	std::vector<sf::Sprite*>* getLife() const {

		return life;

	}



};
#endif

