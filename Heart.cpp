#include "Heart.hpp"

Heart::Heart(): _numberOfQuarter(12) {
	
	std::cout<< "Heart_constructor"<<std:: endl;

	_textures = new std::vector<sf::Texture*>();
	_sprites = new std::vector<sf::Sprite*>();
	_life = new std::vector<sf::Sprite*>();

	std::cout << "j'ai initialisÃ© les vector"<< std::endl;
	
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

Heart::Heart(const Heart& other)
{
	// Copie les textures
	_textures = new std::vector<sf::Texture*>(*other._textures);

	// Copie les sprites
	_sprites = new std::vector<sf::Sprite*>(*other._sprites);

	// Copie les vies
	_life = new std::vector<sf::Sprite*>(*other._life);

	// Copie le nombre de quartiers
	_numberOfQuarter = other._numberOfQuarter;
}

Heart& Heart::operator=(const Heart& other)
{
	if (this != &other)
	{
		// Supprime les anciennes textures
		delete[] _textures;

		// Copie les textures
		_textures = new std::vector<sf::Texture*>(*other._textures);

		// Supprime les anciens sprites
		delete[] _sprites;

		// Copie les sprites
		_sprites = new std::vector<sf::Sprite*>(*other._sprites);

		// Supprime les anciennes vies
		delete[] _life;

		// Copie les vies
		_life = new std::vector<sf::Sprite*>(*other._life);

		// Copie le nombre de quartiers
		_numberOfQuarter = other._numberOfQuarter;
	}

	return *this;
}



Heart::~Heart() {
	for (auto it = _textures->begin(); it != _textures->end(); ++it) {
		delete[] *it;
	}
	delete _textures;

	for (auto it = _sprites->begin(); it != _sprites->end(); ++it) {
		delete[] *it;
	}
	delete _sprites;

	for (auto it = _life->begin(); it != _life->end(); ++it) {
		delete[] *it;
	}
	delete _life;
}


void Heart::initlife() {

	std::cout<<"entrÃ© initlife()"<< std::endl;
	for (int i = 0; i < 3;i++){
		sf::Sprite* sprite = new sf::Sprite();
		*sprite = getHeart(4);
		_life->push_back(sprite);
		sprite->setPosition(i * 48.0, 0);
	}

	_numberOfQuarter = 12;
	std::cout<<"sortie initlife()"<< std::endl;
}

void Heart::changelife(int i) { // i = 1 ou i=-1

	if (i > 0) {

		if (_numberOfQuarter < 12)
			_numberOfQuarter++;

	}
	else if (i < 0) {
		if (_numberOfQuarter > 0) {
			_numberOfQuarter--;
		}
		
	
	}

		switch(_numberOfQuarter/4) {
		case 0:
				_life->push_back((*_sprites)[_numberOfQuarter%4]);
				_life->push_back((*_sprites)[0]);
				_life->push_back((*_sprites)[0]);
			break;

		case 1:
				_life->push_back((*_sprites)[4]);
				_life->push_back((*_sprites)[_numberOfQuarter % 4]);
				_life->push_back((*_sprites)[0]);
			break;

		case 2:
				_life->push_back((*_sprites)[4]);
				_life->push_back((*_sprites)[4]);
				_life->push_back((*_sprites)[_numberOfQuarter % 4]);
			break;

		case 3:
				_life->push_back((*_sprites)[4]);
				_life->push_back((*_sprites)[4]);
				_life->push_back((*_sprites)[4]);
			break;
		}

		for (int i = 0; i < 3; i++) {
			(*_life)[i]->setPosition(i*48.0,0);
		}
}

void Heart::removeLife() {
	changelife(-1);
}

void Heart::addLife() {
	changelife(+1);
}


