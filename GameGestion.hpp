#ifndef _GAMEGESTION_HPP_
#define _GAMEGESTION_HPP_

/// Special library
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/// STL
#include <iostream>
#include <vector>
#include <string>

/// Header create
#include "Player.hpp"
//#include "Object.hpp"
#include "Map.hpp"
#include "ColisionInterface.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "Monster.hpp"

using namespace std;

class GameGestion : public ColisionInterface{
private:

	std::vector< Player*>* playerVector;
	Player* player;
	sf::Clock time;
	Map* _map;
	sf::Music* forestMusic;
	sf::Music townMusic;
	sf::Music MountainMusic;
	sf::Music BeatchMusic;


public:

	GameGestion();

	~GameGestion();

	enum Orientation { Down, Left, Right, Up };

	Map* getMap(){
		return _map;
	}

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
	void getWallMap(std::vector<Object*>& wallList);

	void collideVisitor(Object* player,Object * o);


	void collideWallGestion();

	int collidePosition(Object* object1, Object* object2);

	void collideWall(Character* c, std::vector <Object*>& wallList,std::vector<int>& info) ;

	void LimitMap();

	int collidePosition2(Object* object1, Object* object2);


	//mise a jour des monstres (et autres objets qui bougent eventuellement)
	void updateMobs();


//musique gestion

void musicGestion();
};
#endif
