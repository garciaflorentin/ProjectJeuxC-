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
#include "ColisionInterface.hpp"

class GameGestion : public ColisionInterface{
private:

	//sf::Sprite* player1; //sprite du joueur
	std::vector< Player*>* playerVector;
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

	std::vector< Player*>* getPlayerVector() {
		return playerVector;
	}


	void setPlayer(sf::Sprite* player); // ajoute un joeur au jeu

	void keyEvent(sf::Event e);//focntion interaction 

	std::vector<Object*>* toDrawUpdate(std::vector<sf::Vector2f>* currentWindow);

//interface colision
std::vector<Object*>& getWallMap(){
	std::vector<Object*> wallList;
	for(int i=0;i< _map->getMap()->size();i++){
		if(!(*_map->getMap())[i]->isPassable()){
			wallList.push_back((*_map->getMap())[i]);
		}
	}
	return wallList;
}

int collidePosition(Object* object1, Object* object2);

std::vector<int>& collideWall(Character* c, std::vector <Object*>& wallList);

};
#endif
