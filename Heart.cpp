#include "Heart.hpp"

Heart::Heart(): numberOfQuarter(12) {
	
	_textures = new std::vector<sf::Texture*>();
	_sprites = new std::vector<sf::Sprite*>();
	life = new std::vector<sf::Sprite*>();
	
	for (int i = 0; i < 5; i++) {
		sf::Texture* texture = new sf::Texture();
		if (!(texture->loadFromFile("TextureJeu/heart" + std::to_string(i) + ".png"))){
			std::cout<<"probleme dans la creation du coeur"<< i << std::endl;
		}
		
		_textures->push_back(texture);

		sf::Sprite* sprite = new sf::Sprite(*_textures->back());
		_sprites->push_back(sprite);
		//sprite->setPosition(i * 48.0, 0);
	}
	std::cout << "coeur entierement cree" << std::endl;
	initlife();
}

Heart::~Heart() {
	for (auto it = _textures->begin(); it != _textures->end(); ++it) {
		delete* it;
	}
	delete _textures;

	for (auto it = _sprites->begin(); it != _sprites->end(); ++it) {
		delete* it;
	}
	delete _sprites;

	for (auto it = life->begin(); it != life->end(); ++it) {
		delete* it;
	}
	delete life;
}


void Heart::initlife() {

	for (int i = 0; i < 3;i++){
		sf::Sprite* sprite = new sf::Sprite();
		*sprite = getHeart(4);
		life->push_back(sprite);
		sprite->setPosition(i * 48.0, 0);
	}
	numberOfQuarter = 12;
}

void Heart::changelife(int i) { // i = 1 ou i=-1

	if (i > 0) {

		if (numberOfQuarter < 12)
			numberOfQuarter++;

	}
	else if (i < 0) {
		if (numberOfQuarter > 0) {
			numberOfQuarter--;
		}
		
	
	}

		switch(numberOfQuarter/4) {
		case 0:
				life->push_back((*_sprites)[numberOfQuarter%4]);
				life->push_back((*_sprites)[0]);
				life->push_back((*_sprites)[0]);
			break;

		case 1:
				life->push_back((*_sprites)[4]);
				life->push_back((*_sprites)[numberOfQuarter % 4]);
				life->push_back((*_sprites)[0]);
			break;

		case 2:
				life->push_back((*_sprites)[4]);
				life->push_back((*_sprites)[4]);
				life->push_back((*_sprites)[numberOfQuarter % 4]);
			break;

		case 3:
				life->push_back((*_sprites)[4]);
				life->push_back((*_sprites)[4]);
				life->push_back((*_sprites)[4]);
			break;
		}

		for (int i = 0; i < 3; i++) {
			(*life)[i]->setPosition(i*48.0,0);
		}
}

void Heart::removeLife() {
	changelife(-1);
}

void Heart::addLife() {
	changelife(+1);
}


