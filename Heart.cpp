#include "Heart.hpp"


Heart::Heart(): _numberOfQuarter(12){
    //cout << "Entering Heart constructor" << endl;

	for (int i = 0; i < 5; i++) {
        _textures.push_back(&TexturesLib::assignTexture("HeartTextures/heart" + std::to_string(i) + ".png"));
        //_sprites.push_back(new sf::Sprite(*_textures[i]));
	}

	initLife();
}


Heart::Heart(string owner): _numberOfQuarter(12){
    //cout << "Entering Heart constructor" << endl;

    _belongTo = owner;

	for (int i = 0; i < 5; i++) {
        _textures.push_back(&TexturesLib::assignTexture("HeartTextures/heart" + std::to_string(i) + ".png"));
        //_sprites.push_back(new sf::Sprite(*_textures[i]));
	}

	initLife();
}


Heart::Heart(const Heart& other) {
    //cout << "Heart by copy constructor" << endl;

	// Copie les textures
	_textures = other._textures;

	// Copie les sprites
	//_sprites = other._sprites;

	// Copie les vies
	_life = other._life;

	// Copie le nombre de quartiers
	_numberOfQuarter = other._numberOfQuarter;

    _belongTo = other._belongTo;

    initLife();
}



Heart& Heart::operator=(const Heart& other) {
    //cout << "Heart operator=" << endl;

	if (this != &other) {
        //cout << "deleting textures" << endl;

		// Supprime les anciennes textures
		// for (auto it = _textures.begin(); it != _textures.end(); ++it)
		//     delete *it;

		// Copie les textures
		_textures = std::vector<sf::Texture*>(other._textures);

		// Supprime les anciens sprites
		// for (auto it = _sprites.begin(); it != _sprites.end(); ++it)
		//     delete *it;

		// Copie les sprites
		//_sprites = std::vector<sf::Sprite*>(other._sprites);

		// Supprime les anciennes vies
		for (auto it = _life.begin(); it != _life.end(); ++it)
		    delete *it;

        //cout << "Textures copied" << endl;

		// Copie les vies
		_life = std::vector<sf::Sprite*>(other._life);

		// Copie le nombre de quartiers
		_numberOfQuarter = other._numberOfQuarter;

        _belongTo = other._belongTo;

        initLife();
	}

    //cout << "returning *this" << endl;

    //cout << "Exiting Heart::operator= with _belongTo = " << _belongTo << endl;

	return *this;
}

Heart::~Heart() {
	for (auto it = _textures.begin(); it != _textures.end(); ++it)
		delete *it;

	// for (auto it = _sprites.begin(); it != _sprites.end(); ++it)
	// 	delete *it;

    for (auto it = _life.begin(); it != _life.end(); ++it)
		delete *it;
}


void Heart::initLife() {
    //cout << "Entering initLife for " << getBelongTo() << endl;

    for (int i = 0; i < 3; i++) _life.push_back(new sf::Sprite(*_textures[4]));

	if( getBelongTo()=="PlayerTextures/player1.png") {

        //cout << "Positioning Player1 hearts" << endl;

	    for (int i = 0; i < 3; i++) 
            _life[i]->setPosition(i*32.0,0);

	} else if (getBelongTo()=="PlayerTextures/player2.png") {

        //cout << "Positioning Player2 hearts" << endl;
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32+570.0,0);
	}

	_numberOfQuarter = 12;
}


void Heart::changeLife(int i) {
    for (auto it = _life.begin(); it != _life.end(); ++it)
		delete *it;

	_life.clear();

    //cout << "Members in _life after clear() : " << _life.size() << endl;

	if (i > 0) {
		if (_numberOfQuarter < 12)
			_numberOfQuarter++;
	} else if (i < 0) {
		if (_numberOfQuarter > 0)
			_numberOfQuarter--;
	}

    switch(_numberOfQuarter/4) {
        case 0:
            _life.push_back(new sf::Sprite(*_textures[_numberOfQuarter%4]));
            _life.push_back(new sf::Sprite(*_textures[0]));
            _life.push_back(new sf::Sprite(*_textures[0]));
            break;

        case 1:
            _life.push_back(new sf::Sprite(*_textures[4]));
            _life.push_back(new sf::Sprite(*_textures[_numberOfQuarter % 4]));
            _life.push_back(new sf::Sprite(*_textures[0]));
            break;

        case 2:
            _life.push_back(new sf::Sprite(*_textures[4]));
            _life.push_back(new sf::Sprite(*_textures[4]));
            _life.push_back(new sf::Sprite(*_textures[_numberOfQuarter % 4]));
            break;

        case 3:
            _life.push_back(new sf::Sprite(*_textures[4]));
            _life.push_back(new sf::Sprite(*_textures[4]));
            _life.push_back(new sf::Sprite(*_textures[4]));
            break;
    }

    if(getBelongTo()=="PlayerTextures/player1.png"){
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32.0,0);
    } else if (getBelongTo()=="PlayerTextures/player2.png"){
        for (int i = 0; i < 3; i++)
            _life[i]->setPosition(i*32+570.0,0);
    }

    cout << "Members in _life after pushing back : " << _life.size() << endl;
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

// const sf::Sprite Heart::getHeart(int NOQ) const {
//     return *_sprites[NOQ];
// }

std::vector<sf::Sprite*>& Heart::getLife() {
    cout << "Members in _life : " << _life.size() << endl;
    return _life;
}