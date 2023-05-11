#ifndef _GAMEGESTION_HPP_
#define _GAMEGESTION_HPP_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

/// Header create
#include "Player.hpp"
#include "Object.hpp"
#include "Map.hpp"


class GameGestion{
private:

	//sf::Sprite* player1; //sprite du joueur
	std::vector< Player*>* _playerVector;

	sf::Vector2i _anim;
	std::vector< sf::Sprite*> _spriteVector;
	Player* _player;
	sf::Clock _time;

	Map* _map;

public:

	GameGestion();

	~GameGestion();


	enum Orientation { Down, Left, Right, Up };

	sf::Sprite* getPlayerSprite() const;// retourne le sprites du joueur

	const int getObjectSize() const {
		return _player->getBlockSize();
	}

	std::vector< sf::Sprite*>& getSpriteVector() {
		return _spriteVector;
	}

	std::vector< Player*>* getPlayerVector() {
		cout << "players: " << _playerVector->size() << endl;
		return _playerVector;
	}
	
	sf::Vector2i& getAnimVector() {
		return _anim;
	}

	void setPlayer(sf::Sprite* player); // ajoute un joeur au jeu

	void keyEvent(sf::Event e);//focntion interaction 

	Map* getMap() { return _map; }	//a des fins educatifs

	std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2i> currentWindow);
};
#endif
