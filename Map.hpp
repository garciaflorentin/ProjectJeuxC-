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
#include "RangedMonster.hpp" 

#define SPAWN_FREQUENCY 200

using namespace std;

class Map {

private:

	std::vector<Object*>* toDraw;
	std::vector<Object*>* _map;
	std::vector<Object*>* _wallList;
	std::vector<Monster*>* _monsterList;
	float LIMITE_Xneg= 0;
	float LIMITE_Y= 7125.f;
	float LIMITE_X= 14350;
	float LIMITE_Yneg=-7125.f;

	bool _spf = false;
	bool _spm = false;
	bool _spb = false;
	bool _spt = false;



public:

	Map();
	~Map();

	void getLimitMap(std::vector<float>& limit){
		limit={LIMITE_X,LIMITE_Y,LIMITE_Xneg,LIMITE_Yneg};
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

	void spawnMobs(string area);
	
};
#endif
