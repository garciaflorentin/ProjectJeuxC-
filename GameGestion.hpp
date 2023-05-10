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
	std::vector< Player*> playerVector;
	Player* player;
	sf::Clock time;
	Map* _map;

public:

	GameGestion();

	~GameGestion();

	enum Orientation { Down, Left, Right, Up };



	const int getObjectSize() const {
		return player->getBlockSize();
	}

	std::vector< Player*>& getPlayerVector() {
		return playerVector;
	}


	void setPlayer(sf::Sprite* player); // ajoute un joeur au jeu

	void keyEvent(sf::Event e);//focntion interaction 

	std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2i> currentWindow);



};
#endif
