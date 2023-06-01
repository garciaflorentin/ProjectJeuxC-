#include "Heart.hpp"


Heart::Heart(): _numberOfQuarter(12){
	for (int i = 0; i < 5; i++) {
        sf::Texture* texture = &TexturesLib::assignTexture("HeartTextures/heart" + std::to_string(i) + ".png");
        _textures.push_back(texture);
        _sprites.push_back(new sf::Sprite(*texture));
	}

	initLife();
}


Heart& Heart::operator=(const Heart& other) {
    cout << "Heart operator=" << endl;

	if (this != &other) {
        cout << "deleting textures" << endl;

		// Supprime les anciennes textures
		// for (auto it = _textures.begin(); it != _textures.end(); ++it)
		//     delete *it;

		// Copie les textures
		_textures = std::vector<sf::Texture*>(other._textures);

		// Supprime les anciens sprites
		// for (auto it = _sprites.begin(); it != _sprites.end(); ++it)
		//     delete *it;

		// Copie les sprites
		_sprites = std::vector<sf::Sprite*>(other._sprites);

		// Supprime les anciennes vies
		// for (auto it = _life.begin(); it != _life.end(); ++it)
		//     delete *it;

        cout << "Textures copied" << endl;

		// Copie les vies
		_life = std::vector<sf::Sprite*>(other._life);

		// Copie le nombre de quartiers
		_numberOfQuarter = other._numberOfQuarter;

        _belongTo = other._belongTo;
	}

    cout << "returning *this" << endl;

	return *this;
}

Heart::~Heart() {
	for (auto it = _textures.begin(); it != _textures.end(); ++it)
		delete *it;

	for (auto it = _sprites.begin(); it != _sprites.end(); ++it)
		delete *it;

    for (auto it = _life.begin(); it != _life.end(); ++it)
		delete *it;
}


void Heart::initLife() {
    for (int i = 0; i < 3; i++) _life.push_back(_sprites[4]);

	if( getBelongTo()=="player1.png") {
	    for (int i = 0; i < 3; i++) 
            _life[i]->setPosition(i*32.0,0);
	} else if (getBelongTo()=="player2.png") {
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32+570.0,0);
	}

	_numberOfQuarter = 12;
}


void Heart::changeLife(int i) {
	getLife().clear();

	if (i > 0) {
		if (_numberOfQuarter < 12)
			_numberOfQuarter++;
	} else if (i < 0) {
		if (_numberOfQuarter > 0)
			_numberOfQuarter--;
	}

    switch(_numberOfQuarter/4) {
        case 0:
            _life.push_back(_sprites[_numberOfQuarter%4]);
            _life.push_back(_sprites[0]);
            _life.push_back(_sprites[0]);
            break;

        case 1:
            _life.push_back(_sprites[4]);
            _life.push_back(_sprites[_numberOfQuarter % 4]);
            _life.push_back(_sprites[0]);
            break;

        case 2:
            _life.push_back(_sprites[4]);
            _life.push_back(_sprites[4]);
            _life.push_back(_sprites[_numberOfQuarter % 4]);
            break;

        case 3:
            _life.push_back(_sprites[4]);
            _life.push_back(_sprites[4]);
            _life.push_back(_sprites[4]);
            break;
    }

    if(getBelongTo()=="player1.png"){
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32.0,0);
    } else if (getBelongTo()=="player2.png"){
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32+570.0,0);
    }
}


void Heart::removeLife() {
	changeLife(-1);
}

void Heart::addLife() {
	changeLife(+1);
}


void Heart::initPlayerLife(){
    initLife();
}

const string Heart::getBelongTo() const {
    return _belongTo;
}

void Heart::setBelongTo(string belongTo){
    _belongTo = _belongTo;
}

const int Heart::getNumberOfQuarter() const{
    return _numberOfQuarter;
}

const sf::Sprite Heart::getHeart(int NOQ) const {
    return *_sprites[NOQ];
}

std::vector<sf::Sprite*>& Heart::getLife() {
    return _life;
}