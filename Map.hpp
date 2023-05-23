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
#include "MeleeMonster.hpp"
#include "GoldenChest.hpp"
#include "Door.hpp"
#include "RangedMonster.hpp" 

#define SPAWN_FREQUENCY 200

using namespace std;

class Map {

private:

	std::vector<Object*>* toDraw;
	std::vector<Object*>* _map;
	std::vector<Object*>* _wallList;
	std::vector<Monster*>* _monsterList;
	Door* door;
	float LIMITE_Xneg= 0;
	float LIMITE_Y= 4992.f;
	float LIMITE_X= 9540;
	float LIMITE_Yneg=-4896.f;
	float LIMITE_XnegBoss=9472.f;
	float LIMITE_YnegBoss=9600.f;
	float LIMITE_XBoss=10456.f;
	float LIMITE_YBoss=10328.f;
	bool _spf = false;
	bool _spm = false;
	bool _spb = false;
	bool _spt = false;

	

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
	
	void spawnMobs(string area);
	
};
#endif
