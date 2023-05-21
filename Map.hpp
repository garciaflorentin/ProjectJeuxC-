#ifndef MAP_HPP
#define MAP_HPP


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"
#include "Gain.hpp"
#include "TexturesLib.hpp"
#include "Tile.hpp"
#include "Object.hpp"
#include "Character.hpp"
#include "Chest.hpp"
#include "Ground.hpp"
#include "TypeGround.hpp"
#include "Wall.hpp"
#include "TypeWall.hpp"
#include "Projectile.hpp"
#include "Monster.hpp"
#include "GoldenChest.hpp"
#include "Door.hpp"

using namespace std;

class Map {

private:

	std::vector<Object*>* toDraw;
	std::vector<Object*>* _map;
	std::vector<Object*>* _wallList;
	std::vector<Monster*>* _monsterList;
	Door* door;
	float LIMITE_Xneg= 0;
	float LIMITE_Y= 14350.f;
	float LIMITE_X= 14350;
	float LIMITE_Yneg=-7125.f;
	float LIMITE_XnegBoss=9472.f;
	float LIMITE_YnegBoss=9600.f;
	float LIMITE_XBoss=10456.f;
	float LIMITE_YBoss=10328.f;
	

public:
//384
	Map();
	~Map();

	void getLimitMap(std::vector<float>& limit){
		limit={LIMITE_X,LIMITE_Y,LIMITE_Xneg,LIMITE_Yneg};
	}

	void getLimitMapBoss(std::vector<float>& limit){
		limit={LIMITE_XnegBoss,LIMITE_YnegBoss,LIMITE_XBoss,LIMITE_YBoss};
	}


	std::vector<Object*>* objectToDraw(std::vector<sf::Vector2f>* currentWindow);

	void addObject(Wall* w);
	void addObject(Chest* c);
	void addObject(Ground* g);

	void addObject(Monster* m);

	void removeObject(Object* o);
	
	void createMap();

	void putObjectToDraw(std::vector<sf::Vector2f>* pos);


	std::vector<Object*>* getMap() {
		return _map;
	}

	std::vector<Object*>* getWallList();
	std::vector<Monster*>* getMonsters();

	void updateObjects(Player* player);	
	
	void updateAnimateObject();
	
};
#endif
