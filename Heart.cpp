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
	initlife();
}

Heart::Heart(const Heart& other)
{
	// Copie les textures
	_textures = new std::vector<sf::Texture*>(*other._textures);

	// Copie les sprites
	_sprites = new std::vector<sf::Sprite*>(*other._sprites);

	// Copie les vies
	life = new std::vector<sf::Sprite*>(*other.life);

	// Copie le nombre de quartiers
	numberOfQuarter = other.numberOfQuarter;
}

Heart& Heart::operator=(const Heart& other)
{
	if (this != &other)
	{
		// Supprime les anciennes textures
		delete _textures;

		// Copie les textures
		_textures = new std::vector<sf::Texture*>(*other._textures);

		// Supprime les anciens sprites
		delete _sprites;

		// Copie les sprites
		_sprites = new std::vector<sf::Sprite*>(*other._sprites);

		// Supprime les anciennes vies
		delete life;

		// Copie les vies
		life = new std::vector<sf::Sprite*>(*other.life);

		// Copie le nombre de quartiers
		numberOfQuarter = other.numberOfQuarter;
	}

	return *this;
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
		sprite->setPosition(i * 32, 0);
	}
	numberOfQuarter = 12;

}

void Heart::changelife(int i) { // i = 1 ou i=-1
	getLife()->clear();
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
			(*life)[i]->setPosition(i*32.0,0);
		}
}


void Heart::removeLife() {
	changelife(-1);
}

void Heart::addLife() {
	changelife(+1);
}


